#!/usr/bin/env python3
# -*- coding: utf-8-unix; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
"""@brief EZ-Win: Pre-built windows using GTK3 for Python3

@file ezwin.py
@package pybooster.ezwin.ezwin
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


# pylint: disable=C0103


from os.path import dirname, join as pathjoin, normcase, realpath
from signal import SIGINT, SIG_DFL, signal
from sys import argv, stdout

from gi import require_version
require_version(r'Gtk', r'3.0')
from gi.repository import Gtk  # noqa: E402  # pylint: disable=C0413


# GLOBAL DATA #


__all__ = [
    r'ezcolor',
    r'ezerr',
    r'ezfilech',
    r'ezinfo',
    r'ezmsg',
    r'ezpswd',
    r'ezq',
    r'ezsecurity',
    r'eztext',
    r'ezupd',
    r'ezwarn'
]


__author__ = r'Devyn Collier Johnson'
__copyright__ = r'LGPLv3'
__version__ = r'2018.04.27'


__about__ = (
    '\n\n=====ABOUT=====\n\n'
    '    Created by Devyn Collier Johnson\n'
    '    <DevynCJohnson@Gmail.com>\n'
    '    LGPL3\n'
    '    -- --\n'
    '    EZ-Win - Pre-built windows using GTK3 for Python3\n'
    '    Version - ' + __version__ + '\n\n'
)


__usage_sh__ = """\n\n=====USAGE (Shell/Terminal)=====\n
    ezwin [-h|--help|--api|-v|--version|-d|--doc]
    ezwin -[-FLAG] "Message"  # Message, Question, and Password dialogs
    ezwin --ynq "Message"  # Yes/No/Quit dialog
    ezwin --text "Message"  # Text entry
    ezwin --textcancel "Message"  # Text entry (with cancel)
    ezwin -p "Message"  # Password dialog
    ezwin -f|--file [ARGS]  # File chooser (file)
    ezwin --dir|--folder [ARGS]  # File chooser (directory)
    ezwin --[color|colour] [ARGS]  # Select a color

    Examples

        # Display text/message
        user@host:$ ezwin -i "This is a message."

        # Display command output
        user@host:$ ezwin -i `whoami`

        # Display command output (multi-line)
        user@host:$ ezwin -i $(whoami; echo '\\n'; date)

        # Similarly,
        user@host:$ ezwin -i "$(cat /etc/hosts)"

        # Select a color and save the returned value to a file
        user@host:$ ezwin --color > FILE

        # Remove a file
        user@host:$ rm `ezwin -f --str -n`

        # Choose where to save data; then select a color
        # The data is sent to the choosen file
        user@host:$ ezwin --color > `ezwin -f --save --str -n`

        # Select a color; then choose where to save data
        # The data is sent to the choosen file
        # Then, the value is displayed
        user@host:$ X=$(ezwin --color); \\
            echo $X > `ezwin -f --save --str -n`; \\
            ezwin -m $X

        # Alternately,
        user@host:$ X=$(ezwin --color); \\
            Y=$(ezwin -f --save --str -n); \\
            echo $X > $Y; \\
            ezwin -m `cat $Y`

"""


__usage_py__ = """\n\n=====USAGE (Python)=====

    import ezwin
    ezwin.ezinfo('This is an example.')

"""


__flags__ = """\n\n=====FLAGS (Shell/Terminal)=====

    --api
            Display details about the API

    -h,--help
            Display help info

    -d,--doc
            Display docstrings

    -v,--version
            Display version

    --color,--colour
            Color Dialog

    -f,--file,--dir,--folder
            File Chooser Dialog

                -m
                    Select multiple files

                -h
                    Show hidden files

                --save
                    Save a file or set of files

                --local
                    Local files only (no samba, ftp, etc.),

                -n,--uri
                    -n = return name
                    --uri = return URI

                --str,--list
                    --str = return output as a string
                    --list = return output as a list

                --ext
                    Disable the "choose filetype" menu

                --path,-p
                    Initial path of file chooser
                    This argument must be the last one listed

    -i,--info
            Information Dialog

    -m,--msg
            Message Dialog

    -w,--warn
            Warning Dialog

    -e,--err
            Error Dialog

    -u,--up,--update
            Update Dialog

    -s,--security
            Security Dialog

    -q,--yn
            Question Dialog with Yes/No

    --ync,--ynclose
            Question Dialog with Yes/No/Close

    --ynq,--ynquit
            Question Dialog with Yes/No/Quit

    -c,--yncancel
            Question Dialog with Yes/No/Cancel

    -x,-t,--text
            Input Text Dialog

    --tc,--textcancel,--canceltext
            Input Text Dialog with 'Cancel'

    -p,--pw,--pwd,--pswd,--password
            Password Dialog

    --pc,--pwdc,--passwordcancel
            Password Dialog with 'Cancel'

