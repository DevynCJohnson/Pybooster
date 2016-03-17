// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file cryptx.c
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Cryptography Functions
@version 2016.03.09

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


#include "cryptx.h"


/* HELPER FUNCTIONS */


#ifdef __GNUC__
static size_t strlenx(const char *__restrict__ str) __attribute__((const, flatten));
static size_t strlenx_uint8(const uint8_t *__restrict__ str) __attribute__((const, flatten));
#else
static size_t strlenx(const char *__restrict__ str);
static size_t strlenx_uint8(const uint8_t *__restrict__ str);
#endif
/** Private Function: Returns the length of a string */
static size_t strlenx(const char *__restrict__ str) {
    register const char *s;
    for (s = str; *s; ++s);
    return (size_t)(s - str);
}


/** Private Function: Returns the length of a string as `uint8_t` (not counting the NULL terminator) */
static size_t strlenx_uint8(const uint8_t *__restrict__ str) {
    register const uint8_t *s;
    for (s = str; *s; ++s);
    return (size_t)(s - str);
}


/* CONSTANTS */


/** Table of constants needed by some CRC16 functions */
const uint16_t crc16_table[256] = {
    0x0000,  0x1021,  0x2042,  0x3063,  0x4084,  0x50a5,  0x60c6,  0x70e7,
    0x8108,  0x9129,  0xa14a,  0xb16b,  0xc18c,  0xd1ad,  0xe1ce,  0xf1ef,
    0x1231,  0x0210,  0x3273,  0x2252,  0x52b5,  0x4294,  0x72f7,  0x62d6,
    0x9339,  0x8318,  0xb37b,  0xa35a,  0xd3bd,  0xc39c,  0xf3ff,  0xe3de,
    0x2462,  0x3443,  0x0420,  0x1401,  0x64e6,  0x74c7,  0x44a4,  0x5485,
    0xa56a,  0xb54b,  0x8528,  0x9509,  0xe5ee,  0xf5cf,  0xc5ac,  0xd58d,
    0x3653,  0x2672,  0x1611,  0x0630,  0x76d7,  0x66f6,  0x5695,  0x46b4,
    0xb75b,  0xa77a,  0x9719,  0x8738,  0xf7df,  0xe7fe,  0xd79d,  0xc7bc,
    0x48c4,  0x58e5,  0x6886,  0x78a7,  0x0840,  0x1861,  0x2802,  0x3823,
    0xc9cc,  0xd9ed,  0xe98e,  0xf9af,  0x8948,  0x9969,  0xa90a,  0xb92b,
    0x5af5,  0x4ad4,  0x7ab7,  0x6a96,  0x1a71,  0x0a50,  0x3a33,  0x2a12,
    0xdbfd,  0xcbdc,  0xfbbf,  0xeb9e,  0x9b79,  0x8b58,  0xbb3b,  0xab1a,
    0x6ca6,  0x7c87,  0x4ce4,  0x5cc5,  0x2c22,  0x3c03,  0x0c60,  0x1c41,
    0xedae,  0xfd8f,  0xcdec,  0xddcd,  0xad2a,  0xbd0b,  0x8d68,  0x9d49,
    0x7e97,  0x6eb6,  0x5ed5,  0x4ef4,  0x3e13,  0x2e32,  0x1e51,  0x0e70,
    0xff9f,  0xefbe,  0xdfdd,  0xcffc,  0xbf1b,  0xaf3a,  0x9f59,  0x8f78,
    0x9188,  0x81a9,  0xb1ca,  0xa1eb,  0xd10c,  0xc12d,  0xf14e,  0xe16f,
    0x1080,  0x00a1,  0x30c2,  0x20e3,  0x5004,  0x4025,  0x7046,  0x6067,
    0x83b9,  0x9398,  0xa3fb,  0xb3da,  0xc33d,  0xd31c,  0xe37f,  0xf35e,
    0x02b1,  0x1290,  0x22f3,  0x32d2,  0x4235,  0x5214,  0x6277,  0x7256,
    0xb5ea,  0xa5cb,  0x95a8,  0x8589,  0xf56e,  0xe54f,  0xd52c,  0xc50d,
    0x34e2,  0x24c3,  0x14a0,  0x0481,  0x7466,  0x6447,  0x5424,  0x4405,
    0xa7db,  0xb7fa,  0x8799,  0x97b8,  0xe75f,  0xf77e,  0xc71d,  0xd73c,
    0x26d3,  0x36f2,  0x0691,  0x16b0,  0x6657,  0x7676,  0x4615,  0x5634,
    0xd94c,  0xc96d,  0xf90e,  0xe92f,  0x99c8,  0x89e9,  0xb98a,  0xa9ab,
    0x5844,  0x4865,  0x7806,  0x6827,  0x18c0,  0x08e1,  0x3882,  0x28a3,
    0xcb7d,  0xdb5c,  0xeb3f,  0xfb1e,  0x8bf9,  0x9bd8,  0xabbb,  0xbb9a,
    0x4a75,  0x5a54,  0x6a37,  0x7a16,  0x0af1,  0x1ad0,  0x2ab3,  0x3a92,
    0xfd2e,  0xed0f,  0xdd6c,  0xcd4d,  0xbdaa,  0xad8b,  0x9de8,  0x8dc9,
    0x7c26,  0x6c07,  0x5c64,  0x4c45,  0x3ca2,  0x2c83,  0x1ce0,  0x0cc1,
    0xef1f,  0xff3e,  0xcf5d,  0xdf7c,  0xaf9b,  0xbfba,  0x8fd9,  0x9ff8,
    0x6e17,  0x7e36,  0x4e55,  0x5e74,  0x2e93,  0x3eb2,  0x0ed1,  0x1ef0
};


/** Table of constants needed by some CRC32 functions */
const uint32_t crc32_table[256] = {
    0x00000000U,0x04C11DB7U,0x09823B6EU,0x0D4326D9U,
    0x130476DCU,0x17C56B6BU,0x1A864DB2U,0x1E475005U,
    0x2608EDB8U,0x22C9F00FU,0x2F8AD6D6U,0x2B4BCB61U,
    0x350C9B64U,0x31CD86D3U,0x3C8EA00AU,0x384FBDBDU,
    0x4C11DB70U,0x48D0C6C7U,0x4593E01EU,0x4152FDA9U,
    0x5F15ADACU,0x5BD4B01BU,0x569796C2U,0x52568B75U,
    0x6A1936C8U,0x6ED82B7FU,0x639B0DA6U,0x675A1011U,
    0x791D4014U,0x7DDC5DA3U,0x709F7B7AU,0x745E66CDU,
    0x9823B6E0U,0x9CE2AB57U,0x91A18D8EU,0x95609039U,
    0x8B27C03CU,0x8FE6DD8BU,0x82A5FB52U,0x8664E6E5U,
    0xBE2B5B58U,0xBAEA46EFU,0xB7A96036U,0xB3687D81U,
    0xAD2F2D84U,0xA9EE3033U,0xA4AD16EAU,0xA06C0B5DU,
    0xD4326D90U,0xD0F37027U,0xDDB056FEU,0xD9714B49U,
    0xC7361B4CU,0xC3F706FBU,0xCEB42022U,0xCA753D95U,
    0xF23A8028U,0xF6FB9D9FU,0xFBB8BB46U,0xFF79A6F1U,
    0xE13EF6F4U,0xE5FFEB43U,0xE8BCCD9AU,0xEC7DD02DU,
    0x34867077U,0x30476DC0U,0x3D044B19U,0x39C556AEU,
    0x278206ABU,0x23431B1CU,0x2E003DC5U,0x2AC12072U,
    0x128E9DCFU,0x164F8078U,0x1B0CA6A1U,0x1FCDBB16U,
    0x018AEB13U,0x054BF6A4U,0x0808D07DU,0x0CC9CDCAU,
    0x7897AB07U,0x7C56B6B0U,0x71159069U,0x75D48DDEU,
    0x6B93DDDBU,0x6F52C06CU,0x6211E6B5U,0x66D0FB02U,
    0x5E9F46BFU,0x5A5E5B08U,0x571D7DD1U,0x53DC6066U,
    0x4D9B3063U,0x495A2DD4U,0x44190B0DU,0x40D816BAU,
    0xACA5C697U,0xA864DB20U,0xA527FDF9U,0xA1E6E04EU,
    0xBFA1B04BU,0xBB60ADFCU,0xB6238B25U,0xB2E29692U,
    0x8AAD2B2FU,0x8E6C3698U,0x832F1041U,0x87EE0DF6U,
    0x99A95DF3U,0x9D684044U,0x902B669DU,0x94EA7B2AU,
    0xE0B41DE7U,0xE4750050U,0xE9362689U,0xEDF73B3EU,
    0xF3B06B3BU,0xF771768CU,0xFA325055U,0xFEF34DE2U,
    0xC6BCF05FU,0xC27DEDE8U,0xCF3ECB31U,0xCBFFD686U,
    0xD5B88683U,0xD1799B34U,0xDC3ABDEDU,0xD8FBA05AU,
    0x690CE0EEU,0x6DCDFD59U,0x608EDB80U,0x644FC637U,
    0x7A089632U,0x7EC98B85U,0x738AAD5CU,0x774BB0EBU,
    0x4F040D56U,0x4BC510E1U,0x46863638U,0x42472B8FU,
    0x5C007B8AU,0x58C1663DU,0x558240E4U,0x51435D53U,
    0x251D3B9EU,0x21DC2629U,0x2C9F00F0U,0x285E1D47U,
    0x36194D42U,0x32D850F5U,0x3F9B762CU,0x3B5A6B9BU,
    0x0315D626U,0x07D4CB91U,0x0A97ED48U,0x0E56F0FFU,
    0x1011A0FAU,0x14D0BD4DU,0x19939B94U,0x1D528623U,
    0xF12F560EU,0xF5EE4BB9U,0xF8AD6D60U,0xFC6C70D7U,
    0xE22B20D2U,0xE6EA3D65U,0xEBA91BBCU,0xEF68060BU,
    0xD727BBB6U,0xD3E6A601U,0xDEA580D8U,0xDA649D6FU,
    0xC423CD6AU,0xC0E2D0DDU,0xCDA1F604U,0xC960EBB3U,
    0xBD3E8D7EU,0xB9FF90C9U,0xB4BCB610U,0xB07DABA7U,
    0xAE3AFBA2U,0xAAFBE615U,0xA7B8C0CCU,0xA379DD7BU,
    0x9B3660C6U,0x9FF77D71U,0x92B45BA8U,0x9675461FU,
    0x8832161AU,0x8CF30BADU,0x81B02D74U,0x857130C3U,
    0x5D8A9099U,0x594B8D2EU,0x5408ABF7U,0x50C9B640U,
    0x4E8EE645U,0x4A4FFBF2U,0x470CDD2BU,0x43CDC09CU,
    0x7B827D21U,0x7F436096U,0x7200464FU,0x76C15BF8U,
    0x68860BFDU,0x6C47164AU,0x61043093U,0x65C52D24U,
    0x119B4BE9U,0x155A565EU,0x18197087U,0x1CD86D30U,
    0x029F3D35U,0x065E2082U,0x0B1D065BU,0x0FDC1BECU,
    0x3793A651U,0x3352BBE6U,0x3E119D3FU,0x3AD08088U,
    0x2497D08DU,0x2056CD3AU,0x2D15EBE3U,0x29D4F654U,
    0xC5A92679U,0xC1683BCEU,0xCC2B1D17U,0xC8EA00A0U,
    0xD6AD50A5U,0xD26C4D12U,0xDF2F6BCBU,0xDBEE767CU,
    0xE3A1CBC1U,0xE760D676U,0xEA23F0AFU,0xEEE2ED18U,
    0xF0A5BD1DU,0xF464A0AAU,0xF9278673U,0xFDE69BC4U,
    0x89B8FD09U,0x8D79E0BEU,0x803AC667U,0x84FBDBD0U,
    0x9ABC8BD5U,0x9E7D9662U,0x933EB0BBU,0x97FFAD0CU,
    0xAFB010B1U,0xAB710D06U,0xA6322BDFU,0xA2F33668U,
    0xBCB4666DU,0xB8757BDAU,0xB5365D03U,0xB1F740B4U,
};


