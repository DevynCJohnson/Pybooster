#!/bin/sh
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
# @author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
# @brief Install Geany Plugins (Run with Root privileges)


# Remove existing version
rm -frd --one-file-system /opt/bin/PyTools/geany-plugins/
mkdir --mode=755 -p /opt/bin/PyTools/geany-plugins/
# Copy files to installaion location
cp -Rf ./geany-plugins/* /opt/bin/PyTools/geany-plugins/
chmod --quiet 755 /opt/bin/PyTools/geany-plugins/*
# Finish
echo "Installation Complete (Geany Plugins)!"
echo "The user or admin must append /opt/bin/PyTools/geany-plugins to the PATH"
echo "This may be done in /etc/environment, /etc/profile.d/, ~/.bashrc, ~/.profile, or some equivalent"

exit 0
