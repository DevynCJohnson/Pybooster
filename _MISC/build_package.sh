#!/bin/sh
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
# Created by Devyn Collier Johnson
# <DevynCJohnson@Gmail.com>


cd ..

__MODULE_VERSION__=\"`date +"%Y.%m.%d"`\"

make rmtmp


## LINUX X86 AND X86-64 ##


make -j4 all dcj=1 && make -j4 all dcj=py && cd ../ && tar -cf - PyBooster | gzip -9 > ./PyBooster_v`date +"%Y.%m.%d"`_Linux_Haswell64.tar.gz && cd ./PyBooster && echo '' && echo '' && echo 'Packaged Linux Haswell (64-bit) Build' && echo '' && echo ''

make rmtmp

make -j4 all dcj=2 && make -j4 all dcj=py && cd ../ && tar -cf - PyBooster | gzip -9 > ./PyBooster_v`date +"%Y.%m.%d"`_Linux_Broadwell64.tar.gz && cd ./PyBooster && echo '' && echo '' && echo 'Packaged Linux Broadwell (64-bit) Build' && echo '' && echo ''

make rmtmp

make -j4 all dcj=3 && make -j4 all dcj=py && cd ../ && tar -cf - PyBooster | gzip -9 > ./PyBooster_v`date +"%Y.%m.%d"`_Linux_Skylake64.tar.gz && cd ./PyBooster && echo '' && echo '' && echo 'Packaged Linux Skylake (64-bit) Build' && echo '' && echo ''

make rmtmp

make -j4 all dcj=4 && make -j4 all dcj=py && cd ../ && tar -cf - PyBooster | gzip -9 > ./PyBooster_v`date +"%Y.%m.%d"`_Linux_Knight64.tar.gz && cd ./PyBooster && echo '' && echo '' && echo 'Packaged Linux Knight (64-bit) Build' && echo '' && echo ''

make rmtmp

make -j4 all dcj=athlon64-sse3 && make -j4 all dcj=py && cd ../ && tar -cf - PyBooster | gzip -9 > ./PyBooster_v`date +"%Y.%m.%d"`_Linux_Athlon64.tar.gz && cd ./PyBooster && echo '' && echo '' && echo 'Packaged Linux Athlon64 (SSE3) Build' && echo '' && echo ''

make rmtmp

make -j4 all dcj=znver1 && make -j4 all dcj=py && cd ../ && tar -cf - PyBooster | gzip -9 > ./PyBooster_v`date +"%Y.%m.%d"`_Linux_AMD64_Family_17h.tar.gz && cd ./PyBooster && echo '' && echo '' && echo 'Packaged Linux AMD64 (AMD Family 17h) Build' && echo '' && echo ''

make rmtmp

make -j4 all dcj=GENERICX86 && cd ../ && tar -cf - PyBooster | gzip -9 > ./PyBooster_v`date +"%Y.%m.%d"`_Linux_Generic_x86.tar.gz && cd ./PyBooster && echo '' && echo '' && echo 'Packaged Generic x86 Build' && echo '' && echo ''

make rmtmp

make -j4 all dcj=GENERICX86_64 && cd ../ && tar -cf - PyBooster | gzip -9 > ./PyBooster_v`date +"%Y.%m.%d"`_Linux_Generic_x86_64.tar.gz && cd ./PyBooster && echo '' && echo '' && echo 'Packaged Generic x86-64 Build' && echo '' && echo ''

make rmtmp

make -j4 all dcj=INTEL INTEL=32 && cd ../ && tar -cf - PyBooster | gzip -9 > ./PyBooster_v`date +"%Y.%m.%d"`_Linux_Intel32.tar.gz && cd ./PyBooster && echo '' && echo '' && echo 'Packaged Intel32 Build' && echo '' && echo ''

make rmtmp

make -j4 all dcj=INTEL INTEL=64 && cd ../ && tar -cf - PyBooster | gzip -9 > ./PyBooster_v`date +"%Y.%m.%d"`_Linux_Intel64.tar.gz && cd ./PyBooster && echo '' && echo '' && echo 'Packaged Intel64 Build' && echo '' && echo ''

make rmtmp


## LINUX ARM ##


make -j4 all OS=LINUX CROSS_COMPILE=armel && cd ../ && tar -cf - PyBooster | gzip -9 > ./PyBooster_v`date +"%Y.%m.%d"`_Linux_ARMEL.tar.gz && cd ./PyBooster && echo '' && echo '' && echo 'Packaged ARMEL Build' && echo '' && echo ''

make rmtmp

make -j4 all OS=LINUX CROSS_COMPILE=armhf && cd ../ && tar -cf - PyBooster | gzip -9 > ./PyBooster_v`date +"%Y.%m.%d"`_Linux_ARMHF.tar.gz && cd ./PyBooster && echo '' && echo '' && echo 'Packaged ARMHF Build' && echo '' && echo ''

make rmtmp

make -j4 all OS=LINUX dcj=rpi && cd ../ && tar -cf - PyBooster | gzip -9 > ./PyBooster_v`date +"%Y.%m.%d"`_Linux_RPi.tar.gz && cd ./PyBooster && echo '' && echo '' && echo 'Packaged RPi Build' && echo '' && echo ''

make rmtmp


## WINDOWS ##


make -j4 all OS=WIN CROSS_COMPILE=win32 && cd ../ && tar -cf - PyBooster | gzip -9 > ./PyBooster_v`date +"%Y.%m.%d"`_WIN32.tar.gz && cd ./PyBooster && echo '' && echo '' && echo 'Packaged WIN32 Build' && echo '' && echo ''

make rmtmp

make -j4 all OS=WIN CROSS_COMPILE=win64 && cd ../ && tar -cf - PyBooster | gzip -9 > ./PyBooster_v`date +"%Y.%m.%d"`_WIN64.tar.gz && cd ./PyBooster && echo '' && echo '' && echo 'Packaged WIN64 Build' && echo '' && echo ''

make rmtmp


## DONE ##


echo ''
echo 'DONE; Press enter to exit'
echo ''
read