/** Table of constants needed by some cryptography functions */
const uint8_t Sbox[256] = {
    0x02, 0x03, 0x05, 0x07, 0x0B, 0x0D, 0x11, 0x13,
    0x17, 0x1D, 0x1F, 0x25, 0x29, 0x2B, 0x2F, 0x35,
    0x3B, 0x3D, 0x43, 0x47, 0x49, 0x4F, 0x53, 0x59,
    0x61, 0x65, 0x67, 0x6B, 0x6D, 0x71, 0x7F, 0x83,
    0x89, 0x8B, 0x95, 0x97, 0x9D, 0xA3, 0xA7, 0xAD,
    0xB3, 0xB5, 0xBF, 0xC1, 0xC5, 0xC7, 0xD3, 0xDF,
    0xE3, 0xE5, 0xE9, 0xEF, 0xF1, 0xFB, 0x01, 0x07,
    0x0D, 0x0F, 0x15, 0x19, 0x1B, 0x25, 0x33, 0x37,
    0x39, 0x3D, 0x4B, 0x51, 0x5B, 0x5D, 0x61, 0x67,
    0x6F, 0x75, 0x7B, 0x7F, 0x85, 0x8D, 0x91, 0x99,
    0xA3, 0xA5, 0xAF, 0xB1, 0xB7, 0xBB, 0xC1, 0xC9,
    0xCD, 0xCF, 0xD3, 0xDF, 0xE7, 0xEB, 0xF3, 0xF7,
    0xFD, 0x09, 0x0B, 0x1D, 0x23, 0x2D, 0x33, 0x39,
    0x3B, 0x41, 0x4B, 0x51, 0x57, 0x59, 0x5F, 0x65,
    0x69, 0x6B, 0x77, 0x81, 0x83, 0x87, 0x8D, 0x93,
    0x95, 0xA1, 0xA5, 0xAB, 0xB3, 0xBD, 0xC5, 0xCF,
    0xD7, 0xDD, 0xE3, 0xE7, 0xEF, 0xF5, 0xF9, 0x01,
    0x05, 0x13, 0x1D, 0x29, 0x2B, 0x35, 0x37, 0x3B,
    0x3D, 0x47, 0x55, 0x59, 0x5B, 0x5F, 0x6D, 0x71,
    0x73, 0x77, 0x8B, 0x8F, 0x97, 0xA1, 0xA9, 0xAD,
    0xB3, 0xB9, 0xC7, 0xCB, 0xD1, 0xD7, 0xDF, 0xE5,
    0xF1, 0xF5, 0xFB, 0xFD, 0x07, 0x09, 0x0F, 0x19,
    0x1B, 0x25, 0x27, 0x2D, 0x3F, 0x43, 0x45, 0x49,
    0x4F, 0x55, 0x5D, 0x63, 0x69, 0x7F, 0x81, 0x8B,
    0x93, 0x9D, 0xA3, 0xA9, 0xB1, 0xBD, 0xC1, 0xC7,
    0xCD, 0xCF, 0xD5, 0xE1, 0xEB, 0xFD, 0xFF, 0x03,
    0x09, 0x0B, 0x11, 0x15, 0x17, 0x1B, 0x27, 0x29,
    0x2F, 0x51, 0x57, 0x5D, 0x65, 0x77, 0x81, 0x8F,
    0x93, 0x95, 0x99, 0x9F, 0xA7, 0xAB, 0xAD, 0xB3,
    0xBF, 0xC9, 0xCB, 0xCF, 0xD1, 0xD5, 0xDB, 0xE7,
    0xF3, 0xFB, 0x07, 0x0D, 0x11, 0x17, 0x1F, 0x23,
    0x2B, 0x2F, 0x3D, 0x41, 0x47, 0x49, 0x4D, 0x53
};


/** Table of constants needed by some Anubis functions */
const u32 ANUBIS_T0[256] = {
    0xa753a6f5U, 0xd3bb6bd0U, 0xe6d1bf6eU, 0x71e2d93bU,
    0xd0bd67daU, 0xac458acfU, 0x4d9a29b3U, 0x79f2f90bU,
    0x3a74e89cU, 0xc98f038cU, 0x913f7e41U, 0xfce5d732U,
    0x1e3c7844U, 0x478e018fU, 0x54a84de5U, 0xbd67cea9U,
    0x8c050a0fU, 0xa557aef9U, 0x7af4f501U, 0xfbebcb20U,
    0x63c69157U, 0xb86ddab7U, 0xdda753f4U, 0xd4b577c2U,
    0xe5d7b364U, 0xb37bf68dU, 0xc59733a4U, 0xbe61c2a3U,
    0xa94f9ed1U, 0x880d1a17U, 0x0c183028U, 0xa259b2ebU,
    0x3972e496U, 0xdfa35bf8U, 0x2952a4f6U, 0xdaa94fe6U,
    0x2b56acfaU, 0xa84d9ad7U, 0xcb8b0b80U, 0x4c982db5U,
    0x4b9631a7U, 0x224488ccU, 0xaa4992dbU, 0x244890d8U,
    0x4182199bU, 0x70e0dd3dU, 0xa651a2f3U, 0xf9efc32cU,
    0x5ab475c1U, 0xe2d9af76U, 0xb07dfa87U, 0x366cd8b4U,
    0x7dfae913U, 0xe4d5b762U, 0x3366ccaaU, 0xffe3db38U,
    0x60c09d5dU, 0x204080c0U, 0x08102030U, 0x8b0b161dU,
    0x5ebc65d9U, 0xab4b96ddU, 0x7ffee11fU, 0x78f0fd0dU,
    0x7cf8ed15U, 0x2c58b0e8U, 0x57ae41efU, 0xd2b96fd6U,
    0xdca557f2U, 0x6ddaa973U, 0x7efce519U, 0x0d1a342eU,
    0x53a651f7U, 0x94356a5fU, 0xc39b2bb0U, 0x2850a0f0U,
    0x274e9cd2U, 0x060c1814U, 0x5fbe61dfU, 0xad478ec9U,
    0x67ce814fU, 0x5cb86dd5U, 0x55aa49e3U, 0x48903dadU,
    0x0e1c3824U, 0x52a455f1U, 0xeac98f46U, 0x42841591U,
    0x5bb671c7U, 0x5dba69d3U, 0x3060c0a0U, 0x58b07dcdU,
    0x51a259fbU, 0x59b279cbU, 0x3c78f088U, 0x4e9c25b9U,
    0x3870e090U, 0x8a09121bU, 0x72e4d531U, 0x14285078U,
    0xe7d3bb68U, 0xc6913faeU, 0xdea15ffeU, 0x50a05dfdU,
    0x8e010203U, 0x9239724bU, 0xd1bf63dcU, 0x77eec12fU,
    0x933b764dU, 0x458a0983U, 0x9a29527bU, 0xce811f9eU,
    0x2d5ab4eeU, 0x03060c0aU, 0x62c49551U, 0xb671e293U,
    0xb96fdeb1U, 0xbf63c6a5U, 0x96316253U, 0x6bd6b167U,
    0x3f7efc82U, 0x070e1c12U, 0x1224486cU, 0xae4182c3U,
    0x40801d9dU, 0x3468d0b8U, 0x468c0589U, 0x3e7cf884U,
    0xdbab4be0U, 0xcf831b98U, 0xecc59752U, 0xcc851792U,
    0xc19f23bcU, 0xa15fbee1U, 0xc09d27baU, 0xd6b17fceU,
    0x1d3a744eU, 0xf4f5f702U, 0x61c2995bU, 0x3b76ec9aU,
    0x10204060U, 0xd8ad47eaU, 0x68d0bd6dU, 0xa05dbae7U,
    0xb17ffe81U, 0x0a14283cU, 0x69d2b96bU, 0x6cd8ad75U,
    0x499239abU, 0xfae9cf26U, 0x76ecc529U, 0xc49537a2U,
    0x9e214263U, 0x9b2b567dU, 0x6edca579U, 0x992f5e71U,
    0xc2992fb6U, 0xb773e695U, 0x982d5a77U, 0xbc65caafU,
    0x8f030605U, 0x85172e39U, 0x1f3e7c42U, 0xb475ea9fU,
    0xf8edc72aU, 0x11224466U, 0x2e5cb8e4U, 0x00000000U,
    0x254a94deU, 0x1c387048U, 0x2a54a8fcU, 0x3d7af48eU,
    0x050a141eU, 0x4f9e21bfU, 0x7bf6f107U, 0xb279f28bU,
    0x3264c8acU, 0x903d7a47U, 0xaf4386c5U, 0x19326456U,
    0xa35bb6edU, 0xf7f3fb08U, 0x73e6d137U, 0x9d274e69U,
    0x152a547eU, 0x74e8cd25U, 0xeec19f5eU, 0xca890f86U,
    0x9f234665U, 0x0f1e3c22U, 0x1b366c5aU, 0x75eac923U,
    0x86112233U, 0x84152a3fU, 0x9c254a6fU, 0x4a9435a1U,
    0x97336655U, 0x1a34685cU, 0x65ca8943U, 0xf6f1ff0eU,
    0xedc79354U, 0x09122436U, 0xbb6bd6bdU, 0x264c98d4U,
    0x831b362dU, 0xebcb8b40U, 0x6fdea17fU, 0x811f3e21U,
    0x04081018U, 0x6ad4b561U, 0x43861197U, 0x01020406U,
    0x172e5c72U, 0xe1dfa37cU, 0x87132635U, 0xf5f7f304U,
    0x8d070e09U, 0xe3dbab70U, 0x23468ccaU, 0x801d3a27U,
    0x44880d85U, 0x162c5874U, 0x66cc8549U, 0x214284c6U,
    0xfee1df3eU, 0xd5b773c4U, 0x3162c4a6U, 0xd9af43ecU,
    0x356ad4beU, 0x18306050U, 0x0204080cU, 0x64c88d45U,
    0xf2f9ef16U, 0xf1ffe31cU, 0x56ac45e9U, 0xcd871394U,
    0x8219322bU, 0xc88d078aU, 0xba69d2bbU, 0xf0fde71aU,
    0xefc39b58U, 0xe9cf834cU, 0xe8cd874aU, 0xfde7d334U,
    0x890f1e11U, 0xd7b37bc8U, 0xc7933ba8U, 0xb577ee99U,
    0xa455aaffU, 0x2f5ebce2U, 0x95376e59U, 0x13264c6aU,
    0x0b162c3aU, 0xf3fbeb10U, 0xe0dda77aU, 0x376edcb2U,
};


