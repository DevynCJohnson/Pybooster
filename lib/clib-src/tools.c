// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file tools.c
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Miscellaneous Functions
@version 2016.03.18

@section DESCRIPTION
Various functions that do not fit in other categories.
Such functions include string manipulations, file I/O, boolean tests, etc.

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


#include "tools.h"


/* STD-STRING AND STD-CTYPES ALTERNATIVES */


/** Test if the char is lowercase */
int islower_ascii(const int x) {
    return (int)((unsigned int)((unsigned int)x - 0x61u) < 26u);
}
int islowerx(const int x) __attribute__((alias("islower_ascii")));


/** Test if the char is uppercase */
int isupper_ascii(const int x) {
    return (int)((unsigned int)((unsigned int)x - 0x41u) < 26u);
}
int isupperx(const int x) __attribute__((alias("isupper_ascii")));


/** Test if the char is an alphanum */
int isalnumx(const int x) {
    return (int)(((unsigned int)(((unsigned int)x | 0x20u) - 0x61u) < 26u) || ((unsigned int)((unsigned int)x - 0x30u) < 10u));
}


/** Test if the char is a letter */
int isalphax(const int x) {
    return (int)((unsigned int)((x | 0x20) - 0x61) < 26u);
}


/** Test if the char is ascii */
int isasciix(const int x) {
    return (int)((unsigned int)x < 128u);
}


/** Test if the char is a space or tab */
int isblankx(const int x) {
    return (int)((x == 0x20) || (x == 0x9));
}


/** Test if the char is an control character */
int iscntrl_ascii(const int x) {
    return (int)(((unsigned int)x < 32u) || ((unsigned int)x == 127u));
}
int iscntrlx(const int x) __attribute__((alias("iscntrl_ascii")));


/** Test if the char is a number */
int isdigit_ascii(const int x) {
    return (int)((unsigned int)(x - 0x30) < 10u);
}
int isdigitx(const int x) __attribute__((alias("isdigit_ascii")));


/** Test if the char is a graph */
int isgraph_ascii(const int x) {
    return (int)((unsigned int)(x - 0x21) < 0x5Eu);
}
int isgraphx(const int x) __attribute__((alias("isgraph_ascii")));


/** Test if the char is an printable character */
int isprintx(const int x) {
    return (int)(((x & 0x7F) >= 32) && ((x & 0x7F) < 127));
}


/** Test if the char is punctuation */
int ispunct_ascii(const int x) {
    return (int)((((x & 0x7F) >= 32) && ((x & 0x7F) < 127)) && !(((unsigned int)(((unsigned int)x | 0x20u) - 0x61u) < 26u) || ((unsigned int)((unsigned int)x - 0x30u) < 10u)) && !(((x - 0x9) < 0x5) || (x == 0x20)));
}
int ispunctx(const int x) __attribute__((alias("ispunct_ascii")));


/** Test if the char is a space */
int isspace_ascii(const int x) {
    return (int)(((x - 0x9) < 0x5) || (x == 0x20));
}
int isspacex(const int x) __attribute__((alias("isspace_ascii")));


/** Test if the char is a hexadecimal character */
int isxdigit_ascii(const int x) {
    return (int)((unsigned int)(x - 0x30) < 0xAu || (unsigned int)((x | 0x20) - 0x61) <  0x6u);
}
int isxdigitx(const int x) __attribute__((alias("isxdigit_ascii")));


/** Return the lowercase form of a character */
int tolowerx(const int x) {
    return ((x > 0x5A || x < 0x41) ? x : (int)((uint8_t)x + 0x20u));
}


/** Return the uppercase form of a character */
int toupperx(const int x) {
    return ((x > 0x7A || x < 0x61) ? x : (int)((uint8_t)x - 0x20u));
}


/** Return the length of a string (not counting the NULL terminator) */
size_t strlenx(const char *__restrict__ str) {
    register const char *s;
    for (s = str; *s; ++s);
    return (size_t)(s - str);
}


/** Return the length of a `uint8_t` string (not counting the NULL terminator) */
size_t strlenx_uint8(const uint8_t *__restrict__ str) {
    register const uint8_t *s;
    for (s = str; *s; ++s);
    return (size_t)(s - str);
}


/** Return the number of UTF32 characters in a UTF32 string (not counting the NULL terminator) */
size_t strlen_utf32(const uint32_t *__restrict__ utf32str) {
    register const uint32_t *s;
    for (s = utf32str; *s; ++s);
    return (size_t)(s - utf32str);
}


/** Return the number of bytes in a UTF32 string (not counting the NULL terminator) */
size_t bytelen_utf32(const uint32_t *__restrict__ utf32str) {
    register const uint32_t *s;
    for (s = utf32str; *s; ++s);
    return (size_t)(0x4u * (s - utf32str));
}


/** Duplicate string; remember to use `free()` */
char *strdupx(const char *__restrict__ s) {
    register size_t len = (0x01u + strlenx(s));
    char *p = (char *)malloc(len);
    return (p ? memmove(p, s, len) : (char *)NULL);
}


/** Like strcpy, but returns a pointer to the NULL terminator */
char *STPCPY(char *__restrict__ dst, const char *__restrict__ src) {
    register const size_t length = strlenx(src);
    memmove(dst, src, (length + 0x1u));
    return (dst + length);
}


/** Like strcpy, but returns a pointer to the NULL terminator (re-implemented) */
char *STPCPYX(char *__restrict__ dst, const char *__restrict__ src, const size_t srclen) {
    memmove(dst, src, (srclen + 0x1u));
    return (dst + srclen);
}


/** Like strncpy, but returns a pointer to the NULL terminator */
char *STPNCPY(char *__restrict__ dst, const char *__restrict__ src, const size_t maxlen) {
    register const size_t srclen = strlenx(src);
    if (srclen < maxlen) {
        memmove(dst, src, srclen);
        memset(dst + srclen, 0x00, (maxlen - srclen));
        return (dst + srclen);
    } else {
        memmove(dst, src, maxlen);
        return (dst + maxlen);
    }
}


/** strcat (re-implemented) */
char *STRCAT(char *__restrict__ dst, const char *__restrict__ src) {
    memmove((dst + strlenx(dst)), src, (strlenx(src) + 0x1u));
    return dst;
}


/** strcat (re-implemented): Specify source and destination length */
char *STRCATX(char *__restrict__ dst, const char *__restrict__ src, const size_t dstlen, const size_t srclen) {
    memmove((dst + dstlen), src, (srclen + 0x1u));
    return dst;
}


/** Like strcat, but does not guarantee a NULL terminator */
size_t STRLCAT(char *__restrict__ dst, const char *__restrict__ src, const size_t maxlen) {
    register const size_t srclen = strlenx(src), dstlen = strlenx(dst);
    if (dstlen == maxlen) { return (maxlen + srclen); }
    if (srclen < (maxlen - dstlen)) {
        memmove((dst + dstlen), src, (srclen + 0x1u));
    } else {
        memmove((dst + dstlen), src, (maxlen - dstlen - 1));
        dst[maxlen - 1] = '\0';
    }
    return (dstlen + srclen);
}


/** Like strcpy, but does not guarantee a NULL terminator */
size_t STRLCPY(char *__restrict__ dst, const char *__restrict__ src, const size_t maxlen) {
    const size_t srclen = strlenx(src);
    if (srclen < maxlen) {
        memmove(dst, src, (srclen + 0x1u));
    } else if (maxlen != 0x00) {
        memmove(dst, src, (maxlen - 1));
        dst[maxlen - 1] = '\0';
    }
    return srclen;
}


/** strncat (re-implemented) */
char *STRNCAT(char *__restrict__ dst, const char *__restrict__ src, const size_t maxlen) {
    register const size_t dstlen = strlenx(dst), srclen = strlenx(src);
    register const size_t cpylen = (size_t)((srclen < maxlen) ? srclen : maxlen);
    memmove((dst + dstlen), src, cpylen);
    dst[dstlen + cpylen] = '\0';
    return dst;
}


/** strcpy (re-implemented) */
char *STRCPY(char *__restrict__ dst, const char *__restrict__ src) {
    memmove(dst, src, (strlenx(src) + 0x1u));
    return dst;
}


/** strcpy (re-implemented): Specify length of source */
char *STRCPYX(char *__restrict__ dst, const char *__restrict__ src, const size_t srclen) {
    memmove(dst, src, (srclen + 0x1u));
    return dst;
}


