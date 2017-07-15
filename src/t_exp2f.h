// -*- coding: utf-8 -*-
// vim:fileencoding=utf-8
/**
@file t_exp2f.h
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@brief Constants for exp2f()
@version 2017.07.15

@section DESCRIPTION
This file defines tables for exp2f() constants

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


#define W30   ((float)9.31322575e-10F)
static const UNUSED float __exp2f_deltatable[256] = {
	-810 * W30, 283 * W30, -1514 * W30, 1304 * W30,
	-1148 * W30, -98 * W30, -744 * W30, -156 * W30,
	-419 * W30, -155 * W30, 474 * W30, 167 * W30,
	-1984 * W30, -826 * W30, 692 * W30, 781 * W30,
	-578 * W30, -411 * W30, -129 * W30, -1500 * W30,
	654 * W30, -141 * W30, -816 * W30, -53 * W30,
	148 * W30, 493 * W30, -2214 * W30, 760 * W30,
	260 * W30, 750 * W30, -1300 * W30, 1424 * W30,
	-1445 * W30, -339 * W30, -680 * W30, -349 * W30,
	-922 * W30, 531 * W30, 193 * W30, -2892 * W30,
	290 * W30, -2145 * W30, -276 * W30, 485 * W30,
	-695 * W30, 215 * W30, -7093 * W30, 412 * W30,
	-4596 * W30, 367 * W30, 592 * W30, -615 * W30,
	-97 * W30, -1066 * W30, 972 * W30, -226 * W30,
	-625 * W30, -374 * W30, -5647 * W30, -180 * W30,
	20349 * W30, -447 * W30, 111 * W30, -4164 * W30,
	-87 * W30, -21 * W30, -251 * W30, 66 * W30,
	-517 * W30, 2093 * W30, -263 * W30, 182 * W30,
	-601 * W30, 475 * W30, -483 * W30, -1251 * W30,
	-373 * W30, 1471 * W30, -92 * W30, -215 * W30,
	-97 * W30, -190 * W30, 0 * W30, -290 * W30,
	-2647 * W30, 1940 * W30, -582 * W30, 28 * W30,
	833 * W30, 1493 * W30, 34 * W30, 321 * W30,
	3327 * W30, -35 * W30, 177 * W30, -135 * W30,
	-796 * W30, -428 * W30, 129 * W30, 9332 * W30,
	-12 * W30, -69 * W30, -1743 * W30, 6508 * W30,
	-60 * W30, 359 * W30, 43447 * W30, 15 * W30,
	-23 * W30, -305 * W30, -375 * W30, -652 * W30,
	667 * W30, 269 * W30, -1575 * W30, 185 * W30,
	-329 * W30, 200 * W30, 6002 * W30, 163 * W30,
	-647 * W30, 19 * W30, -603 * W30, -755 * W30,
	742 * W30, -438 * W30, 3587 * W30, 2560 * W30,
	0 * W30, -520 * W30, -241 * W30, -299 * W30,
	-1270 * W30, -991 * W30, -1138 * W30, 255 * W30,
	-1192 * W30, 1722 * W30, 1023 * W30, 3700 * W30,
	-1388 * W30, -1551 * W30, -2549 * W30, 27 * W30,
	282 * W30, 673 * W30, 113 * W30, 1561 * W30,
	72 * W30, 873 * W30, 87 * W30, -395 * W30,
	-433 * W30, 629 * W30, 3440 * W30, -284 * W30,
	-592 * W30, -103 * W30, -46 * W30, -3844 * W30,
	1712 * W30, 303 * W30, 1555 * W30, -631 * W30,
	-1400 * W30, -961 * W30, -854 * W30, -276 * W30,
	407 * W30, 833 * W30, -345 * W30, -1501 * W30,
	121 * W30, -1581 * W30, 400 * W30, 150 * W30,
	1224 * W30, -139 * W30, -563 * W30, 879 * W30,
	933 * W30, 2939 * W30, 788 * W30, 211 * W30,
	530 * W30, -192 * W30, 706 * W30, -13347 * W30,
	1065 * W30, 3 * W30, 111 * W30, -208 * W30,
	-360 * W30, -532 * W30, -291 * W30, 483 * W30,
	987 * W30, -33 * W30, -1373 * W30, -166 * W30,
	-1174 * W30, -3955 * W30, 1601 * W30, -280 * W30,
	1405 * W30, 600 * W30, -1659 * W30, -23 * W30,
	390 * W30, 449 * W30, 570 * W30, -13143 * W30,
	-9 * W30, -1646 * W30, 1201 * W30, 294 * W30,
	2181 * W30, -1173 * W30, 1388 * W30, -4504 * W30,
	190 * W30, -2304 * W30, 211 * W30, 239 * W30,
	48 * W30, -817 * W30, 1018 * W30, 1828 * W30,
	-663 * W30, 1408 * W30, 408 * W30, -36 * W30,
	1295 * W30, -230 * W30, 1341 * W30, 9 * W30,
	40 * W30, 705 * W30, 186 * W30, 376 * W30,
	557 * W30, 5866 * W30, 363 * W30, -1558 * W30,
	718 * W30, 669 * W30, 1369 * W30, -2972 * W30,
	-468 * W30, -121 * W30, -219 * W30, 667 * W30,
	29954 * W30, 366 * W30, 48 * W30, -203 * W30
};
#undef W30


static const UNUSED float __exp2f_atable[256]  = {
	0.707106411447F, 0.709024071690F, 0.710945606239F,
	0.712874472142F, 0.714806139464F, 0.716744661340F,
	0.718687653549F, 0.720636486992F, 0.722590208040F,
	0.724549472323F, 0.726514220228F, 0.728483855735F,
	0.730457961549F, 0.732438981522F, 0.734425544748F,
	0.736416816713F, 0.738412797450F, 0.740414917465F,
	0.742422521111F, 0.744434773914F, 0.746454179287F,
	0.748477637755F, 0.750506639473F, 0.752541840064F,
	0.754582285889F, 0.756628334525F, 0.758678436269F,
	0.760736882681F, 0.762799203401F, 0.764867603790F,
	0.766940355298F, 0.769021093841F, 0.771104693409F,
	0.773195922364F, 0.775292098512F, 0.777394294745F,
	0.779501736166F, 0.781615912910F, 0.783734917628F,
	0.785858273516F, 0.787990570071F, 0.790125787245F,
	0.792268991467F, 0.794417440881F, 0.796570718287F,
	0.798730909811F, 0.800892710672F, 0.803068041795F,
	0.805242776881F, 0.807428598393F, 0.809617877002F,
	0.811812341211F, 0.814013659956F, 0.816220164311F,
	0.818434238424F, 0.820652604094F, 0.822877407074F,
	0.825108587751F, 0.827342867839F, 0.829588949684F,
	0.831849217401F, 0.834093391880F, 0.836355149750F,
	0.838620424257F, 0.840896368027F, 0.843176305293F,
	0.845462262643F, 0.847754716864F, 0.850052893157F,
	0.852359056469F, 0.854668736446F, 0.856986224651F,
	0.859309315673F, 0.861639738080F, 0.863975346095F,
	0.866317391394F, 0.868666708472F, 0.871022939695F,
	0.873383641229F, 0.875751554968F, 0.878126025200F,
	0.880506813521F, 0.882894217966F, 0.885287821299F,
	0.887686729423F, 0.890096127973F, 0.892507970338F,
	0.894928157336F, 0.897355020043F, 0.899788379682F,
	0.902227103705F, 0.904673457151F, 0.907128036008F,
	0.909585535528F, 0.912051796915F, 0.914524436003F,
	0.917003571999F, 0.919490039339F, 0.921983361257F,
	0.924488604054F, 0.926989555360F, 0.929502844812F,
	0.932021975503F, 0.934553921208F, 0.937083780759F,
	0.939624726786F, 0.942198514924F, 0.944726586343F,
	0.947287976728F, 0.949856162070F, 0.952431440345F,
	0.955013573175F, 0.957603693021F, 0.960199773321F,
	0.962801992906F, 0.965413510788F, 0.968030691152F,
	0.970655620084F, 0.973290979849F, 0.975926160805F,
	0.978571653370F, 0.981225252139F, 0.983885228626F,
	0.986552715296F, 0.989228487027F, 0.991909801964F,
	0.994601726545F, 0.997297704209F, 1.000000000000F,
	1.002710938457F, 1.005429744692F, 1.008155703526F,
	1.010888457284F, 1.013629436498F, 1.016377568250F,
	1.019134163841F, 1.021896362316F, 1.024668931945F,
	1.027446627635F, 1.030234098408F, 1.033023953416F,
	1.035824656494F, 1.038632392900F, 1.041450142840F,
	1.044273972530F, 1.047105550795F, 1.049944162390F,
	1.052791833895F, 1.055645227426F, 1.058507919326F,
	1.061377286898F, 1.064254641510F, 1.067140102389F,
	1.070034146304F, 1.072937250162F, 1.075843691823F,
	1.078760385496F, 1.081685543070F, 1.084618330005F,
	1.087556362176F, 1.090508937863F, 1.093464612954F,
	1.096430182434F, 1.099401354802F, 1.102381587017F,
	1.105370759965F, 1.108367800686F, 1.111373305331F,
	1.114387035385F, 1.117408752440F, 1.120437502874F,
	1.123474478729F, 1.126521706601F, 1.129574775716F,
	1.132638812065F, 1.135709524130F, 1.138789534565F,
	1.141876101508F, 1.144971728301F, 1.148077130296F,
	1.151189923305F, 1.154312610610F, 1.157440662410F,
	1.160578370109F, 1.163725256932F, 1.166879892324F,
	1.170044302935F, 1.173205971694F, 1.176397800428F,
	1.179586529747F, 1.182784795737F, 1.185991406414F,
	1.189206838636F, 1.192430973067F, 1.195664167430F,
	1.198906540890F, 1.202157497408F, 1.205416083326F,
	1.208683252332F, 1.211961269402F, 1.215246438983F,
	1.218539118740F, 1.221847295770F, 1.225158572187F,
	1.228481650325F, 1.231811761846F, 1.235149741144F,
	1.238499879811F, 1.241858124726F, 1.245225191102F,
	1.248601436624F, 1.251975655584F, 1.255380749731F,
	1.258783102010F, 1.262198328973F, 1.265619754780F,
	1.269052743928F, 1.272490739830F, 1.275942921659F,
	1.279397487615F, 1.282870173427F, 1.286346316319F,
	1.289836049094F, 1.293333172770F, 1.296839594835F,
	1.300354957560F, 1.303882122055F, 1.307417988757F,
	1.310960650439F, 1.314516782746F, 1.318079948424F,
	1.321653246888F, 1.325237751030F, 1.328829526907F,
	1.332433700535F, 1.336045145966F, 1.339667558645F,
	1.343300342533F, 1.346941947961F, 1.350594043714F,
	1.354256033883F, 1.357932448365F, 1.361609339707F,
	1.365299344044F, 1.369003057507F, 1.372714757920F,
	1.376437187179F, 1.380165219333F, 1.383909463864F,
	1.387661933907F, 1.391424179060F, 1.395197510706F,
	1.399006724329F, 1.402773022651F, 1.406576037403F,
	1.410389423392F
};