/** Table of constants needed by some Anubis functions */
const u32 ANUBIS_T1[256] = {
    0x53a7f5a6U, 0xbbd3d06bU, 0xd1e66ebfU, 0xe2713bd9U,
    0xbdd0da67U, 0x45accf8aU, 0x9a4db329U, 0xf2790bf9U,
    0x743a9ce8U, 0x8fc98c03U, 0x3f91417eU, 0xe5fc32d7U,
    0x3c1e4478U, 0x8e478f01U, 0xa854e54dU, 0x67bda9ceU,
    0x058c0f0aU, 0x57a5f9aeU, 0xf47a01f5U, 0xebfb20cbU,
    0xc6635791U, 0x6db8b7daU, 0xa7ddf453U, 0xb5d4c277U,
    0xd7e564b3U, 0x7bb38df6U, 0x97c5a433U, 0x61bea3c2U,
    0x4fa9d19eU, 0x0d88171aU, 0x180c2830U, 0x59a2ebb2U,
    0x723996e4U, 0xa3dff85bU, 0x5229f6a4U, 0xa9dae64fU,
    0x562bfaacU, 0x4da8d79aU, 0x8bcb800bU, 0x984cb52dU,
    0x964ba731U, 0x4422cc88U, 0x49aadb92U, 0x4824d890U,
    0x82419b19U, 0xe0703dddU, 0x51a6f3a2U, 0xeff92cc3U,
    0xb45ac175U, 0xd9e276afU, 0x7db087faU, 0x6c36b4d8U,
    0xfa7d13e9U, 0xd5e462b7U, 0x6633aaccU, 0xe3ff38dbU,
    0xc0605d9dU, 0x4020c080U, 0x10083020U, 0x0b8b1d16U,
    0xbc5ed965U, 0x4babdd96U, 0xfe7f1fe1U, 0xf0780dfdU,
    0xf87c15edU, 0x582ce8b0U, 0xae57ef41U, 0xb9d2d66fU,
    0xa5dcf257U, 0xda6d73a9U, 0xfc7e19e5U, 0x1a0d2e34U,
    0xa653f751U, 0x35945f6aU, 0x9bc3b02bU, 0x5028f0a0U,
    0x4e27d29cU, 0x0c061418U, 0xbe5fdf61U, 0x47adc98eU,
    0xce674f81U, 0xb85cd56dU, 0xaa55e349U, 0x9048ad3dU,
    0x1c0e2438U, 0xa452f155U, 0xc9ea468fU, 0x84429115U,
    0xb65bc771U, 0xba5dd369U, 0x6030a0c0U, 0xb058cd7dU,
    0xa251fb59U, 0xb259cb79U, 0x783c88f0U, 0x9c4eb925U,
    0x703890e0U, 0x098a1b12U, 0xe47231d5U, 0x28147850U,
    0xd3e768bbU, 0x91c6ae3fU, 0xa1defe5fU, 0xa050fd5dU,
    0x018e0302U, 0x39924b72U, 0xbfd1dc63U, 0xee772fc1U,
    0x3b934d76U, 0x8a458309U, 0x299a7b52U, 0x81ce9e1fU,
    0x5a2deeb4U, 0x06030a0cU, 0xc4625195U, 0x71b693e2U,
    0x6fb9b1deU, 0x63bfa5c6U, 0x31965362U, 0xd66b67b1U,
    0x7e3f82fcU, 0x0e07121cU, 0x24126c48U, 0x41aec382U,
    0x80409d1dU, 0x6834b8d0U, 0x8c468905U, 0x7c3e84f8U,
    0xabdbe04bU, 0x83cf981bU, 0xc5ec5297U, 0x85cc9217U,
    0x9fc1bc23U, 0x5fa1e1beU, 0x9dc0ba27U, 0xb1d6ce7fU,
    0x3a1d4e74U, 0xf5f402f7U, 0xc2615b99U, 0x763b9aecU,
    0x20106040U, 0xadd8ea47U, 0xd0686dbdU, 0x5da0e7baU,
    0x7fb181feU, 0x140a3c28U, 0xd2696bb9U, 0xd86c75adU,
    0x9249ab39U, 0xe9fa26cfU, 0xec7629c5U, 0x95c4a237U,
    0x219e6342U, 0x2b9b7d56U, 0xdc6e79a5U, 0x2f99715eU,
    0x99c2b62fU, 0x73b795e6U, 0x2d98775aU, 0x65bcafcaU,
    0x038f0506U, 0x1785392eU, 0x3e1f427cU, 0x75b49feaU,
    0xedf82ac7U, 0x22116644U, 0x5c2ee4b8U, 0x00000000U,
    0x4a25de94U, 0x381c4870U, 0x542afca8U, 0x7a3d8ef4U,
    0x0a051e14U, 0x9e4fbf21U, 0xf67b07f1U, 0x79b28bf2U,
    0x6432acc8U, 0x3d90477aU, 0x43afc586U, 0x32195664U,
    0x5ba3edb6U, 0xf3f708fbU, 0xe67337d1U, 0x279d694eU,
    0x2a157e54U, 0xe87425cdU, 0xc1ee5e9fU, 0x89ca860fU,
    0x239f6546U, 0x1e0f223cU, 0x361b5a6cU, 0xea7523c9U,
    0x11863322U, 0x15843f2aU, 0x259c6f4aU, 0x944aa135U,
    0x33975566U, 0x341a5c68U, 0xca654389U, 0xf1f60effU,
    0xc7ed5493U, 0x12093624U, 0x6bbbbdd6U, 0x4c26d498U,
    0x1b832d36U, 0xcbeb408bU, 0xde6f7fa1U, 0x1f81213eU,
    0x08041810U, 0xd46a61b5U, 0x86439711U, 0x02010604U,
    0x2e17725cU, 0xdfe17ca3U, 0x13873526U, 0xf7f504f3U,
    0x078d090eU, 0xdbe370abU, 0x4623ca8cU, 0x1d80273aU,
    0x8844850dU, 0x2c167458U, 0xcc664985U, 0x4221c684U,
    0xe1fe3edfU, 0xb7d5c473U, 0x6231a6c4U, 0xafd9ec43U,
    0x6a35bed4U, 0x30185060U, 0x04020c08U, 0xc864458dU,
    0xf9f216efU, 0xfff11ce3U, 0xac56e945U, 0x87cd9413U,
    0x19822b32U, 0x8dc88a07U, 0x69babbd2U, 0xfdf01ae7U,
    0xc3ef589bU, 0xcfe94c83U, 0xcde84a87U, 0xe7fd34d3U,
    0x0f89111eU, 0xb3d7c87bU, 0x93c7a83bU, 0x77b599eeU,
    0x55a4ffaaU, 0x5e2fe2bcU, 0x3795596eU, 0x26136a4cU,
    0x160b3a2cU, 0xfbf310ebU, 0xdde07aa7U, 0x6e37b2dcU,
};


/** Table of constants needed by some Anubis functions */
const u32 ANUBIS_T2[256] = {
    0xa6f5a753U, 0x6bd0d3bbU, 0xbf6ee6d1U, 0xd93b71e2U,
    0x67dad0bdU, 0x8acfac45U, 0x29b34d9aU, 0xf90b79f2U,
    0xe89c3a74U, 0x038cc98fU, 0x7e41913fU, 0xd732fce5U,
    0x78441e3cU, 0x018f478eU, 0x4de554a8U, 0xcea9bd67U,
    0x0a0f8c05U, 0xaef9a557U, 0xf5017af4U, 0xcb20fbebU,
    0x915763c6U, 0xdab7b86dU, 0x53f4dda7U, 0x77c2d4b5U,
    0xb364e5d7U, 0xf68db37bU, 0x33a4c597U, 0xc2a3be61U,
    0x9ed1a94fU, 0x1a17880dU, 0x30280c18U, 0xb2eba259U,
    0xe4963972U, 0x5bf8dfa3U, 0xa4f62952U, 0x4fe6daa9U,
    0xacfa2b56U, 0x9ad7a84dU, 0x0b80cb8bU, 0x2db54c98U,
    0x31a74b96U, 0x88cc2244U, 0x92dbaa49U, 0x90d82448U,
    0x199b4182U, 0xdd3d70e0U, 0xa2f3a651U, 0xc32cf9efU,
    0x75c15ab4U, 0xaf76e2d9U, 0xfa87b07dU, 0xd8b4366cU,
    0xe9137dfaU, 0xb762e4d5U, 0xccaa3366U, 0xdb38ffe3U,
    0x9d5d60c0U, 0x80c02040U, 0x20300810U, 0x161d8b0bU,
    0x65d95ebcU, 0x96ddab4bU, 0xe11f7ffeU, 0xfd0d78f0U,
    0xed157cf8U, 0xb0e82c58U, 0x41ef57aeU, 0x6fd6d2b9U,
    0x57f2dca5U, 0xa9736ddaU, 0xe5197efcU, 0x342e0d1aU,
    0x51f753a6U, 0x6a5f9435U, 0x2bb0c39bU, 0xa0f02850U,
    0x9cd2274eU, 0x1814060cU, 0x61df5fbeU, 0x8ec9ad47U,
    0x814f67ceU, 0x6dd55cb8U, 0x49e355aaU, 0x3dad4890U,
    0x38240e1cU, 0x55f152a4U, 0x8f46eac9U, 0x15914284U,
    0x71c75bb6U, 0x69d35dbaU, 0xc0a03060U, 0x7dcd58b0U,
    0x59fb51a2U, 0x79cb59b2U, 0xf0883c78U, 0x25b94e9cU,
    0xe0903870U, 0x121b8a09U, 0xd53172e4U, 0x50781428U,
    0xbb68e7d3U, 0x3faec691U, 0x5ffedea1U, 0x5dfd50a0U,
    0x02038e01U, 0x724b9239U, 0x63dcd1bfU, 0xc12f77eeU,
    0x764d933bU, 0x0983458aU, 0x527b9a29U, 0x1f9ece81U,
    0xb4ee2d5aU, 0x0c0a0306U, 0x955162c4U, 0xe293b671U,
    0xdeb1b96fU, 0xc6a5bf63U, 0x62539631U, 0xb1676bd6U,
    0xfc823f7eU, 0x1c12070eU, 0x486c1224U, 0x82c3ae41U,
    0x1d9d4080U, 0xd0b83468U, 0x0589468cU, 0xf8843e7cU,
    0x4be0dbabU, 0x1b98cf83U, 0x9752ecc5U, 0x1792cc85U,
    0x23bcc19fU, 0xbee1a15fU, 0x27bac09dU, 0x7fced6b1U,
    0x744e1d3aU, 0xf702f4f5U, 0x995b61c2U, 0xec9a3b76U,
    0x40601020U, 0x47ead8adU, 0xbd6d68d0U, 0xbae7a05dU,
    0xfe81b17fU, 0x283c0a14U, 0xb96b69d2U, 0xad756cd8U,
    0x39ab4992U, 0xcf26fae9U, 0xc52976ecU, 0x37a2c495U,
    0x42639e21U, 0x567d9b2bU, 0xa5796edcU, 0x5e71992fU,
    0x2fb6c299U, 0xe695b773U, 0x5a77982dU, 0xcaafbc65U,
    0x06058f03U, 0x2e398517U, 0x7c421f3eU, 0xea9fb475U,
    0xc72af8edU, 0x44661122U, 0xb8e42e5cU, 0x00000000U,
    0x94de254aU, 0x70481c38U, 0xa8fc2a54U, 0xf48e3d7aU,
    0x141e050aU, 0x21bf4f9eU, 0xf1077bf6U, 0xf28bb279U,
    0xc8ac3264U, 0x7a47903dU, 0x86c5af43U, 0x64561932U,
    0xb6eda35bU, 0xfb08f7f3U, 0xd13773e6U, 0x4e699d27U,
    0x547e152aU, 0xcd2574e8U, 0x9f5eeec1U, 0x0f86ca89U,
    0x46659f23U, 0x3c220f1eU, 0x6c5a1b36U, 0xc92375eaU,
    0x22338611U, 0x2a3f8415U, 0x4a6f9c25U, 0x35a14a94U,
    0x66559733U, 0x685c1a34U, 0x894365caU, 0xff0ef6f1U,
    0x9354edc7U, 0x24360912U, 0xd6bdbb6bU, 0x98d4264cU,
    0x362d831bU, 0x8b40ebcbU, 0xa17f6fdeU, 0x3e21811fU,
    0x10180408U, 0xb5616ad4U, 0x11974386U, 0x04060102U,
    0x5c72172eU, 0xa37ce1dfU, 0x26358713U, 0xf304f5f7U,
    0x0e098d07U, 0xab70e3dbU, 0x8cca2346U, 0x3a27801dU,
    0x0d854488U, 0x5874162cU, 0x854966ccU, 0x84c62142U,
    0xdf3efee1U, 0x73c4d5b7U, 0xc4a63162U, 0x43ecd9afU,
    0xd4be356aU, 0x60501830U, 0x080c0204U, 0x8d4564c8U,
    0xef16f2f9U, 0xe31cf1ffU, 0x45e956acU, 0x1394cd87U,
    0x322b8219U, 0x078ac88dU, 0xd2bbba69U, 0xe71af0fdU,
    0x9b58efc3U, 0x834ce9cfU, 0x874ae8cdU, 0xd334fde7U,
    0x1e11890fU, 0x7bc8d7b3U, 0x3ba8c793U, 0xee99b577U,
    0xaaffa455U, 0xbce22f5eU, 0x6e599537U, 0x4c6a1326U,
    0x2c3a0b16U, 0xeb10f3fbU, 0xa77ae0ddU, 0xdcb2376eU,
};


