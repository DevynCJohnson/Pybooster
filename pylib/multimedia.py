#!/usr/bin/env python3
# -*- coding: utf-8-unix; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;
"""@brief Library for multimedia manipulation

@file multimedia.py
@package pybooster.multimedia
@version 2018.12.28
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@section HELPFUL DOCUMENTATION
FFmpeg
 - FFmpeg Codecs: https://ffmpeg.org/ffmpeg-codecs.html
 - FFmpeg Filters: https://ffmpeg.org/ffmpeg-filters.html

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


from array import array
from multiprocessing import cpu_count
import shlex
from subprocess import PIPE, Popen  # nosec
from tempfile import NamedTemporaryFile
import wave

from pybooster.fs import doesfileexist, getfilename
from pybooster.iterables import mergeoddeven
from pybooster.system import is_program_aval

PYGAME_IMPORTED: bool = False

try:
    from pygame.mixer import init, music
    PYGAME_IMPORTED = True
except ImportError:
    pass


__all__: list = [
    # GLOBAL CONSTANTS #
    r'FFMPEG',
    # AUDIO #
    r'merge2rawwav',
    r'openwavfile',
    r'openmp3file',
    r'writewavfile',
    r'playmusic',
    r'audioimg2mp4',
    # AUDIO CONVERSIONS #
    r'to_aac',
    r'to_ac3',
    r'to_ac3_fixed',
    r'to_flac',
    r'to_mp3',
    r'to_ogg',
    r'to_opus',
    r'to_wav_tmp',
    r'to_wav',
    r'mp3_to_wav',
    r'wav_to_mp3'
]


# GLOBAL CONSTANTS #


FFMPEG: str = r'ffmpeg -y -hide_banner -loglevel panic -sn -vn'


# AUDIO #


def merge2rawwav(_wav_data: dict) -> bytes:
    """Merge the split WAV channels back together and convert the data to the original raw WAV format"""
    if _wav_data[r'num_channels'] == 2:
        return mergeoddeven(_wav_data[r'left_audio'], _wav_data[r'right_audio']).tobytes()
    return _wav_data[r'data'].tobytes()


def openwavfile(_filename: str) -> dict:
    """Get the contents of the specified WAV file and return the data as a list of integers in a dictionary describing the data"""
    _wav_data: list = []
    with wave.open(_filename, mode=r'rb') as _file:
        _wav_data.append(_file.readframes(_file.getnframes()))
    _out: dict = {
        r'num_frames': _file.getnframes(),
        r'frame_rate': _file.getframerate(),
        r'num_channels': _file.getnchannels(),
        r'sample_width': _file.getsampwidth()
    }
    if _out[r'sample_width'] == 1:  # 8-bit
        _out[r'data'] = array(r'b', _wav_data[0])
    elif _out[r'sample_width'] == 2:  # 16-bit
        _out[r'data'] = array(r'h', _wav_data[0])
    elif _out[r'sample_width'] == 4:  # 32-bit
        _out[r'data'] = array(r'l', _wav_data[0])
    if _out[r'num_channels'] == 2:
        _out[r'left_audio'] = _out[r'data'][0::2]
        _out[r'right_audio'] = _out[r'data'][1::2]
    return _out


def openmp3file(_filename: str) -> dict:
    """Get the contents of the specified MP3 file and return the data as a list of integers in a dictionary describing the data"""
    _wav_data: list = []
    _tmpfile = NamedTemporaryFile()
    if not to_wav_tmp(_filename, _tmpfile.name):
        raise Exception(r'Failed to convert MP3 file to WAV!')
    with wave.open(_tmpfile.name, mode=r'rb') as _file:
        _wav_data.append(_file.readframes(_file.getnframes()))
    _out: dict = {
        r'num_frames': _file.getnframes(),
        r'frame_rate': _file.getframerate(),
        r'num_channels': _file.getnchannels(),
        r'sample_width': _file.getsampwidth()
    }
    if _out[r'sample_width'] == 1:  # 8-bit
        _out[r'data'] = array(r'b', _wav_data[0])
    elif _out[r'sample_width'] == 2:  # 16-bit
        _out[r'data'] = array(r'h', _wav_data[0])
    elif _out[r'sample_width'] == 4:  # 32-bit
        _out[r'data'] = array(r'l', _wav_data[0])
    if _out[r'num_channels'] == 2:
        _out[r'left_audio'] = _out[r'data'][0::2]
        _out[r'right_audio'] = _out[r'data'][1::2]
    return _out


def writewavfile(_wav_data: dict, _filename: str) -> None:
    """Write a WAV file using data in the given WAV data dictionary"""
    with wave.open(_filename, mode=r'wb') as _file:
        _file.setparams((_wav_data[r'num_channels'], _wav_data[r'sample_width'], _wav_data[r'frame_rate'], _wav_data[r'num_frames'], r'NONE', r'not compressed'))  # pylint: disable=E1101
        _file.writeframes(merge2rawwav(_wav_data))  # pylint: disable=E1101


def playmusic(_filename: str) -> None:
    """Play an MP3, WAV, or other audio files"""
    if PYGAME_IMPORTED:
        init()
        music.load(_filename)
        music.play()
        while music.get_busy() is True:
            continue
    elif is_program_aval(r'ffplay'):
        _process = Popen(shlex.split(r'ffplay -hide_banner -loglevel panic -sn -vn -nodisp ' + _filename), stdout=PIPE, stderr=PIPE)
        _stdout, _stderr = _process.communicate()
    elif is_program_aval(r'play'):
        _process = Popen(shlex.split(r'play -q -V1 ' + _filename), stdout=PIPE, stderr=PIPE)
        _stdout, _stderr = _process.communicate()
    elif _filename.endswith(r'.mp3') and is_program_aval(r'mpeg321'):
        _process = Popen(shlex.split(r'mpg321 --quiet ' + _filename), stdout=PIPE, stderr=PIPE)
        _stdout, _stderr = _process.communicate()
    elif _filename.endswith(r'.mp3') and is_program_aval(r'mpg123'):
        _process = Popen(shlex.split(r'mpg123 --quiet ' + _filename), stdout=PIPE, stderr=PIPE)
        _stdout, _stderr = _process.communicate()
    elif _filename.endswith(r'.ogg') and is_program_aval(r'ogg123'):
        _process = Popen(shlex.split(r'ogg123 --quiet ' + _filename), stdout=PIPE, stderr=PIPE)
        _stdout, _stderr = _process.communicate()


def audioimg2mp4(_audio_filename: str, _img_filename: str, sample_rate: int = 44100) -> bool:
    """Create an MP4 video given an audio file & an image file; Return True if successful"""
    if doesfileexist(_img_filename) and doesfileexist(_audio_filename):
        # Conversion
        if is_program_aval(r'ffmpeg'):
            core_count = r'-threads ' + str(cpu_count())
            hw_params = r'-hwaccel cuvid ' + core_count if is_program_aval(r'nvidia-smi') else r'-hwaccel vaapi ' + core_count
            _process = Popen(shlex.split(r'ffmpeg -y -hide_banner -loglevel panic ' + hw_params + r' -thread_queue_size 4096 -probesize 20M -analyzeduration 20M -i ' + _img_filename + r' -i ' + _audio_filename + r' -c:v libx264 -crf 15 -tune stillimage -vf scale=2560:1440 -c:a libmp3lame -b:a 320000 -ar ' + str(sample_rate) + r' -compression_level 0 ' + getfilename(_audio_filename) + r'_merged.mp4'), stdout=PIPE, stderr=PIPE)
            _stdout, _stderr = _process.communicate()
        else:
            return False
        # Check for success
        if not _stderr:
            return True
    return False


# AUDIO CONVERSIONS #


def to_aac(_filename: str, sample_rate: int = 44100) -> bool:
    """Convert an audio file to an AAC file; Return True if successful"""
    if doesfileexist(_filename):
        # Conversion
        if is_program_aval(r'ffmpeg'):
            _process = Popen(shlex.split(FFMPEG + r' -i ' + _filename + r' -codec:a libfaac -ar ' + str(sample_rate) + r' -f aac ' + getfilename(_filename) + r'.aac'), stdout=PIPE, stderr=PIPE)
            _stdout, _stderr = _process.communicate()
        else:
            return False
        # Check for success
        if not _stderr:
            return True
    return False


def to_ac3(_filename: str, sample_rate: int = 44100) -> bool:
    """Convert an audio file to an AC3 file; Return True if successful"""
    if doesfileexist(_filename):
        # Conversion
        if is_program_aval(r'ffmpeg'):
            _process = Popen(shlex.split(FFMPEG + r' -i ' + _filename + r' -codec:a ac3 -ar ' + str(sample_rate) + r' -f ac3 ' + getfilename(_filename) + r'.ac3'), stdout=PIPE, stderr=PIPE)
            _stdout, _stderr = _process.communicate()
        else:
            return False
        # Check for success
        if not _stderr:
            return True
    return False


def to_ac3_fixed(_filename: str, sample_rate: int = 44100) -> bool:
    """Convert an audio file to an AC3 (Fixed) file; Return True if successful"""
    if doesfileexist(_filename):
        # Conversion
        if is_program_aval(r'ffmpeg'):
            _process = Popen(shlex.split(FFMPEG + r' -i ' + _filename + r' -codec:a ac3_fixed -ar ' + str(sample_rate) + r' -f ac3 ' + getfilename(_filename) + r'.ac3'), stdout=PIPE, stderr=PIPE)
            _stdout, _stderr = _process.communicate()
        else:
            return False
        # Check for success
        if not _stderr:
            return True
    return False


def to_flac(_filename: str, sample_rate: int = 44100) -> bool:
    """Convert an audio file to a Flac file; Return True if successful"""
    if doesfileexist(_filename):
        # Conversion
        if is_program_aval(r'ffmpeg'):
            _process = Popen(shlex.split(FFMPEG + r' -i ' + _filename + r' -codec:a flac -ar ' + str(sample_rate) + r' -compression_level 12 -f flac ' + getfilename(_filename) + r'.flac'), stdout=PIPE, stderr=PIPE)
            _stdout, _stderr = _process.communicate()
        else:
            return False
        # Check for success
        if not _stderr:
            return True
    return False


def to_mp3(_filename: str, bitrate: int = 320000, sample_rate: int = 44100) -> bool:
    """Convert an audio file to an MP3 file; Return True if successful"""
    if doesfileexist(_filename):
        # Conversion
        if is_program_aval(r'ffmpeg'):
            _process = Popen(shlex.split(FFMPEG + r' -i ' + _filename + r' -codec:a libmp3lame -b:a ' + str(bitrate) + r' -ar ' + str(sample_rate) + r' -compression_level 0 -f mp3 ' + getfilename(_filename) + r'.mp3'), stdout=PIPE, stderr=PIPE)
            _stdout, _stderr = _process.communicate()
        else:
            return False
        # Check for success
        if not _stderr:
            return True
    return False


def to_ogg(_filename: str, sample_rate: int = 44100) -> bool:
    """Convert an audio file to an OGG file; Return True if successful"""
    if doesfileexist(_filename):
        # Conversion
        if is_program_aval(r'ffmpeg'):
            _process = Popen(shlex.split(FFMPEG + r' -i ' + _filename + r' -codec:a libvorbis -ar ' + str(sample_rate) + r' -f ogg ' + getfilename(_filename) + r'.ogg'), stdout=PIPE, stderr=PIPE)
            _stdout, _stderr = _process.communicate()
        else:
            return False
        # Check for success
        if not _stderr:
            return True
    return False


def to_opus(_filename: str) -> bool:
    """Convert an audio file to an OPUS file; Return True if successful"""
    if doesfileexist(_filename):
        # Conversion
        if is_program_aval(r'ffmpeg'):
            _process = Popen(shlex.split(FFMPEG + r' -i ' + _filename + r' -codec:a libopus -compression_level 10 -f opus ' + getfilename(_filename) + r'.opus'), stdout=PIPE, stderr=PIPE)
            _stdout, _stderr = _process.communicate()
        else:
            return False
        # Check for success
        if not _stderr:
            return True
    return False


def to_wav_tmp(_filename: str, _tmpname: str, sample_rate: int = 44100) -> bool:
    """Convert an audio file to a WAV file; Return True if successful"""
    if doesfileexist(_filename):
        # Conversion
        if is_program_aval(r'ffmpeg'):
            _process = Popen(shlex.split(FFMPEG + r' -i ' + _filename + r' -codec:a pcm_s16le -ar ' + str(sample_rate) + r' -f wav ' + _tmpname), stdout=PIPE, stderr=PIPE)
            _stdout, _stderr = _process.communicate()
        else:
            return False
        # Check for success
        if not _stderr:
            return True
    return False


def to_wav(_filename: str, sample_rate: int = 44100) -> bool:
    """Convert an audio file to a WAV file; Return True if successful"""
    if doesfileexist(_filename):
        # Conversion
        if is_program_aval(r'ffmpeg'):
            _process = Popen(shlex.split(FFMPEG + r' -i ' + _filename + r' -codec:a pcm_s16le -ar ' + str(sample_rate) + r' -f wav ' + getfilename(_filename) + r'.wav'), stdout=PIPE, stderr=PIPE)
            _stdout, _stderr = _process.communicate()
        else:
            return False
        # Check for success
        if not _stderr:
            return True
    return False


def mp3_to_wav(_filename: str, sample_rate: int = 44100) -> bool:
    """Convert an MP3 file to a WAV file; Return True if successful"""
    if doesfileexist(_filename):
        # Conversion
        if is_program_aval(r'ffmpeg'):
            return to_wav(_filename, sample_rate)
        if is_program_aval(r'mpeg321'):
            _process = Popen(shlex.split(r'mpg321 --quiet --stereo --wav ' + _filename + r' ' + _filename.replace(r'.mp3', r'.wav')), stdout=PIPE, stderr=PIPE)
            _stdout, _stderr = _process.communicate()
        elif is_program_aval(r'mpg123'):
            _process = Popen(shlex.split(r'mpg123 --quiet --stereo --wav ' + _filename + r' ' + _filename.replace(r'.mp3', r'.wav')), stdout=PIPE, stderr=PIPE)
            _stdout, _stderr = _process.communicate()
        else:
            return False
        # Check for success
        if not _stderr:
            return True
    return False


def wav_to_mp3(_filename: str, bitrate: int = 320000, sample_rate: int = 44100) -> bool:
    """Convert a WAV file to an MP3 file; Return True if successful"""
    if doesfileexist(_filename):
        # Conversion
        if is_program_aval(r'ffmpeg'):
            return to_mp3(_filename, bitrate, sample_rate)
    return False
