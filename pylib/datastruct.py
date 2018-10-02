#!/usr/bin/env python3
# -*- coding: utf-8-unix; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
"""@brief Functions used to manipulate data structure files such as Config/INI, CSV, JSON, & others

@file datastruct.py
@package pybooster.datastruct
@version 2018.09.22
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


from base64 import b64decode, b64encode
from codecs import open as codec_opener
from collections import OrderedDict
from configparser import ConfigParser, RawConfigParser
from csv import DictReader, DictWriter, QUOTE_MINIMAL, reader as creader, writer as cwriter
from io import StringIO
from json import dumps as jdump, loads as jloads, JSONDecodeError
from pickle import dumps, loads  # nosec
from sys import stderr
from typing import Sequence, Tuple, Union
from zlib import compress as zcompress, decompress as zdecompress

from pybooster.fs import ensurefileexists, getfile, write2file

from pyaml import dump as yamldump
from yaml import MarkedYAMLError, load as yamlload, YAMLError


__all__ = [
    # CONSTANTS #
    r'FALSE_VALUES',
    r'TRUE_VALUES',
    # CONFIG/INI #
    r'openinifile',
    r'write2ini',
    r'ini2str',
    r'get_ini_value',
    r'get_ini_sections',
    r'get_ini_options',
    r'set_ini_value',
    r'convertinibool',
    # CSV #
    r'opencsvfile',
    r'loadcsvstr',
    r'write2csv',
    r'writedict2csv',
    # JSON #
    r'openjsonfile',
    r'write2json',
    r'writeyaml2json',
    r'write2minijson',
    # TSV #
    r'opentsvfile',
    r'write2tsv',
    r'writedict2tsv',
    # YAML #
    r'openyamlfile',
    # CONVERTERS #
    r'csv2json',
    r'dict2csv',
    r'dict2json',
    r'dict2ini',
    r'ini2dict',
    r'ini2json',
    r'json2csv',
    r'json2csvstr',
    r'json2dict',
    r'json2yaml',
    r'yaml2dict',
    r'yaml2json',
    # PICKLE #
    r'data2pklfile',
    r'pklfile2data'
]


# CONSTANTS #


FALSE_VALUES: list = [r'0', r'off', r'false', r'no']
TRUE_VALUES: list = [r'1', r'on', r'true', r'yes']


# CONFIG/INI #


def openinifile(_file: Union[object, str]) -> object:
    """Open an INI file given a pathname or ConfigParser object and return the object"""
    if isinstance(_file, ConfigParser):
        return _file
    if isinstance(_file, StringIO):
        configfile = ConfigParser()
        _file.seek(0)
        configfile.read_file(_file)  # type: ignore
        return configfile
    ensurefileexists(_file)
    configfile = ConfigParser()
    configfile.read(_file)  # type: ignore
    return configfile


def write2ini(_filename: str, _config: object) -> None:
    """Send data to a new INI file or overwrite an existing INI file"""
    with open(_filename, mode=r'wt', encoding=r'utf-8') as _file:
        _config.write(_file)  # type: ignore


def ini2str(_file: object) -> str:
    """Get the string from the ConfigParser"""
    _buf = StringIO(r'')
    _out: str = r''
    _file.write(_buf)  # type: ignore
    _out = _buf.getvalue()
    _buf.close()
    return _out.replace('\n\n', '\n')


def get_ini_value(_file: Union[object, str], _section: str, _opt: str) -> Union[None, str]:
    """Retrieve the value (as a string) from the specified section and option"""
    try:
        return openinifile(_file)[_section][_opt]  # type: ignore
    except KeyError:
        return None


def get_ini_sections(_file: Union[object, str]) -> list:
    """Retrieve a list of the INI file's sections from the specified file"""
    try:
        return openinifile(_file).sections()  # type: ignore
    except KeyError:
        return [r'']