/** Table of constants needed by some Anubis functions */
const u32 ANUBIS_T3[256] = {
    0xf5a653a7U, 0xd06bbbd3U, 0x6ebfd1e6U, 0x3bd9e271U,
    0xda67bdd0U, 0xcf8a45acU, 0xb3299a4dU, 0x0bf9f279U,
    0x9ce8743aU, 0x8c038fc9U, 0x417e3f91U, 0x32d7e5fcU,
    0x44783c1eU, 0x8f018e47U, 0xe54da854U, 0xa9ce67bdU,
    0x0f0a058cU, 0xf9ae57a5U, 0x01f5f47aU, 0x20cbebfbU,
    0x5791c663U, 0xb7da6db8U, 0xf453a7ddU, 0xc277b5d4U,
    0x64b3d7e5U, 0x8df67bb3U, 0xa43397c5U, 0xa3c261beU,
    0xd19e4fa9U, 0x171a0d88U, 0x2830180cU, 0xebb259a2U,
    0x96e47239U, 0xf85ba3dfU, 0xf6a45229U, 0xe64fa9daU,
    0xfaac562bU, 0xd79a4da8U, 0x800b8bcbU, 0xb52d984cU,
    0xa731964bU, 0xcc884422U, 0xdb9249aaU, 0xd8904824U,
    0x9b198241U, 0x3ddde070U, 0xf3a251a6U, 0x2cc3eff9U,
    0xc175b45aU, 0x76afd9e2U, 0x87fa7db0U, 0xb4d86c36U,
    0x13e9fa7dU, 0x62b7d5e4U, 0xaacc6633U, 0x38dbe3ffU,
    0x5d9dc060U, 0xc0804020U, 0x30201008U, 0x1d160b8bU,
    0xd965bc5eU, 0xdd964babU, 0x1fe1fe7fU, 0x0dfdf078U,
    0x15edf87cU, 0xe8b0582cU, 0xef41ae57U, 0xd66fb9d2U,
    0xf257a5dcU, 0x73a9da6dU, 0x19e5fc7eU, 0x2e341a0dU,
    0xf751a653U, 0x5f6a3594U, 0xb02b9bc3U, 0xf0a05028U,
    0xd29c4e27U, 0x14180c06U, 0xdf61be5fU, 0xc98e47adU,
    0x4f81ce67U, 0xd56db85cU, 0xe349aa55U, 0xad3d9048U,
    0x24381c0eU, 0xf155a452U, 0x468fc9eaU, 0x91158442U,
    0xc771b65bU, 0xd369ba5dU, 0xa0c06030U, 0xcd7db058U,
    0xfb59a251U, 0xcb79b259U, 0x88f0783cU, 0xb9259c4eU,
    0x90e07038U, 0x1b12098aU, 0x31d5e472U, 0x78502814U,
    0x68bbd3e7U, 0xae3f91c6U, 0xfe5fa1deU, 0xfd5da050U,
    0x0302018eU, 0x4b723992U, 0xdc63bfd1U, 0x2fc1ee77U,
    0x4d763b93U, 0x83098a45U, 0x7b52299aU, 0x9e1f81ceU,
    0xeeb45a2dU, 0x0a0c0603U, 0x5195c462U, 0x93e271b6U,
    0xb1de6fb9U, 0xa5c663bfU, 0x53623196U, 0x67b1d66bU,
    0x82fc7e3fU, 0x121c0e07U, 0x6c482412U, 0xc38241aeU,
    0x9d1d8040U, 0xb8d06834U, 0x89058c46U, 0x84f87c3eU,
    0xe04babdbU, 0x981b83cfU, 0x5297c5ecU, 0x921785ccU,
    0xbc239fc1U, 0xe1be5fa1U, 0xba279dc0U, 0xce7fb1d6U,
    0x4e743a1dU, 0x02f7f5f4U, 0x5b99c261U, 0x9aec763bU,
    0x60402010U, 0xea47add8U, 0x6dbdd068U, 0xe7ba5da0U,
    0x81fe7fb1U, 0x3c28140aU, 0x6bb9d269U, 0x75add86cU,
    0xab399249U, 0x26cfe9faU, 0x29c5ec76U, 0xa23795c4U,
    0x6342219eU, 0x7d562b9bU, 0x79a5dc6eU, 0x715e2f99U,
    0xb62f99c2U, 0x95e673b7U, 0x775a2d98U, 0xafca65bcU,
    0x0506038fU, 0x392e1785U, 0x427c3e1fU, 0x9fea75b4U,
    0x2ac7edf8U, 0x66442211U, 0xe4b85c2eU, 0x00000000U,
    0xde944a25U, 0x4870381cU, 0xfca8542aU, 0x8ef47a3dU,
    0x1e140a05U, 0xbf219e4fU, 0x07f1f67bU, 0x8bf279b2U,
    0xacc86432U, 0x477a3d90U, 0xc58643afU, 0x56643219U,
    0xedb65ba3U, 0x08fbf3f7U, 0x37d1e673U, 0x694e279dU,
    0x7e542a15U, 0x25cde874U, 0x5e9fc1eeU, 0x860f89caU,
    0x6546239fU, 0x223c1e0fU, 0x5a6c361bU, 0x23c9ea75U,
    0x33221186U, 0x3f2a1584U, 0x6f4a259cU, 0xa135944aU,
    0x55663397U, 0x5c68341aU, 0x4389ca65U, 0x0efff1f6U,
    0x5493c7edU, 0x36241209U, 0xbdd66bbbU, 0xd4984c26U,
    0x2d361b83U, 0x408bcbebU, 0x7fa1de6fU, 0x213e1f81U,
    0x18100804U, 0x61b5d46aU, 0x97118643U, 0x06040201U,
    0x725c2e17U, 0x7ca3dfe1U, 0x35261387U, 0x04f3f7f5U,
    0x090e078dU, 0x70abdbe3U, 0xca8c4623U, 0x273a1d80U,
    0x850d8844U, 0x74582c16U, 0x4985cc66U, 0xc6844221U,
    0x3edfe1feU, 0xc473b7d5U, 0xa6c46231U, 0xec43afd9U,
    0xbed46a35U, 0x50603018U, 0x0c080402U, 0x458dc864U,
    0x16eff9f2U, 0x1ce3fff1U, 0xe945ac56U, 0x941387cdU,
    0x2b321982U, 0x8a078dc8U, 0xbbd269baU, 0x1ae7fdf0U,
    0x589bc3efU, 0x4c83cfe9U, 0x4a87cde8U, 0x34d3e7fdU,
    0x111e0f89U, 0xc87bb3d7U, 0xa83b93c7U, 0x99ee77b5U,
    0xffaa55a4U, 0xe2bc5e2fU, 0x596e3795U, 0x6a4c2613U,
    0x3a2c160bU, 0x10ebfbf3U, 0x7aa7dde0U, 0xb2dc6e37U,
};


/** Table of constants needed by some Anubis functions */
const u32 ANUBIS_T4[256] = {
    0xa7a7a7a7U, 0xd3d3d3d3U, 0xe6e6e6e6U, 0x71717171U,
    0xd0d0d0d0U, 0xacacacacU, 0x4d4d4d4dU, 0x79797979U,
    0x3a3a3a3aU, 0xc9c9c9c9U, 0x91919191U, 0xfcfcfcfcU,
    0x1e1e1e1eU, 0x47474747U, 0x54545454U, 0xbdbdbdbdU,
    0x8c8c8c8cU, 0xa5a5a5a5U, 0x7a7a7a7aU, 0xfbfbfbfbU,
    0x63636363U, 0xb8b8b8b8U, 0xddddddddU, 0xd4d4d4d4U,
    0xe5e5e5e5U, 0xb3b3b3b3U, 0xc5c5c5c5U, 0xbebebebeU,
    0xa9a9a9a9U, 0x88888888U, 0x0c0c0c0cU, 0xa2a2a2a2U,
    0x39393939U, 0xdfdfdfdfU, 0x29292929U, 0xdadadadaU,
    0x2b2b2b2bU, 0xa8a8a8a8U, 0xcbcbcbcbU, 0x4c4c4c4cU,
    0x4b4b4b4bU, 0x22222222U, 0xaaaaaaaaU, 0x24242424U,
    0x41414141U, 0x70707070U, 0xa6a6a6a6U, 0xf9f9f9f9U,
    0x5a5a5a5aU, 0xe2e2e2e2U, 0xb0b0b0b0U, 0x36363636U,
    0x7d7d7d7dU, 0xe4e4e4e4U, 0x33333333U, 0xffffffffU,
    0x60606060U, 0x20202020U, 0x08080808U, 0x8b8b8b8bU,
    0x5e5e5e5eU, 0xababababU, 0x7f7f7f7fU, 0x78787878U,
    0x7c7c7c7cU, 0x2c2c2c2cU, 0x57575757U, 0xd2d2d2d2U,
    0xdcdcdcdcU, 0x6d6d6d6dU, 0x7e7e7e7eU, 0x0d0d0d0dU,
    0x53535353U, 0x94949494U, 0xc3c3c3c3U, 0x28282828U,
    0x27272727U, 0x06060606U, 0x5f5f5f5fU, 0xadadadadU,
    0x67676767U, 0x5c5c5c5cU, 0x55555555U, 0x48484848U,
    0x0e0e0e0eU, 0x52525252U, 0xeaeaeaeaU, 0x42424242U,
    0x5b5b5b5bU, 0x5d5d5d5dU, 0x30303030U, 0x58585858U,
    0x51515151U, 0x59595959U, 0x3c3c3c3cU, 0x4e4e4e4eU,
    0x38383838U, 0x8a8a8a8aU, 0x72727272U, 0x14141414U,
    0xe7e7e7e7U, 0xc6c6c6c6U, 0xdedededeU, 0x50505050U,
    0x8e8e8e8eU, 0x92929292U, 0xd1d1d1d1U, 0x77777777U,
    0x93939393U, 0x45454545U, 0x9a9a9a9aU, 0xcecececeU,
    0x2d2d2d2dU, 0x03030303U, 0x62626262U, 0xb6b6b6b6U,
    0xb9b9b9b9U, 0xbfbfbfbfU, 0x96969696U, 0x6b6b6b6bU,
    0x3f3f3f3fU, 0x07070707U, 0x12121212U, 0xaeaeaeaeU,
    0x40404040U, 0x34343434U, 0x46464646U, 0x3e3e3e3eU,
    0xdbdbdbdbU, 0xcfcfcfcfU, 0xececececU, 0xccccccccU,
    0xc1c1c1c1U, 0xa1a1a1a1U, 0xc0c0c0c0U, 0xd6d6d6d6U,
    0x1d1d1d1dU, 0xf4f4f4f4U, 0x61616161U, 0x3b3b3b3bU,
    0x10101010U, 0xd8d8d8d8U, 0x68686868U, 0xa0a0a0a0U,
    0xb1b1b1b1U, 0x0a0a0a0aU, 0x69696969U, 0x6c6c6c6cU,
    0x49494949U, 0xfafafafaU, 0x76767676U, 0xc4c4c4c4U,
    0x9e9e9e9eU, 0x9b9b9b9bU, 0x6e6e6e6eU, 0x99999999U,
    0xc2c2c2c2U, 0xb7b7b7b7U, 0x98989898U, 0xbcbcbcbcU,
    0x8f8f8f8fU, 0x85858585U, 0x1f1f1f1fU, 0xb4b4b4b4U,
    0xf8f8f8f8U, 0x11111111U, 0x2e2e2e2eU, 0x00000000U,
    0x25252525U, 0x1c1c1c1cU, 0x2a2a2a2aU, 0x3d3d3d3dU,
    0x05050505U, 0x4f4f4f4fU, 0x7b7b7b7bU, 0xb2b2b2b2U,
    0x32323232U, 0x90909090U, 0xafafafafU, 0x19191919U,
    0xa3a3a3a3U, 0xf7f7f7f7U, 0x73737373U, 0x9d9d9d9dU,
    0x15151515U, 0x74747474U, 0xeeeeeeeeU, 0xcacacacaU,
    0x9f9f9f9fU, 0x0f0f0f0fU, 0x1b1b1b1bU, 0x75757575U,
    0x86868686U, 0x84848484U, 0x9c9c9c9cU, 0x4a4a4a4aU,
    0x97979797U, 0x1a1a1a1aU, 0x65656565U, 0xf6f6f6f6U,
    0xededededU, 0x09090909U, 0xbbbbbbbbU, 0x26262626U,
    0x83838383U, 0xebebebebU, 0x6f6f6f6fU, 0x81818181U,
    0x04040404U, 0x6a6a6a6aU, 0x43434343U, 0x01010101U,
    0x17171717U, 0xe1e1e1e1U, 0x87878787U, 0xf5f5f5f5U,
    0x8d8d8d8dU, 0xe3e3e3e3U, 0x23232323U, 0x80808080U,
    0x44444444U, 0x16161616U, 0x66666666U, 0x21212121U,
    0xfefefefeU, 0xd5d5d5d5U, 0x31313131U, 0xd9d9d9d9U,
    0x35353535U, 0x18181818U, 0x02020202U, 0x64646464U,
    0xf2f2f2f2U, 0xf1f1f1f1U, 0x56565656U, 0xcdcdcdcdU,
    0x82828282U, 0xc8c8c8c8U, 0xbabababaU, 0xf0f0f0f0U,
    0xefefefefU, 0xe9e9e9e9U, 0xe8e8e8e8U, 0xfdfdfdfdU,
    0x89898989U, 0xd7d7d7d7U, 0xc7c7c7c7U, 0xb5b5b5b5U,
    0xa4a4a4a4U, 0x2f2f2f2fU, 0x95959595U, 0x13131313U,
    0x0b0b0b0bU, 0xf3f3f3f3U, 0xe0e0e0e0U, 0x37373737U,
};


