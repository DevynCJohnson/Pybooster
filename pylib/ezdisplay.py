#!/usr/bin/env python3
# -*- coding: utf-8-unix; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
"""@brief EzDisplay: View text in a GTK window

@file ezdisplay.py
@package pybooster.ezdisplay
@version 2018.04.27
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
"""


from sys import stdin

from gi import require_version
require_version(r'Gtk', r'3.0')
from gi.repository import Gtk  # noqa: E402  # pylint: disable=C0413


_GUI = """<?xml version="1.0" encoding="UTF-8"?>
<!-- Generated with glade 3.18.3

Copyright (C) LGPLv3

This file is part of EzDisplay.

EzDisplay is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

EzDisplay is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with EzDisplay.  If not, see <http://www.gnu.org/licenses/>.

Author: Devyn Collier Johnson

-->
<interface>
  <requires lib="gtk+" version="3.12"/>
  <!-- interface-license-type lgplv3 -->
  <!-- interface-name EzDisplay -->
  <!-- interface-description Display the contents of a file or command-output -->
  <!-- interface-copyright LGPLv3 -->
  <!-- interface-authors Devyn Collier Johnson -->
  <object class="GtkApplicationWindow" id="ezdisplay">
    <property name="visible">True</property>
    <property name="can_focus">False</property>
    <property name="title" translatable="yes">EzDisplay</property>
    <property name="default_width">600</property>
    <property name="default_height">500</property>
    <signal name="damage-event" handler="_winexit" swapped="no"/>
    <signal name="delete-event" handler="_winexit" swapped="no"/>
    <signal name="destroy" handler="_winexit" swapped="no"/>
    <signal name="destroy-event" handler="_winexit" swapped="no"/>
    <child>
      <object class="GtkBox" id="box2">
        <property name="visible">True</property>
        <property name="can_focus">False</property>
        <property name="margin_top">5</property>
        <property name="margin_bottom">5</property>
        <property name="orientation">vertical</property>
        <child>
          <object class="GtkViewport" id="viewport1">
            <property name="visible">True</property>
            <property name="can_focus">False</property>
            <property name="margin_left">5</property>
            <property name="margin_right">5</property>
            <property name="margin_top">5</property>
            <property name="margin_bottom">5</property>
            <child>
              <object class="GtkScrolledWindow" id="scrolledwindow1">
                <property name="width_request">600</property>
                <property name="height_request">500</property>
                <property name="visible">True</property>
                <property name="can_focus">True</property>
                <property name="shadow_type">in</property>
                <child>
                  <object class="GtkTextView" id="textview">
                    <property name="visible">True</property>
                    <property name="can_focus">True</property>
                  </object>
                </child>
              </object>
            </child>
          </object>
          <packing>
            <property name="expand">True</property>
            <property name="fill">True</property>
            <property name="position">0</property>
          </packing>
        </child>
        <child>
          <object class="GtkLabel" id="viewing_label">
            <property name="visible">True</property>
            <property name="can_focus">False</property>
            <property name="justify">center</property>
            <property name="selectable">True</property>
            <property name="track_visited_links">False</property>
          </object>
          <packing>
            <property name="expand">False</property>
            <property name="fill">True</property>
            <property name="padding">5</property>
            <property name="position">1</property>
          </packing>
        </child>
        <child>
          <object class="GtkButton" id="_close">
            <property name="label">gtk-close</property>
            <property name="width_request">100</property>
            <property name="visible">True</property>
            <property name="can_focus">True</property>
            <property name="receives_default">True</property>
            <property name="halign">center</property>
            <property name="use_stock">True</property>
            <property name="image_position">top</property>
            <property name="always_show_image">True</property>
            <signal name="clicked" handler="_winexit" object="ezdisplay" swapped="no"/>
          </object>
          <packing>
            <property name="expand">False</property>
            <property name="fill">True</property>
            <property name="pack_type">end</property>
            <property name="position">2</property>
          </packing>
        </child>
      </object>
    </child>
  </object>
</interface>"""


def readpipe() -> str:
    """Read from pipe"""
    while True:
        _input = r''
        _character = stdin.read(1)
        while _character:
            _input += _character
            _character = stdin.read(1)
        return str(_input)


class MainWin():  # pylint: disable=R0903
    """Main Window"""

    def __init__(self):
        """Initialize the main window"""
        self.interface = Gtk.Builder()
        self.interface.add_from_string(buffer=_GUI)
        dic = {r'_winexit': Gtk.main_quit}  # Match signal to function (handler)
        self.interface.connect_signals(dic)
        _label = self.interface.get_object(r'viewing_label')
        _label.set_text(r'EzDisplay')
        _textview = self.interface.get_object(r'textview')
        _textbuffer = _textview.get_buffer()
        _textbuffer.set_text(readpipe())


if __name__ == '__main__':
    WINDOW = MainWin()
    Gtk.main()