def get_ini_options(_file: Union[object, str], _section: str) -> list:
    """Retrieve a list of the options in a particular section of an INI file from the specified file"""
    try:
        return openinifile(_file).options(_section)  # type: ignore
    except KeyError:
        return [r'']


def set_ini_value(_file: Union[object, str], _section: str, _opt: str, _val: str) -> Tuple[bool, object]:
    """Set the value for the specified section and option and return a tuple containing a success flag and ConfigParser"""
    configfile = openinifile(_file)
    try:
        configfile[_section][_opt] = _val  # type: ignore
        return (True, configfile)
    except KeyError:
        return (False, configfile)


def is_section_in_ini(_file: str, _section: str) -> bool:
    """Return a boolean value indicating the presence of the specified section"""
    return True if _section in openinifile(_file) else False  # type: ignore


def convertinibool(_file: str, _destfile: str) -> None:
    """Convert INI file booleans to 'True'/'False' and write the modified INI data to a file"""
    configfile = openinifile(_file)
    for _section in configfile.sections():  # type: ignore
        for _option in configfile.options(_section):  # type: ignore
            _testval = configfile[_section][_option].lower()  # type: ignore
            if _testval in FALSE_VALUES:
                configfile[_section][_option] = r'False'  # type: ignore
            elif _testval in TRUE_VALUES:
                configfile[_section][_option] = r'True'  # type: ignore
    return write2ini(_destfile, configfile)


# CSV #


def opencsvfile(_filepath: str, _retodict: bool = False, _fieldnames: Union[Sequence[str], None] = None, _delimiter: str = r',', _quotechar: str = r'"') -> list:
    """Convert the specified CSV file to a list of ordered Python dictionaries or a plain list"""
    ensurefileexists(_filepath)
    with codec_opener(_filepath, mode=r'rt', encoding=r'utf-8') as _file:
        if _retodict:
            csvreader = DictReader(_file, fieldnames=_fieldnames, delimiter=_delimiter, quotechar=_quotechar)  # type: ignore
            return [_row for _row in csvreader]
        return list(creader(_file, delimiter=_delimiter, quotechar=_quotechar))


def loadcsvstr(_csv: str, _retodict: bool = False, _fieldnames: Union[Sequence[str], None] = None, _delimiter: str = r',', _quotechar: str = r'"') -> list:
    r"""Convert the specified CSV string to a list of ordered Python dictionaries or a plain list

    >>> loadcsvstr('Val1,Val2,Val3,Val4\n1,2,3,4\n5,6,7,8\n9,10,11,12\n13,14,15,16\n17,18,19,20\n3.14,6.28,2.73,1.57')
    [['Val1', 'Val2', 'Val3', 'Val4'], ['1', '2', '3', '4'], ['5', '6', '7', '8'], ['9', '10', '11', '12'], ['13', '14', '15', '16'], ['17', '18', '19', '20'], ['3.14', '6.28', '2.73', '1.57']]
    """
    if _retodict:
        csvreader = DictReader(StringIO(_csv), fieldnames=_fieldnames, delimiter=_delimiter, quotechar=_quotechar)  # type: ignore
        return [_row for _row in csvreader]
    return list(creader(StringIO(_csv), delimiter=_delimiter, quotechar=_quotechar))


def write2csv(_filename: str, _list: list, _dialect: str = r'unix', _delimiter=r',', _quotechar=r'"') -> None:
    """Send data (as a list) to a new CSV file or overwrite an existing CSV file"""
    with open(_filename, mode=r'wt', encoding=r'utf-8') as _file:
        csvwriter = cwriter(_file, dialect=_dialect, delimiter=_delimiter, quotechar=_quotechar, quoting=QUOTE_MINIMAL)
        for _row in _list:
            csvwriter.writerow(_row)


