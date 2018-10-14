// -*- coding: utf-8-unix; Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-
// vim: set fileencoding=utf-8 filetype=c syntax=c.doxygen fileformat=unix tabstop=4 :
// kate: encoding utf-8; bom off; syntax c; indent-mode cstyle; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
/**
@brief Datatypes & Macros for Character Set Names
@file stringpool.h
@version 2018.10.13
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@section DESCRIPTION
This file defines character-set-name datatypes and macros

@section LICENSE
GNU Lesser General Public License v3
Copyright (c) Devyn Collier Johnson, All rights reserved.

This software is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This software is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this software.
*/


typedef struct stringpool_t {
	char stringpool_str17[sizeof("L6")];
	char stringpool_str18[sizeof("CN")];
	char stringpool_str19[sizeof("L1")];
	char stringpool_str25[sizeof("SJIS")];
	char stringpool_str27[sizeof("L4")];
	char stringpool_str29[sizeof("L5")];
	char stringpool_str30[sizeof("R8")];
	char stringpool_str35[sizeof("L8")];
	char stringpool_str36[sizeof("866")];
	char stringpool_str45[sizeof("L2")];
	char stringpool_str51[sizeof("ISO-IR-6")];
	char stringpool_str54[sizeof("CP866")];
	char stringpool_str60[sizeof("MAC")];
	char stringpool_str64[sizeof("C99")];
	char stringpool_str65[sizeof("ISO-IR-166")];
	char stringpool_str67[sizeof("LATIN6")];
	char stringpool_str70[sizeof("CP154")];
	char stringpool_str71[sizeof("LATIN1")];
	char stringpool_str72[sizeof("ISO646-CN")];
	char stringpool_str78[sizeof("CYRILLIC")];
	char stringpool_str79[sizeof("ISO-IR-14")];
	char stringpool_str84[sizeof("CP1256")];
	char stringpool_str85[sizeof("IBM866")];
	char stringpool_str86[sizeof("HZ")];
	char stringpool_str87[sizeof("LATIN4")];
	char stringpool_str88[sizeof("CP1251")];
	char stringpool_str89[sizeof("ISO-IR-165")];
	char stringpool_str91[sizeof("LATIN5")];
	char stringpool_str92[sizeof("862")];
	char stringpool_str93[sizeof("ISO-IR-126")];
	char stringpool_str95[sizeof("ISO-IR-144")];
	char stringpool_str96[sizeof("CP819")];
	char stringpool_str101[sizeof("MS-CYRL")];
	char stringpool_str103[sizeof("LATIN8")];
	char stringpool_str104[sizeof("CP1254")];
	char stringpool_str105[sizeof("ISO-IR-58")];
	char stringpool_str106[sizeof("CP949")];
	char stringpool_str108[sizeof("CP1255")];
	char stringpool_str110[sizeof("CP862")];
	char stringpool_str111[sizeof("ISO-IR-148")];
	char stringpool_str112[sizeof("PT154")];
	char stringpool_str113[sizeof("LATIN-9")];
	char stringpool_str115[sizeof("ISO-IR-149")];
	char stringpool_str117[sizeof("ISO-IR-159")];
	char stringpool_str118[sizeof("L3")];
	char stringpool_str119[sizeof("ISO-IR-226")];
	char stringpool_str120[sizeof("CP1258")];
	char stringpool_str123[sizeof("LATIN2")];
	char stringpool_str124[sizeof("ISO8859-6")];
	char stringpool_str125[sizeof("ISO-IR-199")];
	char stringpool_str127[sizeof("IBM819")];
	char stringpool_str128[sizeof("ISO8859-1")];
	char stringpool_str130[sizeof("ISO-8859-6")];
	char stringpool_str131[sizeof("ISO_8859-6")];
	char stringpool_str132[sizeof("ISO8859-16")];
	char stringpool_str134[sizeof("ISO-8859-1")];
	char stringpool_str135[sizeof("ISO_8859-1")];
	char stringpool_str136[sizeof("ISO8859-11")];
	char stringpool_str138[sizeof("ISO-8859-16")];
	char stringpool_str139[sizeof("ISO_8859-16")];
	char stringpool_str140[sizeof("CP1252")];
	char stringpool_str141[sizeof("IBM862")];
	char stringpool_str142[sizeof("ISO-8859-11")];
	char stringpool_str143[sizeof("ISO_8859-11")];
	char stringpool_str144[sizeof("ISO8859-4")];
	char stringpool_str145[sizeof("MACCYRILLIC")];
	char stringpool_str146[sizeof("ISO_8859-16:2001")];
	char stringpool_str148[sizeof("ISO8859-5")];
	char stringpool_str149[sizeof("CP1361")];
	char stringpool_str150[sizeof("ISO-8859-4")];
	char stringpool_str151[sizeof("ISO_8859-4")];
	char stringpool_str152[sizeof("ISO8859-14")];
	char stringpool_str153[sizeof("ISO-IR-101")];
	char stringpool_str154[sizeof("ISO-8859-5")];
	char stringpool_str155[sizeof("ISO_8859-5")];
	char stringpool_str156[sizeof("ISO8859-15")];
	char stringpool_str157[sizeof("CP936")];
	char stringpool_str158[sizeof("ISO-8859-14")];
	char stringpool_str159[sizeof("ISO_8859-14")];
	char stringpool_str160[sizeof("ISO8859-8")];
	char stringpool_str161[sizeof("L7")];
	char stringpool_str162[sizeof("ISO-8859-15")];
	char stringpool_str163[sizeof("ISO_8859-15")];
	char stringpool_str164[sizeof("ISO8859-9")];
	char stringpool_str165[sizeof("VISCII")];
	char stringpool_str166[sizeof("ISO-8859-8")];
	char stringpool_str167[sizeof("ISO_8859-8")];
	char stringpool_str168[sizeof("RK1048")];
	char stringpool_str169[sizeof("TCVN")];
	char stringpool_str170[sizeof("ISO-8859-9")];
	char stringpool_str171[sizeof("ISO_8859-9")];
	char stringpool_str172[sizeof("ISO_8859-14:1998")];
	char stringpool_str174[sizeof("ISO_8859-15:1998")];
	char stringpool_str176[sizeof("EUCCN")];
	char stringpool_str177[sizeof("US")];
	char stringpool_str178[sizeof("PTCP154")];
	char stringpool_str180[sizeof("ISO8859-2")];
	char stringpool_str181[sizeof("MS936")];
	char stringpool_str182[sizeof("EUC-CN")];
	char stringpool_str183[sizeof("CHAR")];
	char stringpool_str184[sizeof("CSVISCII")];
	char stringpool_str186[sizeof("ISO-8859-2")];
	char stringpool_str187[sizeof("ISO_8859-2")];
	char stringpool_str189[sizeof("ISO-IR-109")];
	char stringpool_str191[sizeof("L10")];
	char stringpool_str192[sizeof("ASCII")];
	char stringpool_str195[sizeof("UHC")];
	char stringpool_str202[sizeof("ISO-IR-138")];
	char stringpool_str203[sizeof("KOI8-R")];
	char stringpool_str204[sizeof("850")];
	char stringpool_str210[sizeof("CSASCII")];
	char stringpool_str213[sizeof("CP932")];
	char stringpool_str214[sizeof("X0212")];
	char stringpool_str215[sizeof("UCS-4")];
	char stringpool_str216[sizeof("CSKOI8R")];
	char stringpool_str218[sizeof("CP874")];
	char stringpool_str221[sizeof("CSPTCP154")];
	char stringpool_str227[sizeof("MS-ANSI")];
	char stringpool_str228[sizeof("GB2312")];
	char stringpool_str231[sizeof("ISO646-US")];
	char stringpool_str233[sizeof("CSUCS4")];
	char stringpool_str234[sizeof("CP850")];
	char stringpool_str235[sizeof("ISO-IR-110")];
	char stringpool_str236[sizeof("CP950")];
	char stringpool_str241[sizeof("BIG5")];
	char stringpool_str242[sizeof("ISO-2022-CN")];
	char stringpool_str243[sizeof("LATIN10")];
	char stringpool_str244[sizeof("X0201")];
	char stringpool_str245[sizeof("ISO-CELTIC")];
	char stringpool_str246[sizeof("CYRILLIC-ASIAN")];
	char stringpool_str247[sizeof("BIG-5")];
	char stringpool_str248[sizeof("CSISO2022CN")];
	char stringpool_str249[sizeof("ISO-IR-179")];
	char stringpool_str251[sizeof("UCS-2")];
	char stringpool_str252[sizeof("CP1250")];
	char stringpool_str253[sizeof("KOI8-T")];
	char stringpool_str255[sizeof("ROMAN8")];
	char stringpool_str256[sizeof("ISO_8859-10:1992")];
	char stringpool_str257[sizeof("TIS620")];
	char stringpool_str258[sizeof("CSISOLATIN6")];
	char stringpool_str260[sizeof("CSBIG5")];
	char stringpool_str261[sizeof("MACINTOSH")];
	char stringpool_str262[sizeof("CSISOLATIN1")];
	char stringpool_str263[sizeof("TIS-620")];
	char stringpool_str265[sizeof("IBM850")];
	char stringpool_str266[sizeof("CN-BIG5")];
	char stringpool_str268[sizeof("MACROMAN")];
	char stringpool_str269[sizeof("LATIN3")];
	char stringpool_str271[sizeof("ISO-2022-CN-EXT")];
	char stringpool_str276[sizeof("X0208")];
	char stringpool_str277[sizeof("CSISOLATINCYRILLIC")];
	char stringpool_str278[sizeof("CSISOLATIN4")];
	char stringpool_str279[sizeof("GEORGIAN-PS")];
	char stringpool_str281[sizeof("ARMSCII-8")];
	char stringpool_str282[sizeof("CSISOLATIN5")];
	char stringpool_str283[sizeof("CN-GB-ISOIR165")];
	char stringpool_str286[sizeof("CP1253")];
	char stringpool_str291[sizeof("CSIBM866")];
	char stringpool_str293[sizeof("ELOT_928")];
	char stringpool_str294[sizeof("VISCII1.1-1")];
	char stringpool_str299[sizeof("ISO_646.IRV:1991")];
	char stringpool_str300[sizeof("ISO8859-10")];
	char stringpool_str303[sizeof("KSC_5601")];
	char stringpool_str306[sizeof("ISO-8859-10")];
	char stringpool_str307[sizeof("ISO_8859-10")];
	char stringpool_str310[sizeof("GB_1988-80")];
	char stringpool_str312[sizeof("JP")];
	char stringpool_str314[sizeof("CSISOLATIN2")];
	char stringpool_str317[sizeof("ISO-IR-100")];
	char stringpool_str318[sizeof("EUCKR")];
	char stringpool_str319[sizeof("GBK")];
	char stringpool_str322[sizeof("KZ-1048")];
	char stringpool_str324[sizeof("EUC-KR")];
	char stringpool_str326[sizeof("ISO8859-3")];
	char stringpool_str328[sizeof("UTF-16")];
	char stringpool_str330[sizeof("MACTHAI")];
	char stringpool_str332[sizeof("ISO-8859-3")];
	char stringpool_str333[sizeof("ISO_8859-3")];
	char stringpool_str334[sizeof("ISO8859-13")];
	char stringpool_str336[sizeof("CSKZ1048")];
	char stringpool_str340[sizeof("ISO-8859-13")];
	char stringpool_str341[sizeof("ISO_8859-13")];
	char stringpool_str343[sizeof("ISO-10646-UCS-4")];
	char stringpool_str345[sizeof("KS_C_5601-1989")];
	char stringpool_str346[sizeof("HP-ROMAN8")];
	char stringpool_str349[sizeof("CP1133")];
	char stringpool_str352[sizeof("CSISO14JISC6220RO")];
	char stringpool_str353[sizeof("TIS620-0")];
	char stringpool_str355[sizeof("LATIN7")];
	char stringpool_str356[sizeof("UTF-8")];
	char stringpool_str357[sizeof("ISO-IR-57")];
	char stringpool_str361[sizeof("ISO-10646-UCS-2")];
	char stringpool_str363[sizeof("ISO-IR-87")];
	char stringpool_str365[sizeof("ISO-IR-157")];
	char stringpool_str366[sizeof("ISO_8859-4:1988")];
	char stringpool_str368[sizeof("ISO_8859-5:1988")];
	char stringpool_str372[sizeof("CP1257")];
	char stringpool_str374[sizeof("ISO_8859-8:1988")];
	char stringpool_str375[sizeof("US-ASCII")];
	char stringpool_str377[sizeof("ISO-IR-203")];
	char stringpool_str378[sizeof("ISO_8859-9:1989")];
	char stringpool_str381[sizeof("ISO-IR-127")];
	char stringpool_str382[sizeof("UNICODE-1-1")];
	char stringpool_str384[sizeof("ISO-2022-KR")];
	char stringpool_str386[sizeof("MULELAO-1")];
	char stringpool_str387[sizeof("TIS620.2529-1")];
	char stringpool_str388[sizeof("CSUNICODE11")];
	char stringpool_str389[sizeof("ECMA-114")];
	char stringpool_str390[sizeof("CSISO2022KR")];
	char stringpool_str395[sizeof("TCVN5712-1")];
	char stringpool_str401[sizeof("MACICELAND")];
	char stringpool_str405[sizeof("ECMA-118")];
	char stringpool_str406[sizeof("CSHPROMAN8")];
	char stringpool_str408[sizeof("GEORGIAN-ACADEMY")];
	char stringpool_str409[sizeof("UCS-4-INTERNAL")];
	char stringpool_str411[sizeof("GB_2312-80")];
	char stringpool_str412[sizeof("ISO8859-7")];
	char stringpool_str413[sizeof("TCVN-5712")];
	char stringpool_str414[sizeof("ISO646-JP")];
	char stringpool_str415[sizeof("CSISOLATINGREEK")];
	char stringpool_str417[sizeof("CN-GB")];
	char stringpool_str418[sizeof("ISO-8859-7")];
	char stringpool_str419[sizeof("ISO_8859-7")];
	char stringpool_str420[sizeof("GB18030")];
	char stringpool_str421[sizeof("WINDOWS-1256")];
	char stringpool_str422[sizeof("CSISOLATINARABIC")];
	char stringpool_str423[sizeof("WINDOWS-1251")];
	char stringpool_str425[sizeof("CP367")];
	char stringpool_str426[sizeof("NEXTSTEP")];
	char stringpool_str427[sizeof("UCS-2-INTERNAL")];
	char stringpool_str431[sizeof("WINDOWS-1254")];
	char stringpool_str432[sizeof("CSMACINTOSH")];
	char stringpool_str433[sizeof("WINDOWS-1255")];
	char stringpool_str434[sizeof("CSGB2312")];
	char stringpool_str439[sizeof("WINDOWS-1258")];
	char stringpool_str441[sizeof("MACCROATIAN")];
	char stringpool_str449[sizeof("WINDOWS-1252")];
	char stringpool_str451[sizeof("CHINESE")];
	char stringpool_str452[sizeof("IBM-CP1133")];
	char stringpool_str454[sizeof("CSISO159JISX02121990")];
	char stringpool_str456[sizeof("IBM367")];
	char stringpool_str457[sizeof("ISO_8859-3:1988")];
	char stringpool_str458[sizeof("SHIFT-JIS")];
	char stringpool_str459[sizeof("SHIFT_JIS")];
	char stringpool_str460[sizeof("CSISOLATIN3")];
	char stringpool_str462[sizeof("MS-EE")];
	char stringpool_str465[sizeof("CSISO57GB1988")];
	char stringpool_str466[sizeof("MS-HEBR")];
	char stringpool_str469[sizeof("KS_C_5601-1987")];
	char stringpool_str470[sizeof("STRK1048-2002")];
	char stringpool_str471[sizeof("KOREAN")];
	char stringpool_str472[sizeof("WCHAR_T")];
	char stringpool_str474[sizeof("JIS_C6220-1969-RO")];
	char stringpool_str478[sizeof("CSPC850MULTILINGUAL")];
	char stringpool_str482[sizeof("ISO_8859-6:1987")];
	char stringpool_str483[sizeof("UTF-32")];
	char stringpool_str484[sizeof("ISO_8859-1:1987")];
	char stringpool_str485[sizeof("BIG5HKSCS")];
	char stringpool_str487[sizeof("JIS_C6226-1983")];
	char stringpool_str489[sizeof("CSISOLATINHEBREW")];
	char stringpool_str490[sizeof("UCS-4LE")];
	char stringpool_str491[sizeof("BIG5-HKSCS")];
	char stringpool_str492[sizeof("CSKSC56011987")];
	char stringpool_str493[sizeof("GREEK8")];
	char stringpool_str496[sizeof("ASMO-708")];
	char stringpool_str499[sizeof("WINDOWS-936")];
	char stringpool_str501[sizeof("CSEUCKR")];
	char stringpool_str503[sizeof("EUCTW")];
	char stringpool_str504[sizeof("CSUNICODE")];
	char stringpool_str505[sizeof("WINDOWS-1250")];
	char stringpool_str508[sizeof("UCS-2LE")];
	char stringpool_str509[sizeof("EUC-TW")];
	char stringpool_str510[sizeof("ISO_8859-2:1987")];
	char stringpool_str512[sizeof("HZ-GB-2312")];
	char stringpool_str514[sizeof("CSISO58GB231280")];
	char stringpool_str517[sizeof("CSPC862LATINHEBREW")];
	char stringpool_str518[sizeof("EUCJP")];
	char stringpool_str522[sizeof("WINDOWS-1253")];
	char stringpool_str524[sizeof("EUC-JP")];
	char stringpool_str526[sizeof("JIS0208")];
	char stringpool_str527[sizeof("ANSI_X3.4-1986")];
	char stringpool_str530[sizeof("UNICODE-1-1-UTF-7")];
	char stringpool_str533[sizeof("KOI8-U")];
	char stringpool_str534[sizeof("CSUNICODE11UTF7")];
	char stringpool_str539[sizeof("KOI8-RU")];
	char stringpool_str540[sizeof("ISO-2022-JP-1")];
	char stringpool_str541[sizeof("TIS620.2533-1")];
	char stringpool_str542[sizeof("CSSHIFTJIS")];
	char stringpool_str543[sizeof("ARABIC")];
	char stringpool_str545[sizeof("ANSI_X3.4-1968")];
	char stringpool_str558[sizeof("MS-TURK")];
	char stringpool_str560[sizeof("WINDOWS-874")];
	char stringpool_str565[sizeof("WINDOWS-1257")];
	char stringpool_str566[sizeof("ISO-2022-JP-2")];
	char stringpool_str568[sizeof("UNICODELITTLE")];
	char stringpool_str569[sizeof("UNICODEBIG")];
	char stringpool_str571[sizeof("CSISO2022JP2")];
	char stringpool_str575[sizeof("JIS_X0212")];
	char stringpool_str579[sizeof("MACTURKISH")];
	char stringpool_str583[sizeof("ISO_8859-7:2003")];
	char stringpool_str584[sizeof("ISO-2022-JP")];
	char stringpool_str587[sizeof("MACROMANIA")];
	char stringpool_str590[sizeof("CSISO2022JP")];
	char stringpool_str597[sizeof("MACARABIC")];
	char stringpool_str599[sizeof("GREEK")];
	char stringpool_str605[sizeof("JIS_X0201")];
	char stringpool_str608[sizeof("UTF-7")];
	char stringpool_str609[sizeof("CSISO87JISX0208")];
	char stringpool_str613[sizeof("UTF-16LE")];
	char stringpool_str623[sizeof("TIS620.2533-0")];
	char stringpool_str626[sizeof("ISO_8859-7:1987")];
	char stringpool_str634[sizeof("MS_KANJI")];
	char stringpool_str637[sizeof("JIS_X0208")];
	char stringpool_str638[sizeof("JISX0201-1976")];
	char stringpool_str646[sizeof("WINBALTRIM")];
	char stringpool_str647[sizeof("MS-GREEK")];
	char stringpool_str648[sizeof("JIS_X0212-1990")];
	char stringpool_str649[sizeof("UCS-4-SWAPPED")];
	char stringpool_str653[sizeof("MACGREEK")];
	char stringpool_str667[sizeof("UCS-2-SWAPPED")];
	char stringpool_str673[sizeof("UCS-4BE")];
	char stringpool_str686[sizeof("CSEUCTW")];
	char stringpool_str691[sizeof("UCS-2BE")];
	char stringpool_str698[sizeof("MACCENTRALEUROPE")];
	char stringpool_str700[sizeof("BIG5-HKSCS:2001")];
	char stringpool_str701[sizeof("TCVN5712-1:1993")];
	char stringpool_str702[sizeof("JAVA")];
	char stringpool_str708[sizeof("BIG5-HKSCS:2004")];
	char stringpool_str718[sizeof("BIG5-HKSCS:1999")];
	char stringpool_str720[sizeof("JIS_X0208-1990")];
	char stringpool_str737[sizeof("JIS_X0208-1983")];
	char stringpool_str738[sizeof("HEBREW")];
	char stringpool_str740[sizeof("UTF-32LE")];
	char stringpool_str742[sizeof("JIS_X0212.1990-0")];
	char stringpool_str749[sizeof("BIGFIVE")];
	char stringpool_str754[sizeof("MS-ARAB")];
	char stringpool_str755[sizeof("BIG-FIVE")];
	char stringpool_str796[sizeof("UTF-16BE")];
	char stringpool_str831[sizeof("MACUKRAINE")];
	char stringpool_str833[sizeof("EXTENDED_UNIX_CODE_PACKED_FORMAT_FOR_JAPANESE")];
	char stringpool_str843[sizeof("CSHALFWIDTHKATAKANA")];
	char stringpool_str883[sizeof("JOHAB")];
	char stringpool_str898[sizeof("CSEUCPKDFMTJAPANESE")];
	char stringpool_str923[sizeof("UTF-32BE")];
	char stringpool_str926[sizeof("MACHEBREW")];
} stringpool_t;