/** Table of constants needed by some Anubis functions */
const u32 ANUBIS_T5[256] = {
    0x00000000U, 0x01020608U, 0x02040c10U, 0x03060a18U,
    0x04081820U, 0x050a1e28U, 0x060c1430U, 0x070e1238U,
    0x08103040U, 0x09123648U, 0x0a143c50U, 0x0b163a58U,
    0x0c182860U, 0x0d1a2e68U, 0x0e1c2470U, 0x0f1e2278U,
    0x10206080U, 0x11226688U, 0x12246c90U, 0x13266a98U,
    0x142878a0U, 0x152a7ea8U, 0x162c74b0U, 0x172e72b8U,
    0x183050c0U, 0x193256c8U, 0x1a345cd0U, 0x1b365ad8U,
    0x1c3848e0U, 0x1d3a4ee8U, 0x1e3c44f0U, 0x1f3e42f8U,
    0x2040c01dU, 0x2142c615U, 0x2244cc0dU, 0x2346ca05U,
    0x2448d83dU, 0x254ade35U, 0x264cd42dU, 0x274ed225U,
    0x2850f05dU, 0x2952f655U, 0x2a54fc4dU, 0x2b56fa45U,
    0x2c58e87dU, 0x2d5aee75U, 0x2e5ce46dU, 0x2f5ee265U,
    0x3060a09dU, 0x3162a695U, 0x3264ac8dU, 0x3366aa85U,
    0x3468b8bdU, 0x356abeb5U, 0x366cb4adU, 0x376eb2a5U,
    0x387090ddU, 0x397296d5U, 0x3a749ccdU, 0x3b769ac5U,
    0x3c7888fdU, 0x3d7a8ef5U, 0x3e7c84edU, 0x3f7e82e5U,
    0x40809d3aU, 0x41829b32U, 0x4284912aU, 0x43869722U,
    0x4488851aU, 0x458a8312U, 0x468c890aU, 0x478e8f02U,
    0x4890ad7aU, 0x4992ab72U, 0x4a94a16aU, 0x4b96a762U,
    0x4c98b55aU, 0x4d9ab352U, 0x4e9cb94aU, 0x4f9ebf42U,
    0x50a0fdbaU, 0x51a2fbb2U, 0x52a4f1aaU, 0x53a6f7a2U,
    0x54a8e59aU, 0x55aae392U, 0x56ace98aU, 0x57aeef82U,
    0x58b0cdfaU, 0x59b2cbf2U, 0x5ab4c1eaU, 0x5bb6c7e2U,
    0x5cb8d5daU, 0x5dbad3d2U, 0x5ebcd9caU, 0x5fbedfc2U,
    0x60c05d27U, 0x61c25b2fU, 0x62c45137U, 0x63c6573fU,
    0x64c84507U, 0x65ca430fU, 0x66cc4917U, 0x67ce4f1fU,
    0x68d06d67U, 0x69d26b6fU, 0x6ad46177U, 0x6bd6677fU,
    0x6cd87547U, 0x6dda734fU, 0x6edc7957U, 0x6fde7f5fU,
    0x70e03da7U, 0x71e23bafU, 0x72e431b7U, 0x73e637bfU,
    0x74e82587U, 0x75ea238fU, 0x76ec2997U, 0x77ee2f9fU,
    0x78f00de7U, 0x79f20befU, 0x7af401f7U, 0x7bf607ffU,
    0x7cf815c7U, 0x7dfa13cfU, 0x7efc19d7U, 0x7ffe1fdfU,
    0x801d2774U, 0x811f217cU, 0x82192b64U, 0x831b2d6cU,
    0x84153f54U, 0x8517395cU, 0x86113344U, 0x8713354cU,
    0x880d1734U, 0x890f113cU, 0x8a091b24U, 0x8b0b1d2cU,
    0x8c050f14U, 0x8d07091cU, 0x8e010304U, 0x8f03050cU,
    0x903d47f4U, 0x913f41fcU, 0x92394be4U, 0x933b4decU,
    0x94355fd4U, 0x953759dcU, 0x963153c4U, 0x973355ccU,
    0x982d77b4U, 0x992f71bcU, 0x9a297ba4U, 0x9b2b7dacU,
    0x9c256f94U, 0x9d27699cU, 0x9e216384U, 0x9f23658cU,
    0xa05de769U, 0xa15fe161U, 0xa259eb79U, 0xa35bed71U,
    0xa455ff49U, 0xa557f941U, 0xa651f359U, 0xa753f551U,
    0xa84dd729U, 0xa94fd121U, 0xaa49db39U, 0xab4bdd31U,
    0xac45cf09U, 0xad47c901U, 0xae41c319U, 0xaf43c511U,
    0xb07d87e9U, 0xb17f81e1U, 0xb2798bf9U, 0xb37b8df1U,
    0xb4759fc9U, 0xb57799c1U, 0xb67193d9U, 0xb77395d1U,
    0xb86db7a9U, 0xb96fb1a1U, 0xba69bbb9U, 0xbb6bbdb1U,
    0xbc65af89U, 0xbd67a981U, 0xbe61a399U, 0xbf63a591U,
    0xc09dba4eU, 0xc19fbc46U, 0xc299b65eU, 0xc39bb056U,
    0xc495a26eU, 0xc597a466U, 0xc691ae7eU, 0xc793a876U,
    0xc88d8a0eU, 0xc98f8c06U, 0xca89861eU, 0xcb8b8016U,
    0xcc85922eU, 0xcd879426U, 0xce819e3eU, 0xcf839836U,
    0xd0bddaceU, 0xd1bfdcc6U, 0xd2b9d6deU, 0xd3bbd0d6U,
    0xd4b5c2eeU, 0xd5b7c4e6U, 0xd6b1cefeU, 0xd7b3c8f6U,
    0xd8adea8eU, 0xd9afec86U, 0xdaa9e69eU, 0xdbabe096U,
    0xdca5f2aeU, 0xdda7f4a6U, 0xdea1febeU, 0xdfa3f8b6U,
    0xe0dd7a53U, 0xe1df7c5bU, 0xe2d97643U, 0xe3db704bU,
    0xe4d56273U, 0xe5d7647bU, 0xe6d16e63U, 0xe7d3686bU,
    0xe8cd4a13U, 0xe9cf4c1bU, 0xeac94603U, 0xebcb400bU,
    0xecc55233U, 0xedc7543bU, 0xeec15e23U, 0xefc3582bU,
    0xf0fd1ad3U, 0xf1ff1cdbU, 0xf2f916c3U, 0xf3fb10cbU,
    0xf4f502f3U, 0xf5f704fbU, 0xf6f10ee3U, 0xf7f308ebU,
    0xf8ed2a93U, 0xf9ef2c9bU, 0xfae92683U, 0xfbeb208bU,
    0xfce532b3U, 0xfde734bbU, 0xfee13ea3U, 0xffe338abU,
};


/** Table of constants needed by some Anubis functions */
const u32 ANUBIS_RC[] = {
    0xa7d3e671U, 0xd0ac4d79U, 0x3ac991fcU, 0x1e4754bdU,
    0x8ca57afbU, 0x63b8ddd4U, 0xe5b3c5beU, 0xa9880ca2U,
    0x39df29daU, 0x2ba8cb4cU, 0x4b22aa24U, 0x4170a6f9U,
    0x5ae2b036U, 0x7de433ffU, 0x6020088bU, 0x5eab7f78U,
    0x7c2c57d2U, 0xdc6d7e0dU, 0x5394c328U,
};


/* FUNCTIONS */


/** Return a random integer */
int randomint(void) {
#   ifdef OSPOSIX
    struct timeval tmstrct;
    gettimeofday(&tmstrct, NULL);
    srand((unsigned int)(tmstrct.tv_usec * tmstrct.tv_sec));
#   else
    srand((unsigned int)time(NULL) * (unsigned int)clock());
#   endif
    return (int)rand();
}


/** Return a random unsigned long int */
ulint randomlong(void) {
#   ifdef OSPOSIX
    struct timeval tmstrct;
    gettimeofday(&tmstrct, NULL);
    srand((unsigned int)((ulint)tmstrct.tv_usec ^ ((ulint)tmstrct.tv_usec * (ulint)tmstrct.tv_sec)));
#   else
    srand((unsigned int)(((ulint)time(NULL) + 0x01) | ((ulint)time(NULL) * (ulint)clock())));
#   endif
    ulint rand_num1 = (ulint)rand();
#   ifdef OSPOSIX
    gettimeofday(&tmstrct, NULL);
    srand((unsigned int)((ulint)tmstrct.tv_usec ^ ((ulint)tmstrct.tv_usec * (ulint)tmstrct.tv_sec)));
#   else
    srand((unsigned int)((((ulint)time(NULL) + 0x01) % ((ulint)clock() + 0x01)) | ((ulint)time(NULL) * (ulint)clock())));
#   endif
    ulint rand_num2 = (ulint)rand();
#   ifdef OSPOSIX
    gettimeofday(&tmstrct, NULL);
    srand((unsigned int)((ulint)tmstrct.tv_usec ^ ((ulint)tmstrct.tv_usec * (ulint)tmstrct.tv_sec)));
#   else
    srand((unsigned int)((((ulint)time(NULL) + 0x01) % ((ulint)clock() + 0x01)) | ((ulint)time(NULL) * (ulint)clock())));
#   endif
    return (ulint)((rand_num1 * (ulint)rand()) ^ rand_num2);
}


/** Return a random string with the specified length; remember to `free()` random_string */
char *randstr(const size_t length) {
    char *random_string;
    if (length) {
        random_string = (char *)calloc((length + (size_t)1), sizeof(char));
        if (random_string == (char *)NULL) { return (char *)NULL; }
#       ifdef OSPOSIX
        struct timeval tmstrct;
        gettimeofday(&tmstrct, NULL);
        srand((unsigned int)(tmstrct.tv_usec * tmstrct.tv_sec));
#       else
        srand((unsigned int)time(NULL) * (unsigned int)clock());
#       endif
        static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789<>,.?~`!@#$%^&*()-_+=[]{}|':;";
        register ulint i;
        for (i = 0x00; i < length; ++i) random_string[i] = charset[(int)(rand() % 91)];
    } else { return (char *)NULL; }
    random_string[length] = '\0';
    return random_string;
}


/** Return a random alphabetic string with the specified length; remember to `free()` random_string */
char *randalphastr(const size_t length) {
    char *random_string;
    if (length) {
        random_string = (char *)calloc((length + (size_t)1), sizeof(char));
        if (random_string == (char *)NULL) { return (char *)NULL; }
#       ifdef OSPOSIX
        struct timeval tmstrct;
        gettimeofday(&tmstrct, NULL);
        srand((unsigned int)(tmstrct.tv_usec * tmstrct.tv_sec));
#       else
        srand((unsigned int)time(NULL) * (unsigned int)clock());
#       endif
        static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        register ulint i;
        for (i = 0x00; i < length; ++i) random_string[i] = charset[(rand() % 52)];
    } else { return (char *)NULL; }
    random_string[length] = '\0';
    return random_string;
}


/** Return a random alphanumeric string with the specified length; remember to `free()` random_string */
char *randalphanumstr(const size_t length) {
    char *random_string;
    if (length) {
        random_string = (char *)calloc((length + (size_t)1), sizeof(char));
        if (random_string == (char *)NULL) { return (char *)NULL; }
#       ifdef OSPOSIX
        struct timeval tmstrct;
        gettimeofday(&tmstrct, NULL);
        srand((unsigned int)(tmstrct.tv_usec * tmstrct.tv_sec));
#       else
        srand((unsigned int)time(NULL) * (unsigned int)clock());
#       endif
        static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        register ulint i;
        for (i = 0x00; i < length; ++i) random_string[i] = charset[(rand() % 62)];
    } else { return (char *)NULL; }
    random_string[length] = '\0';
    return random_string;
}


/** Return a random string with the specified length; supports larger strings; remember to `free()` random_string */
char *randstrx(const uint64_t length) {
    char *random_string;
    if (length) {
        random_string = (char *)calloc((size_t)(length + (uint64_t)0x01), sizeof(char));
        if (random_string == (char *)NULL) { return (char *)NULL; }
#       ifdef OSPOSIX
        struct timeval tmstrct;
        gettimeofday(&tmstrct, NULL);
        srand((unsigned int)((ulint)tmstrct.tv_usec % ((ulint)tmstrct.tv_usec * (ulint)tmstrct.tv_sec)));
#       else
        srand((unsigned int)(((ulint)time(NULL)) % ((ulint)time(NULL) * (ulint)clock())));
#       endif
        static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 \"\n\t<>,.?/~`!@#$%^&*()-_+=[]{}|\\':;";
        register uint64_t i;
        for (i = (uint64_t)0x00; i < length; ++i) {
            random_string[i] = charset[(rand() % 97)];
        }
    } else { return (char *)NULL; }
    random_string[length] = '\0';
    return random_string;
}


/** Return a random 16384-bit string; remember to `free()` random_string */
char *rand16384str(void) {
    char *random_string;
    random_string = (char *)calloc((size_t)16384, sizeof(char));
    if (random_string == (char *)NULL) { return (char *)NULL; }
#   ifdef OSPOSIX
    struct timeval tmstrct;
    gettimeofday(&tmstrct, NULL);
    srand((unsigned int)((ulint)tmstrct.tv_usec | ((ulint)tmstrct.tv_usec * (ulint)tmstrct.tv_sec)));
#   else
    srand((unsigned int)((((ulint)time(NULL) + 0x01) / ((ulint)clock() + 0x01)) | ((ulint)time(NULL) * (ulint)clock())));
#   endif
    static const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 \"\n\t<>,.?/~`!@#$%^&*()-_+=[]{}|\\':;";
    register uint32_t i;
    for (i = 0x00; i < 16384; ++i) {
        random_string[i] = charset[(rand() % 97)];
    }
    return random_string;
}


