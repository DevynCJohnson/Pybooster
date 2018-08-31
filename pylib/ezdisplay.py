#!/usr/bin/env python3
# -*- coding: utf-8-unix; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
"""@brief EzDisplay: Display the contents of a file or command-output in a GTK window

@file ezdisplay.py
@package pybooster.ezdisplay
@version 2018.08.31
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


from sys import argv, stdin
from traceback import format_exc

from gi import require_version
require_version(r'Gtk', r'3.0')
from gi.repository import Gtk  # noqa: E402  # pylint: disable=C0413


_GUI: str = """<?xml version="1.0" encoding="UTF-8"?>
<!-- Generated with glade 3.22.1

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
  <requires lib="gtk+" version="3.20"/>
  <!-- interface-license-type lgplv3 -->
  <!-- interface-name EzDisplay -->
  <!-- interface-description Display the contents of a file or command-output -->
  <!-- interface-copyright LGPLv3 -->
  <!-- interface-authors Devyn Collier Johnson -->
  <object class="GtkApplicationWindow" id="ezdisplay">
    <property name="visible">True</property>
    <property name="can_focus">False</property>
    <property name="title" translatable="yes">EzDisplay</property>
    <property name="default_width">1200</property>
    <property name="default_height">600</property>
    <signal name="damage-event" handler="_winexit" swapped="no"/>
    <signal name="delete-event" handler="_winexit" swapped="no"/>
    <signal name="destroy" handler="_winexit" swapped="no"/>
    <signal name="destroy-event" handler="_winexit" swapped="no"/>
    <child>
      <placeholder/>
    </child>
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
                <property name="width_request">1200</property>
                <property name="height_request">600</property>
                <property name="visible">True</property>
                <property name="can_focus">True</property>
                <property name="shadow_type">in</property>
                <child>
                  <object class="GtkTextView" id="textview">
                    <property name="visible">True</property>
                    <property name="can_focus">True</property>
                    <property name="monospace">True</property>
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
            <property name="visible">True</property>
            <property name="can_focus">True</property>
            <property name="receives_default">True</property>
            <property name="halign">center</property>
            <property name="use_stock">True</property>
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


def getinput() -> str:
    """Read from a file or pipe"""
    try:
        if len(argv) == 1:
            while True:
                _input = r''
                _character = stdin.read(1)
                while _character:
                    _input += _character
                    _character = stdin.read(1)
                return str(_input)
        elif argv[1]:
            _out: list = []
            with open(argv[1], mode=r'rt', encoding=r'utf-8') as _file:
                _out.append(r''.join(_file.readlines()).strip())
            return r''.join(_out)
    except BaseException:
        return format_exc() + '\n'
    return r'No input data provided!'


class MainWin():  # pylint: disable=R0903
    """Main Window"""

    def __init__(self):
        """Initialize the main window"""
        self.interface = Gtk.Builder()
        self.interface.add_from_string(buffer=_GUI)
        self.interface.connect_signals({r'_winexit': Gtk.main_quit})  # Match signal to function (handler)
        _textbuffer = self.interface.get_object(r'textview').get_buffer()
        _textbuffer.set_text(getinput())


if __name__ == '__main__':
    WINDOW = MainWin()
    Gtk.main()