static const UNUSED struct stringpool_t stringpool_contents = {
	"L6",
	"CN",
	"L1",
	"SJIS",
	"L4",
	"L5",
	"R8",
	"L8",
	"866",
	"L2",
	"ISO-IR-6",
	"CP866",
	"MAC",
	"C99",
	"ISO-IR-166",
	"LATIN6",
	"CP154",
	"LATIN1",
	"ISO646-CN",
	"CYRILLIC",
	"ISO-IR-14",
	"CP1256",
	"IBM866",
	"HZ",
	"LATIN4",
	"CP1251",
	"ISO-IR-165",
	"LATIN5",
	"862",
	"ISO-IR-126",
	"ISO-IR-144",
	"CP819",
	"MS-CYRL",
	"LATIN8",
	"CP1254",
	"ISO-IR-58",
	"CP949",
	"CP1255",
	"CP862",
	"ISO-IR-148",
	"PT154",
	"LATIN-9",
	"ISO-IR-149",
	"ISO-IR-159",
	"L3",
	"ISO-IR-226",
	"CP1258",
	"LATIN2",
	"ISO8859-6",
	"ISO-IR-199",
	"IBM819",
	"ISO8859-1",
	"ISO-8859-6",
	"ISO_8859-6",
	"ISO8859-16",
	"ISO-8859-1",
	"ISO_8859-1",
	"ISO8859-11",
	"ISO-8859-16",
	"ISO_8859-16",
	"CP1252",
	"IBM862",
	"ISO-8859-11",
	"ISO_8859-11",
	"ISO8859-4",
	"MACCYRILLIC",
	"ISO_8859-16:2001",
	"ISO8859-5",
	"CP1361",
	"ISO-8859-4",
	"ISO_8859-4",
	"ISO8859-14",
	"ISO-IR-101",
	"ISO-8859-5",
	"ISO_8859-5",
	"ISO8859-15",
	"CP936",
	"ISO-8859-14",
	"ISO_8859-14",
	"ISO8859-8",
	"L7",
	"ISO-8859-15",
	"ISO_8859-15",
	"ISO8859-9",
	"VISCII",
	"ISO-8859-8",
	"ISO_8859-8",
	"RK1048",
	"TCVN",
	"ISO-8859-9",
	"ISO_8859-9",
	"ISO_8859-14:1998",
	"ISO_8859-15:1998",
	"EUCCN",
	"US",
	"PTCP154",
	"ISO8859-2",
	"MS936",
	"EUC-CN",
	"CHAR",
	"CSVISCII",
	"ISO-8859-2",
	"ISO_8859-2",
	"ISO-IR-109",
	"L10",
	"ASCII",
	"UHC",
	"ISO-IR-138",
	"KOI8-R",
	"850",
	"CSASCII",
	"CP932",
	"X0212",
	"UCS-4",
	"CSKOI8R",
	"CP874",
	"CSPTCP154",
	"MS-ANSI",
	"GB2312",
	"ISO646-US",
	"CSUCS4",
	"CP850",
	"ISO-IR-110",
	"CP950",
	"BIG5",
	"ISO-2022-CN",
	"LATIN10",
	"X0201",
	"ISO-CELTIC",
	"CYRILLIC-ASIAN",
	"BIG-5",
	"CSISO2022CN",
	"ISO-IR-179",
	"UCS-2",
	"CP1250",
	"KOI8-T",
	"ROMAN8",
	"ISO_8859-10:1992",
	"TIS620",
	"CSISOLATIN6",
	"CSBIG5",
	"MACINTOSH",
	"CSISOLATIN1",
	"TIS-620",
	"IBM850",
	"CN-BIG5",
	"MACROMAN",
	"LATIN3",
	"ISO-2022-CN-EXT",
	"X0208",
	"CSISOLATINCYRILLIC",
	"CSISOLATIN4",
	"GEORGIAN-PS",
	"ARMSCII-8",
	"CSISOLATIN5",
	"CN-GB-ISOIR165",
	"CP1253",
	"CSIBM866",
	"ELOT_928",
	"VISCII1.1-1",
	"ISO_646.IRV:1991",
	"ISO8859-10",
	"KSC_5601",
	"ISO-8859-10",
	"ISO_8859-10",
	"GB_1988-80",
	"JP",
	"CSISOLATIN2",
	"ISO-IR-100",
	"EUCKR",
	"GBK",
	"KZ-1048",
	"EUC-KR",
	"ISO8859-3",
	"UTF-16",
	"MACTHAI",
	"ISO-8859-3",
	"ISO_8859-3",
	"ISO8859-13",
	"CSKZ1048",
	"ISO-8859-13",
	"ISO_8859-13",
	"ISO-10646-UCS-4",
	"KS_C_5601-1989",
	"HP-ROMAN8",
	"CP1133",
	"CSISO14JISC6220RO",
	"TIS620-0",
	"LATIN7",
	"UTF-8",
	"ISO-IR-57",
	"ISO-10646-UCS-2",
	"ISO-IR-87",
	"ISO-IR-157",
	"ISO_8859-4:1988",
	"ISO_8859-5:1988",
	"CP1257",
	"ISO_8859-8:1988",
	"US-ASCII",
	"ISO-IR-203",
	"ISO_8859-9:1989",
	"ISO-IR-127",
	"UNICODE-1-1",
	"ISO-2022-KR",
	"MULELAO-1",
	"TIS620.2529-1",
	"CSUNICODE11",
	"ECMA-114",
	"CSISO2022KR",
	"TCVN5712-1",
	"MACICELAND",
	"ECMA-118",
	"CSHPROMAN8",
	"GEORGIAN-ACADEMY",
	"UCS-4-INTERNAL",
	"GB_2312-80",
	"ISO8859-7",
	"TCVN-5712",
	"ISO646-JP",
	"CSISOLATINGREEK",
	"CN-GB",
	"ISO-8859-7",
	"ISO_8859-7",
	"GB18030",
	"WINDOWS-1256",
	"CSISOLATINARABIC",
	"WINDOWS-1251",
	"CP367",
	"NEXTSTEP",
	"UCS-2-INTERNAL",
	"WINDOWS-1254",
	"CSMACINTOSH",
	"WINDOWS-1255",
	"CSGB2312",
	"WINDOWS-1258",
	"MACCROATIAN",
	"WINDOWS-1252",
	"CHINESE",
	"IBM-CP1133",
	"CSISO159JISX02121990",
	"IBM367",
	"ISO_8859-3:1988",
	"SHIFT-JIS",
	"SHIFT_JIS",
	"CSISOLATIN3",
	"MS-EE",
	"CSISO57GB1988",
	"MS-HEBR",
	"KS_C_5601-1987",
	"STRK1048-2002",
	"KOREAN",
	"WCHAR_T",
	"JIS_C6220-1969-RO",
	"CSPC850MULTILINGUAL",
	"ISO_8859-6:1987",
	"UTF-32",
	"ISO_8859-1:1987",
	"BIG5HKSCS",
	"JIS_C6226-1983",
	"CSISOLATINHEBREW",
	"UCS-4LE",
	"BIG5-HKSCS",
	"CSKSC56011987",
	"GREEK8",
	"ASMO-708",
	"WINDOWS-936",
	"CSEUCKR",
	"EUCTW",
	"CSUNICODE",
	"WINDOWS-1250",
	"UCS-2LE",
	"EUC-TW",
	"ISO_8859-2:1987",
	"HZ-GB-2312",
	"CSISO58GB231280",
	"CSPC862LATINHEBREW",
	"EUCJP",
	"WINDOWS-1253",
	"EUC-JP",
	"JIS0208",
	"ANSI_X3.4-1986",
	"UNICODE-1-1-UTF-7",
	"KOI8-U",
	"CSUNICODE11UTF7",
	"KOI8-RU",
	"ISO-2022-JP-1",
	"TIS620.2533-1",
	"CSSHIFTJIS",
	"ARABIC",
	"ANSI_X3.4-1968",
	"MS-TURK",
	"WINDOWS-874",
	"WINDOWS-1257",
	"ISO-2022-JP-2",
	"UNICODELITTLE",
	"UNICODEBIG",
	"CSISO2022JP2",
	"JIS_X0212",
	"MACTURKISH",
	"ISO_8859-7:2003",
	"ISO-2022-JP",
	"MACROMANIA",
	"CSISO2022JP",
	"MACARABIC",
	"GREEK",
	"JIS_X0201",
	"UTF-7",
	"CSISO87JISX0208",
	"UTF-16LE",
	"TIS620.2533-0",
	"ISO_8859-7:1987",
	"MS_KANJI",
	"JIS_X0208",
	"JISX0201-1976",
	"WINBALTRIM",
	"MS-GREEK",
	"JIS_X0212-1990",
	"UCS-4-SWAPPED",
	"MACGREEK",
	"UCS-2-SWAPPED",
	"UCS-4BE",
	"CSEUCTW",
	"UCS-2BE",
	"MACCENTRALEUROPE",
	"BIG5-HKSCS:2001",
	"TCVN5712-1:1993",
	"JAVA",
	"BIG5-HKSCS:2004",
	"BIG5-HKSCS:1999",
	"JIS_X0208-1990",
	"JIS_X0208-1983",
	"HEBREW",
	"UTF-32LE",
	"JIS_X0212.1990-0",
	"BIGFIVE",
	"MS-ARAB",
	"BIG-FIVE",
	"UTF-16BE",
	"MACUKRAINE",
	"EXTENDED_UNIX_CODE_PACKED_FORMAT_FOR_JAPANESE",
	"CSHALFWIDTHKATAKANA",
	"JOHAB",
	"CSEUCPKDFMTJAPANESE",
	"UTF-32BE",
	"MACHEBREW"
};
#define stringpool   ((const char*)&stringpool_contents)


/** Definitions of charmaps: Each charmap consists of
1. Empty-string-terminated list of null-terminated aliases
2. Special type code or number of elided entries
3. Character table (size determined by field 2) */
static const UNUSED unsigned char charmaps[] = {
	"utf8\0char\0\0\310"
	"wchart\0\0\306"
	"ucs2\0ucs2be\0\0\304"
	"ucs2le\0\0\305"
	"utf16\0utf16be\0\0\302"
	"utf16le\0\0\301"
	"ucs4\0ucs4be\0utf32\0utf32be\0\0\300"
	"ucs4le\0utf32le\0\0\303"
	"ascii\0usascii\0iso646\0iso646us\0\0\307"
	"eucjp\0\0\320"
	"shiftjis\0sjis\0\0\321"
	"gb18030\0\0\330"
	"gbk\0\0\331"
	"gb2312\0\0\332"
	"big5\0bigfive\0cp950\0big5hkscs\0\0\340"
	"euckr\0ksc5601\0ksx1001\0cp949\0\0\350"
#   include "codepages.def"
};
