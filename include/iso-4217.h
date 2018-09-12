// -*- coding: utf-8-unix; Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-
// vim: set fileencoding=utf-8 filetype=c syntax=c.doxygen fileformat=unix tabstop=4 :
// kate: encoding utf-8; bom off; syntax c; indent-mode cstyle; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
/**
@brief ISO-4217 character set
@file iso-4217.h
@version 2018.09.11
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

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


/** Defines the valid international currency symbols according to ISO 4217 */

static const UNUSED char* const valid_int_curr[162] = {
	"AED",  // United Arab Emirates Dirham
	"AFN",  // Afghanistan Afgani
	"ALL",  // Albanian Lek
	"AMD",  // Armenia Dram
	"ANG",  // Netherlands Antilles
	"AOA",  // Angolan Kwanza
	"ARS",  // Argentine Peso
	"AUD",  // Australian Dollar
	"AWG",  // Aruba Guilder
	"AZN",  // Azerbaijan Manat
	"BAM",  // Bosnian and Herzegovina Convertible Mark
	"BBD",  // Barbados Dollar
	"BDT",  // Bangladesh Taka
	"BGN",  // Bulgarian Lev
	"BHD",  // Bahraini Dinar
	"BIF",  // Burundi Franc
	"BMD",  // Burmudian Dollar
	"BND",  // Brunei Dollar
	"BOB",  // Bolivian Boliviano
	"BRL",  // Brazil Real
	"BSD",  // Bahamas Dollar
	"BTC",  // Bitcoin
	"BTN",  // Bhutan Ngultrum
	"BWP",  // Botswana Pula
	"BYR",  // Belarus Ruble
	"BZD",  // Belize Dollar
	"CAD",  // Canadian Dollar
	"CDF",  // Congo Dem.Rep. Franc
	"CHF",  // Swiss Franc (Liechtenstein)
	"CLP",  // Chilean Peso
	"CNY",  // China Yuan Renminbi
	"COP",  // Colombian Peso
	"CRC",  // Costa Rican Colon
	"CUP",  // Cuban Peso
	"CVE",  // Cape Verde Escudo
	"CYP",  // Cypriot Pound
	"CZK",  // Czech Koruna
	"DJF",  // Djibouti Franc
	"DKK",  // Danish Krone (Faroe Islands, Greenland)
	"DOP",  // Dominican Republic
	"DZD",  // Algerian Dinar
	"EEK",  // Estonian Kroon
	"EGP",  // Egyptian Pound
	"ERN",  // Eritrean Nakfa
	"ETB",  // Ethiopian Birr
	"EUR",  // European Union Euro
	"FJD",  // Fiji Dollar
	"FKP",  // Falkland Islands Pound (Malvinas)
	"GBP",  // British Pound
	"GEL",  // Georgia Lari
	"GHS",  // Ghana Cedi
	"GIP",  // Gibraltar Pound
	"GMD",  // Gambian Dalasi
	"GNF",  // Guinea Franc
	"GTQ",  // Guatemala Quetzal
	"GYD",  // Guyana Dollar
	"HKD",  // Hong Kong Dollar
	"HNL",  // Honduras Lempira
	"HRK",  // Croatia Kuna
	"HTG",  // Haiti Gourde
	"HUF",  // Hungarian Forint
	"IDR",  // Indonesia Rupiah
	"ILS",  // Israeli Shekel
	"INR",  // Indian Rupee (Bhutan)
	"IQD",  // Iraqi Dinar
	"IRR",  // Iranian Rial
	"ISK",  // Iceland Krona
	"JMD",  // Jamaican Dollar
	"JOD",  // Jordanian Dinar
	"JPY",  // Japanese Yen
	"KES",  // Kenyan Shilling
	"KGS",  // Kyrgyzstan Som
	"KHR",  // Democratic Kampuchea Riel
	"KMF",  // Comoros Franc
	"KPW",  // Democratic People's of Korea Won
	"KRW",  // Republic of Korea Won
	"KWD",  // Kuwaiti Dinar
	"KYD",  // Cayman Islands
	"KZT",  // Kazakhstan Tenge
	"LAK",  // Lao People's Democratic Republic New Kip
	"LBP",  // Lebanese Pound
	"LKR",  // Sri Lankan Rupee
	"LRD",  // Liberian Dollar
	"LSL",  // Lesotho Maloti
	"LTL",  // Lithuanian Litas
	"LVL",  // Latvia Lat
	"LYD",  // Libyan Arab Jamahiriya Dinar
	"MAD",  // Moroccan Dirham
	"MDL",  // Moldova Lei
	"MGA",  // Madagasy Ariary
	"MKD",  // Macedonia Denar
	"MMK",  // Myanmar Kyat
	"MNT",  // Mongolia Tugrik
	"MOP",  // Macau Pataca
	"MRO",  // Mauritania Ouguiya
	"MTL",  // Maltese Lira
	"MUR",  // Mauritius Rupee
	"MVR",  // Maldives Rufiyaa
	"MWK",  // Malawi Kwacha
	"MXN",  // Mexican Peso
	"MYR",  // Malaysian Ringgit
	"MZN",  // Mozambique Metical
	"NAD",  // Namibia Dollar
	"NGN",  // Nigeria Naira
	"NIO",  // Nicaragua Cordoba Oro
	"NOK",  // Norwegian Krone
	"NPR",  // Nepalese Rupee
	"NZD",  // New Zealand Dollar
	"OMR",  // Omani Rial
	"PAB",  // Panamaniam Balboa
	"PEN",  // Peruvian New Sol
	"PGK",  // Papau New Guinea Kina
	"PHP",  // Philippines Peso
	"PKR",  // Pakistan Rupee
	"PLN",  // Polish Zloty
	"PYG",  // Paraguay Guarani
	"QAR",  // Qatar Rial
	"RON",  // Romanian New Leu
	"RSD",  // Serbian Dinars
	"RUB",  // Russian Ruble
	"RWF",  // Rwanda Franc
	"SAR",  // Saudi Arabia Riyal
	"SBD",  // Solomon Islands Dollar
	"SCR",  // Seychelles Rupee
	"SDG",  // Sudanese Pound
	"SEK",  // Swedish Krona
	"SGD",  // Singapore Dollar
	"SHP",  // St. Helena Pound
	"SLL",  // Sierra Leone Leone
	"SOS",  // Somalia Schilling
	"SRD",  // Suriname Dollar
	"STD",  // Sao Tome and Principe Dobra
	"SVC",  // El Salvador Colon
	"SYP",  // Syrian Arab Republic Pound
	"SZL",  // Swaziland Lilangeni
	"THB",  // Thai Baht
	"TJS",  // Tajikistani Somoni
	"TMM",  // Turkmenistan Manet
	"TND",  // Tunisian Dinar
	"TOP",  // Tonga Pa'Anga
	"TRY",  // New Turkish Lira
	"TTD",  // Trinidad and Tobago
	"TWD",  // Taiwan, Province of China Dollar
	"TZS",  // United Republic of Tanzania Shilling
	"UAH",  // Ukraine Hryvna
	"UGX",  // Ugandan Shilling
	"USD",  // United States Dollar
	"UYU",  // Uruguay Peso Uruguayo
	"UZS",  // Uzbekistan Sum
	"VEF",  // Venezuelan Bolivar Fuerte
	"VND",  // Viet Nam Dong
	"VUV",  // Vanuatu Vatu
	"WST",  // Samoa Tala
	"XAF",  // Central African Franc (United Republic of Cameroon, Central African Republic, Chad, Congo, Gabon)
	"XCD",  // East Caribbean Dollar (Antiqua, Dominica, Grenada, Montserrat, St. Kitts-Nevis-Anguilla, Saint Lucia, Saint Vincent and the Grenadines)
	"XDR",  // International Monetary Fund
	"XOF",  // West African Franc (Benin, Ivory Coast, Niger, Senegal, Togo, Upper Volta)
	"XPF",  // French polynesia, New Caledonia, Wallis and Futuna Islands
	"YER",  // Yemeni Rial
	"ZAR",  // South Africa Rand (Lesotho, Namibia)
	"ZMK",  // Zambian Kwacha
	"ZWD"  // Zimbabwe Dollar
};
