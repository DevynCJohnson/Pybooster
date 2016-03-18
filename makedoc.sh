#!/bin/sh
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
# Created by Devyn Collier Johnson
# <DevynCJohnson@Gmail.com>
# -- --
# Generate PyBooster documentation in ./doc/

rm -frd ./lib/doc/*

python3 -m pydoc pybooster.astronomy > ./lib/doc/astronomy.txt
python3 -m pydoc pybooster.basic > ./lib/doc/basic.txt
python3 -m pydoc pybooster.bitwise > ./lib/doc/bitwise.txt
python3 -m pydoc pybooster.chemistry > ./lib/doc/chemistry.txt
python3 -m pydoc pybooster.clibutil > ./lib/doc/clibutil.txt
python3 -m pydoc pybooster.code_interpreter > ./lib/doc/code_interpreter.txt
python3 -m pydoc pybooster.color > ./lib/doc/color.txt
python3 -m pydoc pybooster.compress > ./lib/doc/compress.txt
python3 -m pydoc pybooster.convarea > ./lib/doc/convarea.txt
python3 -m pydoc pybooster.convlength > ./lib/doc/convlength.txt
python3 -m pydoc pybooster.convmass > ./lib/doc/convmass.txt
python3 -m pydoc pybooster.convspeed > ./lib/doc/convspeed.txt
python3 -m pydoc pybooster.convtemp > ./lib/doc/convtemp.txt
python3 -m pydoc pybooster.convtime > ./lib/doc/convtime.txt
python3 -m pydoc pybooster.convvolume > ./lib/doc/convvolume.txt
python3 -m pydoc pybooster.cryptography > ./lib/doc/cryptography.txt
python3 -m pydoc pybooster.electronics > ./lib/doc/electronics.txt
python3 -m pydoc pybooster.ezdisplay > ./lib/doc/ezdisplay.txt
python3 -m pydoc pybooster.ezwin > ./lib/doc/ezwin.txt
python3 -m pydoc pybooster.ezwin.ezwin > ./lib/doc/ezwin_ezwin.txt
python3 -m pydoc pybooster.ezwin.ezwin.ezcolor > ./lib/doc/ezwin_ezwin_ezcolor.txt
python3 -m pydoc pybooster.ezwin.ezwin.ezerr > ./lib/doc/ezwin_ezwin_ezerr.txt
python3 -m pydoc pybooster.ezwin.ezwin.ezfilech > ./lib/doc/ezwin_ezwin_ezfilech.txt
python3 -m pydoc pybooster.ezwin.ezwin.ezinfo > ./lib/doc/ezwin_ezwin_ezinfo.txt
python3 -m pydoc pybooster.ezwin.ezwin.ezmsg > ./lib/doc/ezwin_ezwin_ezmsg.txt
python3 -m pydoc pybooster.ezwin.ezwin.ezpswd > ./lib/doc/ezwin_ezwin_ezpswd.txt
python3 -m pydoc pybooster.ezwin.ezwin.ezq > ./lib/doc/ezwin_ezwin_ezq.txt
python3 -m pydoc pybooster.ezwin.ezwin.ezsecurity > ./lib/doc/ezwin_ezwin_ezsecurity.txt
python3 -m pydoc pybooster.ezwin.ezwin.eztext > ./lib/doc/ezwin_ezwin_eztext.txt
python3 -m pydoc pybooster.ezwin.ezwin.ezupd > ./lib/doc/ezwin_ezwin_ezupd.txt
python3 -m pydoc pybooster.ezwin.ezwin.ezwarn > ./lib/doc/ezwin_ezwin_ezwarn.txt
python3 -m pydoc pybooster.financial > ./lib/doc/financial.txt
python3 -m pydoc pybooster.fs > ./lib/doc/fs.txt
python3 -m pydoc pybooster.geometry > ./lib/doc/geometry.txt
python3 -m pydoc pybooster.geo_services > ./lib/doc/geo_services.txt
python3 -m pydoc pybooster.mathconstants > ./lib/doc/mathconstants.txt
python3 -m pydoc pybooster.mathfunc > ./lib/doc/mathfunc.txt
python3 -m pydoc pybooster.metric > ./lib/doc/metric.txt
python3 -m pydoc pybooster.net > ./lib/doc/net.txt
python3 -m pydoc pybooster.physics > ./lib/doc/physics.txt
python3 -m pydoc pybooster.pipx > ./lib/doc/pipx.txt
python3 -m pydoc pybooster.pronouns > ./lib/doc/pronouns.txt
python3 -m pydoc pybooster.religion > ./lib/doc/religion.txt
python3 -m pydoc pybooster.science_data > ./lib/doc/science_data.txt
python3 -m pydoc pybooster.sing > ./lib/doc/sing.txt
python3 -m pydoc pybooster.strtools > ./lib/doc/strtools.txt
python3 -m pydoc pybooster.system > ./lib/doc/system.txt
python3 -m pydoc pybooster.timeutil > ./lib/doc/timeutil.txt
python3 -m pydoc pybooster.tools > ./lib/doc/tools.txt
python3 -m pydoc pybooster.typesize > ./lib/doc/typesize.txt
python3 -m pydoc pybooster.unix > ./lib/doc/unix.txt
python3 -m pydoc pybooster.xmath > ./lib/doc/xmath.txt

doxygen ./Doxyfile

chmod --quiet 644 ./lib/doc/*.txt
chmod --quiet 755 ./lib/doc/html/
chmod --quiet 644 ./lib/doc/html/*
chmod --quiet 755 ./lib/doc/html/search
chmod --quiet 644 ./lib/doc/html/search/*

exit 0
