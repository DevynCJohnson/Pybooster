#!/usr/bin/env python3
# -*- coding: utf-8; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on;
"""@brief Generate poetry using neural nets.

@file lstm_text_generation.py
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


from argparse import ArgumentParser
from os import environ
from os.path import isfile
from random import randint  # nosec
from sys import stderr, stdout
from warnings import filterwarnings

environ[r'KERAS_BACKEND'] = r'tensorflow'
environ[r'TF_CPP_MIN_LOG_LEVEL'] = r'3'
filterwarnings(r'ignore', category=DeprecationWarning)

from keras.callbacks import LambdaCallback  # noqa: E402  # pylint: disable=C0413
from keras.layers import Dense  # noqa: E402  # pylint: disable=C0413
from keras.layers.recurrent import LSTM  # noqa: E402  # pylint: disable=C0413
from keras.models import Sequential  # noqa: E402  # pylint: disable=C0413
import numpy as xp  # noqa: E402  # pylint: disable=C0413


# SETTINGS #


SETTINGS: dict = {
    r'activation': r'tanh',
    r'activation_dense': r'tanh',
    r'activation_final': r'softmax',
    r'batch_size': 256,
    r'dropout_rate': 0.3,
    r'epochs': 100,
    r'hidden_dimension_size': 512,
    r'loss': r'categorical_crossentropy',
    r'optimizer': r'adam',
    r'poem_char_len': 400,
    r'seq_len': 100,
    r'step': 1
}


# CLASSES #


class PoetryNeuralNet:  # pylint: disable=R0902
    """Object representing a neural-net instance for poetry."""

    def __init__(self, text_path: str) -> None:
        """Initialize the neurl-net."""
        self.generated_poetry: str = r''
        self.model = Sequential()
        self.text: str = getfile(text_path).casefold()
        chars: list = sorted(set(self.text))
        self.char_indices: dict = {char: index for index, char in enumerate(chars)}
        self.text_len: int = len(self.text)
        # Cut the text into semi-redundant sequences of characters
        sentences: list = []
        next_chars: list = []
        for i in range(0, self.text_len - SETTINGS[r'seq_len'], SETTINGS[r'step']):
            sentences.append(self.text[i: i + SETTINGS[r'seq_len']])
            next_chars.append(self.text[i + SETTINGS[r'seq_len']])
        self.char_len: int = len(chars)
        if not self.char_len:
            raise Exception(r'No characters found!')
        sentence_len: int = len(sentences)
        if not sentence_len:
            raise Exception(r'No sentences found!')
        stdout.write(f'Number of Sequences: {sentence_len}\n')
        # Vectorization
        self.poetry_x: xp.array = xp.zeros((sentence_len, SETTINGS[r'seq_len'], self.char_len), dtype=xp.bool)
        self.poetry_y: xp.array = xp.zeros((sentence_len, self.char_len), dtype=xp.bool)
        for _index, sentence in enumerate(sentences):
            for _char_index, char in enumerate(sentence):
                self.poetry_x[_index, _char_index, self.char_indices[char]] = 1
            self.poetry_y[_index, self.char_indices[next_chars[_index]]] = 1

    def save_model_weights(self) -> None:
        """Save the weights of the model to a file."""
        self.model.save_weights(f'''Poetry_Weights_m{SETTINGS[r'seq_len']}_e{SETTINGS[r'epochs']}_b{SETTINGS[r'batch_size']}_hd{SETTINGS[r'hidden_dimension_size']}.h5''')

    def load_model_weights(self) -> bool:
        """Load the weights into the model form a file."""
        model_filename: str = f'''Poetry_Weights_m{SETTINGS[r'seq_len']}_e{SETTINGS[r'epochs']}_b{SETTINGS[r'batch_size']}_hd{SETTINGS[r'hidden_dimension_size']}.h5'''
        if isfile(model_filename):
            self.model.load_weights(model_filename)
            return True
        stdout.write(f'Model file {model_filename} could not be found!\n')
        return False

    def write2file(self, _filename: str) -> None:
        """Send data to a new file or overwrite the file."""
        if not self.generated_poetry:
            raise Exception(r'Poetry is available to write!')
        with open(_filename, mode=r'wt', encoding=r'utf-8') as _file:
            _file.write(self.generated_poetry)

    def build_model(self) -> None:
        """Build the LSTM model."""
        self.model.add(LSTM(SETTINGS[r'hidden_dimension_size'], activation=SETTINGS[r'activation'], recurrent_activation=r'sigmoid', use_bias=True, kernel_initializer=r'glorot_uniform', recurrent_initializer=r'orthogonal', bias_initializer=r'zeros', unit_forget_bias=True, kernel_regularizer=None, recurrent_regularizer=None, bias_regularizer=None, activity_regularizer=None, kernel_constraint=None, recurrent_constraint=None, bias_constraint=None, dropout=SETTINGS[r'dropout_rate'], recurrent_dropout=SETTINGS[r'dropout_rate'], implementation=1, return_sequences=True, return_state=False, go_backwards=False, stateful=False, unroll=False, input_shape=(SETTINGS[r'seq_len'], self.char_len)))
        self.model.add(Dense(self.char_len, activation=SETTINGS[r'activation_dense'], use_bias=True, kernel_initializer=r'glorot_uniform', bias_initializer=r'zeros', kernel_regularizer=None, bias_regularizer=None, activity_regularizer=None, kernel_constraint=None, bias_constraint=None))
        self.model.add(LSTM(SETTINGS[r'hidden_dimension_size'], activation=SETTINGS[r'activation'], recurrent_activation=r'sigmoid', use_bias=True, kernel_initializer=r'glorot_uniform', recurrent_initializer=r'orthogonal', bias_initializer=r'zeros', unit_forget_bias=True, kernel_regularizer=None, recurrent_regularizer=None, bias_regularizer=None, activity_regularizer=None, kernel_constraint=None, recurrent_constraint=None, bias_constraint=None, dropout=SETTINGS[r'dropout_rate'], recurrent_dropout=SETTINGS[r'dropout_rate'], implementation=1, return_sequences=True, return_state=False, go_backwards=False, stateful=False, unroll=False))
        self.model.add(Dense(self.char_len, activation=SETTINGS[r'activation_dense'], use_bias=True, kernel_initializer=r'glorot_uniform', bias_initializer=r'zeros', kernel_regularizer=None, bias_regularizer=None, activity_regularizer=None, kernel_constraint=None, bias_constraint=None))
        self.model.add(LSTM(SETTINGS[r'hidden_dimension_size'], activation=SETTINGS[r'activation'], recurrent_activation=r'sigmoid', use_bias=True, kernel_initializer=r'glorot_uniform', recurrent_initializer=r'orthogonal', bias_initializer=r'zeros', unit_forget_bias=True, kernel_regularizer=None, recurrent_regularizer=None, bias_regularizer=None, activity_regularizer=None, kernel_constraint=None, recurrent_constraint=None, bias_constraint=None, dropout=SETTINGS[r'dropout_rate'], recurrent_dropout=SETTINGS[r'dropout_rate'], implementation=1, return_sequences=False, return_state=False, go_backwards=False, stateful=False, unroll=False))
        self.model.add(Dense(self.char_len, activation=SETTINGS[r'activation_final'], use_bias=True, kernel_initializer=r'glorot_uniform', bias_initializer=r'zeros', kernel_regularizer=None, bias_regularizer=None, activity_regularizer=None, kernel_constraint=None, bias_constraint=None))
        self.model.compile(optimizer=SETTINGS[r'optimizer'], loss=SETTINGS[r'loss'], metrics=[r'accuracy'], loss_weights=None, sample_weight_mode=None, weighted_metrics=None, target_tensors=None)

    def train_model(self) -> None:
        """Train the model."""
        stdout.write('Begin Training\n')
        self.model.fit(  # type: ignore
            x=self.poetry_x,
            y=self.poetry_y,
            batch_size=SETTINGS[r'batch_size'],
            callbacks=[LambdaCallback(
                on_epoch_begin=epoch_begin_callback,
                on_epoch_end=self.epoch_end_callback
            )],
            epochs=SETTINGS[r'epochs'],
            verbose=0,
            validation_split=0.0
        )

    def epoch_end_callback(self, epoch, _) -> None:  # pylint: disable=W0613
        """Function invoked at the end of each epoch."""
        start_index: int = randint(0, self.text_len - SETTINGS[r'seq_len'] - 1)
        seed: str = self.text[start_index: start_index + SETTINGS[r'seq_len']]
        self.generated_poetry = r''
        # Create poetry
        for i in range(SETTINGS[r'poem_char_len']):  # pylint: disable=W0612
            # Make the input sequence
            x_pred: xp.array = xp.zeros((1, SETTINGS[r'seq_len'], self.char_len))
            for index, char in enumerate(seed):
                x_pred[0, (SETTINGS[r'seq_len'] - len(seed)) + index, self.char_indices[char]] = 1
            # Predict the next character
            predicted: xp.array = self.model.predict(
                x_pred,
                batch_size=SETTINGS[r'batch_size'],
                callbacks=None,
                max_queue_size=8,
                steps=None,
                use_multiprocessing=False,
                verbose=0,
                workers=1
            )[0]
            # Convert the vector to an integer and then to a character
            next_char: str = self.text[xp.argmax(predicted)]
            # Add the character to results
            self.generated_poetry += next_char
            # Shift seed and the predicted character
            seed = seed[1:] + next_char


# FUNCTIONS #


def epoch_begin_callback(epoch, _) -> None:
    """Function invoked at the beginning of each epoch."""
    stdout.write(f'''Epoch: {epoch + 1}/{SETTINGS[r'epochs']}\n''')


def getfile(_filename: str) -> str:
    """Get the file contents and return as a str."""
    with open(_filename, mode=r'rt', encoding=r'utf-8') as _file:
        return r''.join(_file.readlines()).strip()


# MAIN #


def main(text_path: str, output_path: str) -> int:
    """Entry-point for poetry creation."""
    try:
        neural_net = PoetryNeuralNet(text_path)
        neural_net.build_model()
        neural_net.train_model()
        neural_net.save_model_weights()
        neural_net.write2file(output_path)
    except KeyboardInterrupt:
        return 2
    except BaseException as _err:  # pylint: disable=W0703
        stderr.write(f'ERROR: {_err}\n')
        return 1
    return 0


if __name__ == '__main__':
    # Process Arguments
    PARSER = ArgumentParser(description=r'Generate poetry using neural nets.')
    PARSER.add_argument(
        r'text_path',
        metavar=r'text_path',
        type=str,
        help=r'Path to the training text.'
    )
    PARSER.add_argument(
        r'output_path',
        metavar=r'output_path',
        type=str,
        help=r'Path to save the generated poetry.'
    )
    ARGS = PARSER.parse_args()
    TEXT_PATH: str = ARGS.text_path
    OUTPUT_PATH: str = ARGS.output_path
    del ARGS, PARSER
    if not (TEXT_PATH and OUTPUT_PATH):
        raise SystemExit(1)
    # Begin Deep-learning
    raise SystemExit(main(TEXT_PATH, OUTPUT_PATH))
