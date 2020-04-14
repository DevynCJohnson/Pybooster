#!/usr/bin/env python3
# -*- coding: utf-8; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on;
"""@brief Generate poetry using neural nets.

@file deep_poetry.py
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
from keras.models import Sequential  # noqa: E402  # pylint: disable=C0413
from keras.layers import Dense  # noqa: E402  # pylint: disable=C0413
from keras.layers.recurrent import LSTM  # noqa: E402  # pylint: disable=C0413
import numpy as xp  # noqa: E402  # pylint: disable=C0413


# SETTINGS #


SETTINGS: dict = {
    r'activation': r'tanh',
    r'activation_dense': r'tanh',
    r'activation_final': r'softmax',
    r'batch_size': 512,
    r'diversity': 0.7,  # (0.2, 0.5, 1.0, 1.2)
    r'dropout_rate': 0.4,
    r'epochs': 80,  # 60
    r'hidden_dimension_size': 1024,
    r'learning_rate': 0.03,  # 0.01
    r'loss': r'categorical_crossentropy',
    r'maxlen': 40,
    r'optimizer': r'adam',
    r'seq_len': 100,
    r'poem_char_len': 400,
    r'step': 3
}


# CLASSES #


class PoetryNeuralNet:  # pylint: disable=R0902
    """Object representing a neural-net instance for poetry."""

    def __init__(self, text_path: str) -> None:
        """Initialize the neurl-net."""
        self.generated_poetry: str = r''
        self.model = Sequential()
        self.text: str = getfile(text_path).casefold()
        text_len: int = len(self.text)
        self.chars: list = sorted(set(self.text))
        self.char_indices: dict = {_char: _index for _index, _char in enumerate(self.chars)}
        # Cut the text into semi-redundant sequences of characters
        sentences: list = []
        next_chars: list = []
        for i in range(0, text_len - SETTINGS[r'maxlen'], SETTINGS[r'step']):
            sentences.append(self.text[i: i + SETTINGS[r'maxlen']])
            next_chars.append(self.text[i + SETTINGS[r'maxlen']])
        self.char_len: int = len(self.chars)
        if not self.char_len:
            raise Exception(r'No characters found!')
        sentence_len: int = len(sentences)
        if not sentence_len:
            raise Exception(r'No sentences found!')
        stdout.write(f'Number of Sequences: {sentence_len}\n')
        # Data Pre-processing
        self.poetry_x: xp.array = xp.zeros((sentence_len, SETTINGS[r'maxlen'], self.char_len), dtype=xp.bool)
        self.poetry_y: xp.array = xp.zeros((sentence_len, self.char_len), dtype=xp.bool)
        for _index, sentence in enumerate(sentences):
            for _char_index, char in enumerate(sentence):
                self.poetry_x[_index, _char_index, self.char_indices[char]] = 1
            self.poetry_y[_index, self.char_indices[next_chars[_index]]] = 1

    def build_model(self) -> None:
        """Build the LSTM model."""
        self.model.add(LSTM(SETTINGS[r'hidden_dimension_size'], activation=r'tanh', recurrent_activation=r'sigmoid', use_bias=True, kernel_initializer=r'glorot_uniform', recurrent_initializer=r'orthogonal', bias_initializer=r'zeros', unit_forget_bias=True, kernel_regularizer=None, recurrent_regularizer=None, bias_regularizer=None, activity_regularizer=None, kernel_constraint=None, recurrent_constraint=None, bias_constraint=None, dropout=SETTINGS[r'dropout_rate'], recurrent_dropout=SETTINGS[r'dropout_rate'], implementation=1, return_sequences=True, return_state=False, go_backwards=False, stateful=False, unroll=False, input_shape=(self.poetry_x.shape[1], self.poetry_x.shape[2])))  # pylint: disable=E1136
        self.model.add(LSTM(SETTINGS[r'hidden_dimension_size'], activation=r'tanh', recurrent_activation=r'sigmoid', use_bias=True, kernel_initializer=r'glorot_uniform', recurrent_initializer=r'orthogonal', bias_initializer=r'zeros', unit_forget_bias=True, kernel_regularizer=None, recurrent_regularizer=None, bias_regularizer=None, activity_regularizer=None, kernel_constraint=None, recurrent_constraint=None, bias_constraint=None, dropout=SETTINGS[r'dropout_rate'], recurrent_dropout=SETTINGS[r'dropout_rate'], implementation=1, return_sequences=True, return_state=False, go_backwards=False, stateful=False, unroll=False))
        self.model.add(LSTM(SETTINGS[r'hidden_dimension_size'], activation=r'tanh', recurrent_activation=r'sigmoid', use_bias=True, kernel_initializer=r'glorot_uniform', recurrent_initializer=r'orthogonal', bias_initializer=r'zeros', unit_forget_bias=True, kernel_regularizer=None, recurrent_regularizer=None, bias_regularizer=None, activity_regularizer=None, kernel_constraint=None, recurrent_constraint=None, bias_constraint=None, dropout=SETTINGS[r'dropout_rate'], recurrent_dropout=SETTINGS[r'dropout_rate'], implementation=1, return_sequences=False, return_state=False, go_backwards=False, stateful=False, unroll=False))
        self.model.add(Dense(self.poetry_y.shape[1], activation=SETTINGS[r'activation_final'], use_bias=True, kernel_initializer=r'glorot_uniform', bias_initializer=r'zeros', kernel_regularizer=None, bias_regularizer=None, activity_regularizer=None, kernel_constraint=None, bias_constraint=None))  # pylint: disable=E1136
        self.model.compile(optimizer=SETTINGS[r'optimizer'], loss=SETTINGS[r'loss'], metrics=None, loss_weights=None, sample_weight_mode=None, weighted_metrics=None, target_tensors=None)

    def train_model(self) -> None:
        """Train the model."""
        self.model.fit(  # type: ignore
            x=self.poetry_x,
            y=self.poetry_y,
            batch_size=SETTINGS[r'batch_size'],
            callbacks=[LambdaCallback(on_epoch_end=self.epoch_end_callback)],
            epochs=SETTINGS[r'epochs'],
            verbose=0,
            validation_split=0.0
        )

    def create_poetry(self, output_path: str) -> None:
        """Create poetry."""
        stdout.write('\nGenerating Poetry\n')
        self.generated_poetry = self.model.predict(
            xp.zeros((1, SETTINGS[r'maxlen'], self.char_len)),
            batch_size=SETTINGS[r'batch_size'],
            callbacks=None,
            max_queue_size=8,
            steps=None,
            use_multiprocessing=False,
            verbose=0,
            workers=1
        )
        self.write2file(output_path)

    def save_model_weights(self) -> None:
        """Save the weights of the model to a file."""
        self.model.save_weights(f'''Poetry_Weights_m{SETTINGS[r'maxlen']}_e{SETTINGS[r'epochs']}_b{SETTINGS[r'batch_size']}_hd{SETTINGS[r'hidden_dimension_size']}.h5''')

    def load_model_weights(self) -> None:
        """Load the weights into the model form a file."""
        model_filename: str = f'''Poetry_Weights_m{SETTINGS[r'maxlen']}_e{SETTINGS[r'epochs']}_b{SETTINGS[r'batch_size']}_hd{SETTINGS[r'hidden_dimension_size']}.h5'''
        if isfile(model_filename):
            self.model.load_weights(model_filename)
        else:
            stdout.write(f'Model filename {model_filename} could not be found!\n')

    def epoch_end_callback(self, epoch: int, _) -> None:
        """Function invoked at end of each epoch."""
        stdout.write(f'''Epoch: {epoch + 1}/{SETTINGS[r'epochs']}\n''')
        start_index: int = randint(0, len(self.text) - SETTINGS[r'maxlen'] - 1)
        sentence: str = self.text[start_index: start_index + SETTINGS[r'maxlen']]
        for i in range(SETTINGS[r'poem_char_len']):  # pylint: disable=W0612
            x_pred: xp.array = xp.zeros((1, SETTINGS[r'maxlen'], self.char_len))
            for _char_index, char in enumerate(sentence):
                x_pred[0, _char_index, self.char_indices[char]] = 1.0
            next_index: xp.array = sample_probability(
                self.model.predict(
                    x_pred,
                    batch_size=SETTINGS[r'batch_size'],
                    callbacks=None,
                    max_queue_size=8,
                    steps=None,
                    use_multiprocessing=False,
                    verbose=0,
                    workers=1
                )[0],
                SETTINGS[r'diversity']
            )
            sentence = sentence[1:] + self.chars[next_index]
        self.generated_poetry += '\n' + sentence

    def write2file(self, _filename: str) -> None:
        """Send data to a new file or overwrite the file."""
        if not self.generated_poetry:
            raise Exception(r'Poetry is available to write!')
        with open(_filename, mode=r'wt', encoding=r'utf-8') as _file:
            _file.write(self.generated_poetry)


# FUNCTIONS #


def getfile(_filename: str) -> str:
    """Get the file contents and return as a str."""
    with open(_filename, mode=r'rt', encoding=r'utf-8') as _file:
        return r''.join(_file.readlines()).strip()


def sample_probability(preds: xp.array, diversity: float = 1.0) -> xp.array:
    """Helper function to sample an index from a probability array."""
    exp_preds: xp.array = xp.exp(xp.log(xp.asarray(preds).astype(r'float64')) / diversity)
    return xp.argmax(xp.random.multinomial(1, exp_preds / xp.sum(exp_preds), 1))


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
