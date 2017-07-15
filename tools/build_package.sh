#!/bin/sh
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
# @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>


cd ..

make rmtmp


## LINUX X86 AND X86-64 ##


make -j3 dcj=1 all && cd ../ && tar -cf - PyBooster | gzip -9 > ./PyBooster_v"$(date +"%Y.%m.%d")"_Linux_Haswell64.tar.gz && cd ./PyBooster && echo '' && echo '' && echo 'Packaged Linux Haswell (64-bit) Build' && echo '' && echo ''

make rmtmp

make -j3 dcj=2 all && cd ../ && tar -cf - PyBooster | gzip -9 > ./PyBooster_v"$(date +"%Y.%m.%d")"_Linux_Broadwell64.tar.gz && cd ./PyBooster && echo '' && echo '' && echo 'Packaged Linux Broadwell (64-bit) Build' && echo '' && echo ''

make rmtmp

make -j3 dcj=3 all && cd ../ && tar -cf - PyBooster | gzip -9 > ./PyBooster_v"$(date +"%Y.%m.%d")"_Linux_Skylake64.tar.gz && cd ./PyBooster && echo '' && echo '' && echo 'Packaged Linux Skylake (64-bit) Build' && echo '' && echo ''

make rmtmp

make -j3 dcj=4 all && cd ../ && tar -cf - PyBooster | gzip -9 > ./PyBooster_v"$(date +"%Y.%m.%d")"_Linux_Knight64.tar.gz && cd ./PyBooster && echo '' && echo '' && echo 'Packaged Linux Knight (64-bit) Build' && echo '' && echo ''

make rmtmp

make -j3 dcj=athlon64-sse3 all && cd ../ && tar -cf - PyBooster | gzip -9 > ./PyBooster_v"$(date +"%Y.%m.%d")"_Linux_Athlon64.tar.gz && cd ./PyBooster && echo '' && echo '' && echo 'Packaged Linux Athlon64 (SSE3) Build' && echo '' && echo ''

make rmtmp

make -j3 dcj=znver1 all && cd ../ && tar -cf - PyBooster | gzip -9 > ./PyBooster_v"$(date +"%Y.%m.%d")"_Linux_AMD64_Family_17h.tar.gz && cd ./PyBooster && echo '' && echo '' && echo 'Packaged Linux AMD64 (AMD Family 17h) Build' && echo '' && echo ''

make rmtmp

make -j3 dcj=GENERICX86 all && cd ../ && tar -cf - PyBooster | gzip -9 > ./PyBooster_v"$(date +"%Y.%m.%d")"_Linux_Generic_x86.tar.gz && cd ./PyBooster && echo '' && echo '' && echo 'Packaged Generic x86 Build' && echo '' && echo ''

make rmtmp

make -j3 dcj=GENERICX86_64 all && cd ../ && tar -cf - PyBooster | gzip -9 > ./PyBooster_v"$(date +"%Y.%m.%d")"_Linux_Generic_x86_64.tar.gz && cd ./PyBooster && echo '' && echo '' && echo 'Packaged Generic x86-64 Build' && echo '' && echo ''

make rmtmp

make -j3 dcj=INTEL INTEL=32 all && cd ../ && tar -cf - PyBooster | gzip -9 > ./PyBooster_v"$(date +"%Y.%m.%d")"_Linux_Intel32.tar.gz && cd ./PyBooster && echo '' && echo '' && echo 'Packaged Intel32 Build' && echo '' && echo ''

make rmtmp

make -j3 dcj=INTEL INTEL=64 all && cd ../ && tar -cf - PyBooster | gzip -9 > ./PyBooster_v"$(date +"%Y.%m.%d")"_Linux_Intel64.tar.gz && cd ./PyBooster && echo '' && echo '' && echo 'Packaged Intel64 Build' && echo '' && echo ''

make rmtmp


## LINUX ARM ##


make -j3 OS=LINUX CROSS_COMPILE=armel all && cd ../ && tar -cf - PyBooster | gzip -9 > ./PyBooster_v"$(date +"%Y.%m.%d")"_Linux_ARMEL.tar.gz && cd ./PyBooster && echo '' && echo '' && echo 'Packaged ARMEL Build' && echo '' && echo ''

make rmtmp

make -j3 OS=LINUX CROSS_COMPILE=armhf all && cd ../ && tar -cf - PyBooster | gzip -9 > ./PyBooster_v"$(date +"%Y.%m.%d")"_Linux_ARMHF.tar.gz && cd ./PyBooster && echo '' && echo '' && echo 'Packaged ARMHF Build' && echo '' && echo ''

make rmtmp

make -j3 OS=LINUX dcj=rpi all && cd ../ && tar -cf - PyBooster | gzip -9 > ./PyBooster_v"$(date +"%Y.%m.%d")"_Linux_RPi.tar.gz && cd ./PyBooster && echo '' && echo '' && echo 'Packaged RPi Build' && echo '' && echo ''

make rmtmp


## WINDOWS ##


make -j3 OS=WIN CROSS_COMPILE=win32 all && cd ../ && tar -cf - PyBooster | gzip -9 > ./PyBooster_v"$(date +"%Y.%m.%d")"_WIN32.tar.gz && cd ./PyBooster && echo '' && echo '' && echo 'Packaged WIN32 Build' && echo '' && echo ''

make rmtmp

make -j3 OS=WIN CROSS_COMPILE=win64 all && cd ../ && tar -cf - PyBooster | gzip -9 > ./PyBooster_v"$(date +"%Y.%m.%d")"_WIN64.tar.gz && cd ./PyBooster && echo '' && echo '' && echo 'Packaged WIN64 Build' && echo '' && echo ''

make rmtmp


## DONE ##


echo ''
echo 'DONE; Press enter to exit'
echo ''
read