/** strncpy (re-implemented) */
char *STRNCPY(char *__restrict__ dst, const char *__restrict__ src, const size_t maxlen) {
    register const size_t srclen = strlenx(src);
    if (srclen < maxlen) {
        memmove(dst, src, srclen);
        memset((dst + srclen), 0x00, (maxlen - srclen));  // The remainder of dst is filled with \0
    } else {  // dst is not NULL terminated
        memmove(dst, src, maxlen);
    }
    return dst;
}


/** strncpy (re-implemented): Specify length of source */
char *STRNCPYX(char *__restrict__ dst, const char *__restrict__ src, const size_t maxlen, const size_t srclen) {
    if (srclen < maxlen) {
        memmove(dst, src, srclen);
        memset((dst + srclen), 0x00, (maxlen - srclen));  // The remainder of dst is filled with \0
    } else {  // dst is not NULL terminated
        memmove(dst, src, maxlen);
    }
    return dst;
}


/* FILE IO */


/** Test if the file exists */
int fileexists(const char *__restrict__ filename) {
    FILE *fileptr;
    fileptr = fopen(filename, "r");
    if (fileptr != (FILE *)NULL) {
        fclose(fileptr);
        return 0x1;
    }
    return 0x0;
}


/** Test if the file is writable */
int filewritable(const char *__restrict__ filename) {
    FILE *fileptr;
    fileptr = fopen(filename, "wb");
    if (fileptr != (FILE *)NULL) {
        fclose(fileptr);
        return 0x1;
    }
    return 0x0;
}