/** Change the endianness of an 8-bit integer */
uint8_t endianswap8(uint8_t x) {
    return ((uint8_t)(x << (uint8_t)0x4) | (uint8_t)(x >> (uint8_t)0x4));
}


/** Change the endianness of a 16-bit integer */
uint16_t endianswap16(uint16_t x) {
    return ((uint16_t)(x << (uint16_t)0x8) | (uint16_t)(x >> (uint16_t)0x8));
}


/** Change the endianness of a 32-bit integer */
uint32_t endianswap32(uint32_t x) {
    return ((x >> 0x18) | ((x >> 0x8) & 0xFF00u) | ((x << 0x8) & 0xFF0000u) | (x << 0x18));
}


/** Change the endianness of a 64-bit integer */
uint64_t endianswap64(uint64_t x) {
#   ifdef INTEL
    register uint64_t y;
    __asm__ ("bswap %q0" : "=r" (y) : "0" (x));
    return y;
#   else
    return (((x & 0xFF00000000000000ull) >> 0x38) | ((x & 0x00FF000000000000ull) >> 0x28) | ((x & 0x0000FF0000000000ull) >> 0x18) | ((x & 0x000000FF00000000ull) >> 0x8) | ((x & 0x00000000FF000000ull) << 0x8) | ((x & 0x0000000000FF0000ull) << 0x18) | ((x & 0x000000000000FF00ull) << 0x28) | ((x & 0x00000000000000FFull) << 0x38));
    //return (((((x >> 0x18) | ((x >> 0x8) & 0xFF00u) | ((x << 0x8) & 0xFF0000u) | (x << 0x18)) + 0x0ull) << 0x20) | ((x >> 0x38) | ((x >> 0x28) & 0xFF00u) | ((x << 0x28) & 0xFF0000u) | (x << 0x38)));
#   endif
}


