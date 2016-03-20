// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file compression.c
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Compression Functions
@version 2016.03.20

@section DESCRIPTION
This library provides compression and decompression functions

@section LICENSE
GNU Lesser General Public License v3
Copyright (c) Devyn Collier Johnson, All rights reserved.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 3.0 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library.
*/


#include "compression.h"


/* FUNCTIONS */


#ifdef OSPOSIX
/** Private Function: Returns the size of a file (in bytes); POSIX systems only */
static ulint getfilesize(const char *filename) {
    struct stat sb;
    if (stat(filename, &sb) != 0x00) {
        fprintf(stderr, "ERROR: `getfilesize()` failed to get the filesize of `%s`!\n%s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
    }
    return (ulint)sb.st_size;
}
#else
/** Private Function: Returns the size of a file (in bytes) */
static ulint getfilesize(const char *filename) {
    FILE *fileptr = fopen(filename, "r");
    if (fileptr == (FILE *)NULL) { FAILED_OPEN_FILE() }
    if (fseek(fileptr, (slint)0x00, SEEK_END) != 0x00) { EXIT_ON_ERROR("Failed to get filesize") }
    ulint retval = (ulint)ftell(fileptr);
    fclose(fileptr);
    return retval;
}
#endif


/** zlib stream compression */
int zlib_compress_stream(FILE *source, FILE *dest, const int level) {
    int ret, flush;
    unsigned have;
    z_stream strm;
    unsigned char in[CHUNK];
    unsigned char out[CHUNK];
    // Allocate deflate state
    strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL;
    strm.opaque = Z_NULL;
    ret = deflateInit(&strm, level);
    if (ret != Z_OK) return ret;
    do {  // Compress until end of file
        strm.avail_in = (unsigned int)fread(in, 1, CHUNK, source);
        if (ferror(source)) {
            (void)deflateEnd(&strm);
            return Z_ERRNO;
        }
        flush = (feof(source) ? Z_FINISH : Z_NO_FLUSH);
        strm.next_in = in;
        do {  // Run deflate() on input until output buffer is not full
            strm.avail_out = CHUNK;
            strm.next_out = out;
            ret = deflate(&strm, flush);  // No bad return value
            if (ret == Z_STREAM_ERROR) return Z_STREAM_ERROR;  // State not clobbered
            have = (CHUNK - strm.avail_out);
            if ((fwrite(out, sizeof(char), have, dest)) != have || ferror(dest)) {
                (void)deflateEnd(&strm);
                return Z_ERRNO;
            }
        } while (strm.avail_out == 0);  // Finish compression if all data has been read
        if (strm.avail_in != 0x00) return Z_STREAM_ERROR;  // All input will be used
        // Done when all data has been processed
    } while (flush != Z_FINISH);
    if (ret != Z_STREAM_END) return Z_STREAM_ERROR;  // Stream is complete
    // Clean up and return
    (void)deflateEnd(&strm);
    return Z_OK;
}


/** zlib file compression */
int zlib_compress_file(char *source_filename, char *dest_filename, const int level) {
    FILE *source = fopen(source_filename, "rb");
    if (source == (FILE *)NULL) {
        fprintf(stderr, "ERROR: Failed to open file!\n%s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    FILE *dest = fopen(dest_filename, "wb");
    if (dest == (FILE *)NULL) {
        fprintf(stderr, "ERROR: Failed to open file!\n%s\n", strerror(errno));
        fclose(source);
        exit(EXIT_FAILURE);
    }
    // Prepare source file and buffer
    ulint source_size = getfilesize(source_filename);
    Bytef *source_data = (Bytef *)calloc(source_size + 1, 0x01);
    if (source_data == (Bytef *)NULL) { ALLOC_ERROR() }
    if (fread(source_data, 0x01, source_size, source) != source_size) {
        free(source_data);
        UNABLE_TO_READ_FILE()
    }
    fclose(source);
    source_data[source_size + 1] = '\0';
    // Prepare dest file
    ulint dest_size = compressBound(source_size + 1024);
    Bytef *dest_buf = (Bytef *)calloc(dest_size, 0x01);
    if (dest_buf == (Bytef *)NULL) {
        fclose(dest);
        free(source_data);
        free(dest_buf);
        ALLOC_WRITE_ERROR()
    }
    // Compress data
    int ret;
    ret = compress2(dest_buf, &dest_size, source_data, source_size, level);
    if (ret != Z_OK) {
        fclose(dest);
        free(dest_buf);
        return ret;
    }
    // Write compressed data
    setbuf(dest, (char *)dest_buf);
    if ((fwrite((char *)dest_buf, 0x01, dest_size, dest)) != dest_size) {
        fclose(dest);
        free(dest_buf);
        UNABLE_TO_WRITE_FILE()
    }
    // Clean up and return
    fclose(dest);
    free(dest_buf);
    return Z_OK;
}


/** zlib stream decompression */
int zlib_decompress_stream(FILE *source, FILE *dest) {
    int ret;
    unsigned have;
    z_stream strm;
    unsigned char in[CHUNK];
    unsigned char out[CHUNK];
    // Allocate inflate state
    strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL;
    strm.opaque = Z_NULL;
    strm.avail_in = 0;
    strm.next_in = Z_NULL;
    ret = inflateInit(&strm);
    if (ret != Z_OK) return ret;
    do {  // Decompress until deflate stream ends or end of file
        strm.avail_in = (unsigned int)fread(in, 1, CHUNK, source);
        if (ferror(source)) {
            (void)inflateEnd(&strm);
            return Z_ERRNO;
        }
        if (strm.avail_in == 0x00) break;
        strm.next_in = in;
        do {  // Run inflate() on data until the output buffer is not full
            strm.avail_out = CHUNK;
            strm.next_out = out;
            ret = inflate(&strm, Z_NO_FLUSH);
            if (ret == Z_STREAM_ERROR) return Z_STREAM_ERROR;  // State not clobbered
            switch (ret) {
                case Z_NEED_DICT:
                    ret = Z_DATA_ERROR;  // Fall through
                case Z_DATA_ERROR:
                case Z_MEM_ERROR:
                    (void)inflateEnd(&strm);
                    return ret;
                default: continue;
            }
            have = (CHUNK - strm.avail_out);
            if ((fwrite(out, sizeof(char), have, dest)) != have || ferror(dest)) {
                (void)inflateEnd(&strm);
                return Z_ERRNO;
            }
        } while (strm.avail_out == 0);
    } while (ret != Z_STREAM_END);  // Done when inflate() finishes
    // Clean up and return
    (void)inflateEnd(&strm);
    return ((ret == Z_STREAM_END) ? Z_OK : Z_DATA_ERROR);
}


/** zlib file decompression */
int zlib_decompress_file(char *source_filename, char *dest_filename) {
    FILE *source = fopen(source_filename, "rb");
    if (source == NULL) {
        fprintf(stderr, "ERROR: Failed to open source file!\n%s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    FILE *dest = fopen(dest_filename, "wb");
    if (dest == NULL) {
        fprintf(stderr, "ERROR: Failed to open file!\n%s\n", strerror(errno));
        fclose(source);
        exit(EXIT_FAILURE);
    }
    // Prepare source file and buffer
    ulint source_size = getfilesize(source_filename);
    uint8_t *source_data = (uint8_t *)calloc(source_size + 1, 0x01);
    if (source_data == NULL) { ALLOC_ERROR() }
    if (fread(source_data, 0x01, source_size + 1, source) != source_size) {
        fputs("`zlib_decompress_file` (Reading source file): ", stderr);
        free(source_data);
        fclose(source);
        fclose(dest);
        UNABLE_TO_READ_FILE()
    }
    fclose(source);
    source_data[source_size + 1] = '\0';
    // Allocate inflate state
    unsigned char output_data[CHUNK] = { 0 };
    z_stream strm;
    strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL;
    strm.opaque = Z_NULL;
    strm.avail_in = (unsigned int)source_size;
    strm.next_in = (Bytef *)source_data;
    strm.data_type = Z_BINARY;
    int ret = inflateInit(&strm);
    if (ret != Z_OK) {
        free(source_data);
        fclose(dest);
        return ret;
    }
    size_t dest_size = 0x00;
    // Decompress data
    do {  // Run inflate() on data until finished
        if (strm.avail_in == 0) break;
        strm.avail_out = CHUNK;
        strm.next_out = (Bytef *)output_data;
        ret = inflate(&strm, Z_NO_FLUSH);
        if (ret == Z_STREAM_ERROR) {  // State not clobbered
            free(source_data);
            fclose(dest);
            return Z_STREAM_ERROR;
        }
        switch (ret) {
            case Z_NEED_DICT:
                ret = Z_DATA_ERROR;  // Fall through
            case Z_DATA_ERROR:
            case Z_MEM_ERROR:
                (void)inflateEnd(&strm);
                free(source_data);
                fclose(dest);
                return ret;
            default:
                dest_size += (size_t)(CHUNK - strm.avail_out);
                if (strm.avail_in == 0 || strm.avail_out == 0 || ret == Z_STREAM_END) break;
        }
    } while (ret != Z_STREAM_END && strm.avail_out == 0);  // Wait until inflate() finishes
    (void)inflateEnd(&strm);
    Bytef *dest_buf = (Bytef *)calloc(dest_size, 0x01);
    ret = uncompress(dest_buf, &dest_size, source_data, source_size);
    if (ret != Z_OK) {
        fclose(dest);
        free(dest_buf);
        free(source_data);
        return ret;
    }
    free(source_data);
    // Write compressed data
    setbuf(dest, NULL);
    if ((fwrite((char *)dest_buf, 0x01, dest_size, dest)) != dest_size) {
        fclose(dest);
        free(dest_buf);
        fputs("`zlib_decompress_file` (Writing compressed file): ", stderr);
        UNABLE_TO_WRITE_FILE()
    }
    // Clean up and return
    fclose(dest);
    free(dest_buf);
    return Z_OK;
}


/** Zlib error reporting */
void zlib_err(const int ret) {
    fputs("zlib: ", stderr);
    switch (ret) {
        case Z_STREAM_ERROR:
            fputs("Invalid compression level\n", stderr);
            break;
        case Z_DATA_ERROR:
            fputs("Invalid or incomplete deflate data\n", stderr);
            break;
        case Z_MEM_ERROR:
            fputs("Out of memory\n", stderr);
            break;
        case Z_VERSION_ERROR:
            fputs("zlib version mismatch\n", stderr);
            break;
        case Z_ERRNO:
            if (ferror(stdin)) fputs("Failed to read stdin\n", stderr);
            if (ferror(stdout)) fputs("Failed to write to stdout\n", stderr);
            break;
        default:
            fputs("Unknown error\n", stderr);
    }
}