def writedict2csv(_filename: str, _list: list, _fieldnames: Sequence[str], _dialect: str = r'unix', _delimiter: str = r',', _quotechar: str = r'"') -> None:
    """Send data (as a list of OrderedDicts) to a new CSV file or overwrite an existing CSV file"""
    with open(_filename, mode=r'wt', encoding=r'utf-8') as _file:
        csvwriter = DictWriter(_file, fieldnames=_fieldnames, dialect=_dialect, delimiter=_delimiter, quotechar=_quotechar, quoting=QUOTE_MINIMAL)
        csvwriter.writeheader()
        for _row in _list:
            csvwriter.writerow(_row)


# JSON #


def openjsonfile(_filename: str, _encoding: str = r'utf-8', _jsondata: bool = True) -> Union[dict, str]:
    """Open an JSON file given a pathname and return the object as a dict or str (if `_jsondata` is set to `False`)"""
    try:
        _out: list = []
        ensurefileexists(_filename)
        with codec_opener(_filename, mode=r'rt', encoding=_encoding, buffering=1) as _file:
            _out.append(r''.join(_file.readlines()))
        return jloads(r''.join(_out)) if _jsondata else r''.join(_out)
    except JSONDecodeError:
        stderr.write('The JSON file is malformed!\n')
        raise SystemExit(1)
    except (LookupError, UnicodeError):
        stderr.write('Unable to determine and process data encoding!\n')
        raise SystemExit(1)


def write2json(_filename: str, _dict: dict, _indent: int = 2, _sort_keys: bool = True) -> None:
    """Send data to a new JSON file or overwrite an existing JSON file"""
    with open(_filename, mode=r'wt', encoding=r'utf-8') as _file:
        _file.write(jdump(_dict, indent=2, separators=(r', ', r': '), sort_keys=_sort_keys))


def writeyaml2json(_filename: str, _yamlfile: str, _indent: int = 2, _sort_keys: bool = True, _minify: bool = False) -> None:
    """Convert YAML to JSON and write the JSON file (overwrites exist JSON files)"""
    ensurefileexists(_yamlfile)
    _tmpyaml: dict = yamlload(_yamlfile)  # nosec
    _out: str = jdump(_tmpyaml, indent=0, separators=(r',', r':'), sort_keys=_sort_keys).replace('\n', r'') if _minify else jdump(_tmpyaml, indent=2, separators=(r', ', r': '), sort_keys=_sort_keys)
    with open(_filename, mode=r'wt', encoding=r'utf-8') as _file:
        _file.write(_out)


def write2minijson(_filename: str, _dict: dict, _sort_keys: bool = True) -> None:
    """Send minified JSON data to a new JSON file or overwrite an existing JSON file"""
    with open(_filename, mode=r'wt', encoding=r'utf-8') as _file:
        _file.write(jdump(_dict, indent=0, separators=(r',', r':'), sort_keys=_sort_keys).replace('\n', r''))


# TSV #


def opentsvfile(_filepath: str, _retodict: bool = False, _fieldnames: Union[Sequence[str], None] = None, _quotechar: str = r'"') -> list:
    """Convert the specified TSV file to a list of ordered Python dictionaries or a plain list"""
    ensurefileexists(_filepath)
    with codec_opener(_filepath, mode=r'rt', encoding=r'utf-8') as _file:
        if _retodict:
            csvreader = DictReader(_file, fieldnames=_fieldnames, delimiter='\t', quotechar=_quotechar)  # type: ignore
            return [_row for _row in csvreader]
        return list(creader(_file, delimiter='\t', quotechar=_quotechar))


def write2tsv(_filename: str, _list: list, _dialect: str = r'unix', _quotechar=r'"') -> None:
    """Send data (as a list) to a new TSV file or overwrite an existing TSV file"""
    with open(_filename, mode=r'wt', encoding=r'utf-8') as _file:
        csvwriter = cwriter(_file, dialect=_dialect, delimiter='\t', quotechar=_quotechar, quoting=QUOTE_MINIMAL)
        for _row in _list:
            csvwriter.writerow(_row)


