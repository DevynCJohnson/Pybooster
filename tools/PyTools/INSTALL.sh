#!/bin/sh
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
# @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
# @brief Install all files in the directory


# Remove existing version
rm -frd --one-file-system /opt/bin/PyTools/*
mkdir --mode=755 -p /opt/bin/PyTools/doc/
# Copy files to installaion location
cp -Rf ./* /opt/bin/PyTools/
chmod --quiet 755 /opt/bin/PyTools/*
chmod --quiet 755 /opt/bin/PyTools/geany-plugins/*
# Over-write older Pep8
cp -f /opt/bin/PyTools/pep8 /usr/local/bin/pep8
# Over-write older PyFlakes
cp -f /opt/bin/PyTools/pyflakes2 /usr/bin/pyflakes
cp -f /opt/bin/PyTools/pyflakes3 /usr/bin/pyflakes3
# Over-write older Pylint
cp -f /opt/bin/PyTools/pylint2 /usr/bin/pylint
cp -f /opt/bin/PyTools/pylint3 /usr/bin/pylint3
cp -f /opt/bin/PyTools/pylint3 /usr/local/bin/pylint
# Install flake8_optimal
cd ./flake8_optimal/
python3 ./setup.py install
# Clean-up and Finish
echo ""
cd ..
rm -fr ./build
rm -fr ./dist
rm -fr ./flake8_optimal.egg-info
rm -fr ./flake8_optimal/build
rm -fr ./flake8_optimal/dist
rm -fr ./flake8_optimal/flake8_optimal.egg-info
rm /opt/bin/PyTools/INSTALL.sh
rm /opt/bin/PyTools/GET-DEPS.sh
rm /opt/bin/PyTools/Install_Geany_plugins.sh
rm /opt/bin/PyTools/README
echo ""
echo "Installation Complete (PyTools)!"
echo "The user or admin must append /opt/bin/PyTools/ and /opt/bin/PyTools/geany-plugins to the PATH"
echo "This may be done in"
echo "/etc/environment, /etc/profile.d/, ~/.bashrc, ~/.profile, or some equivalent"

exit 0