"""


__examples__ = """\n\n=====BASIC PYTHON EXAMPLES=====

    import ezwin

    print(ezwin.__doc__)  # Print help info

    ezwin.ezinfo('Information')  # No output
        Information Dialog

    ezwin.ezmsg('Message')  # No output
        Message Dialog

    ezwin.ezwarn('Warning')  # No output
        Warning Dialog

    ezwin.ezerr('Error')  # No output
        Error Dialog

    ezwin.ezupd('Update Message')  # No output
        Update Dialog

    ezwin.ezsecurity('Security Message')  # No output
        Security Dialog

    ezwin.ezq('Question', 'yn')  # Return user's answer
        Question Dialog with Yes/No

    ezwin.ezcolor()  # Return RGBA color code
        Color Dialog

    ezwin.eztext('Message')  # Return entered text
        Input Text Dialog

    ezwin.eztext('Message', 'c')  # Return entered text
        Input Text Dialog with 'Cancel'

    ezwin.ezpswd('Message')  # Return entered password
        Password Dialog

    ezwin.ezpswd('Message', 'c')  # Return entered password
        Password Dialog with 'Cancel'

    ==File Chooser Dialog==

    ezfilech()  # Return the selected file's pathname as a list

    ezfilech(_return_dtype='str')  # Return selected pathname as str

    ezfilech(_multiple=True)  # Return list of selected files

    ezfilech(_save=True)  # Return the desired pathname for a file

    ezfilech(_select_file: bool=True, _select_dir: bool=False,
            _multiple: bool=False, _save: bool=False,
            _viewhidden: bool=False, _file_exten: bool=True,
            _init_path: str='', _local: bool=True,
            _return_uri: bool=True, _return_dtype: str='list',
        ) -> list or str:

"""


__help__ = (
    '\n=====EZ-Win Documentation=====\n' +
    __about__ + __usage_sh__ + __usage_py__ + __flags__ + __examples__
)


__api__ = """\n\n=====EZ-Win API=====

    =====DEFINE FILES (_G* = glade-file)=====

        # Information Dialog (ezinfo)
        _GINFO = pathjoin(_PATH, 'info.glade')
        # Error Dialog (ezerr)
        _GERR = pathjoin(_PATH, 'err.glade')
        # Warning Dialog (ezwarn)
        _GWARN = pathjoin(_PATH, 'warn.glade')
        # Message Dialog (ezmsg)
        _GMSG = pathjoin(_PATH, 'msg.glade')
        # Update Dialog (ezupd)
        _GUPD = pathjoin(_PATH, 'upd.glade')
        # Security Dialog (ezsecurity)
        _GSECURITY = pathjoin(_PATH, 'security.glade')
        # Color Chooser (ezcolor)
        _GCOLOR = pathjoin(_PATH, 'color.glade')
        # Password Dialog (ezpswd)
        _GPSWD = pathjoin(_PATH, 'pswd.glade')
        # Password Dialog with 'Cancel' (ezpswd)
        _GPSWDC = pathjoin(_PATH, 'pswdc.glade')
        # Input Text Dialog (eztext)
        _GTEXT = pathjoin(_PATH, 'text.glade')
        # Input Text Dialog with 'Cancel' (eztext)
        _GTEXTC = pathjoin(_PATH, 'textc.glade')
        # Question Dialog with Yes/No/Cancel (ezq)
        _GQYNCANCEL = pathjoin(_PATH, 'qyncancel.glade')
        # Question Dialog with Yes/No/Close (ezq)
        _GQYNCLOSE = pathjoin(_PATH, 'qynclose.glade')
        # Question Dialog with Yes/No (ezq)
        _GQYN = pathjoin(_PATH, 'qyn.glade')
        # Question Dialog with Yes/No/Quit (ezq)
        _GQYNQ = pathjoin(_PATH, 'qynq.glade')
        # File Chooser Dialog (ezfilech)
        _GFILECH = pathjoin(_PATH, 'filech.glade')


    =====NAMING SCHEME=====

    Functions        -> ez*
    Glade-file vars  -> _G*
    Glade-files      -> *.glade

    *The names of various objects match with their corresponding object
    *Example for Info Dialog
        Function        -> ezinfo
        Glade-file var  -> _GINFO
        Glade-file      -> info.glade


    =====HEADERS=====

        def ezinfo(_msg: str='Information') -> None:

        def ezmsg(_msg: str='Message') -> None:

        def ezwarn(_msg: str='Warning') -> None:

        def ezerr(_msg: str='Error Message') -> None:

        def ezupd(_msg: str='Message') -> None:

        def ezsecurity(_msg: str='Security Message') -> None:

        def ezq(_msg: str='Question', _type: str='yn') -> str:

        def ezcolor(_datatype: str='list') -> type:

        def eztext(_msg: str='Message', _type: str='') -> str:

        def ezpswd(_msg: str='Message', _type: str='') -> str:

        def ezfilech(_select_file: bool=True, _select_dir: bool=False,
                _multiple: bool=False, _save: bool=False,
                _viewhidden: bool=False, _file_exten: bool=True,
                _init_path: str='', _local: bool=True,
                _return_uri: bool=True, _return_dtype: str='list',
            ) -> list or str:

"""


_EXCEPTION_MSG = (r'INVALID PARAMETERS!' + __usage_sh__)
_PATH = normcase(dirname(realpath(normcase(__file__))))


# Define Files (_G* = glade-file)
# Information Dialog (ezinfo)
_GINFO = pathjoin(_PATH, r'info.glade')
# Error Dialog (ezerr)
_GERR = pathjoin(_PATH, r'err.glade')
# Warning Dialog (ezwarn)
_GWARN = pathjoin(_PATH, r'warn.glade')
# Message Dialog (ezmsg)
_GMSG = pathjoin(_PATH, r'msg.glade')
# Update Dialog (ezupd)
_GUPD = pathjoin(_PATH, r'upd.glade')
# Security Dialog (ezsecurity)
_GSECURITY = pathjoin(_PATH, r'security.glade')
# Color Chooser (ezcolor)
_GCOLOR = pathjoin(_PATH, r'color.glade')
# Password Dialog (ezpswd)
_GPSWD = pathjoin(_PATH, r'pswd.glade')
# Password Dialog with 'Cancel' (ezpswd)
_GPSWDC = pathjoin(_PATH, r'pswdc.glade')
# Input Text Dialog (eztext)
_GTEXT = pathjoin(_PATH, r'text.glade')
# Input Text Dialog with 'Cancel' (eztext)
_GTEXTC = pathjoin(_PATH, r'textc.glade')
# Question Dialog with Yes/No/Cancel (ezq)
_GQYNCANCEL = pathjoin(_PATH, r'qyncancel.glade')
# Question Dialog with Yes/No/Close (ezq)
_GQYNCLOSE = pathjoin(_PATH, r'qynclose.glade')
# Question Dialog with Yes/No (ezq)
_GQYN = pathjoin(_PATH, r'qyn.glade')
# Question Dialog with Yes/No/Quit (ezq)
_GQYNQ = pathjoin(_PATH, r'qynq.glade')
# File Chooser Dialog (ezfilech)
_GFILECH = pathjoin(_PATH, r'filech.glade')


signal(SIGINT, SIG_DFL)


# EZWIN WINDOW FUNCTIONS #


def ezinfo(_msg: str = r'Information') -> None:
    """Information Dialog: Display some information"""
    ui = Gtk.Builder()
    ui.add_from_file(_GINFO)
    ui.connect_signals({r'_winexit': Gtk.main_quit})
    l_msg = ui.get_object(r'l_msg')
    l_msg.set_text(_msg)
    Gtk.main()
    return


def ezmsg(_msg: str = r'Message') -> None:
    """Message Dialog: Display a message"""
    ui = Gtk.Builder()
    ui.add_from_file(_GMSG)
    ui.connect_signals({r'_winexit': Gtk.main_quit})
    l_msg = ui.get_object(r'l_msg')
    l_msg.set_text(_msg)
    Gtk.main()
    return


def ezwarn(_msg: str = r'Warning') -> None:
    """Warning Dialog: Display a warning message"""
    ui = Gtk.Builder()
    ui.add_from_file(_GWARN)
    ui.connect_signals({r'_winexit': Gtk.main_quit})
    l_msg = ui.get_object(r'l_msg')
    l_msg.set_text(_msg)
    Gtk.main()
    return


def ezerr(_msg: str = r'Error Message') -> None:
    """Error Dialog: Display an error message"""
    ui = Gtk.Builder()
    ui.add_from_file(_GERR)
    ui.connect_signals({r'_winexit': Gtk.main_quit})
    l_msg = ui.get_object(r'l_msg')
    l_msg.set_text(_msg)
    Gtk.main()
    return


def ezupd(_msg: str = r'Message') -> None:
    """Update Dialog: Display information on an update"""
    ui = Gtk.Builder()
    ui.add_from_file(_GUPD)
    ui.connect_signals({r'_winexit': Gtk.main_quit})
    l_msg = ui.get_object(r'l_msg')
    l_msg.set_text(_msg)
    Gtk.main()
    return


def ezsecurity(_msg: str = r'Security Message') -> None:
    """Security Dialog: Display a security-related message"""
    ui = Gtk.Builder()
    ui.add_from_file(_GSECURITY)
    ui.connect_signals({r'_winexit': Gtk.main_quit})
    l_msg = ui.get_object(r'l_msg')
    l_msg.set_text(_msg)
    Gtk.main()
    return


def ezq(_msg: str = r'Question', _type: str = r'yn') -> str:
    """Question Dialog: Ask the user a question

    '_type' is a string that may have one of several values and effects.
    Each choice determines the buttons on the window.
    'Yes' and 'No' are included in all choices
    'yn' || 'yesno': Only use 'Yes' and 'No' buttons
    'ynq' || 'quit': Add a 'Quit' button
    'ynclose' || 'close': Add a 'Close' button
    'yncancel' || 'cancel': Add a 'Cancel' button
    """
    if _type.lower() in {r'yn', r'yesno'}:
        _gf = _GQYN
    elif _type.lower() in {r'ynq', r'quit'}:
        _gf = _GQYNQ
    elif _type.lower() in {r'ynclose', r'close'}:
        _gf = _GQYNCLOSE
    elif _type.lower() in {r'yncancel', r'cancel'}:
        _gf = _GQYNCANCEL
    else:
        raise Exception(
            'INVALID WINDOW TYPE! Usage: '
            'ezquestion(_msg: str = \'Question\', _type: str = \'yn\') '
            'where _type is yn,ynq,ynclose,yncancel'
        )
    ui = Gtk.Builder()
    ui.add_from_file(_gf)
    _out = ''

    def _yes(*_x) -> None:
        """YES Button"""
        nonlocal _out
        _out = r'True'
        Gtk.main_quit()
        return

    def _no(*_x) -> None:
        """NO Button"""
        nonlocal _out
        _out = r'False'
        Gtk.main_quit()
        return

    def _close(*_x) -> None:
        """CLOSE Button"""
        nonlocal _out
        _out = r'Close'
        Gtk.main_quit()
        return

    def _cancel(*_x) -> None:
        """CANCEL Button"""
        nonlocal _out
        _out = r'Cancel'
        Gtk.main_quit()
        return

    def _quit(*_x) -> None:
        """QUIT Button"""
        nonlocal _out
        _out = r'Quit'
        Gtk.main_quit()
        return

    ui.connect_signals({
        r'_winexit': Gtk.main_quit,
        r'_yes': _yes,
        r'_no': _no,
        r'_quit': _quit,
        r'_close': _close,
        r'_cancel': _cancel,
    })
    l_msg = ui.get_object(r'l_msg')
    l_msg.set_text(_msg)
    Gtk.main()
    return _out


def ezcolor(_datatype: str = r'list') -> type:
    """Color Dialog: Select a color"""
    ui = Gtk.Builder()
    ui.add_from_file(_GCOLOR)
    _cc = ui.get_object(r'cc')
    _rgba = None

    def _submit_color(*_x) -> None:
        """SUBMIT Button: Submit color values for processing"""
        nonlocal _rgba
        _rgba = _cc.get_rgba()
        Gtk.main_quit()
        return

    ui.connect_signals({
        r'_winexit': Gtk.main_quit,
        r'_submit_color': _submit_color,
    })
    Gtk.main()
    if _rgba:
        _round = 6
        _r = round(_rgba.red, _round)
        _g = round(_rgba.green, _round)
        _b = round(_rgba.blue, _round)
        _a = round(_rgba.alpha, _round)
        if _datatype.lower() in {r'list', r'lst'}:
            _lst = []
            _lst.append(_r)
            _lst.append(_g)
            _lst.append(_b)
            _lst.append(_a)
            return _lst
        elif _datatype.lower() in {r'dict', r'dic'}:
            _dict = {r'red': _r, r'green': _g, r'blue': _b, r'alpha': _a}
            return _dict
        elif _datatype.lower() in {r'str', r'string'}:
            _x = str(_r) + r' ' + str(_g) + r' ' + str(_b) + r' ' + str(_a)
            return _x
        return _rgba
    return None


def eztext(_msg: str = r'Message', _type: str = r'') -> str:
    """Input Text Dialog: Get text from the user"""
    ui = Gtk.Builder()
    if r'c' in _type.lower():
        _gf = _GTEXTC
    else:
        _gf = _GTEXT
    ui.add_from_file(_gf)
    _obj = ui.get_object(r'entry1')
    _out = ''

    def _submit_text(*_x) -> None:
        """SUBMIT Button: Submit text for processing"""
        nonlocal _out
        _out = _obj.get_text()
        Gtk.main_quit()
        return

    ui.connect_signals({
        r'_winexit': Gtk.main_quit,
        r'_submit_text': _submit_text,
        r'_cancel': Gtk.main_quit,
    })
    l_msg = ui.get_object(r'l_msg')
    l_msg.set_text(_msg)
    Gtk.main()
    return _out


def ezpswd(_msg: str = r'Message', _type: str = r'') -> str:
    """Password Dialog: Get a password from the user"""
    ui = Gtk.Builder()
    if r'c' in _type.lower():
        _gf = _GPSWDC
    else:
        _gf = _GPSWD
    ui.add_from_file(_gf)
    _obj = ui.get_object(r'entry1')
    _out = r''

    def _submit_text(*_x) -> None:
        """SUBMIT Button: Submit password for processing"""
        nonlocal _out
        _out = _obj.get_text()
        Gtk.main_quit()
        return

    ui.connect_signals({
        r'_winexit': Gtk.main_quit,
        r'_submit_text': _submit_text,
        r'_cancel': Gtk.main_quit,
    })
    l_msg = ui.get_object(r'l_msg')
    l_msg.set_text(_msg)
    Gtk.main()
    return _out


def ezfilech(  # noqa: C901
        _select_file: bool = True,
        _select_dir: bool = False,
        _multiple: bool = False,
        _save: bool = False,
        _viewhidden: bool = False,
        _file_exten: bool = True,
        _init_path: str = '',
        _local: bool = True,
        _return_uri: bool = True,
        _return_dtype: str = r'list'
) -> list or str:
    """File Chooser Dialog: Select a file or folder"""
    ui = Gtk.Builder()
    ui.add_from_file(_GFILECH)
    _filew = ui.get_object(r'filechooser')
    _chkbtn_hidden = ui.get_object(r'chkbtn1')
    _chkbtn_dir = ui.get_object(r'chkbtn2')
    _out = []
    _chkbtn_dir.set_visible(False)
    _filew.set_create_folders(_save)
    _filew.set_select_multiple(_multiple)
    _filew.set_local_only(_local)
    _filew.set_show_hidden(_viewhidden)
    _chkbtn_hidden.set_active(_viewhidden)
    if _init_path:
        try:
            _filew.set_current_folder(_init_path)
        except (NameError, OSError, TypeError, ValueError):
            pass
    if _select_dir and not _save:
        _filew.set_action(Gtk.FileChooserAction.SELECT_FOLDER)
        _chkbtn_dir.set_visible(not _multiple)
    elif _select_dir and _save:
        _multiple = False
        _filew.set_action(Gtk.FileChooserAction.CREATE_FOLDER)
        _filew.set_do_overwrite_confirmation(True)
    elif _select_file and not _save:
        _filew.set_action(Gtk.FileChooserAction.OPEN)
    elif _select_file and _save:
        _multiple = False
        _filew.set_action(Gtk.FileChooserAction.SAVE)
        _filew.set_do_overwrite_confirmation(True)
    else:
        _save = False
        _filew.set_action(Gtk.FileChooserAction.OPEN)

    # FILE FILTERS #

    if _select_file and _file_exten:
        _filters = [
            (r'All Files', r'*'),
            (r'Text Files', r'*.[Tt][Xx][Tt]'),
        ]
        for _fltr in _filters:
            _filter = Gtk.FileFilter()
            _filter.set_name(_fltr[0])
            _filter.add_pattern(_fltr[1])
            _filew.add_filter(_filter)
        # INSTALLATION FILES #
        _filter = Gtk.FileFilter()
        _filter.set_name(r'Installation packages')
        _filter.add_pattern(r'*.rpm')
        _filter.add_pattern(r'*.pet')
        _filter.add_pattern(r'*.pup')
        _filter.add_pattern(r'*.srpm')
        _filter.add_pattern(r'*.src.rpm')
        _filter.add_pattern(r'*.delta.rpm')
        _filter.add_pattern(r'*.cpio')
        _filter.add_pattern(r'*.tgz')
        _filter.add_mime_type(r'application/vnd.debian.binary-package')
        # UNOFFICIAL INSTALLATION FILE MIMETYPES #
        _filter.add_mime_type(r'application/x-rpm')
        _filter.add_mime_type(r'application/x-redhat-package-manager')
        _filter.add_mime_type(r'application/x-debian-package')
        _filter.add_mime_type(r'application/x-msi')
        _filter.add_mime_type(r'application/x-gtar')
        _filter.add_mime_type(r'application/x-gtar-compressed')
        _filew.add_filter(_filter)
        # ECMA SCRIPTS #
        _filter = Gtk.FileFilter()
        _filter.set_name(r'ECMA scripts')
        _filter.add_mime_type(r'application/ecmascript')
        _filter.add_mime_type(r'application/javascript')
        _filter.add_mime_type(r'text/ecmascript')  # Unofficial
        _filter.add_mime_type(r'text/javascript')  # Unofficial
        _filter.add_mime_type(r'text/coffeescript')  # Unofficial
        _filter.add_mime_type(r'application/coffeescript')  # Unofficial
        _filter.add_pattern(r'*.coffee')
        _filter.add_mime_type(r'application/x-vbscript')  # Unofficial
        _filter.add_pattern(r'*.vbs')
        _filter.add_mime_type(r'text/jscript')  # Unofficial
        _filter.add_pattern(r'*.js')
        _filter.add_pattern(r'*.jse')
        _filew.add_filter(_filter)
        # MARKUP FILES #
        _filter = Gtk.FileFilter()
        _filter.set_name(r'Markup files')
        _filter.add_mime_type(r'text/SGML')
        _filter.add_mime_type(r'text/html')
        _filter.add_mime_type(r'text/xml')
        _filter.add_mime_type(r'model/x3d+xml')
        _filter.add_mime_type(r'model/x3d-vrml')
        _filter.add_mime_type(r'application/xml')
        _filter.add_mime_type(r'application/xml-dtd')
        _filter.add_mime_type(r'application/xml-external-parsed-entity')
        _filter.add_mime_type(r'application/xhtml+xml')
        _filter.add_mime_type(r'application/ssml+xml')
        _filter.add_mime_type(r'application/soap+xml')
        _filter.add_mime_type(r'application/SGML')
        _filter.add_mime_type(r'application/resource-lists+xml')
        _filter.add_mime_type(r'application/emotionml+xml')
        _filter.add_mime_type(r'application/calendar+xml')
        _filew.add_filter(_filter)
        # MIMETYPES (TOP-LEVEL) #
        _filter = Gtk.FileFilter()
        _filter.set_name(r'Application (Mime-type)')
        _filter.add_mime_type(r'application/*')
        _filew.add_filter(_filter)
        _filter = Gtk.FileFilter()
        _filter.set_name(r'Audio Files')
        _filter.add_mime_type(r'audio/*')
        _filter.add_mime_type(r'application/mp4')
        _filter.add_mime_type(r'application/mpeg4-generic')
        _filter.add_mime_type(r'application/ogg')
        _filew.add_filter(_filter)
        _filter = Gtk.FileFilter()
        _filter.set_name(r'Images')
        _filter.add_mime_type(r'image/*')
        _filew.add_filter(_filter)
        _filter = Gtk.FileFilter()
        _filter.set_name(r'Message (Mime-type)')
        _filter.add_mime_type(r'message/*')
        _filew.add_filter(_filter)
        _filter = Gtk.FileFilter()
        _filter.set_name(r'Model (Mime-type)')
        _filter.add_mime_type(r'model/*')
        _filew.add_filter(_filter)
        _filter = Gtk.FileFilter()
        _filter.set_name(r'Multipart (Mime-type)')
        _filter.add_mime_type(r'multipart/*')
        _filew.add_filter(_filter)
        _filter = Gtk.FileFilter()
        _filter.set_name(r'Text (Mime-type)')
        _filter.add_mime_type(r'text/*')
        _filew.add_filter(_filter)
        _filter = Gtk.FileFilter()
        _filter.set_name(r'Videos')
        _filter.add_mime_type(r'video/*')
        _filew.add_filter(_filter)

    # HANDLER FUNCTIONS #

    def _cancel(*_x) -> None:
        """CANCEL Button"""
        nonlocal _out
        _out = r'Cancel'
        Gtk.main_quit()
        return

    def _select(*_x) -> None:
        """SELECT Button: Submit selection for processing"""
        nonlocal _out
        if _select_dir and not _multiple and _chkbtn_dir.get_active():
            if _return_uri and _return_dtype == r'str':
                _out = r' '.join(_filew.get_current_folder_uri())
            elif _return_uri and _return_dtype != r'str':
                _out = _filew.get_current_folder_uri()
            elif not _return_uri and _return_dtype == r'str':
                _out = r' '.join(_filew.get_current_folder())
            else:
                _out = _filew.get_current_folder()
        else:
            if _return_uri and _return_dtype == r'str':
                _out = r' '.join(_filew.get_uris())
            elif _return_uri and _return_dtype != r'str':
                _out = _filew.get_uris()
            elif not _return_uri and _return_dtype == r'str':
                _out = r' '.join(_filew.get_filenames())
            else:
                _out = _filew.get_filenames()
        Gtk.main_quit()
        return

    def _hidden(_widget, *_x) -> None:
        """HIDDEN Checkbox: Toggle the visibility of hidden files"""
        _widget.set_show_hidden(not _widget.get_show_hidden())
        return

    ui.connect_signals({
        r'_winexit': Gtk.main_quit,
        r'_cancel': _cancel,
        r'_select': _select,
        r'_hidden': _hidden,
    })
    Gtk.main()
    return _out


# MAIN #


if __name__ == '__main__':  # noqa: C901
    # Command help/info
    if len(argv) == 2 and argv[1].lower() in {r'-h', r'--help'}:
        stdout.write(__help__ + '\n')
        raise SystemExit()
    elif len(argv) == 2 and argv[1].lower() == r'--api':
        stdout.write(__api__ + '\n')
        raise SystemExit()
    elif len(argv) == 2 and argv[1].lower() in {r'-v', r'--version'}:
        stdout.write(__version__ + '\n')
        raise SystemExit()
    elif len(argv) == 2 and argv[1].lower() in {r'-d', r'--doc'}:
        stdout.write(__doc__ + '\n')
        stdout.write(__version__ + '\n')
        stdout.write(__copyright__ + '\n')
        stdout.write(__help__ + '\n')
        stdout.write(__api__ + '\n')
        raise SystemExit()
    # Windows/GUI
    elif argv[1].lower() in {r'-f', r'--file', r'--dir', r'--folder'}:
        # File chooser
        multiple = False
        viewhidden = False
        save = False
        return_uri = True
        init_path = r''
        return_dtype = r'list'
        __local = True
        file_exten = True
        if len(argv) > 2:
            if r'-m' in argv[2:]:
                # Select multiple files
                multiple = True
            if r'-h' in argv[2:]:
                # Show hidden files
                viewhidden = True
            if r'--save' in argv[2:]:
                # Enable save-mode
                save = True
            if r'--local' in argv[2:]:
                # Local files only (no samba, ftp, etc.)
                __local = True
            if r'-n' in argv[2:] and r'--uri' not in argv[2:]:
                # -n = return name
                # --uri = return URI
                return_uri = False
            if r'--str' in argv[2:] and r'--list' not in argv[2:]:
                # --str = return as a string
                # --list = return as a list
                return_dtype = 'str'
            if r'--ext' in argv[2:]:
                # Disable the "choose filetype" menu
                file_exten = False
            if r'--path' in argv[-2:] or r'-p' in argv[-2:]:
                # Specify initial path
                # This must be the last parameter (--path PATH)
                init_path = argv[-1]
        if argv[1].lower() in {r'-f', r'--file'}:
            stdout.write(ezfilech(
                True, False, multiple, save, viewhidden,
                file_exten, init_path, __local,
                return_uri, return_dtype
            ) + '\n')
        elif argv[1].lower() in {r'--dir', r'--folder'}:
            stdout.write(ezfilech(
                False, True, multiple, save, viewhidden,
                file_exten, init_path, __local,
                return_uri, return_dtype
            ) + '\n')
        raise SystemExit()
    elif argv[1].lower() in {r'--color', r'--colour'}:
        # Color selector
        if len(argv) == 3 and argv[2].lower() in {r'list', r'lst'}:
            stdout.write(ezcolor(r'list') + '\n')
        elif len(argv) == 3 and argv[2].lower() in {r'dict', r'dic'}:
            stdout.write(ezcolor(r'dict') + '\n')
        elif len(argv) == 3 and argv[2].lower() in {r'str', r'string'}:
            stdout.write(ezcolor(r'str') + '\n')
        else:
            stdout.write(ezcolor(r'rgba') + '\n')
        raise SystemExit()
    elif len(argv) >= 3:
        _wintype = argv[1].lower()
        MESSAGE = r' '.join(
            str(i) for i in argv[2:]
        ).replace('\\n', '\n').replace('\\t', '\t')
        if _wintype in {r'-i', r'--info'}:  # Info window
            ezinfo(MESSAGE)
        elif _wintype in {r'-m', r'--msg'}:  # Message window
            ezmsg(MESSAGE)
        elif _wintype in {r'-w', r'--warn'}:  # Warning window
            ezwarn(MESSAGE)
        elif _wintype in {r'-e', r'--err'}:  # Error window
            ezerr(MESSAGE)
        elif _wintype in {r'-u', r'--up', r'--update'}:  # Update-info window
            ezupd(MESSAGE)
        elif _wintype in {r'-s', r'--security'}:  # Security-info window
            ezsecurity(MESSAGE)
        elif _wintype in {r'-q', r'--yn'}:  # Question window
            stdout.write(ezq(MESSAGE, 'yesno') + '\n')
        elif _wintype in {r'--ync', r'--ynclose'}:  # Question window
            stdout.write(ezq(MESSAGE, 'close') + '\n')
        elif _wintype in {r'--ynq', r'--ynquit'}:  # Question window
            stdout.write(ezq(MESSAGE, 'quit') + '\n')
        elif _wintype in {r'-c', r'--yncancel'}:  # Question window
            stdout.write(ezq(MESSAGE, 'cancel') + '\n')
        elif _wintype in {r'-x', r'-t', r'--text'}:  # Text-input window
            stdout.write(eztext(MESSAGE) + '\n')
        elif _wintype in {r'--tc', r'--textcancel', r'--canceltext'}:  # Text-input window
            stdout.write(eztext(MESSAGE, 'c') + '\n')
        elif _wintype in {r'-p', r'--pw', r'--pwd', r'--pswd', r'--password'}:  # Password-input window
            stdout.write(ezpswd(MESSAGE) + '\n')
        elif _wintype in {r'--pc', r'--pwdc', r'--passwordcancel'}:  # Password-input window
            stdout.write(ezpswd(MESSAGE, 'c') + '\n')
        else:
            raise Exception(_EXCEPTION_MSG)
        raise SystemExit()
    raise Exception(_EXCEPTION_MSG)