def writedict2tsv(_filename: str, _list: list, _fieldnames: list, _dialect: str = r'unix', _quotechar: str = r'"') -> None:
    """Send data (as a list of OrderedDicts) to a new TSV file or overwrite an existing TSV file"""
    with open(_filename, mode=r'wt', encoding=r'utf-8') as _file:
        csvwriter = DictWriter(_file, fieldnames=_fieldnames, dialect=_dialect, delimiter='\t', quotechar=_quotechar, quoting=QUOTE_MINIMAL)
        csvwriter.writeheader()
        for _row in _list:
            csvwriter.writerow(_row)


# YAML #


def openyamlfile(_filename: str, _encoding: str = r'utf-8') -> dict:
    """Open an YAML file given a pathname and return the object as a dict"""
    try:
        _out: dict = {}
        ensurefileexists(_filename)
        with codec_opener(_filename, mode=r'rb', encoding=_encoding, buffering=1) as _file:
            _out = yamlload(_file)  # nosec
        return _out
    except (MarkedYAMLError, YAMLError):
        stderr.write('The YAML file is malformed!\n')
        raise SystemExit(1)
    except (LookupError, UnicodeError):
        stderr.write('Unable to determine and process data encoding!\n')
        raise SystemExit(1)


# CONVERTERS #


def csv2dict(_list: list) -> dict:
    """Convert the specified CSV (as a list) to a Python dictionary

    >>> csv2dict([['Val1', 'Val2', 'Val3', 'Val4'], ['1', '2', '3', '4'], ['5', '6', '7', '8'], ['9', '10', '11', '12'], ['13', '14', '15', '16'], ['17', '18', '19', '20'], ['3.14', '6.28', '2.73', '1.57']])
    {0: ['Val1', 'Val2', 'Val3', 'Val4'], 1: ['1', '2', '3', '4'], 2: ['5', '6', '7', '8'], 3: ['9', '10', '11', '12'], 4: ['13', '14', '15', '16'], 5: ['17', '18', '19', '20'], 6: ['3.14', '6.28', '2.73', '1.57']}
    """
    return {_key: _row for _key, _row in enumerate(_list)}


def csv2json(_list: list, _indent: int = 2, _sort_keys: bool = True, _minify: bool = False) -> str:
    """Convert the specified CSV (as a list) to a JSON string

    >>> csv2json([['Val1', 'Val2', 'Val3', 'Val4'], ['1', '2', '3', '4'], ['5', '6', '7', '8'], ['9', '10', '11', '12'], ['13', '14', '15', '16'], ['17', '18', '19', '20'], ['3.14', '6.28', '2.73', '1.57']], _sort_keys=True, _minify=True)
    '{"0":["Val1","Val2","Val3","Val4"],"1":["1","2","3","4"],"2":["5","6","7","8"],"3":["9","10","11","12"],"4":["13","14","15","16"],"5":["17","18","19","20"],"6":["3.14","6.28","2.73","1.57"]}'
    """
    _dict: dict = {_key: _row for _key, _row in enumerate(_list)}
    return jdump(_dict, indent=0, separators=(r',', r':'), sort_keys=_sort_keys).replace('\n', r'') if _minify else jdump(_dict, indent=2, separators=(r', ', r': '), sort_keys=_sort_keys)


def dict2csv(_dict: dict) -> list:
    """Convert a Python dictionary to a CSV (as list)

    >>> dict2csv({'0': ['Val1', 'Val2', 'Val3', 'Val4'], '1': ['1', '2', '3', '4'], '2': ['5', '6', '7', '8'], '3': ['9', '10', '11', '12'], '4': ['13', '14', '15', '16'], '5': ['17', '18', '19', '20'], '6': ['3.14', '6.28', '2.73', '1.57']})
    [['Val1', 'Val2', 'Val3', 'Val4'], ['1', '2', '3', '4'], ['5', '6', '7', '8'], ['9', '10', '11', '12'], ['13', '14', '15', '16'], ['17', '18', '19', '20'], ['3.14', '6.28', '2.73', '1.57']]
    """
    return [_dict[_key] for _key in _dict.keys()]


