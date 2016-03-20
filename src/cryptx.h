// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file cryptx.h
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Cryptography Functions (header)
@version 2016.03.20

@section DESCRIPTION
This library provides many encryption, decryption, cipher, hash, and checksum functions

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


#ifndef FILE_CRYPTX_SEEN
#define FILE_CRYPTX_SEEN


#include "MACROS.h"

#include <time.h>
#ifdef OSPOSIX
#   include <sys/time.h>  // http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/sys_time.h.html
#endif

#define TREYFER_NUMROUNDS   ((uint8_t)(32))


#define byteswap8(x)   endianswap8((x))
#define byteswap16(x)   endianswap16((x))
#define byteswap32(x)   endianswap32((x))
#define byteswap64(x)   endianswap64((x))


/* DATATYPES */
typedef struct { uint8_t R, i, j, k; } quaternion_crypt_byte;
/* CONSTANTS */
extern const uint16_t crc16_table[256];
extern const uint32_t crc32_table[256];
extern const uint8_t Sbox[256];
extern const u32 ANUBIS_T0[256];
extern const u32 ANUBIS_T1[256];
extern const u32 ANUBIS_T2[256];
extern const u32 ANUBIS_T3[256];
extern const u32 ANUBIS_T4[256];
extern const u32 ANUBIS_T5[256];
extern const u32 ANUBIS_RC[];
/* FUNCTIONS */
int randomint(void);
ulint randomlong(void);
char *randstr(const size_t length);
char *randalphastr(const size_t length);
char *randalphanumstr(const size_t length);
char *randstrx(const uint64_t length);
char *rand16384str(void);
#ifdef __GNUC__
uint8_t endianswap8(uint8_t x) __attribute__((const));
uint16_t endianswap16(uint16_t x) __attribute__((const));
uint32_t endianswap32(uint32_t x) __attribute__((const));
uint64_t endianswap64(uint64_t x) __attribute__((const));
void shuffle_int(signed int *__restrict__ array, const size_t num_items) __attribute__((nonnull));
void shuffle_uint32(uint32_t *__restrict__ array, const uint32_t num_items) __attribute__((nonnull));
#else
uint8_t endianswap8(uint8_t x);
uint16_t endianswap16(uint16_t x);
uint32_t endianswap32(uint32_t x);
uint64_t endianswap64(uint64_t x);
void shuffle_int(signed int *__restrict__ array, const size_t num_items);
void shuffle_uint32(uint32_t *__restrict__ array, const uint32_t num_items);
#endif
void byte_rotl(uint8_t byte, const uint8_t num);
void byte_rotr(uint8_t byte, const uint8_t num);
#ifdef __GNUC__
void array_rotl(uint8_t *__restrict__ array, const size_t len, const uint32_t num_shifts) __attribute__((nonnull));
void array_rotl64(uint8_t *__restrict__ array, const uint64_t len, const uint64_t num_shifts) __attribute__((nonnull));
void array_rotr(uint8_t *__restrict__ array, const size_t len, const uint32_t num_shifts) __attribute__((nonnull));
void array_rotr64(uint8_t *__restrict__ array, const uint64_t len, const uint64_t num_shifts) __attribute__((nonnull));
void chararray_rotl(char *__restrict__ array, const size_t len, const uint32_t num_shifts) __attribute__((nonnull));
void chararray_rotl64(char *__restrict__ array, const uint64_t len, const uint64_t num_shifts) __attribute__((nonnull));
void chararray_rotr(char *__restrict__ array, const size_t len, const uint32_t num_shifts) __attribute__((nonnull));
void chararray_rotr64(char *__restrict__ array, const uint64_t len, const uint64_t num_shifts) __attribute__((nonnull));
void caesar_cipher(char *__restrict__ data, const ulint shift) __attribute__((nonnull));
void decrypt_caesar_cipher(char *__restrict__ data, const ulint shift) __attribute__((nonnull));
void xor_cipher(char *__restrict__ data, const char *__restrict__ password) __attribute__((nonnull));
void nxor_cipher(char *__restrict__ data, const char *__restrict__ password) __attribute__((nonnull));
#else
void array_rotl(uint8_t *__restrict__ array, const size_t len, const uint32_t num_shifts);
void array_rotl64(uint8_t *__restrict__ array, const uint64_t len, const uint64_t num_shifts);
void array_rotr(uint8_t *__restrict__ array, const size_t len, const uint32_t num_shifts);
void array_rotr64(uint8_t *__restrict__ array, const uint64_t len, const uint64_t num_shifts);
void chararray_rotl(char *__restrict__ array, const size_t len, const uint32_t num_shifts);
void chararray_rotl64(char *__restrict__ array, const uint64_t len, const uint64_t num_shifts);
void chararray_rotr(char *__restrict__ array, const size_t len, const uint32_t num_shifts);
void chararray_rotr64(char *__restrict__ array, const uint64_t len, const uint64_t num_shifts);
void caesar_cipher(char *__restrict__ data, const ulint shift);
void decrypt_caesar_cipher(char *__restrict__ data, const ulint shift);
void xor_cipher(char *__restrict__ data, const char *__restrict__ password);
void nxor_cipher(char *__restrict__ data, const char *__restrict__ password);
#endif
void tea_cipher(uint32_t *__restrict__ v, const uint32_t *__restrict__ k);
void decrypt_tea_cipher(uint32_t *__restrict__ v, const uint32_t *__restrict__ k);
void xtea_cipher(const uint32_t num_rounds, uint32_t v[2], const uint32_t key[4]);
void decrypt_xtea_cipher(const uint32_t num_rounds, uint32_t v[2], const uint32_t key[4]);
void xxtea_cipher(uint32_t *__restrict__ v, const int32_t num_items, const uint32_t key[4]);
void treyfer_cipher(uint8_t text[8], const uint8_t key[8]);
void decrypt_treyfer_cipher(uint8_t text[8], const uint8_t key[8]);
#ifdef __GNUC__
void quaternion_encryption32(uint8_t *__restrict__ data, const uint32_t datasize, const uint8_t *__restrict__ key) __attribute__((flatten, nonnull));
void quaternion_decryption32(uint8_t *__restrict__ data, const uint32_t datasize, const uint8_t *__restrict__ key) __attribute__((flatten, nonnull));
void quaternion_encryption64(uint8_t *__restrict__ data, const uint32_t datasize, const uint8_t *__restrict__ key) __attribute__((flatten, nonnull));
void quaternion_decryption64(uint8_t *__restrict__ data, const uint32_t datasize, const uint8_t *__restrict__ key) __attribute__((flatten, nonnull));
uint8_t bitparity(const uint32_t data) __attribute__((const, flatten));
uint8_t bitparity64(const uint64_t data) __attribute__((const, flatten));
#else
void quaternion_encryption32(uint8_t *__restrict__ data, const uint32_t datasize, const uint8_t *__restrict__ key);
void quaternion_decryption32(uint8_t *__restrict__ data, const uint32_t datasize, const uint8_t *__restrict__ key);
void quaternion_encryption64(uint8_t *__restrict__ data, const uint32_t datasize, const uint8_t *__restrict__ key);
void quaternion_decryption64(uint8_t *__restrict__ data, const uint32_t datasize, const uint8_t *__restrict__ key);
uint8_t bitparity(const uint32_t data);
uint8_t bitparity64(const uint64_t data);
#endif
#ifdef UINT128_SUPPORTED
uint8_t bitparity128(const uint128_t data);
#endif
uint8_t crc8(const uint8_t *__restrict__ data, size_t len);
uint8_t crc8x(const uint8_t *__restrict__ data);
uint8_t crc8portable(const uint8_t *__restrict__ data, const uint32_t len);
uint16_t crc16(const uint8_t *__restrict__ data, size_t len);
#ifdef __GNUC__
uint16_t crc16x(const uint8_t *__restrict__ data) __attribute__((const, flatten));
uint16_t crc16mem(const uint16_t *ptr_crc, const uint8_t *data, const uint32_t len) __attribute__((const, flatten));
uint16_t crc16memx(const uint8_t *data) __attribute__((const, flatten));
#else
uint16_t crc16x(const uint8_t *__restrict__ data);
uint16_t crc16mem(const uint16_t *ptr_crc, const uint8_t *data, const uint32_t len);
uint16_t crc16memx(const uint8_t *data);
#endif
uint32_t crc32(uint32_t crc, const uint8_t *__restrict__ data, const size_t len);
uint32_t crc32x(uint32_t crc, const uint8_t *__restrict__ data);
#ifdef INTEL64
uint32_t fastcrc32(char *str, const uint32_t len);
#endif
#ifdef __GNUC__
uint8_t adler8(const uint8_t *__restrict__ data, register size_t len) __attribute__((const, flatten, nonnull));
uint16_t adler16(const uint8_t *__restrict__ data, register size_t len) __attribute__((const, flatten, nonnull));
uint32_t adler32(const uint8_t *__restrict__ data, register size_t len) __attribute__((const, flatten, nonnull));
uint64_t adler64(const uint8_t *__restrict__ data, register size_t len) __attribute__((const, flatten, nonnull));
uint64_t antiadler64(const uint8_t *__restrict__ data, register size_t len) __attribute__((const, flatten, nonnull));
uint64_t antiadler64rev2(const uint8_t *__restrict__ data, register size_t len) __attribute__((const, flatten, nonnull));
#ifdef UINT128_SUPPORTED
uint128_t adler128(const uint8_t *__restrict__ data, register size_t len) __attribute__((const, flatten, nonnull));
#endif
uint8_t fletcher8(const uint8_t *__restrict__ data, const size_t count) __attribute__((const, flatten, nonnull));
uint16_t fletcher16(const uint8_t *__restrict__ data, const size_t count) __attribute__((const, flatten, nonnull));
uint16_t fletcher16fast(const uint8_t *__restrict__ data, const size_t words) __attribute__((const, flatten, nonnull));
uint32_t fletcher32(const uint16_t *__restrict__ data, const size_t count) __attribute__((const, flatten, nonnull));
uint32_t fletcher32fast(const uint16_t *__restrict__ data, const size_t words) __attribute__((const, flatten, nonnull));
uint64_t fletcher64(const uint32_t *__restrict__ data, const size_t count) __attribute__((const, flatten, nonnull));
uint64_t fletcher64char(const uint8_t *__restrict__ data, const size_t count) __attribute__((const, flatten, nonnull));
uint32_t collier32(const uint16_t *__restrict__ data, const size_t count) __attribute__((const, flatten, nonnull));
#else
uint8_t adler8(const uint8_t *__restrict__ data, register size_t len);
uint16_t adler16(const uint8_t *__restrict__ data, register size_t len);
uint32_t adler32(const uint8_t *__restrict__ data, register size_t len);
uint64_t adler64(const uint8_t *__restrict__ data, register size_t len);
uint64_t antiadler64(const uint8_t *__restrict__ data, register size_t len);
uint64_t antiadler64rev2(const uint8_t *__restrict__ data, register size_t len);
#ifdef UINT128_SUPPORTED
uint128_t adler128(const uint8_t *__restrict__ data, register size_t len);
#endif
uint8_t fletcher8(const uint8_t *__restrict__ data, const size_t count);
uint16_t fletcher16(const uint8_t *__restrict__ data, const size_t count);
uint16_t fletcher16fast(const uint8_t *__restrict__ data, const size_t words);
uint32_t fletcher32(const uint16_t *__restrict__ data, const size_t count);
uint32_t fletcher32fast(const uint16_t *__restrict__ data, const size_t words);
uint64_t fletcher64(const uint32_t *__restrict__ data, const size_t count);
uint64_t fletcher64char(const uint8_t *__restrict__ data, const size_t count);
uint32_t collier32(const uint16_t *__restrict__ data, const size_t count);
#endif

#endif
