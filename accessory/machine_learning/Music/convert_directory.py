#!/usr/bin/env python3
# -*- coding: utf-8; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on;
"""@brief Convert audio files to WAV.

@file convert_directory.py
@version 2020.04.02
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
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this software.
"""


from os import environ, listdir

environ[r'TF_CPP_MIN_LOG_LEVEL'] = r'3'

from nn_funcs import convert_folder_to_wav, convert_wav_files_to_nptensor, NEURAL_NET_CONFIG  # noqa: E402  # pylint: disable=C0413


__all__: list = []


# FUNCTIONS #


def list_wav_files(directory: str) -> list:
    """List the WAV files in the specified directory."""
    files: list = []
    for _file in listdir(directory):
        if _file.endswith(r'.wav'):
            files.append(directory + _file)
    return files


def main() -> int:
    """Entry-point for music file conversions."""
    # CONVERT MP3 TO WAV #
    new_directory: str = convert_folder_to_wav(NEURAL_NET_CONFIG[r'dataset_directory'], NEURAL_NET_CONFIG[r'sampling_frequency'])
    # CONVERT WAV TO A FREQUENCY DOMAIN #
    files: list = list_wav_files(new_directory)
    convert_wav_files_to_nptensor(
        files,
        NEURAL_NET_CONFIG[r'block_size'],
        NEURAL_NET_CONFIG[r'max_seq_len'],
        NEURAL_NET_CONFIG[r'model_file']
    )
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