#ifdef OSPOSIX
/** Return the size of a file (number of bytes as `unsigned long int`); POSIX systems only */
ulint getfilesize(const char *__restrict__ filename) {
    struct stat sb;
    if (stat(filename, &sb) != 0x00) {
        fprintf(stderr, "ERROR: `getfilesize()` failed to get the filesize of `%s`!\n%s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
    }
    return (ulint)sb.st_size;
}


/** Return the size of a file (number of bytes as `size_t`); POSIX systems only */
size_t getfilesize_t(const char *__restrict__ filename) {
    struct stat sb;
    if (stat(filename, &sb) != 0x00) {
        fprintf(stderr, "ERROR: `getfilesize_t()` failed to get the filesize of `%s`!\n%s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
    }
    return (size_t)sb.st_size;
}


#else


/** Return the size of a file (in bytes) */
ulint getfilesize(const char *__restrict__ filename) {
    FILE *fileptr = fopen(filename, "r");
    if (fileptr == (FILE *)NULL) { FAILED_OPEN_FILE() }
    if (fseek(fileptr, (slint)0x00, SEEK_END) != 0x00) { EXIT_ON_ERROR("Failed to get filesize") }
    ulint retval = (ulint)ftell(fileptr);
    fclose(fileptr);
    return retval;
}


/** Return the size of a file (in size_t) */
size_t getfilesize_t(const char *__restrict__ filename) {
    FILE *fileptr = fopen(filename, "r");
    if (fileptr == (FILE *)NULL) { FAILED_OPEN_FILE() }
    if (fseek(fileptr, (slint)0x00, SEEK_END) != 0x00) { EXIT_ON_ERROR("Failed to get filesize") }
    size_t retval = (size_t)ftell(fileptr);
    fclose(fileptr);
    return retval;
}
#endif


/** Return the size of a file (in bytes); supports larger files */
uint64_t filesize64(const char *__restrict__ filename) {
    FILE *fileptr = fopen(filename, "r");
    if (fileptr == (FILE *)NULL) { FAILED_OPEN_FILE() }
    if (fseek(fileptr, (slint)0x00, SEEK_END) != 0x00) { UNABLE_TO_READ_FILE() }
    uint64_t retval = (uint64_t)ftell(fileptr);
    fclose(fileptr);
    return retval;
}


/** Return the file's contents as a char-array; remember to use `free()` */
char *getfile(const char *__restrict__ filename) {
    FILE *fileptr = fopen(filename, "r");
    if (fileptr == (FILE *)NULL) { FAILED_OPEN_FILE() }
#   ifdef OSPOSIX
    register size_t filesize = getfilesize(filename);
#   else
    if (fseek(fileptr, (slint)0x00, SEEK_END) != 0x00) { UNABLE_TO_READ_FILE() }
    register size_t filesize = (size_t)ftell(fileptr);
    rewind(fileptr);  // fseek(fileptr, (slint)0x00, SEEK_SET);
#   endif
#   if (defined(__SSP_ALL__) || defined(__SSP_STRONG__) || defined(__OPTIMIZE__))
    char *filestr = (char *)calloc(filesize, 0x01);
#   else
    char *filestr = (char *)malloc(filesize);
#   endif
    if (filestr == (char *)NULL) { ALLOC_ERROR() }
    if (fread(filestr, 0x01, filesize, fileptr) != filesize) { free(filestr); UNABLE_TO_READ_FILE() }
    fclose(fileptr);
    filestr[filesize] = '\0';
    return filestr;
}


/** Given the filesize, return the file's contents as a char-array; remember to use `free()` */
char *getfile_sizet(const char *__restrict__ filename, const size_t filesize) {
    FILE *fileptr = fopen(filename, "r");
    if (fileptr == (FILE *)NULL) { FAILED_OPEN_FILE() }
#   if (defined(__SSP_ALL__) || defined(__SSP_STRONG__) || defined(__OPTIMIZE__))
    char *filestr = (char *)calloc(filesize, 0x01);
#   else
    char *filestr = (char *)malloc(filesize);
#   endif
    if (filestr == (char *)NULL) { ALLOC_ERROR() }
    if (fread(filestr, 0x01, filesize, fileptr) != filesize) { free(filestr); UNABLE_TO_READ_FILE() }
    fclose(fileptr);
    filestr[filesize] = '\0';
    return filestr;
}


/** Return the binary file's contents as an array of uint8_t; remember to use `free()` */
uint8_t *getbinfile(const char *__restrict__ filename) {
    FILE *fileptr = fopen(filename, "rb");
    if (fileptr == (FILE *)NULL) { FAILED_OPEN_FILE() }
#   ifdef OSPOSIX
    register size_t filesize = getfilesize(filename);
#   else
    if (fseek(fileptr, (slint)0x00, SEEK_END) != 0x00) { UNABLE_TO_READ_FILE() }
    register size_t filesize = (size_t)ftell(fileptr);
    rewind(fileptr);  // fseek(fileptr, (slint)0x00, SEEK_SET);
#   endif
#   if (defined(__SSP_ALL__) || defined(__SSP_STRONG__) || defined(__OPTIMIZE__))
    uint8_t *filestr = (uint8_t *)calloc(filesize, 0x01);
#   else
    uint8_t *filestr = (uint8_t *)malloc(filesize);
#   endif
    if (filestr == (uint8_t *)NULL) { ALLOC_ERROR() }
    if (fread(filestr, 0x01, filesize, fileptr) != filesize) { free(filestr); UNABLE_TO_READ_FILE() }
    fclose(fileptr);
    filestr[filesize] = '\0';
    return filestr;
}


/** Given the filesize, return the binary file's contents as an array of uint8_t; remember to use `free()` */
uint8_t *getbinfile_sizet(const char *__restrict__ filename, const size_t filesize) {
    FILE *fileptr = fopen(filename, "rb");
    if (fileptr == (FILE *)NULL) { FAILED_OPEN_FILE() }
#   if (defined(__SSP_ALL__) || defined(__SSP_STRONG__) || defined(__OPTIMIZE__))
    uint8_t *filestr = (uint8_t *)calloc(filesize, 0x01);
#   else
    uint8_t *filestr = (uint8_t *)malloc(filesize);
#   endif
    if (filestr == (uint8_t *)NULL) { ALLOC_ERROR() }
    if (fread(filestr, 0x01, filesize, fileptr) != filesize) { free(filestr); UNABLE_TO_READ_FILE() }
    fclose(fileptr);
    filestr[filesize] = '\0';
    return filestr;
}


/** Write data to a file; unbuffered */
void writefile(const char *__restrict__ filename, uint8_t *data, const size_t filesize) {
    register FILE *fileptr = fopen(filename, "wb");
    if (fileptr == (FILE *)NULL) { FAILED_OPEN_FILE() }
    setbuf(fileptr, (char *)NULL);
    if ((fwrite((char *)data, 0x1, filesize, fileptr)) != filesize) {
        fclose(fileptr);
        UNABLE_TO_WRITE_FILE()
    }
    fclose(fileptr);
}


/** Write data to a file; buffered */
void writefilebuf(const char *__restrict__ filename, char *data, const size_t filesize) {
    register FILE *fileptr = fopen(filename, "wb");
    if (fileptr == (FILE *)NULL) { FAILED_OPEN_FILE() }
    char *buffer = (char *)calloc(filesize, 0x01);
    if (buffer == (char *)NULL) { ALLOC_WRITE_ERROR() }
    setbuf(fileptr, buffer);
    if ((fwrite(data, 0x01, filesize, fileptr)) != filesize) {
        fclose(fileptr);
        free(buffer);
        UNABLE_TO_WRITE_FILE()
    }
    fclose(fileptr);
    free(buffer);
}


/** Append data to a file; unbuffered */
void appendfile(const char *__restrict__ filename, uint8_t *data, const size_t datasize) {
    register FILE *fileptr = fopen(filename, "ab");
    if (fileptr == (FILE *)NULL) { FAILED_OPEN_FILE() }
    setbuf(fileptr, (char *)NULL);
    if ((fwrite((char *)data, 0x01, datasize, fileptr)) != datasize) {
        fclose(fileptr);
        UNABLE_TO_WRITE_FILE()
    }
    fclose(fileptr);
}


/** Append data to a file; buffered */
void appendfilebuf(const char *__restrict__ filename, char *data, const size_t datasize) {
    register FILE *fileptr = fopen(filename, "ab");
    if (fileptr == (FILE *)NULL) { FAILED_OPEN_FILE() }
    char *buffer = (char *)calloc(datasize, 0x01);
    if (buffer == (char *)NULL) { ALLOC_WRITE_ERROR() }
    setbuf(fileptr, buffer);
    if ((fwrite(data, 0x01, datasize, fileptr)) != datasize) {
        fclose(fileptr);
        free(buffer);
        UNABLE_TO_WRITE_FILE()
    }
    fclose(fileptr);
    free(buffer);
}


/**
    Hide data by appending the data to an existing file and include the metadata\n
    This IO-stream is buffered
    @param[in] filename    The name of an existing file
    @param[in] data    The data to hide
    @param[in] datasize    The size of data in bytes
*/
void hide_data_in_file(const char *__restrict__ filename, const uint8_t *__restrict__ data, const size_t datasize) {
    const size_t metadata = getfilesize_t(filename);
    FILE *wfileptr = fopen(filename, "ab");
    if (wfileptr == (FILE *)NULL) {
        fprintf(stderr, "ERROR: Failed to open file!\n%s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    char buffer[2048] = { 0 };
    setbuf(wfileptr, buffer);
    // Append data
    if ((fwrite(data, (size_t)0x1, datasize, wfileptr)) != datasize) {
        fclose(wfileptr);
        fprintf(stderr, "ERROR: Unable to append to file!\n");
        exit(EXIT_FAILURE);
    }
    // Append metadata
    if ((fwrite(&metadata, (size_t)0x1, sizeof(size_t), wfileptr)) != sizeof(size_t)) {
        fclose(wfileptr);
        fprintf(stderr, "ERROR: Unable to append metadata to file!\n");
        exit(EXIT_FAILURE);
    }
    // Close
    fclose(wfileptr);
}


/** Return the size of the data hidden in the file */
size_t get_size_of_hidden_data(const char *__restrict__ filename) {
    const size_t wrapperfilesize = getfilesize_t(filename);
    FILE *fileptr = fopen(filename, "rb");
    if (fileptr == (FILE *)NULL) {
        fprintf(stderr, "ERROR: Failed to open file!\n%s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    uint8_t *file_contents = (uint8_t *)calloc((size_t)0x1, wrapperfilesize);
    if (file_contents == (uint8_t *)NULL) {
        fprintf(stderr, "ERROR: Failed to allocate memory for file!\n");
        exit(EXIT_FAILURE);
    }
    if (fread(file_contents, (size_t)0x01, wrapperfilesize, fileptr) != wrapperfilesize) {
        free(file_contents);
        fprintf(stderr, "ERROR: Unable to read file!\n");
        exit(EXIT_FAILURE);
    }
    fclose(fileptr);
    size_t filesize = 0x0;
    memcpy(&filesize, &file_contents[(wrapperfilesize - sizeof(size_t))], sizeof(size_t));
    free(file_contents);
    return ((wrapperfilesize - filesize) - sizeof(size_t));
}


/** Get the hidden data stored in the file as a uint8_t-array; remember to use `free()` */
uint8_t *get_hidden_data_from_file(const char *__restrict__ filename) {
    const size_t wrapperfilesize = getfilesize_t(filename);
    FILE *fileptr = fopen(filename, "rb");
    if (fileptr == (FILE *)NULL) {
        fprintf(stderr, "ERROR: Failed to open file!\n%s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    uint8_t *file_contents = (uint8_t *)calloc((size_t)0x1, wrapperfilesize);
    if (file_contents == (uint8_t *)NULL) {
        fprintf(stderr, "ERROR: Failed to allocate memory for file!\n");
        exit(EXIT_FAILURE);
    }
    if (fread(file_contents, (size_t)0x01, wrapperfilesize, fileptr) != wrapperfilesize) {
        free(file_contents);
        fprintf(stderr, "ERROR: Unable to read file!\n");
        exit(EXIT_FAILURE);
    }
    fclose(fileptr);
    size_t orig_filesize = 0x0;
    memcpy(&orig_filesize, &file_contents[(wrapperfilesize - sizeof(size_t))], sizeof(size_t));
    const size_t size_of_hidden = ((wrapperfilesize - orig_filesize) - sizeof(size_t));
    uint8_t *hidden_data = (uint8_t *)calloc((size_t)0x1, size_of_hidden + 1);
    if (hidden_data == (uint8_t *)NULL) {
        fprintf(stderr, "ERROR: Failed to allocate memory for hidden data!\n");
        exit(EXIT_FAILURE);
    }
    memcpy(hidden_data, &file_contents[(wrapperfilesize - (size_of_hidden + sizeof(size_t)))], size_of_hidden);
    free(file_contents);
    hidden_data[size_of_hidden] = '\0';
    return hidden_data;
}


/* FILE INTEGRITY */


/** Open the specified file and return the parity of the file */
uint8_t filebitparity64(const char *__restrict__ filename) {
    FILE *fileptr = fopen(filename, "rb");
    if (fileptr == (FILE *)NULL) {
        fprintf(stderr, "ERROR: Failed to open file!\n%s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
#   ifdef OSPOSIX
    register size_t filesize = getfilesize(filename);
#   else
    if (fseek(fileptr, (slint)0x00, SEEK_END) != 0x00) {
        fputs("ERROR: Unable to read file!\n", stderr);
        exit(EXIT_FAILURE);
    }
    register size_t filesize = (size_t)ftell(fileptr);
    rewind(fileptr);  // fseek(fileptr, (slint)0x00, SEEK_SET);
#   endif
    uint8_t *filestr = (uint8_t *)calloc((filesize + (64u - (filesize & 63u))), 0x01u);
    if (filestr == (uint8_t *)NULL) {
        fputs("ERROR: Failed to allocate memory!\n", stderr);
        exit(EXIT_FAILURE);
    }
    if (fread(filestr, 0x01, filesize, fileptr) != filesize) {
        free(filestr);
        fputs("ERROR: Unable to read file!\n", stderr);
        exit(EXIT_FAILURE);
    }
    fclose(fileptr);
    filestr[filesize] = '\0';
    // Check parity
    uint8_t xparity = 0x0;
    register size_t i = 0x0;
#   ifdef __clang__
#      pragma GCC diagnostic ignored "-Wcast-align"
#   endif
    uint64_t *filestr64 = (uint64_t *)filestr;
    filesize = (size_t)(filesize + (64 - (filesize & 63)));
    while (i != filesize) {
        register uint64_t x = (filestr64[i & 63] ^ (filestr64[i & 63] >> 0x10));
        x = (x ^ (x >> 0x8));
        x = (x ^ (x >> 0x4));
        xparity = (uint8_t)(xparity | (uint8_t)((0x6996 >> (x & 0xF)) & 0x1));
        i += 64;
        if (i == filesize) { break; }
    }
#   ifdef __clang__
#      pragma GCC diagnostic warning "-Wcast-align"
#   endif
    free(filestr);
    return xparity;
}


/** Open the specified file and return the Adler16 checksum of the file */
uint16_t fileadler16(const char *__restrict__ filename) {
    FILE *fileptr = fopen(filename, "rb");
    if (fileptr == (FILE *)NULL) {
        fprintf(stderr, "ERROR: Failed to open file!\n%s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
#   ifdef OSPOSIX
    register size_t filesize = getfilesize(filename);
#   else
    if (fseek(fileptr, (slint)0x00, SEEK_END) != 0x00) {
        fputs("ERROR: Unable to read file!\n", stderr);
        exit(EXIT_FAILURE);
    }
    register size_t filesize = (size_t)ftell(fileptr);
    rewind(fileptr);  // fseek(fileptr, (slint)0x00, SEEK_SET);
#   endif
    uint8_t *filestr = (uint8_t *)calloc((filesize + (16 - (filesize & 15))), 0x1);
    if (filestr == (uint8_t *)NULL) {
        fputs("ERROR: Failed to allocate memory!\n", stderr);
        exit(EXIT_FAILURE);
    }
    if (fread(filestr, 0x01, filesize, fileptr) != filesize) {
        free(filestr);
        fputs("ERROR: Unable to read file!\n", stderr);
        exit(EXIT_FAILURE);
    }
    fclose(fileptr);
    filestr[filesize] = '\0';
    // Adler16 checksum
    register uint16_t a = 0x1, b = 0x0;
    register size_t index, len = (filesize + (16 - (filesize & 15)));;
    for (index = 0x0; index < len; ++index) {
        a = ((uint16_t)(a + (uint16_t)filestr[index]) % (uint16_t)0xF1);
        b = ((uint16_t)(b + a) % (uint16_t)0xF1);
    }
    return (uint16_t)((uint16_t)(b << 8) | a);
}


/** Open the specified file and return the Adler32 checksum of the file */
uint32_t fileadler32(const char *__restrict__ filename) {
    FILE *fileptr = fopen(filename, "rb");
    if (fileptr == (FILE *)NULL) {
        fprintf(stderr, "ERROR: Failed to open file!\n%s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
#   ifdef OSPOSIX
    register size_t filesize = getfilesize(filename);
#   else
    if (fseek(fileptr, (slint)0x00, SEEK_END) != 0x00) {
        fputs("ERROR: Unable to read file!\n", stderr);
        exit(EXIT_FAILURE);
    }
    register size_t filesize = (size_t)ftell(fileptr);
    rewind(fileptr);  // fseek(fileptr, (slint)0x00, SEEK_SET);
#   endif
    uint8_t *filestr = (uint8_t *)calloc((filesize + (16 - (filesize & 15))), 0x1);
    if (filestr == (uint8_t *)NULL) {
        fputs("ERROR: Failed to allocate memory!\n", stderr);
        exit(EXIT_FAILURE);
    }
    if (fread(filestr, 0x01, filesize, fileptr) != filesize) {
        free(filestr);
        fputs("ERROR: Unable to read file!\n", stderr);
        exit(EXIT_FAILURE);
    }
    fclose(fileptr);
    filestr[filesize] = '\0';
    // Adler32 checksum
    register uint32_t a = 0x1, b = 0x0;
    register size_t index, len = (filesize + (16 - (filesize & 15)));
    for (index = 0x0; index < len; ++index) {
        a = ((uint32_t)(a + (uint32_t)filestr[index]) % (uint32_t)0xFFF1);
        b = ((uint32_t)(b + a) % (uint32_t)0xFFF1);
    }
    return (uint32_t)((uint32_t)(b << 16) | a);
}


/** Open the specified file and return the Adler64 checksum of the file */
uint64_t fileadler64(const char *__restrict__ filename) {
    FILE *fileptr = fopen(filename, "rb");
    if (fileptr == (FILE *)NULL) {
        fprintf(stderr, "ERROR: Failed to open file!\n%s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
#   ifdef OSPOSIX
    register size_t filesize = getfilesize(filename);
#   else
    if (fseek(fileptr, (slint)0x00, SEEK_END) != 0x00) {
        fputs("ERROR: Unable to read file!\n", stderr);
        exit(EXIT_FAILURE);
    }
    register size_t filesize = (size_t)ftell(fileptr);
    rewind(fileptr);  // fseek(fileptr, (slint)0x00, SEEK_SET);
#   endif
    uint8_t *filestr = (uint8_t *)calloc((filesize + (16 - (filesize & 15))), 0x1);
    if (filestr == (uint8_t *)NULL) {
        fputs("ERROR: Failed to allocate memory!\n", stderr);
        exit(EXIT_FAILURE);
    }
    if (fread(filestr, 0x01, filesize, fileptr) != filesize) {
        free(filestr);
        fputs("ERROR: Unable to read file!\n", stderr);
        exit(EXIT_FAILURE);
    }
    fclose(fileptr);
    filestr[filesize] = '\0';
    // Adler64 checksum
    register uint64_t a = 0x1, b = 0x0;
    register size_t index, len = (filesize + (16 - (filesize & 15)));
    for (index = 0x0; index < len; ++index) {
        a = ((uint64_t)(a + (uint64_t)filestr[index]) % (uint64_t)0xFFFFFFF1);
        b = ((uint64_t)(b + a) % (uint64_t)0xFFFFFFF1);
    }
    return (uint64_t)((uint64_t)(b << 32) | a);
}


/** Open the specified file and return the Anti-Adler64 (decrementing for-loop) checksum of the file */
uint64_t fileantiadler64(const char *__restrict__ filename) {
    FILE *fileptr = fopen(filename, "rb");
    if (fileptr == (FILE *)NULL) {
        fprintf(stderr, "ERROR: Failed to open file!\n%s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
#   ifdef OSPOSIX
    register size_t filesize = getfilesize(filename);
#   else
    if (fseek(fileptr, (slint)0x00, SEEK_END) != 0x00) {
        fputs("ERROR: Unable to read file!\n", stderr);
        exit(EXIT_FAILURE);
    }
    register size_t filesize = (size_t)ftell(fileptr);
    rewind(fileptr);  // fseek(fileptr, (slint)0x00, SEEK_SET);
#   endif
    uint8_t *filestr = (uint8_t *)calloc((filesize + (16 - (filesize & 15))), 0x1);
    if (filestr == (uint8_t *)NULL) {
        fputs("ERROR: Failed to allocate memory!\n", stderr);
        exit(EXIT_FAILURE);
    }
    if (fread(filestr, 0x01, filesize, fileptr) != filesize) {
        free(filestr);
        fputs("ERROR: Unable to read file!\n", stderr);
        exit(EXIT_FAILURE);
    }
    fclose(fileptr);
    filestr[filesize] = '\0';
    // Anti-Adler64 checksum
    register uint64_t a = 0x1, b = 0x0;
    register size_t index;
    for (index = (filesize + (16 - (filesize & 15))); --index;) {
        a = ((uint64_t)(a + (uint64_t)filestr[index]) % (uint64_t)0xFFFFFFF1);
        b = ((uint64_t)(b + a) % (uint64_t)0xFFFFFFF1);
    }
    return (uint64_t)((uint64_t)(b << 32) | a);
}


/** Open the specified file and return the Anti-Adler64rev2 (decrementing and re-arranged for-loop) checksum of the file */
uint64_t fileantiadler64rev2(const char *__restrict__ filename) {
    FILE *fileptr = fopen(filename, "rb");
    if (fileptr == (FILE *)NULL) {
        fprintf(stderr, "ERROR: Failed to open file!\n%s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
#   ifdef OSPOSIX
    register size_t filesize = getfilesize(filename);
#   else
    if (fseek(fileptr, (slint)0x00, SEEK_END) != 0x00) {
        fputs("ERROR: Unable to read file!\n", stderr);
        exit(EXIT_FAILURE);
    }
    register size_t filesize = (size_t)ftell(fileptr);
    rewind(fileptr);  // fseek(fileptr, (slint)0x00, SEEK_SET);
#   endif
    uint8_t *filestr = (uint8_t *)calloc((filesize + (16 - (filesize & 15))), 0x1);
    if (filestr == (uint8_t *)NULL) {
        fputs("ERROR: Failed to allocate memory!\n", stderr);
        exit(EXIT_FAILURE);
    }
    if (fread(filestr, 0x01, filesize, fileptr) != filesize) {
        free(filestr);
        fputs("ERROR: Unable to read file!\n", stderr);
        exit(EXIT_FAILURE);
    }
    fclose(fileptr);
    filestr[filesize] = '\0';
    // Anti-Adler64rev2 checksum
    register uint64_t a = 0x1, b = 0x0;
    register size_t index;
    for (index = (filesize + (16 - (filesize & 15))); --index;) {
        b = ((uint64_t)(b + a) % (uint64_t)0xFFFFFFF1);
        a = ((uint64_t)(a + (uint64_t)filestr[index]) % (uint64_t)0xFFFFFFF1);
    }
    return (uint64_t)((uint64_t)(b << 32) | a);
}


/** Open the specified file and return the Fletcher16 checksum of the file */
uint16_t filefletcher16(const char *__restrict__ filename) {
    FILE *fileptr = fopen(filename, "rb");
    if (fileptr == (FILE *)NULL) {
        fprintf(stderr, "ERROR: Failed to open file!\n%s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
#   ifdef OSPOSIX
    register size_t filesize = getfilesize(filename);
#   else
    if (fseek(fileptr, (slint)0x00, SEEK_END) != 0x00) {
        fputs("ERROR: Unable to read file!\n", stderr);
        exit(EXIT_FAILURE);
    }
    register size_t filesize = (size_t)ftell(fileptr);
    rewind(fileptr);  // fseek(fileptr, (slint)0x00, SEEK_SET);
#   endif
    uint8_t *filestr = (uint8_t *)calloc((filesize + (16 - (filesize & 15))), 0x1);
    if (filestr == (uint8_t *)NULL) {
        fputs("ERROR: Failed to allocate memory!\n", stderr);
        exit(EXIT_FAILURE);
    }
    if (fread(filestr, 0x01, filesize, fileptr) != filesize) {
        free(filestr);
        fputs("ERROR: Unable to read file!\n", stderr);
        exit(EXIT_FAILURE);
    }
    fclose(fileptr);
    filestr[filesize] = '\0';
    // Fletcher16 checksum
    register uint16_t sum1 = 0x0, sum2 = 0x0;
    register size_t index, len = (filesize + (16 - (filesize & 15)));
    for (index = 0x0; index < len; ++index) {
        sum1 = (uint16_t)((sum1 + (uint16_t)filestr[index]) % 0xFF);
        sum2 = (uint16_t)((sum2 + sum1) % 0xFF);
    }
    return (uint16_t)((uint16_t)(sum2 << 8) | sum1);
}


/** Open the specified file and return the Fletcher16 checksum (optimized) of the file */
uint16_t filefletcher16fast(const char *__restrict__ filename) {
    FILE *fileptr = fopen(filename, "rb");
    if (fileptr == (FILE *)NULL) {
        fprintf(stderr, "ERROR: Failed to open file!\n%s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
#   ifdef OSPOSIX
    register size_t filesize = getfilesize(filename);
#   else
    if (fseek(fileptr, (slint)0x00, SEEK_END) != 0x00) {
        fputs("ERROR: Unable to read file!\n", stderr);
        exit(EXIT_FAILURE);
    }
    register size_t filesize = (size_t)ftell(fileptr);
    rewind(fileptr);  // fseek(fileptr, (slint)0x00, SEEK_SET);
#   endif
    uint8_t *filestr = (uint8_t *)calloc((filesize + (16 - (filesize & 15))), 0x1);
    if (filestr == (uint8_t *)NULL) {
        fputs("ERROR: Failed to allocate memory!\n", stderr);
        exit(EXIT_FAILURE);
    }
    if (fread(filestr, 0x01, filesize, fileptr) != filesize) {
        free(filestr);
        fputs("ERROR: Unable to read file!\n", stderr);
        exit(EXIT_FAILURE);
    }
    fclose(fileptr);
    filestr[filesize] = '\0';
    // Fletcher16 checksum
#   ifdef __clang__
#      pragma GCC diagnostic ignored "-Wcast-align"
#   endif
    uint8_t *filestr8 = (uint8_t *)filestr;  // Fixes "munmap_chunk(): invalid pointer" abortion
    register uint16_t sum1 = 0xFF, sum2 = 0xFF;
    register size_t len, i = (filesize + (16 - (filesize & 15)));
    while (i) {
        len = ((i >= 20) ? 20 : i);
        i -= len;
        do {
            sum1 = (uint16_t)(sum1 + *filestr8++);
            sum2 = (uint16_t)(sum2 + sum1);
        } while (--len);
        sum1 = (uint16_t)((uint16_t)(sum1 & 0xFF) + (uint16_t)(sum1 >> (uint16_t)8));
        sum2 = (uint16_t)((uint16_t)(sum2 & 0xFF) + (uint16_t)(sum2 >> (uint16_t)8));
    }
    free(filestr);
#   ifdef __clang__
#      pragma GCC diagnostic warning "-Wcast-align"
#   endif
    // Reduce sums to 8 bits
    sum1 = (uint16_t)((uint16_t)(sum1 & 0xFF) + (uint16_t)(sum1 >> (uint16_t)8));
    sum2 = (uint16_t)((uint16_t)(sum2 & 0xFF) + (uint16_t)(sum2 >> (uint16_t)8));
    return (uint16_t)((uint16_t)(sum2 << (uint16_t)8) | sum1);
}


/** Open the specified file and return the Fletcher32 checksum of the file */
uint32_t filefletcher32(const char *__restrict__ filename) {
    FILE *fileptr = fopen(filename, "rb");
    if (fileptr == (FILE *)NULL) {
        fprintf(stderr, "ERROR: Failed to open file!\n%s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
#   ifdef OSPOSIX
    register size_t filesize = getfilesize(filename);
#   else
    if (fseek(fileptr, (slint)0x00, SEEK_END) != 0x00) {
        fputs("ERROR: Unable to read file!\n", stderr);
        exit(EXIT_FAILURE);
    }
    register size_t filesize = (size_t)ftell(fileptr);
    rewind(fileptr);  // fseek(fileptr, (slint)0x00, SEEK_SET);
#   endif
    uint8_t *filestr = (uint8_t *)calloc((filesize + (16 - (filesize & 15))), 0x1);
    if (filestr == (uint8_t *)NULL) {
        fputs("ERROR: Failed to allocate memory!\n", stderr);
        exit(EXIT_FAILURE);
    }
    if (fread(filestr, 0x01, filesize, fileptr) != filesize) {
        free(filestr);
        fputs("ERROR: Unable to read file!\n", stderr);
        exit(EXIT_FAILURE);
    }
    fclose(fileptr);
    filestr[filesize] = '\0';
    // Fletcher32 checksum
#   ifdef __clang__
#      pragma GCC diagnostic ignored "-Wcast-align"
#   endif
    uint16_t *filestr16 = (uint16_t *)filestr;
    register uint32_t sum1 = 0x0, sum2 = 0x0;
    register size_t index, len = (filesize + (16 - (filesize & 15)));
    for (index = 0x0; index < len; ++index) {
        sum1 = (uint32_t)((sum1 + (uint32_t)filestr16[index]) % 0xFFFF);
        sum2 = (uint32_t)((sum2 + sum1) % 0xFFFF);
    }
#   ifdef __clang__
#      pragma GCC diagnostic warning "-Wcast-align"
#   endif
    return (uint32_t)((uint32_t)(sum2 << 16) | sum1);
}


/** Open the specified file and return the Fletcher32 checksum (optimized) of the file */
uint32_t filefletcher32fast(const char *__restrict__ filename) {
    FILE *fileptr = fopen(filename, "rb");
    if (fileptr == (FILE *)NULL) {
        fprintf(stderr, "ERROR: Failed to open file!\n%s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
#   ifdef OSPOSIX
    register size_t filesize = getfilesize(filename);
#   else
    if (fseek(fileptr, (slint)0x00, SEEK_END) != 0x00) {
        fputs("ERROR: Unable to read file!\n", stderr);
        exit(EXIT_FAILURE);
    }
    register size_t filesize = (size_t)ftell(fileptr);
    rewind(fileptr);  // fseek(fileptr, (slint)0x00, SEEK_SET);
#   endif
    uint8_t *filestr = (uint8_t *)calloc((filesize + (16 - (filesize & 15))), 0x1);
    if (filestr == (uint8_t *)NULL) {
        fputs("ERROR: Failed to allocate memory!\n", stderr);
        exit(EXIT_FAILURE);
    }
    if (fread(filestr, 0x01, filesize, fileptr) != filesize) {
        free(filestr);
        fputs("ERROR: Unable to read file!\n", stderr);
        exit(EXIT_FAILURE);
    }
    fclose(fileptr);
    filestr[filesize] = '\0';
    // Fletcher32 checksum
#   ifdef __clang__
#      pragma GCC diagnostic ignored "-Wcast-align"
#   endif
    uint16_t *filestr16 = (uint16_t *)filestr;
    register uint32_t sum1 = 0xFFFF, sum2 = 0xFFFF;
    register size_t len, i = (filesize + (16 - (filesize & 15)));
    while (i) {
        len = ((i >= 359) ? 359 : i);
        i -= len;
        do { sum2 += sum1 += *filestr16++; } while (--len);
        sum1 = ((sum1 & 0xFFFF) + (sum1 >> (uint32_t)0x10));
        sum2 = ((sum2 & 0xFFFF) + (sum2 >> (uint32_t)0x10));
    }
    free(filestr);
#   ifdef __clang__
#      pragma GCC diagnostic warning "-Wcast-align"
#   endif
    // Reduce sums to 16 bits
    sum1 = ((uint32_t)(sum1 & 0xFFFF) + (uint32_t)(sum1 >> (uint32_t)0x10));
    sum2 = ((uint32_t)(sum2 & 0xFFFF) + (uint32_t)(sum2 >> (uint32_t)0x10));
    return (uint32_t)((uint32_t)(sum2 << (uint32_t)0x10) | sum1);
}


/** Open the specified file and return the Collier32 checksum of the file */
uint32_t filecollier32(const char *__restrict__ filename) {
    FILE *fileptr = fopen(filename, "rb");
    if (fileptr == (FILE *)NULL) {
        fprintf(stderr, "ERROR: Failed to open file!\n%s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
#   ifdef OSPOSIX
    register size_t filesize = getfilesize(filename);
#   else
    if (fseek(fileptr, (slint)0x00, SEEK_END) != 0x00) {
        fputs("ERROR: Unable to read file!\n", stderr);
        exit(EXIT_FAILURE);
    }
    register size_t filesize = (size_t)ftell(fileptr);
    rewind(fileptr);  // fseek(fileptr, (slint)0x00, SEEK_SET);
#   endif
    uint8_t *filestr = (uint8_t *)calloc((filesize + (16 - (filesize & 15))), 0x1);
    if (filestr == (uint8_t *)NULL) {
        fputs("ERROR: Failed to allocate memory!\n", stderr);
        exit(EXIT_FAILURE);
    }
    if (fread(filestr, 0x01, filesize, fileptr) != filesize) {
        free(filestr);
        fputs("ERROR: Unable to read file!\n", stderr);
        exit(EXIT_FAILURE);
    }
    fclose(fileptr);
    filestr[filesize] = '\0';
    // Collier32 checksum
#   ifdef __clang__
#      pragma GCC diagnostic ignored "-Wcast-align"
#   endif
    uint16_t *filestr16 = (uint16_t *)filestr;
    register uint32_t sum1 = 0x0, sum2 = 0x0;
    register size_t index;
    for (index = (filesize + (16 - (filesize & 15))); --index;) {
        sum2 = (uint32_t)((sum2 + sum1) & 0xFFFF);
        sum1 = (uint32_t)((sum1 + (uint32_t)filestr16[index]) & 0xFFFF);
    }
#   ifdef __clang__
#      pragma GCC diagnostic warning "-Wcast-align"
#   endif
    return (uint32_t)((uint32_t)(sum2 << 0xF) ^ sum1);
}


/* STRING CONVERSIONS */


/** Convert a string (in-place) to all lowercase letters */
void lowercasestr(char *__restrict__ str) {
    if (str != (char *)NULL) {
        register size_t i;
        for (i = strlenx(str); --i;) {
            str[i] = ((str[i] > 0x5A || str[i] < 0x41) ? str[i] : (char)((uint8_t)str[i] + 0x20u));
        }
        str[0] = ((str[0] > 0x5A || str[0] < 0x41) ? str[0] : (char)((uint8_t)str[0] + 0x20u));
    }
}


/** Convert a string (in-place) to all uppercase letters */
void uppercasestr(char *__restrict__ str) {
    if (str != (char *)NULL) {
        register size_t i;
        for (i = strlenx(str); --i;) {
            str[i] = ((str[i] > 0x7A || str[i] < 0x61) ? str[i] : (char)((uint8_t)str[i] - 0x20u));
        }
        str[0] = ((str[0] > 0x7A || str[0] < 0x61) ? str[0] : (char)((uint8_t)str[0] - 0x20u));
    }
}


/** Convert a string (in-place) to all lowercase letters, given the string length */
void lowercasestrx(char *__restrict__ str, const size_t len) {
    if (len != 0x0) {
        register size_t i;
        for (i = len; --i;) {
            str[i] = ((str[i] > 0x5A || str[i] < 0x41) ? str[i] : (char)((uint8_t)str[i] + 0x20u));
        }
        str[0] = ((str[0] > 0x5A || str[0] < 0x41) ? str[0] : (char)((uint8_t)str[0] + 0x20u));
    }
}


/** Convert a string (in-place) to all uppercase letters, given the string length */
void uppercasestrx(char *__restrict__ str, const size_t len) {
    if (len != 0x0) {
        register size_t i;
        for (i = len; --i;) {
            str[i] = ((str[i] > 0x7A || str[i] < 0x61) ? str[i] : (char)((uint8_t)str[i] - 0x20u));
        }
        str[0] = ((str[0] > 0x7A || str[0] < 0x61) ? str[0] : (char)((uint8_t)str[0] - 0x20u));
    }
}


/* STRING BOOLEAN TESTS */


/** Test if the string contains the specified character */
int char_in_str(const char *__restrict__ str, const char _char) {
    if ((strchr(str, (int)_char)) != (char *)NULL) return 1;
    return 0;
}


/** Test if the string contains the specified substring */
int str_in_str(const char *__restrict__ str, const char *__restrict__ substr) {
    if ((strstr(str, substr)) != (char *)NULL) return 1;
    return 0;
}


/** Test if the string contains a space */
int space_in_str(const char *__restrict__ str) {
    if ((strchr(str, 0x20)) != (char *)NULL) return 1;
    return 0;
}


/** Check if the string only contains lowercase letters */
int isstrlowercase(const char *__restrict__ str) {
    register size_t i;
#   ifdef __IVDEP__
#   pragma GCC ivdep
    for (i = (strlenx(str) + 0x01); --i;) { if (ISLOWERASCII(str[i - 0x01]) == 0) return 0; }
#   elif defined(__INTEL_COMPILER)
#   pragma ivdep
    for (i = (strlenx(str) + 0x01); --i;) { if (ISLOWERASCII(str[i - 0x01]) == 0) return 0; }
#   else
    for (i = (strlenx(str) + 0x01); --i;) { if (ISLOWERASCII(str[i - 0x01]) == 0) return 0; }
#   endif
    return 1;
}


/** Check if the string only contains uppercase letters */
int isstruppercase(const char *__restrict__ str) {
    register size_t i;
#   ifdef __IVDEP__
#   pragma GCC ivdep
    for (i = (strlenx(str) + 0x01); --i;) { if (ISUPPERASCII(str[i - 0x01]) == 0) return 0; }
#   elif defined(__INTEL_COMPILER)
#   pragma ivdep
    for (i = (strlenx(str) + 0x01); --i;) { if (ISUPPERASCII(str[i - 0x01]) == 0) return 0; }
#   else
    for (i = (strlenx(str) + 0x01); --i;) { if (ISUPPERASCII(str[i - 0x01]) == 0) return 0; }
#   endif
    return 1;
}


/** Check if the string only contains alphanumeric characters */
int isstralnum(const char *__restrict__ str) {
    register size_t i;
    for (i = (strlenx(str) + 0x01); --i;) { if (isalnumx((int)str[i - 0x01]) == 0) return 0; }
    return 1;
}


/** Check if the string only contains alphabetic characters */
int isstralpha(const char *__restrict__ str) {
    register size_t i;
    for (i = (strlenx(str) + 0x01); --i;) { if (isalphax((int)str[i - 0x01]) == 0) return 0; }
    return 1;
}


/** Check if the string only contains numbers */
int isstrnum(const char *__restrict__ str) {
    register size_t i;
    for (i = (strlenx(str) + 0x01); --i;) { if (isdigit_ascii((int)str[i - 0x01]) == 0) return 0; }
    return 1;
}


/** Check if the string only contains printable characters and not whitespace */
int isstrgraphical(const char *__restrict__ str) {
    register size_t i;
    for (i = (strlenx(str) + 0x01); --i;) { if (isgraph_ascii((int)str[i - 0x01]) == 0) return 0; }
    return 1;
}


/** Check if the string only contains printable characters */
int isstrprintable(const char *__restrict__ str) {
    register size_t i;
    for (i = (strlenx(str) + 0x01); --i;) { if (isprintx((int)str[i - 0x01]) == 0) return 0; }
    return 1;
}


/** Check if the string only contains punctuation characters */
int isstrpunctuation(const char *__restrict__ str) {
    register size_t i;
    for (i = (strlenx(str) + 0x01); --i;) { if (ispunct_ascii((int)str[i - 0x01]) == 0) return 0; }
    return 1;
}


/** Check if the string only contains whitespace characters */
int isstrwhitespace(const char *__restrict__ str) {
    register size_t i;
    for (i = (strlenx(str) + 0x01); --i;) { if (isspace_ascii((int)str[i - 0x01]) == 0) return 0; }
    return 1;
}


/** Check if the string only contains hexadecimal characters */
int isstrhex(const char *__restrict__ str) {
    register size_t i;
    for (i = (strlenx(str) + 0x01); --i;) { if (isxdigit_ascii((int)str[i - 0x01]) == 0) return 0; }
    return 1;
}


/** Test if the integer is odd */
int isodd(const int num) {
    return (int)((num & 0x01) != 0x00);
}


/** Test if the integer is even */
int iseven(const int num) {
    return (int)((num & 0x01) == 0x00);
}


/** Test if the long integer is odd */
int islongodd(const long num) {
    return (int)((num & (long)0x01) != (long)0x00);
}


/** Test if the long integer is even */
int islongeven(const long num) {
    return (int)((num & (long)0x01) == (long)0x00);
}


/** Test if the uint64_t is odd */
int isuint64odd(const uint64_t num) {
    return (int)((num & (uint64_t)0x01) != 0x00);
}


/** Test if the uint64_t is even */
int isuint64even(const uint64_t num) {
    return (int)((num & (uint64_t)0x01) == 0x00);
}


/* FIND AND REPLACE/REMOVE */


/** Find and substitute all occurrences of "find" with "sub_with", inplace */
void inplace_strsub(char *orig_string, const char *__restrict__ find, const char *__restrict__ sub_with) {
    register const size_t find_size = strlenx(find);
    if (!(find_size) || (strstr(orig_string, find) == (char *)NULL) || (strlenx(sub_with) != find_size)) return;
    register char *pos;
    for (pos = strstr(orig_string, find); (pos = strstr(orig_string, find));) {
        memmove((orig_string + (pos - orig_string)), sub_with, find_size);
    }
}


/** Find and replace all occurrences of "find" with "replace_with" */
char *strreplace(char *orig_string, const char *find, const char *replace_with) {
    register size_t len_size = strlenx(orig_string);
    register const ulint find_size = strlenx(find);
    if (!(len_size) || !(find_size) || (len_size > 0x400)) return (char *)NULL;
    else if ((strstr(orig_string, find) == (char *)NULL)) return orig_string;  // Is find in orig_string
    static char buffer[0x400];  // 0x400 == 1024
    strncpy(buffer, orig_string, len_size);
    buffer[len_size] = '\0';
    register char *after_find, *p;
    char after_find_buffer[0x400];
    register const size_t rpl_size = strlenx(replace_with);
    for (p = strstr(buffer, find); (p = strstr(buffer, find));) {
        buffer[(size_t)(p - buffer)] = '\0';
        after_find = (char *)(p + find_size);
        len_size = strlenx(after_find);
        strncpy(after_find_buffer, after_find, len_size);
        strncat(buffer, replace_with, rpl_size);
        strncat(buffer, after_find_buffer, len_size);
    }
    return buffer;
}


/** Replace first occurrence of "find" with "replace_with" */
char *strreplace_once(char *orig_string, const char *find, const char *replace_with) {
    register char *p;
    if (!(p = strstr(orig_string, find))) return orig_string;
    register const size_t replace_start_pos = (size_t)(p - orig_string);  // found_ptr - str_start_ptr
    register const char *after_find = p + strlenx(find);
    static char buffer[0x400] = { 0 };  // 0x400 == 1024
    strncpy(buffer, orig_string, replace_start_pos);
    buffer[(int)replace_start_pos] = '\0';
    strncat(buffer, replace_with, strlenx(replace_with));
    strncat(buffer, after_find, strlenx(after_find));
    return buffer;
}


/** Find and remove grave-quotes (`) */
char *rmgravequote(char *orig_string) {
    if ((strlenx(orig_string) == 0)) return (char *)NULL;
    else if ((strchr(orig_string, '`') == (char *)NULL)) return orig_string;  // Is ` in orig_string
    register char *after_find, *p;
    static char buffer[0x400];  // 0x400 == 1024
    memcpy(buffer, orig_string, strlenx(orig_string));
    buffer[strlenx(orig_string)] = '\0';
    for (p = strchr(buffer, '`'); (p = strchr(buffer, '`'));) {
        buffer[(size_t)(p - buffer)] = '\0';
        after_find = (char *)(++p);
        strncat(buffer, after_find, strlenx(after_find));
    }
    return buffer;
}


/** Remove quotes from a string inplace */
void strrmquotes(char *line) {
    register size_t i, j = 0x00;
    register const size_t linelength = strlenx(line);
    for (i = 0x00; i < linelength; ++i) {
        if ((line[i] == '\\') || (line[i] == '"') || (line[i] == '\'') || (line[i] == '`')) continue;
        line[j++] = line[i];
    }
    line[j] = '\0';
}


/* SYSTEM INFO */


#if (defined(__GNUC__) || defined(__CC_ARM) || defined(__INTEL_COMPILER) || defined(_MSC_VER) || defined(__MINGW32__) || defined(__MINGW64__) || defined(__TINYC__))


/** Get the system's architecture type */
const char *getarch(void) {
#if (defined(__arm__) || defined(__arm) || defined(__thumb__) || defined(__TARGET_ARCH_ARM) || defined(__TARGET_ARCH_THUMB) || defined(_ARM) || defined(_M_ARM) || defined(_M_ARMT))
    return "ARM";
#elif defined(__aarch64__)
    return "ARM64";
#elif (defined(__x86_64__) || defined(__x86_64) || defined(_WIN64) || defined(__MINGW64__) || defined(_M_X64))
    return "x86-64";
#elif (defined(__amd64__) || defined(__amd64) || defined(_M_AMD64))
    return "AMD64";
#elif (defined(i386) || defined(__i386) || defined(__i386__) || defined(__i486__) || defined(__i586__) || defined(__i686__) || defined(__IA32__) || defined(_M_IX86) || defined(__X86__) || defined(_X86_) || defined(__386))
    return "x86";
#elif (defined(__ia64__) || defined(_IA64) || defined(__IA64__) || defined(__ia64) || defined(_M_IA64) || defined(__itanium__))
    return "Itanium";
#elif (defined(__ppc64__) || defined(ppc64le) || defined(__powerpc64__) || defined(__PPC64__) || defined(_ARCH_PPC64))
    return "PowerPC64";
#elif (defined(__ppc__) || defined(__powerpc__) || defined(__PPC__) || defined(_ARCH_PPC) || defined(__POWERPC__) || defined(__powerpc))
    return "PowerPC";
#elif (defined(__alpha__) || defined(__alpha) || defined(_M_ALPHA))
    return "Alpha";
#elif (defined(__bfin) || defined(__BFIN__))
    return "Blackfin";
#elif defined(__convex__)
    return "Convex";
#elif (defined(__mips__) || defined(__mips) || defined(mips) || defined(__MIPS__))
    return "MIPS";
#elif (defined(__sparc__) || defined(__sparc))
    return "SPARC";
#else
    return "Unknown";
#endif
}


/** Get the system's operating-system name */
const char *getos(void) {
#if defined(__ANDROID__)
    return "Android";
#elif (defined(__CYGWIN__) || defined(__CYGWIN32__))
    return "Cygwin";
#elif defined(__gnu_hurd__)
    return "GNU/Hurd";
#elif (defined(__FreeBSD_kernel__ ) && defined(__GLIBC__ ))
    return "GNU/kFreeBSD";
#elif defined(__gnu_linux__)
    return "GNU/Linux";
#elif (defined(__linux__) || defined(linux) || defined(__linux) || defined(BOOST_OS_LINUX))
    return "Linux";
#elif (defined(sun) || defined(__sun)) && (defined(__SVR4) || defined(__svr4__))
    return "Solaris";
#elif (defined(sun) || defined(__sun)) && !(defined(__SVR4) || defined(__svr4__))
    return "SunOS";
#elif defined(sun) || defined(__sun)
    return "Sun System";
#elif defined(__DragonFly__)
    return "DragonFlyBSD";
#elif (defined(__FreeBSD__) || defined(__FreeBSD_kernel__))
    return "FreeBSD";
#elif defined(__NetBSD__)
    return "NetBSD";
#elif defined(__OpenBSD__)
    return "OpenBSD";
#elif (defined(BSD) || defined(_SYSTYPE_BSD) || defined(__bsdi__))
    return "BSD";
#elif (defined(macintosh) || defined(Macintosh) || defined(BOOST_OS_MACOS))
    return "MacOS";
#elif (defined(__APPLE__) && defined(__MACH__))
    return "OSX";
#elif (defined(__APPLE__) && !defined(__MACH__))
    return "Apple";
#elif (defined(__MACH__) && !defined(__APPLE__))
    return "NextStep";
#elif (defined(__MINGW32__) || defined(__MINGW64__) || defined(__WINNT__) || defined(__NT__) || defined(_WIN64) || defined(_WIN32) || defined(WIN32) || defined(__WIN32__) || defined(BOOST_OS_WINDOWS) || defined(_UWIN) || defined(__TOS_WIN__) || defined(__WINDOWS__) || defined(_WIN32_WCE) || defined(_MSC_VER))
    return "Windows";
#elif defined(_AIX)
    return "AIX";
#elif (defined(__amigaos__) || defined(AMIGA))
    return "AmigaOS";
#elif defined(aegis)
    return "Apollo AEGIS";
#elif defined(__BEOS__)
    return "BeOS";
#elif (defined(__bg__) || defined(__THW_BLUEGENE__))
    return "Blue Gene";
#elif defined(__ECOS)
    return "eCos";
#elif (defined(_hpux) || defined(hpux) || defined(__hpux))
    return "HP-UX";
#elif (defined(sgi) || defined(__sgi))
    return "IRIX";
#elif defined(__Lynx__)
    return "LynxOS";
#elif defined(__minix)
    return "Minix";
#elif defined(__MORPHOS__)
    return "MorphOS";
#elif defined(EPLAN9)
    return "Plan 9";
#elif (defined(__QNX__) || defined(__QNXNTO__))
    return "QNX";
#elif (defined(ultrix) || defined(__ultrix) || defined(__ultrix__))
    return "Ultrix";
#elif (defined(_CRAY) || defined(__crayx1) || defined(_UNICOS))
    return "UNICOS";
#elif defined(_UNIXWARE7)
    return "UnixWare";
#elif (defined(__VXWORKS__) || defined(__vxworks))
    return "VxWorks";
#elif (defined(__unix__) || defined(unix) || defined(__unix))
    return "Unix";
#else
    return "Unknown";
#endif
}


#endif


/** Return the system's endianness */
const char *endianness(void) {
#ifdef __BYTE_ORDER__
#   if (__ORDER_LITTLE_ENDIAN__ == __BYTE_ORDER__)
    return "ENDIAN_LITTLE";
#   elif (__ORDER_BIG_ENDIAN__ == __BYTE_ORDER__)
    return "ENDIAN_BIG";
#   elif (__ORDER_PDP_ENDIAN__ == __BYTE_ORDER__)
    return "ENDIAN_PDP";
#endif
#   else
    union {
        uint32_t read32_value;
        uint8_t data[sizeof(uint32_t)];
    } number;
    number.data[0] = 0x00;
    number.data[1] = 0x01;
    number.data[2] = 0x02;
    number.data[3] = 0x03;
    switch (number.read32_value) {
        case UINT32_C(0x00010203): return "ENDIAN_BIG";
        case UINT32_C(0x03020100): return "ENDIAN_LITTLE";
        case UINT32_C(0x02030001): return "ENDIAN_BIG_WORD";
        case UINT32_C(0x01000302): return "ENDIAN_LITTLE_WORD";
        default:                   return "ENDIAN_UNKNOWN";
    }
#   endif
}


#ifdef __ANDROID_API__
#include <android/api-level.h>
/** Return the current Android API */
int androidapi(void) {
    return (int)__ANDROID_API__;
}
#endif


#ifdef BSD
/** Return the current BSD version */
int bsdversion(void) {
    return ((int)(BSD));
}
#endif


/** Test if this system is Android */
int isandroid(void) {
#ifdef __ANDROID__
    return 1;
#else
    return 0;
#endif
}


/** Test if this system is AIX */
int isaix(void) {
#ifdef _AIX
    return 1;
#else
    return 0;
#endif
}


/** Test if this system uses 64-bit pointers */
int isptr64bit(void) {
#if (defined(__LP64__) && (__LP64__ == 1))
    return 1;
#elif (defined(_LP64) && (_LP64 == 1))
    return 1;
#elif (defined(TYPESIZE_PTR) && (TYPESIZE_PTR == 64))
    return 1;
#else
    return 0;
#endif
}


#ifdef OSPOSIX
/** Return the system's hostname */
char *getsyshostname(void) {
    static char hostname[32] = { 0 };
    if (gethostname(hostname, sizeof(hostname)) != 0) {
        hostname[0] = '?';
        hostname[1] = '\0';
    }
    return hostname;
}
#endif


/* LIBRARY INFO */


/** Get the name of the compiler that compiled this library */
const char *getcompilername(void) {
#ifdef __clang__
    return "Clang";
#elif defined(__CC_ARM)
    return "ARM Compiler";
#elif defined(__INTEL_COMPILER)
    return "Intel Compiler";
#elif defined(_MSC_VER)
    return "Microsoft Visual C++";
#elif defined(__MINGW32__)
    return "MinGW32";
#elif defined(__MINGW64__)
    return "MinGW64";
#elif defined(__TINYC__)
    return "TinyC";
#elif defined(__GNUC__)
    return "GCC";
#else
    return "Unknown";
#endif
}


#if (defined(__GNUC__) || defined(__clang__) || defined(__CC_ARM) || defined(__INTEL_COMPILER) || defined(_MSC_VER) || defined(__MINGW32__) || defined(__MINGW64__) || defined(__TINYC__))
/** Get the version of the compiler that compiled this library */
const char *getcompilerversion(void) {
#   ifdef __CC_ARM
    return __ARMCC_VERSION;
#   elif defined(__INTEL_COMPILER)
    return __INTEL_COMPILER;
#   elif defined(_MSC_VER)
    return _MSC_FULL_VER;
#   elif defined(__MINGW32__)
    return __VERSION__;  // __MINGW32_MAJOR_VERSION
#   elif defined(__MINGW64__)
    return __VERSION__;  // __MINGW64_MAJOR_VERSION
#   elif defined(__TINYC__)
    return "Unknown";
#   else
    return __VERSION__;
#   endif
}
#endif


/** Return the value of the current C Standard */
long CSTD(void) {
    return ((long)(__STDC_VERSION__));
}


#ifdef _POSIX_VERSION
/** Return the value of the current POSIX Standard */
long POSIXSTD(void) {
    return ((long)(_POSIX_VERSION));
}
#endif


#ifdef _XOPEN_VERSION
/** Return the value of the current POSIX Standard */
int SUSVER(void) {
    return ((int)(_XOPEN_VERSION));
}
#endif


#ifdef __LSB_VERSION__
/** Return the value of the current POSIX Standard */
int LSBVER(void) {
    return ((int)(__LSB_VERSION__));
}
#endif


/** Test if this library is an ELF file */
int islibelf(void) {
#ifdef __ELF__
    return (int)1;
#else
    return (int)0;
#endif
}


/* MISCELLANEOUS */


/** Print a newline character */
void printline(void) {
    fputs("\n\n", stdout);
    fflush(stdout);
    return;
}


/** Swap the values of `x` and `y` (xorswap(&x, &y)) */
void xorswap(int *__restrict__ x, int *__restrict__ y) {
    *x^=*y;
    *y^=*x;
    *x^=*y;
}


/** Swap the values of `x` and `y` (xorswap_sll(&x, &y)) */
void xorswap_sll(sllint *__restrict__ x, sllint *__restrict__ y) {
    *x^=*y;
    *y^=*x;
    *x^=*y;
}
