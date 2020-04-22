#!/usr/bin/env python3
# -*- coding: utf-8; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on;
"""@brief Generate music using the previously generated neural networks.

@file generate.py
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


from os import environ
from os.path import isfile
from sys import stdout

import numpy as xp

environ[r'TF_CPP_MIN_LOG_LEVEL'] = r'3'

from nn_funcs import (  # noqa: E402  # pylint: disable=C0413
    create_neural_network,
    generate_from_seed,
    generate_seed_sequence,
    NEURAL_NET_CONFIG,
    save_generated_example
)


def main() -> int:
    """Entry-point for neural net music generation."""
    # LOAD TRAINING DATA #
    stdout.write('Loading training data\n')
    x_train: xp.array = xp.load(f'''{NEURAL_NET_CONFIG[r'model_file']}_x.npy''')  # Tensor of size (num_train_examples, num_timesteps, num_freq_dims)
    x_mean: xp.array = xp.load(f'''{NEURAL_NET_CONFIG[r'model_file']}_mean.npy''')  # Matrix of size (num_freq_dims,) containing the mean for each frequency dimension
    x_var: xp.array = xp.load(f'''{NEURAL_NET_CONFIG[r'model_file']}_var.npy''')  # Matrix of size (num_freq_dims,) containing the variance for each frequency dimension
    stdout.write('Finished loading training data\n')
    # CREATE NEURAL NETWORK #
    model = create_neural_network(x_train.shape[2], NEURAL_NET_CONFIG[r'hidden_dimension_size'])
    # LOAD EXISTING WEIGHTS IF AVAILABLE #
    model_filename: str = f'''{NEURAL_NET_CONFIG[r'model_basename']}_i{NEURAL_NET_CONFIG[r'num_iters']}_e{NEURAL_NET_CONFIG[r'epochs']}_b{NEURAL_NET_CONFIG[r'batch_size']}_hd{NEURAL_NET_CONFIG[r'hidden_dimension_size']}.h5'''
    if isfile(model_filename):
        model.load_weights(model_filename)
    else:
        stdout.write(f'Model filename {model_filename} could not be found!\n')
    # BEGIN MUSIC GENERATION #
    stdout.write('Generating seed sequence\n')
    seed_seq: xp.array = generate_seed_sequence(NEURAL_NET_CONFIG[r'seed_len'], x_train)
    stdout.write('Generating audio from seed sequence\n')
    output: list = generate_from_seed(model, seed_seq, NEURAL_NET_CONFIG[r'sequence_length'], x_var, x_mean)
    stdout.write('Finished generation\n')
    # SAVE GENERATED MUSIC TO A WAV FILE #
    save_generated_example(NEURAL_NET_CONFIG[r'output_filename'], output, NEURAL_NET_CONFIG[r'sampling_frequency'])
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
