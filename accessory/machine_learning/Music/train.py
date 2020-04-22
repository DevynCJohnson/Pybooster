#!/usr/bin/env python3
# -*- coding: utf-8; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on;
"""@brief Train the neural network to create music.

@file train.py
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

from nn_funcs import create_neural_network, NEURAL_NET_CONFIG  # noqa: E402  # pylint: disable=C0413


def main() -> int:
    """Entry-point for neural net training."""
    # LOAD TRAINING DATA #
    stdout.write('Loading training data\n')
    x_train: xp.array = xp.load(fr'''{NEURAL_NET_CONFIG[r'model_file']}_x.npy''')  # Tensor of size (num_train_examples, num_timesteps, num_freq_dims)
    stdout.write(f'Data Shape: {x_train.shape}\n')
    y_train: xp.array = xp.load(fr'''{NEURAL_NET_CONFIG[r'model_file']}_y.npy''')  # Tensor of size (num_train_examples, num_timesteps, num_freq_dims)
    stdout.write('Finished loading training data\n')
    # CREATE NEURAL NETWORK #
    model = create_neural_network(x_train.shape[2], NEURAL_NET_CONFIG[r'hidden_dimension_size'])
    # LOAD EXISTING WEIGHTS IF AVAILABLE #
    model_filename: str = f'''{NEURAL_NET_CONFIG[r'model_basename']}_i{NEURAL_NET_CONFIG[r'num_iters']}_e{NEURAL_NET_CONFIG[r'epochs']}_b{NEURAL_NET_CONFIG[r'batch_size']}_hd{NEURAL_NET_CONFIG[r'hidden_dimension_size']}.h5'''
    if isfile(model_filename):
        model.load_weights(model_filename)
    # BEGIN TRAINING #
    stdout.write('Starting training\n')
    cur_iter: int = 0
    while cur_iter < NEURAL_NET_CONFIG[r'num_iters']:
        cur_iter += 1
        stdout.write(f'''Iteration: {cur_iter}/{NEURAL_NET_CONFIG[r'num_iters']}\n''')
        model.fit(
            x=x_train,
            y=y_train,
            batch_size=NEURAL_NET_CONFIG[r'batch_size'],
            epochs=NEURAL_NET_CONFIG[r'epochs'],
            verbose=0,
            validation_split=0.0
        )
    stdout.write('Training complete\n')
    model.save_weights(model_filename)
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
