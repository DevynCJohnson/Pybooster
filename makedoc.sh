#!/bin/sh
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
# @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
# @brief Generate PyBooster documentation


rm -frd ./doc/*

cd ./lib/

python3 -m pydoc astronomy > ../doc/astronomy.txt
python3 -m pydoc basic > ../doc/basic.txt
python3 -m pydoc bitwise > ../doc/bitwise.txt
python3 -m pydoc chemistry > ../doc/chemistry.txt
python3 -m pydoc clibutil > ../doc/clibutil.txt
python3 -m pydoc code_interpreter > ../doc/code_interpreter.txt
python3 -m pydoc color > ../doc/color.txt
python3 -m pydoc compress > ../doc/compress.txt
python3 -m pydoc convarea > ../doc/convarea.txt
python3 -m pydoc convlength > ../doc/convlength.txt
python3 -m pydoc convmass > ../doc/convmass.txt
python3 -m pydoc convspeed > ../doc/convspeed.txt
python3 -m pydoc convtemp > ../doc/convtemp.txt
python3 -m pydoc convtime > ../doc/convtime.txt
python3 -m pydoc convvolume > ../doc/convvolume.txt
python3 -m pydoc cryptography > ../doc/cryptography.txt
python3 -m pydoc electronics > ../doc/electronics.txt
python3 -m pydoc ezdisplay > ../doc/ezdisplay.txt
python3 -m pydoc ezwin > ../doc/ezwin.txt
python3 -m pydoc ezwin.ezwin > ../doc/ezwin_ezwin.txt
python3 -m pydoc ezwin.ezwin.ezcolor > ../doc/ezwin_ezwin_ezcolor.txt
python3 -m pydoc ezwin.ezwin.ezerr > ../doc/ezwin_ezwin_ezerr.txt
python3 -m pydoc ezwin.ezwin.ezfilech > ../doc/ezwin_ezwin_ezfilech.txt
python3 -m pydoc ezwin.ezwin.ezinfo > ../doc/ezwin_ezwin_ezinfo.txt
python3 -m pydoc ezwin.ezwin.ezmsg > ../doc/ezwin_ezwin_ezmsg.txt
python3 -m pydoc ezwin.ezwin.ezpswd > ../doc/ezwin_ezwin_ezpswd.txt
python3 -m pydoc ezwin.ezwin.ezq > ../doc/ezwin_ezwin_ezq.txt
python3 -m pydoc ezwin.ezwin.ezsecurity > ../doc/ezwin_ezwin_ezsecurity.txt
python3 -m pydoc ezwin.ezwin.eztext > ../doc/ezwin_ezwin_eztext.txt
python3 -m pydoc ezwin.ezwin.ezupd > ../doc/ezwin_ezwin_ezupd.txt
python3 -m pydoc ezwin.ezwin.ezwarn > ../doc/ezwin_ezwin_ezwarn.txt
python3 -m pydoc financial > ../doc/financial.txt
python3 -m pydoc fs > ../doc/fs.txt
python3 -m pydoc geometry > ../doc/geometry.txt
python3 -m pydoc geo_services > ../doc/geo_services.txt
python3 -m pydoc mathconstants > ../doc/mathconstants.txt
python3 -m pydoc mathfunc > ../doc/mathfunc.txt
python3 -m pydoc metric > ../doc/metric.txt
python3 -m pydoc net > ../doc/net.txt
python3 -m pydoc physics > ../doc/physics.txt
python3 -m pydoc pipx > ../doc/pipx.txt
python3 -m pydoc pronouns > ../doc/pronouns.txt
python3 -m pydoc religion > ../doc/religion.txt
python3 -m pydoc science_data > ../doc/science_data.txt
python3 -m pydoc sing > ../doc/sing.txt
python3 -m pydoc strtools > ../doc/strtools.txt
python3 -m pydoc system > ../doc/system.txt
python3 -m pydoc timeutil > ../doc/timeutil.txt
python3 -m pydoc tools > ../doc/tools.txt
python3 -m pydoc typesize > ../doc/typesize.txt
python3 -m pydoc unix > ../doc/unix.txt
python3 -m pydoc xmath > ../doc/xmath.txt

cd .. && doxygen ./Doxyfile

chmod --quiet 644 ./doc/*.txt
chmod --quiet 755 ./doc/html/
chmod --quiet 644 ./doc/html/*
chmod --quiet 755 ./doc/html/search
chmod --quiet 644 ./doc/html/search/*