def dict2ini(_dict: dict, _nested: bool = False, _delimiters: tuple = (r'=', r':'), _comment_prefixes: tuple = (r'#', r';')) -> str:
    r"""Convert a Python dictionary to an INI (as a string)

    >>> dict2ini({'0': ['Val1', 'Val2', 'Val3', 'Val4'], '1': ['1', '2', '3', '4'], '2': ['5', '6', '7', '8'], '3': ['9', '10', '11', '12'], '4': ['13', '14', '15', '16'], '5': ['17', '18', '19', '20'], '6': ['3.14', '6.28', '2.73', '1.57']})
    "[Default]\n0 = ['Val1', 'Val2', 'Val3', 'Val4']\n1 = ['1', '2', '3', '4']\n2 = ['5', '6', '7', '8']\n3 = ['9', '10', '11', '12']\n4 = ['13', '14', '15', '16']\n5 = ['17', '18', '19', '20']\n6 = ['3.14', '6.28', '2.73', '1.57']\n"
    """
    _ini = RawConfigParser(delimiters=_delimiters, comment_prefixes=_comment_prefixes)
    if _dict:  # Non-nested dict; no INI sections will be made
        _sec = r'Default'
        _ini.add_section(_sec)
        for _name in sorted(_dict.keys()):
            _ini.set(_sec, str(_name), _dict[_name])
    else:
        for _sec in sorted(_dict.keys()):
            _ini.add_section(str(_sec))
            for _name, _val in _dict[_sec].items():
                _ini.set(str(_sec), str(_name), _val)
    return ini2str(_ini)


def dict2json(_dict: dict, _indent: int = 2, _sort_keys: bool = True, _minify: bool = False) -> str:
    """Convert a Python dictionary to a JSON string

    >>> dict2json({'0': ['Val1', 'Val2', 'Val3', 'Val4'], '1': ['1', '2', '3', '4'], '2': ['5', '6', '7', '8'], '3': ['9', '10', '11', '12'], '4': ['13', '14', '15', '16'], '5': ['17', '18', '19', '20'], '6': ['3.14', '6.28', '2.73', '1.57']}, _sort_keys=True, _minify=True)
    '{"0":["Val1","Val2","Val3","Val4"],"1":["1","2","3","4"],"2":["5","6","7","8"],"3":["9","10","11","12"],"4":["13","14","15","16"],"5":["17","18","19","20"],"6":["3.14","6.28","2.73","1.57"]}'
    """
    return jdump(_dict, indent=0, separators=(r',', r':'), sort_keys=_sort_keys).replace('\n', r'') if _minify else jdump(_dict, indent=2, separators=(r', ', r': '), sort_keys=_sort_keys)


def ini2dict(_file: Union[object, str], _rawinistr: bool = False) -> dict:
    r"""Convert an INI to a Python dictionary

    >>> BUF = StringIO(r'')
    >>> BUF.write("[Default]\n0 = ['Val1', 'Val2', 'Val3', 'Val4']\n1 = ['1', '2', '3', '4']\n2 = ['5', '6', '7', '8']\n3 = ['9', '10', '11', '12']\n4 = ['13', '14', '15', '16']\n5 = ['17', '18', '19', '20']\n6 = ['3.14', '6.28', '2.73', '1.57']\n")
    220
    >>> ini2dict(BUF)
    {'Default': {'0': "['Val1', 'Val2', 'Val3', 'Val4']", '1': "['1', '2', '3', '4']", '2': "['5', '6', '7', '8']", '3': "['9', '10', '11', '12']", '4': "['13', '14', '15', '16']", '5': "['17', '18', '19', '20']", '6': "['3.14', '6.28', '2.73', '1.57']"}}
    >>> ini2dict("[Default]\n0 = ['Val1', 'Val2', 'Val3', 'Val4']\n1 = ['1', '2', '3', '4']\n2 = ['5', '6', '7', '8']\n3 = ['9', '10', '11', '12']\n4 = ['13', '14', '15', '16']\n5 = ['17', '18', '19', '20']\n6 = ['3.14', '6.28', '2.73', '1.57']\n", _rawinistr=True)
    {'Default': {'0': "['Val1', 'Val2', 'Val3', 'Val4']", '1': "['1', '2', '3', '4']", '2': "['5', '6', '7', '8']", '3': "['9', '10', '11', '12']", '4': "['13', '14', '15', '16']", '5': "['17', '18', '19', '20']", '6': "['3.14', '6.28', '2.73', '1.57']"}}
    """
    if _rawinistr:
        _buf = StringIO(r'')
        _buf.write(_file)  # type: ignore
        configfile = openinifile(_buf)
    else:
        configfile = openinifile(_file)
    return {_skey: dict(configfile.items(_skey)) for _skey in configfile.sections()}  # type: ignore