/** Shuffle the int array; must have multiple array items and initialize srand() */
void shuffle_int(signed int *__restrict__ array, const size_t num_items) {
    if (num_items > (size_t)0x02) {
        register size_t i, j;
        register signed int t;
        for (i = 0x00; i < (num_items - 0x01); ++i) {
            j = (i + (size_t)(((size_t)rand() + 0x01) / ((size_t)RAND_MAX / (num_items - i) + 0x01)));
            t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}


/** Shuffle the uint32_t array; must have multiple array items and initialize srand() */
void shuffle_uint32(uint32_t *__restrict__ array, const uint32_t num_items) {
    if (num_items > (uint32_t)0x02) {
        register uint32_t i, j, t;
        for (i = 0x00; i < (num_items - (uint32_t)0x01); ++i) {
            j = (i + (((uint32_t)rand() + 0x01) / (uint32_t)(RAND_MAX / (num_items - i) + (uint32_t)0x01)));
            t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}


#if (defined(__x86_64__) || defined(__x86_64) || defined(__amd64__))
/** Rotate the byte to the left `num` times */
void byte_rotl(uint8_t byte, const uint8_t num) {
    __asm__ (  // AT&T Style Assembly
        "rol %1,%2;"
        : "=r" ( byte )  // %0: Output to C variable
        : "r" ( num ), "r" ( byte )  // %1 & %2: Input C variable
        :  // Clobbered Register
    );
}


/** Rotate the byte to the right `num` times */
void byte_rotr(uint8_t byte, const uint8_t num) {
    __asm__ (  // AT&T Style Assembly
        "ror %1,%2;"
        : "=r" ( byte )  // %0: Output to C variable
        : "r" ( num ), "r" ( byte )  // %1 & %2: Input C variable
        :  // Clobbered Register
    );
}


#else


/** Rotate the byte to the left `num` times */
void byte_rotl(uint8_t byte, const uint8_t num) {
    byte = (uint8_t)((uint8_t)(byte << (num & (uint8_t)0x07)) | (uint8_t)(byte >> ((-(num & (uint8_t)0x07)) & 0x07)));
}


/** Rotate the byte to the right `num` times */
void byte_rotr(uint8_t byte, const uint8_t num) {
    byte = (uint8_t)((uint8_t)(byte >> (num & (uint8_t)0x07)) | (uint8_t)(byte << ((-(num & (uint8_t)0x07)) & 0x07)));
}
#endif


/** Rotate an array to the left in-place */
void array_rotl(uint8_t *__restrict__ array, const size_t len, const uint32_t num_shifts) {
    if ((len > 0x02) && (num_shifts != 0x00)) {
        register uint32_t i, j;
        register uint8_t first;
        for (i = num_shifts; i != 0x00; --i) {
            first = array[0x00];
            for (j = 0x00; j < (uint32_t)(len - 0x01); ++j) array[j] = array[j + 0x01];
            array[j] = first;
        }
    }
}


/** Rotate an array to the left; supports larger arrays */
void array_rotl64(uint8_t *__restrict__ array, const uint64_t len, const uint64_t num_shifts) {
    if ((len > 0x02) && (num_shifts != 0x00)) {
        register uint64_t i, j;
        register uint8_t first;
        for (i = num_shifts; i != 0x00; --i) {
            first = array[0x00];
            for (j = 0x00; j < (len - 0x01); ++j) array[j] = array[j + 0x01];
            array[j] = first;
        }
    }
}


/** Rotate an array to the right in-place */
void array_rotr(uint8_t *__restrict__ array, const size_t len, const uint32_t num_shifts) {
    if ((len > 0x02) && (num_shifts != 0x00)) {
        register uint32_t i, j;
        register uint8_t last;
        for (i = num_shifts; i != 0x00; --i) {
            last = array[len - 0x01];
            for (j = (uint32_t)len; --j;) array[j] = array[j - 0x01];
            array[0x00] = last;
        }
    }
}


/** Rotate an array to the right; supports larger arrays */
void array_rotr64(uint8_t *__restrict__ array, const uint64_t len, const uint64_t num_shifts) {
    if ((len > 0x02) && (num_shifts != 0x00)) {
        register uint64_t i, j;
        register uint8_t last;
        for (i = num_shifts; i != 0x00; --i) {
            last = array[len - 0x01];
            for (j = len; --j;) array[j] = array[j - 0x01];
            array[0x00] = last;
        }
    }
}


/** Rotate a char array to the left in-place */
void chararray_rotl(char *__restrict__ array, const size_t len, const uint32_t num_shifts) {
    if ((len > 0x02) && (num_shifts != 0x00)) {
        register uint32_t i, j;
        register char first;
        for (i = num_shifts; i != 0x00; --i) {
            first = array[0x00];
            for (j = 0x00; j < (uint32_t)(len - 0x01); ++j) array[j] = array[j + 0x01];
            array[j] = first;
        }
    }
}


/** Rotate a char array to the left; supports larger arrays */
void chararray_rotl64(char *__restrict__ array, const uint64_t len, const uint64_t num_shifts) {
    if ((len > 0x02) && (num_shifts != 0x00)) {
        register uint64_t i, j;
        register char first;
        for (i = num_shifts; i != 0x00; --i) {
            first = array[0x00];
            for (j = 0x00; j < (len - 0x01); ++j) array[j] = array[j + 0x01];
            array[j] = first;
        }
    }
}


/** Rotate a char array to the right in-place */
void chararray_rotr(char *__restrict__ array, const size_t len, const uint32_t num_shifts) {
    if ((len > 0x02) && (num_shifts != 0x00)) {
        register uint32_t i, j;
        register char last;
        for (i = num_shifts; i != 0x00; --i) {
            last = array[len - 0x01];
            for (j = (uint32_t)len; --j;) { array[j] = array[j - 0x01]; }
            array[0x00] = last;
        }
    }
}


/** Rotate a char array to the right; supports larger arrays */
void chararray_rotr64(char *__restrict__ array, const uint64_t len, const uint64_t num_shifts) {
    if ((len > 0x02) && (num_shifts != 0x00)) {
        register uint64_t i, j;
        register char last;
        for (i = num_shifts; i != 0x00; --i) {
            last = array[len - 0x01];
            for (j = len; --j;) { array[j] = array[j - 0x01]; }
            array[0x00] = last;
        }
    }
}


/** Encrypt a string using a weak and insecure Caesar Cipher */
void caesar_cipher(char *__restrict__ data, const ulint shift) {
    if (shift != 0x00) {
        register size_t i;
        for (i = strlenx(data); --i;) { data[i] = (char)((ulint)data[i] + shift); }
    }
}


/** Decrypt a string using a Caesar Cipher */
void decrypt_caesar_cipher(char *__restrict__ data, const ulint shift) {
    if (shift != 0x00) {
        register size_t i;
        for (i = strlenx(data); --i;) { data[i] = (char)((ulint)data[i] - shift); }
    }
}


/** Encrypt/Decrypt a string using an XOR Cipher */
void xor_cipher(char *__restrict__ data, const char *__restrict__ password) {
    register size_t i, j = 0x00;
    register const size_t pswdlen = strlenx(password);
    for (i = strlenx(data); --i;) {
        if (j < pswdlen) { ++j; }
        else { j = 0x00; }
        data[i] ^= password[j];
    }
}


/** Encrypt/Decrypt a string using an NXOR Cipher */
void nxor_cipher(char *__restrict__ data, const char *__restrict__ password) {
    register size_t i, j = 0x00;
    register const size_t pswdlen = strlenx(password);
    for (i = strlenx(data); --i;) {
        if (j < pswdlen) { ++j; }
        else { j = 0x00; }
        data[i] = (char)(~(data[i] ^ password[j]));
    }
}


/** Tiny Encryption Algorithm: Encrypt an array of two `uint32`s using an array of four `uint32`s */
void tea_cipher(uint32_t *__restrict__ v, const uint32_t *__restrict__ k) {
    const uint32_t delta = 0x9e3779b9;  // Key schedule constant
    const uint32_t k0 = k[0], k1 = k[1], k2 = k[2], k3 = k[3];  // Cache key
    register uint32_t v0 = v[0], v1 = v[1], sum = 0x00, i;
    for (i = 0x00; i < 32; ++i) {  // Basic cycle start
        sum += delta;
        v0 += (((v1 << 4) + k0) ^ (v1 + sum) ^ ((v1 >> 5) + k1));
        v1 += (((v0 << 4) + k2) ^ (v0 + sum) ^ ((v0 >> 5) + k3));
    }
    v[0] = v0;
    v[1] = v1;
}


/** Tiny Encryption Algorithm: Decrypt an array of two `uint32`s using an array of four `uint32`s */
void decrypt_tea_cipher(uint32_t *__restrict__ v, const uint32_t *__restrict__ k) {
    const uint32_t delta = 0x9e3779b9;  // Key schedule constant
    const uint32_t k0 = k[0], k1 = k[1], k2 = k[2], k3 = k[3];  // Cache key
    register uint32_t v0 = v[0], v1 = v[1], sum = 0xC6EF3720, i;
    for (i = 0x00; i < 32; ++i) {  // Basic cycle start
        v1 -= (((v0 << 4) + k2) ^ (v0 + sum) ^ ((v0 >> 5) + k3));
        v0 -= (((v1 << 4) + k0) ^ (v1 + sum) ^ ((v1 >> 5) + k1));
        sum -= delta;
    }
    v[0] = v0;
    v[1] = v1;
}


/** Extended Tiny Encryption Algorithm: Encrypt an array of two `uint32`s using an array of four `uint32`s */
void xtea_cipher(const uint32_t num_rounds, uint32_t v[2], const uint32_t key[4]) {
    const uint32_t delta = 0x9E3779B9;
    register uint32_t i, v0 = v[0], v1 = v[1], sum = 0x00;
    for (i = 0x00; i < num_rounds; ++i) {
        v0 += ((((v1 << 4) ^ (v1 >> 5)) + v1) ^ (sum + key[sum & 3]));
        sum += delta;
        v1 += ((((v0 << 4) ^ (v0 >> 5)) + v0) ^ (sum + key[(sum >> 11) & 3]));
    }
    v[0] = v0;
    v[1] = v1;
}


/** Extended Tiny Encryption Algorithm: Decrypt an array of two `uint32`s using an array of four `uint32`s */
void decrypt_xtea_cipher(const uint32_t num_rounds, uint32_t v[2], const uint32_t key[4]) {
    const uint32_t delta = 0x9E3779B9;
    register uint32_t i, v0 = v[0], v1 = v[1], sum = (delta * num_rounds);
    for (i = 0x00; i < num_rounds; ++i) {
        v1 -= ((((v0 << 4) ^ (v0 >> 5)) + v0) ^ (sum + key[(sum >> 11) & 3]));
        sum -= delta;
        v0 -= ((((v1 << 4) ^ (v1 >> 5)) + v1) ^ (sum + key[sum & 3]));
    }
    v[0] = v0;
    v[1] = v1;
}


/** Corrected Block TEA: Encrypt/Decrypt an array of `num_items` `uint32_t`s using a four `uint32_t` key */
void xxtea_cipher(uint32_t *__restrict__ v, const int32_t num_items, const uint32_t key[4]) {
    register uint32_t e, p, y, z, sum, rounds;
#   define DELTA   (((uint32_t)0x9e3779b9))
#   define MX   (((((z >> 5) ^ y << 2) + ((y >> 3) ^ z << 4)) ^ ((sum ^ y) + (key[(p & 3) ^ e] ^ z))))
    if (num_items > 1) {  // Encode
        uint32_t u_num_items = (uint32_t)num_items;
        rounds = (6 + (52 / u_num_items));
        sum = 0x00;
        z = v[u_num_items - 1];
        do {
            sum += DELTA;
            e = ((sum >> 2) & 3);
            for (p = 0x00; p < (u_num_items - 1); ++p) {
                y = v[p + 1];
                v[p] += MX;
                z = v[p];
            }
            y = v[0];
            v[u_num_items - 1] += MX;
            z = v[u_num_items - 1];
        } while (--rounds);
    } else if (num_items < -1) {  // Decode
        uint32_t u_num_items = (uint32_t)(-num_items);
        rounds = (6 + (52 / (uint32_t)u_num_items));
        sum = (rounds * (DELTA));
        y = v[0];
        do {
            e = (uint32_t)((sum >> 2) & 3);
            for (p = ((uint32_t)(u_num_items) - 1); p--;) {
                z = v[p - 1];
                v[p] = (uint32_t)(v[p] - (uint32_t)(MX));
                y = v[p];
            }
            z = v[u_num_items - 1];
            v[0] = (uint32_t)(v[0] - (uint32_t)(MX));
            y = v[0];
            sum = (uint32_t)(sum - (uint32_t)(DELTA));
        } while (--rounds);
    }
}


/** Treyfer Encryption */
void treyfer_cipher(uint8_t text[8], const uint8_t key[8]) {
    register uint8_t r, i;
#   define TREYFER_ROTL(x)   ((uint8_t)(((x) << (uint8_t)1) | ((x) >> (uint8_t)7)))
    for (r = 0x00; r < (uint8_t)(TREYFER_NUMROUNDS); r++) {
        text[8] = text[0];
        for (i = 0x00; i < 8; i++) {
            text[i + 1] = TREYFER_ROTL(((text[i + 1] + Sbox[(key[i] + text[i]) & (uint8_t)0xFF])));
        }
        text[0x00] = text[8];
    }
}


/** Treyfer Decryption */
void decrypt_treyfer_cipher(uint8_t text[8], const uint8_t key[8]) {
    register uint8_t i, r;
    for (r = 0x00; r < (uint8_t)(TREYFER_NUMROUNDS); r++) {
        text[8] = text[0];
        for (i = 7; i--;) {
            text[i + 1] = ((uint8_t)((uint8_t)((text[i + 1] >> (uint8_t)1) | (text[i + 1] << (uint8_t)7)) - (uint8_t)Sbox[(key[i] + text[i]) & (uint8_t)0xFF]));
        }
        text[0x00] = text[8];
    }
}


/**
    Quaternion Byte Cipher (Encryption) that uses a 32-byte key
    @param[in] data    The data to encrypt
    @param[in] datasize    The number of bytes in the data array (not counting the NULL terminator)
    @param[in] key    Encryption key
*/
void quaternion_encryption32(uint8_t *__restrict__ data, const uint32_t datasize, const uint8_t *__restrict__ key) {
    quaternion_crypt_byte qbyte;
    register uint32_t i = 0x0, j = 0x0;
    while (i != datasize) {
        if (j < 32) { j += 8; }
        else { j = 0x0; }
        qbyte = (quaternion_crypt_byte){
            (uint8_t)(key[((j + 1) + (j + 1)) % 31] ^ (uint8_t)key[j + 4]),
            (uint8_t)(key[j] ^ (~key[j + 5])),
            (uint8_t)(key[j + 7] ^ (uint8_t)key[j + 2]),
            (uint8_t)(key[j + 3] ^ key[j + 1])
        };
        data[i] ^= qbyte.i;
        data[i] ^= qbyte.j;
        byte_rotr((uint8_t)data[i], (uint8_t)((qbyte.j ^ key[j + 6]) % 0xFF));
        data[i] ^= qbyte.R;
        data[i] ^= qbyte.k;
        ++i;
    }
    data[datasize] = '\0';
}


/**
    Quaternion Byte Cipher (Decryption) that uses a 32-byte key
    @param[in] data    The data to decrypt
    @param[in] datasize    The number of bytes in the data array (not counting the NULL terminator)
    @param[in] key    Decryption key
*/
void quaternion_decryption32(uint8_t *__restrict__ data, const uint32_t datasize, const uint8_t *__restrict__ key) {
    quaternion_crypt_byte qbyte;
    register uint32_t i = 0x0, j = 0x0;
    while (i != datasize) {
        if (j < 32) { j += 8; }
        else { j = 0x0; }
        qbyte = (quaternion_crypt_byte){
            (uint8_t)(key[((j + 1) + (j + 1)) % 31] ^ (uint8_t)key[j + 4]),
            (uint8_t)(key[j] ^ (~key[j + 5])),
            (uint8_t)(key[j + 7] ^ (uint8_t)key[j + 2]),
            (uint8_t)(key[j + 3] ^ key[j + 1])
        };
        data[i] ^= qbyte.k;
        data[i] ^= qbyte.R;
        byte_rotl((uint8_t)data[i], (uint8_t)((qbyte.j ^ key[j + 6]) % 0xFF));
        data[i] ^= qbyte.j;
        data[i] ^= qbyte.i;
        ++i;
    }
    data[datasize] = '\0';
}


/**
    Quaternion Byte Cipher (Encryption) that uses a 64-byte key
    @param[in] data    The data to encrypt
    @param[in] datasize    The number of bytes in the data array (not counting the NULL terminator)
    @param[in] key    Encryption key
*/
void quaternion_encryption64(uint8_t *__restrict__ data, const uint32_t datasize, const uint8_t *__restrict__ key) {
    quaternion_crypt_byte qbyte;
    register uint32_t i = 0x0, j = 0x0;
    while (i != datasize) {
        if (j < 64) { j += 8; }
        else { j = 0x0; }
        qbyte = (quaternion_crypt_byte){
            (uint8_t)(key[((j + 1) + (j + 1)) % 63] ^ (uint8_t)key[j + 4]),
            (uint8_t)(key[j] ^ (~key[j + 5])),
            (uint8_t)(key[j + 7] ^ (uint8_t)key[j + 2]),
            (uint8_t)(key[j + 3] ^ key[j + 1])
        };
        data[i] ^= qbyte.i;
        data[i] ^= qbyte.j;
        byte_rotr((uint8_t)data[i], (uint8_t)((qbyte.j ^ key[j + 6]) % 0xFF));
        data[i] ^= qbyte.R;
        data[i] ^= qbyte.k;
        ++i;
    }
    data[datasize] = '\0';
}


/**
    Quaternion Byte Cipher (Decryption) that uses a 64-byte key
    @param[in] data    The data to decrypt
    @param[in] datasize    The number of bytes in the data array (not counting the NULL terminator)
    @param[in] key    Decryption key
*/
void quaternion_decryption64(uint8_t *__restrict__ data, const uint32_t datasize, const uint8_t *__restrict__ key) {
    quaternion_crypt_byte qbyte;
    register uint32_t i = 0x0, j = 0x0;
    while (i != datasize) {
        if (j < 64) { j += 8; }
        else { j = 0x0; }
        qbyte = (quaternion_crypt_byte){
            (uint8_t)(key[((j + 1) + (j + 1)) % 63] ^ (uint8_t)key[j + 4]),
            (uint8_t)(key[j] ^ (~key[j + 5])),
            (uint8_t)(key[j + 7] ^ (uint8_t)key[j + 2]),
            (uint8_t)(key[j + 3] ^ key[j + 1])
        };
        data[i] ^= qbyte.k;
        data[i] ^= qbyte.R;
        byte_rotl((uint8_t)data[i], (uint8_t)((qbyte.j ^ key[j + 6]) % 0xFF));
        data[i] ^= qbyte.j;
        data[i] ^= qbyte.i;
        ++i;
    }
    data[datasize] = '\0';
}


/** Return the parity of the given data */
uint8_t bitparity(const uint32_t data) {
    register uint32_t x = (data ^ (data >> 0x10));
    x = (x ^ (x >> 0x8));
    x = (x ^ (x >> 0x4));
    return (uint8_t)((0x6996 >> (x & 0xF)) & 0x1);
}


/** Return the parity of the given data */
uint8_t bitparity64(const uint64_t data) {
    register uint64_t x = (data ^ (data >> 0x10));
    x = (x ^ (x >> 0x8));
    x = (x ^ (x >> 0x4));
    return (uint8_t)((0x6996 >> (x & 0xF)) & 0x1);
}


#ifdef UINT128_SUPPORTED
/** Return the parity of the given data */
uint8_t bitparity128(const uint128_t data) {
    register uint128_t x = (data ^ (data >> 0x10));
    x = (x ^ (x >> 0x8));
    x = (x ^ (x >> 0x4));
    return (uint8_t)((0x6996 >> (x & 0xF)) & 0x1);
}
#endif


/** Return the CRC8 value for the given byte array (`data`), given length */
uint8_t crc8(const uint8_t *__restrict__ data, size_t len) {
    register uint8_t x, crc = 0xFF;
    while (len--) {
        x = crc >> 4 ^ *data++;
        x ^= (x >> 2);
        crc = (uint8_t)(((uint8_t)(crc << 4)) ^ ((uint8_t)(x << 6)) ^ ((uint8_t)(x << 3)) ^ (uint8_t)x);
    }
    return crc;
}


/** Return the CRC8 value for the given byte array (`data`) */
uint8_t crc8x(const uint8_t *__restrict__ data) {
    register uint8_t x, crc = 0xFF;
    register size_t len = strlenx_uint8(data);
    while (len--) {
        x = crc >> 4 ^ *data++;
        x ^= (x >> 2);
        crc = (uint8_t)(((uint8_t)(crc << 4)) ^ ((uint8_t)(x << 6)) ^ ((uint8_t)(x << 3)) ^ (uint8_t)x);
    }
    return crc;
}


/** Return the CRC8 value for the given byte array (`data`), given length */
uint8_t crc8portable(const uint8_t *__restrict__ data, const uint32_t len) {
    register uint8_t remainder = 0x0;
    register uint32_t i;
    for (i = 0x0; i < len; ++i) {  // Perform modulo-2 division, one byte at a time
        remainder ^= data[i];
        for (uint8_t bit = 0x9; --bit;) {
            if (remainder & 0x80) { remainder = (uint8_t)(((uint8_t)(remainder << 1)) ^ 0xD8); }
            else { remainder = (uint8_t)(remainder << 1); }
        }
    }
    return remainder;
}


/** Return the CRC16 value for the given byte array (`data`), given length */
uint16_t crc16(const uint8_t *__restrict__ data, size_t len) {
    register uint8_t x;
    register uint16_t crc = 0xFFFF;
    while (len--) {
        x = (uint8_t)(crc >> 8 ^ *data++);
        x ^= (x >> 4);
        crc = (uint16_t)(((uint16_t)(crc << 8)) ^ ((uint16_t)(x << 12)) ^ ((uint16_t)(x << 5)) ^ (uint16_t)x);
    }
    return crc;
}


/** Return the CRC16 value for the given byte array (`data`) */
uint16_t crc16x(const uint8_t *__restrict__ data) {
    register uint8_t x;
    register uint16_t crc = 0xFFFF;
    register size_t len = strlenx_uint8(data);
    while (len--) {
        x = (uint8_t)(crc >> 8 ^ *data++);
        x ^= (x >> 4);
        crc = (uint16_t)(((uint16_t)(crc << 8)) ^ ((uint16_t)(x << 12)) ^ ((uint16_t)(x << 5)) ^ (uint16_t)x);
    }
    return crc;
}


/** Return the CRC16 of the data in memory (address and all); `ptr_crc` may be `NULL` or `&var` */
uint16_t crc16mem(const uint16_t *ptr_crc, const uint8_t *data, const uint32_t len) {
    register uint32_t i;
    register uint16_t crc = ((ptr_crc == (uint16_t *)NULL) ? 0xFFFF : *ptr_crc);
    crc = (uint16_t)((crc16_table[((crc >> 8) & 255)] ^ (crc << 8)) ^ (uint16_t)(((size_t)data) % 0xFFFF));
    for (i = 0; i < len; ++i) {
        crc = (uint16_t)((uint16_t)(crc >> 8) | (uint16_t)(crc << 8));
        crc = (uint16_t)(crc ^ (uint16_t)data[i]);
        crc = (uint16_t)(crc ^ (uint16_t)(crc & 0xFF) >> 4);
        crc = (uint16_t)(crc ^ (uint16_t)(crc << 8) << 4);
        crc = (uint16_t)(crc ^ ((crc & 0xFF) << 4) << 1);
    }
    return crc;
}


/** Return the CRC16 of the data in memory (address and all); only specify data location */
uint16_t crc16memx(const uint8_t *data) {
    register uint64_t i;
    register uint16_t crc = (uint16_t)((uint16_t)0x1861 ^ (uint16_t)(((size_t)data) % 0xFFFF));
    register const uint64_t len = (uint64_t)strlenx_uint8(data);
    for (i = 0x00; i < len; ++i) {
        crc = (uint16_t)((uint16_t)(crc >> 0x8) | (uint16_t)(crc << 0x8));
        crc = (uint16_t)(crc ^ (uint16_t)data[i]);
        crc = (uint16_t)(crc ^ (uint16_t)(crc & 0xFF) >> 0x4);
        crc = (uint16_t)(crc ^ (uint16_t)(crc << 0x8) << 0x4);
        crc = (uint16_t)(crc ^ (uint16_t)((crc & 0xFF) << 0x4) << 0x1);
    }
    return crc;
}


/** Return the CRC32 value for the given byte array (`data`), given length */
uint32_t crc32(uint32_t crc, const uint8_t *__restrict__ data, const size_t len) {
    register size_t i;
    for (i = len; i--;) {
        crc = (uint32_t)(crc32_table[*data ^ ((crc >> 24) & 0xFF)] ^ (crc << 8));
        data++;
    }
    return crc;
}


/** Return the CRC32 value for the given byte array (`data`) */
uint32_t crc32x(uint32_t crc, const uint8_t *__restrict__ data) {
    register size_t len;
    for (len = strlenx_uint8(data); len--;) {
        crc = (uint32_t)(crc32_table[*data ^ ((crc >> 24) & 0xFF)] ^ (crc << 8));
        data++;
    }
    return crc;
}


#ifdef INTEL64
/** Optimized CRC32 */
uint32_t fastcrc32(char *str, const uint32_t len) {
#   ifdef __clang__
#      pragma GCC diagnostic ignored "-Wcast-align"
#   endif
    register uint32_t q = (len >> 0x2), r = (len & 3), crc = 0x0;
    uint32_t *p = (uint32_t *)str;
    while (q--) {
        __asm__ __volatile__(
            ".byte 0xf2, 0xf, 0x38, 0xf1, 0xf1;"
            :"=S" (crc)
            :"0" (crc), "c" (*p)
        );
        p++;
    }
    str = (char *)p;
    while (r--) {
        __asm__ __volatile__(
            ".byte 0xf2, 0xf, 0x38, 0xf0, 0xf1"
            :"=S" (crc)
            :"0" (crc), "c" (*str)
        );
        str++;
    }
    return crc;

}
#   ifdef __clang__
#      pragma GCC diagnostic warning "-Wcast-align"
#   endif
#endif


/** Return the Adler8 checksum of the given data */
uint8_t adler8(const uint8_t *__restrict__ data, register size_t len) {
    register uint8_t a = 0x1, b = 0x0;
    register size_t index;
    for (index = 0x0; index < len; ++index) {
        a = ((uint8_t)(a + (uint8_t)data[index]) % (uint8_t)0xF);
        b = ((uint8_t)(b + a) % (uint8_t)0xF);
    }
    return (uint8_t)((uint8_t)(b << 4) | a);
}


/** Return the Adler16 checksum of the given data */
uint16_t adler16(const uint8_t *__restrict__ data, register size_t len) {
    register uint16_t a = 0x1, b = 0x0;
    register size_t index;
    for (index = 0x0; index < len; ++index) {
        a = ((uint16_t)(a + (uint16_t)data[index]) % (uint16_t)0xF1);
        b = ((uint16_t)(b + a) % (uint16_t)0xF1);
    }
    return (uint16_t)((uint16_t)(b << 8) | a);
}


/** Return the Adler32 checksum of the given data */
uint32_t adler32(const uint8_t *__restrict__ data, register size_t len) {
    register uint32_t a = 0x1, b = 0x0;
    register size_t index;
    for (index = 0x0; index < len; ++index) {
        a = ((uint32_t)(a + (uint32_t)data[index]) % (uint32_t)0xFFF1);
        b = ((uint32_t)(b + a) % (uint32_t)0xFFF1);
    }
    return (uint32_t)((uint32_t)(b << 16) | a);
}


/** Return the Adler64 checksum of the given data */
uint64_t adler64(const uint8_t *__restrict__ data, register size_t len) {
    register uint64_t a = 0x1, b = 0x0;
    register size_t index;
    for (index = 0x0; index < len; ++index) {
        a = ((uint64_t)(a + (uint64_t)data[index]) % (uint64_t)0xFFFFFFF1);
        b = ((uint64_t)(b + a) % (uint64_t)0xFFFFFFF1);
    }
    return (uint64_t)((uint64_t)(b << 32) | a);
}


/** Return the Anti-Adler64 (decrementing for-loop) checksum of the given data */
uint64_t antiadler64(const uint8_t *__restrict__ data, register size_t len) {
    register uint64_t a = 0x1, b = 0x0;
    register size_t index;
    for (index = len; --index;) {
        a = ((uint64_t)(a + (uint64_t)data[index]) % (uint64_t)0xFFFFFFF1);
        b = ((uint64_t)(b + a) % (uint64_t)0xFFFFFFF1);
    }
    return (uint64_t)((uint64_t)(b << 32) | a);
}


/** Return the Anti-Adler64rev2 (decrementing and re-arranged for-loop) checksum of the given data */
uint64_t antiadler64rev2(const uint8_t *__restrict__ data, register size_t len) {
    register uint64_t a = 0x1, b = 0x0;
    register size_t index;
    for (index = len; --index;) {
        b = ((uint64_t)(b + a) % (uint64_t)0xFFFFFFF1);
        a = ((uint64_t)(a + (uint64_t)data[index]) % (uint64_t)0xFFFFFFF1);
    }
    return (uint64_t)((uint64_t)(b << 32) | a);
}


#ifdef UINT128_SUPPORTED
/** Return the Adler128 checksum of the given data */
uint128_t adler128(const uint8_t *__restrict__ data, register size_t len) {
    register uint128_t a = 0x1, b = 0x0;
    register size_t index;
    for (index = 0x0; index < len; ++index) {
        a = ((uint128_t)(a + (uint128_t)data[index]) % (uint128_t)0xFFFFFFFFFFFFFFF1);
        b = ((uint128_t)(b + a) % (uint128_t)0xFFFFFFFFFFFFFFF1);
    }
    return (uint128_t)((uint128_t)(b << 64) | a);
}
#endif


/** Return the Fletcher8 checksum of the given data */
uint8_t fletcher8(const uint8_t *__restrict__ data, const size_t count) {
    register uint8_t sum1 = 0x0, sum2 = 0x0;
    register size_t index;
    for (index = 0x0; index < count; ++index) {
        sum1 = (uint8_t)((sum1 + (uint8_t)data[index]) % 0xF);
        sum2 = (uint8_t)((sum2 + sum1) % 0xF);
    }
    return (uint8_t)((uint8_t)(sum2 << 4) | sum1);
}


/** Return the Fletcher16 checksum of the given data */
uint16_t fletcher16(const uint8_t *__restrict__ data, const size_t count) {
    register uint16_t sum1 = 0x0, sum2 = 0x0;
    register size_t index;
    for (index = 0x0; index < count; ++index) {
        sum1 = (uint16_t)((sum1 + (uint16_t)data[index]) % 0xFF);
        sum2 = (uint16_t)((sum2 + sum1) % 0xFF);
    }
    return (uint16_t)((uint16_t)(sum2 << 8) | sum1);
}


/** Return the Fletcher16 checksum for the given data (fast alternative) */
uint16_t fletcher16fast(const uint8_t *__restrict__ data, const size_t words) {
    register uint16_t sum1 = 0xFF, sum2 = 0xFF;
    register size_t len, i = words;
    while (i) {
        len = ((i >= 20) ? 20 : i);
        i -= len;
        do {
            sum1 = (uint16_t)(sum1 + *data++);
            sum2 = (uint16_t)(sum2 + sum1);
        } while (--len);
        sum1 = (uint16_t)((uint16_t)(sum1 & 0xFF) + (uint16_t)(sum1 >> (uint16_t)8));
        sum2 = (uint16_t)((uint16_t)(sum2 & 0xFF) + (uint16_t)(sum2 >> (uint16_t)8));
    }
    // Reduce sums to 8 bits
    sum1 = (uint16_t)((uint16_t)(sum1 & 0xFF) + (uint16_t)(sum1 >> (uint16_t)8));
    sum2 = (uint16_t)((uint16_t)(sum2 & 0xFF) + (uint16_t)(sum2 >> (uint16_t)8));
    return (uint16_t)((uint16_t)(sum2 << (uint16_t)8) | sum1);
}


/** Return the Fletcher32 checksum of the given data */
uint32_t fletcher32(const uint16_t *__restrict__ data, const size_t count) {
    register uint32_t sum1 = 0x0, sum2 = 0x0;
    register size_t index;
    for (index = 0x0; index < count; ++index) {
        sum1 = (uint32_t)((sum1 + (uint32_t)data[index]) % 0xFFFF);
        sum2 = (uint32_t)((sum2 + sum1) % 0xFFFF);
    }
    return (uint32_t)((uint32_t)(sum2 << 16) | sum1);
}


/** Return the Fletcher32 checksum for the given data (fast alternative) */
uint32_t fletcher32fast(const uint16_t *__restrict__ data, const size_t words) {
    register uint32_t sum1 = 0xFFFF, sum2 = 0xFFFF;
    register size_t len, i = words;
    while (i) {
        len = ((i >= 359) ? 359 : i);
        i -= len;
        do { sum2 += sum1 += *data++; } while (--len);
        sum1 = ((sum1 & 0xFFFF) + (sum1 >> 0x10));
        sum2 = ((sum2 & 0xFFFF) + (sum2 >> 0x10));
    }
    // Reduce sums to 16 bits
    sum1 = ((uint32_t)(sum1 & 0xFFFF) + (uint32_t)(sum1 >> (uint32_t)0x10));
    sum2 = ((uint32_t)(sum2 & 0xFFFF) + (uint32_t)(sum2 >> (uint32_t)0x10));
    return (uint32_t)((uint32_t)(sum2 << (uint32_t)0x10) | sum1);
}


/** Return the Fletcher64 checksum for the given data */
uint64_t fletcher64(const uint32_t *__restrict__ data, const size_t count) {
    register uint64_t sum1 = 0x0, sum2 = 0x0;
    register size_t index;
    for (index = 0x0; index < count; ++index) {
        sum1 = (uint64_t)((sum1 + (uint64_t)data[index]) % 0xFFFFFFFF);
        sum2 = (uint64_t)((sum2 + sum1) % 0xFFFFFFFF);
    }
    return (uint64_t)((uint64_t)(sum2 << 32) | sum1);
}


/** Return the Fletcher64 checksum for the given string cast as an uint_t */
uint64_t fletcher64char(const uint8_t *__restrict__ data, const size_t count) {
    register uint64_t sum1 = 0x0, sum2 = 0x0;
    register size_t index;
    for (index = 0x0; index < count; ++index) {
        sum1 = (uint64_t)((sum1 + (uint64_t)data[index]) % 0xFFFFFFFF);
        sum2 = (uint64_t)((sum2 + sum1) % 0xFFFFFFFF);
    }
    return (uint64_t)((uint64_t)(sum2 << 32) | sum1);
}


/** Return the Collier32 checksum of the given data */
uint32_t collier32(const uint16_t *__restrict__ data, const size_t count) {
    register uint32_t sum1 = 0x0, sum2 = 0x0;
    register size_t index;
    for (index = count; --index;) {
        sum2 = (uint32_t)((sum2 + sum1) & 0xFFFF);
        sum1 = (uint32_t)((sum1 + (uint32_t)data[index]) & 0xFFFF);
    }
    return (uint32_t)((uint32_t)(sum2 << 0xF) ^ sum1);
}