def ini2json(_file: Union[object, str], _rawinistr: bool = False, _indent: int = 2, _sort_keys: bool = True, _minify: bool = False) -> str:
    r"""Convert an INI to JSON (as a string)

    >>> BUF = StringIO(r'')
    >>> BUF.write("[Default]\n0 = ['Val1', 'Val2', 'Val3', 'Val4']\n1 = ['1', '2', '3', '4']\n2 = ['5', '6', '7', '8']\n3 = ['9', '10', '11', '12']\n4 = ['13', '14', '15', '16']\n5 = ['17', '18', '19', '20']\n6 = ['3.14', '6.28', '2.73', '1.57']\n")
    220
    >>> ini2json(BUF, _minify=True)
    '{"Default":{"0":"[\'Val1\', \'Val2\', \'Val3\', \'Val4\']","1":"[\'1\', \'2\', \'3\', \'4\']","2":"[\'5\', \'6\', \'7\', \'8\']","3":"[\'9\', \'10\', \'11\', \'12\']","4":"[\'13\', \'14\', \'15\', \'16\']","5":"[\'17\', \'18\', \'19\', \'20\']","6":"[\'3.14\', \'6.28\', \'2.73\', \'1.57\']"}}'
    >>> ini2json("[Default]\n0 = ['Val1', 'Val2', 'Val3', 'Val4']\n1 = ['1', '2', '3', '4']\n2 = ['5', '6', '7', '8']\n3 = ['9', '10', '11', '12']\n4 = ['13', '14', '15', '16']\n5 = ['17', '18', '19', '20']\n6 = ['3.14', '6.28', '2.73', '1.57']\n", _rawinistr=True, _minify=True)
    '{"Default":{"0":"[\'Val1\', \'Val2\', \'Val3\', \'Val4\']","1":"[\'1\', \'2\', \'3\', \'4\']","2":"[\'5\', \'6\', \'7\', \'8\']","3":"[\'9\', \'10\', \'11\', \'12\']","4":"[\'13\', \'14\', \'15\', \'16\']","5":"[\'17\', \'18\', \'19\', \'20\']","6":"[\'3.14\', \'6.28\', \'2.73\', \'1.57\']"}}'
    """
    return dict2json(ini2dict(_file, _rawinistr=_rawinistr), _indent=_indent, _sort_keys=_sort_keys, _minify=_minify)


def json2csv(_str: str) -> list:
    """Convert a JSON string to CSV (as a list)

    >>> json2csv('{"0":["Val1","Val2","Val3","Val4"],"1":["1","2","3","4"],"2":["5","6","7","8"],"3":["9","10","11","12"],"4":["13","14","15","16"],"5":["17","18","19","20"],"6":["3.14","6.28","2.73","1.57"]}')
    [['Val1', 'Val2', 'Val3', 'Val4'], ['1', '2', '3', '4'], ['5', '6', '7', '8'], ['9', '10', '11', '12'], ['13', '14', '15', '16'], ['17', '18', '19', '20'], ['3.14', '6.28', '2.73', '1.57']]
    """
    _dict: Union[dict, list] = jloads(_str)
    if isinstance(_dict, dict):
        return [_dict[_key] for _key in _dict.keys()]
    return _dict


def json2csvstr(_str: str, _dialect: str = r'unix', _delimiter: str = r',', _quotechar: str = r'"') -> str:
    r"""Convert a JSON string to CSV (as a string)

    >>> json2csvstr('{"0":["Val1","Val2","Val3","Val4"],"1":["1","2","3","4"],"2":["5","6","7","8"],"3":["9","10","11","12"],"4":["13","14","15","16"],"5":["17","18","19","20"],"6":["3.14","6.28","2.73","1.57"]}')
    '0,1,2,3,4,5,6\nVal1,Val2,Val3,Val4\n1,2,3,4\n5,6,7,8\n9,10,11,12\n13,14,15,16\n17,18,19,20\n3.14,6.28,2.73,1.57\n'
    """
    _dict: Union[dict, list] = jloads(_str)
    _buf = StringIO(r'')
    _out: str = r''
    csvwriter = cwriter(_buf, dialect=_dialect, delimiter=_delimiter, quotechar=_quotechar, quoting=QUOTE_MINIMAL)
    if isinstance(_dict, dict):
        _tmpdict: list = [_dict[_key] for _key in _dict.keys()]
        csvwriter.writerow(_dict.keys())
        for _row in _tmpdict:
            csvwriter.writerow(_row)
    else:
        for _row in _dict:
            csvwriter.writerow(_row)
    _out = _buf.getvalue()
    _buf.close()
    return _out


def json2dict(_str: str) -> Union[dict, list]:
    """Convert a JSON string to a Python dictionary or list (depending on the data input)

    >>> json2dict('{"0":["Val1","Val2","Val3","Val4"],"1":["1","2","3","4"],"2":["5","6","7","8"],"3":["9","10","11","12"],"4":["13","14","15","16"],"5":["17","18","19","20"],"6":["3.14","6.28","2.73","1.57"]}')
    {'0': ['Val1', 'Val2', 'Val3', 'Val4'], '1': ['1', '2', '3', '4'], '2': ['5', '6', '7', '8'], '3': ['9', '10', '11', '12'], '4': ['13', '14', '15', '16'], '5': ['17', '18', '19', '20'], '6': ['3.14', '6.28', '2.73', '1.57']}
    """
    return jloads(_str)


def json2yaml(_str: str) -> str:
    r"""Convert a JSON string to a YAML string

    >>> json2yaml('{"0":["Val1","Val2","Val3","Val4"],"1":["1","2","3","4"],"2":["5","6","7","8"],"3":["9","10","11","12"],"4":["13","14","15","16"],"5":["17","18","19","20"],"6":["3.14","6.28","2.73","1.57"]}')
    "'0':\n- Val1\n- Val2\n- Val3\n- Val4\n'1':\n- '1'\n- '2'\n- '3'\n- '4'\n'2':\n- '5'\n- '6'\n- '7'\n- '8'\n'3':\n- '9'\n- '10'\n- '11'\n- '12'\n'4':\n- '13'\n- '14'\n- '15'\n- '16'\n'5':\n- '17'\n- '18'\n- '19'\n- '20'\n'6':\n- '3.14'\n- '6.28'\n- '2.73'\n- '1.57'\n"
    """
    return yamldump(jloads(_str, object_pairs_hook=OrderedDict), safe=True)


def yaml2dict(_yaml: str) -> dict:
    r"""Convert a YAML string to a Python dictionary

    >>> yaml2dict("'0':\n- Val1\n- Val2\n- Val3\n- Val4\n'1':\n- '1'\n- '2'\n- '3'\n- '4'\n'2':\n- '5'\n- '6'\n- '7'\n- '8'\n'3':\n- '9'\n- '10'\n- '11'\n- '12'\n'4':\n- '13'\n- '14'\n- '15'\n- '16'\n'5':\n- '17'\n- '18'\n- '19'\n- '20'\n'6':\n- '3.14'\n- '6.28'\n- '2.73'\n- '1.57'\n")
    {'0': ['Val1', 'Val2', 'Val3', 'Val4'], '1': ['1', '2', '3', '4'], '2': ['5', '6', '7', '8'], '3': ['9', '10', '11', '12'], '4': ['13', '14', '15', '16'], '5': ['17', '18', '19', '20'], '6': ['3.14', '6.28', '2.73', '1.57']}
    """
    _buf = StringIO(_yaml)
    _out: dict = yamlload(_buf)  # nosec
    _buf.close()
    return _out


def yaml2json(_yaml: str, _indent: int = 2, _sort_keys: bool = True, _minify: bool = False) -> str:
    r"""Convert a YAML string to a JSON string

    >>> yaml2json("'0':\n- Val1\n- Val2\n- Val3\n- Val4\n'1':\n- '1'\n- '2'\n- '3'\n- '4'\n'2':\n- '5'\n- '6'\n- '7'\n- '8'\n'3':\n- '9'\n- '10'\n- '11'\n- '12'\n'4':\n- '13'\n- '14'\n- '15'\n- '16'\n'5':\n- '17'\n- '18'\n- '19'\n- '20'\n'6':\n- '3.14'\n- '6.28'\n- '2.73'\n- '1.57'\n", _sort_keys=True, _minify=True)
    '{"0":["Val1","Val2","Val3","Val4"],"1":["1","2","3","4"],"2":["5","6","7","8"],"3":["9","10","11","12"],"4":["13","14","15","16"],"5":["17","18","19","20"],"6":["3.14","6.28","2.73","1.57"]}'
    >>> yaml2json("'0':\n- Val1\n- Val2\n- Val3\n- Val4\n'1':\n- '1'\n- '2'\n- '3'\n- '4'\n'2':\n- '5'\n- '6'\n- '7'\n- '8'\n'3':\n- '9'\n- '10'\n- '11'\n- '12'\n'4':\n- '13'\n- '14'\n- '15'\n- '16'\n'5':\n- '17'\n- '18'\n- '19'\n- '20'\n'6':\n- '3.14'\n- '6.28'\n- '2.73'\n- '1.57'\n", _sort_keys=True, _minify=False)
        '{\n  "0": [\n    "Val1", \n    "Val2", \n    "Val3", \n    "Val4"\n  ], \n  "1": [\n    "1", \n    "2", \n    "3", \n    "4"\n  ], \n  "2": [\n    "5", \n    "6", \n    "7", \n    "8"\n  ], \n  "3": [\n    "9", \n    "10", \n    "11", \n    "12"\n  ], \n  "4": [\n    "13", \n    "14", \n    "15", \n    "16"\n  ], \n  "5": [\n    "17", \n    "18", \n    "19", \n    "20"\n  ], \n  "6": [\n    "3.14", \n    "6.28", \n    "2.73", \n    "1.57"\n  ]\n}'
    """
    _buf = StringIO(_yaml)
    _tmpyaml: dict = yamlload(_buf)  # nosec
    _out: str = jdump(_tmpyaml, indent=0, separators=(r',', r':'), sort_keys=_sort_keys).replace('\n', r'') if _minify else jdump(_tmpyaml, indent=2, separators=(r', ', r': '), sort_keys=_sort_keys)
    _buf.close()
    return _out


# PICKLE #


def data2pklfile(_data: object, _filename: str) -> None:
    """Pickle, compress (using Zlib), and encode the data in base64, then write it to a file"""
    write2file(_filename, str(b64encode(zcompress(dumps(_data), level=9), altchars=br'-_'), encoding=r'utf-8'))


def pklfile2data(_filename: str) -> object:
    """Open the specified file and load the contained compressed+pickled base64 data"""
    ensurefileexists(_filename)
    return loads(zdecompress(b64decode(bytes(getfile(_filename), encoding=r'utf-8'), altchars=br'-_')))
