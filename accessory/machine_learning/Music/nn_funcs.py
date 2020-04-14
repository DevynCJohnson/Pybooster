#!/usr/bin/env python3
# -*- coding: utf-8; Mode: Python; indent-tabs-mode: nil; tab-width: 4 -*-
# vim: set fileencoding=utf-8 filetype=python syntax=python.doxygen fileformat=unix tabstop=4 expandtab :
# kate: encoding utf-8; bom off; syntax python; indent-mode python; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on;
"""@brief Functions used by the music neural network scripts.

@file nn_funcs.py
@version 2020.04.02
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3

@section USAGE
python3 ./convert_directory.py && python3 ./train.py && python3 ./generate.py

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


from os import environ, listdir, makedirs, path, system
from pipes import quote
from sys import stdout

environ[r'KERAS_BACKEND'] = r'tensorflow'
environ[r'TF_CPP_MIN_LOG_LEVEL'] = r'3'

from keras.constraints import MinMaxNorm  # noqa: E402  # pylint: disable=C0413
from keras.models import Model, Sequential  # noqa: E402  # pylint: disable=C0413
from keras.layers import (  # noqa: E402  # pylint: disable=C0413
    Bidirectional,
    Conv1D,
    Dense,
    GaussianDropout,
    Input,
    TimeDistributed
)
from keras.layers.recurrent import LSTM  # noqa: E402  # pylint: disable=C0413
import numpy as xp  # noqa: E402  # pylint: disable=C0413
import scipy.io.wavfile as wav  # noqa: E402  # pylint: disable=C0413


__all__: list = [
    # SETTINGS #
    r'NEURAL_NET_CONFIG',
    # GENERATION FUNCTIONS #
    r'generate_from_seed',
    r'generate_seed_sequence',
    r'postprocessing_audio',
    # CONVERSION FUNCTIONS #
    r'convert_flac_to_wav',
    r'convert_folder_to_wav',
    r'convert_mp3_to_wav',
    r'convert_np_audio_to_sample_blocks',
    r'convert_wav_files_to_nptensor',
    r'fft_blocks_to_time_blocks',
    r'time_blocks_to_fft_blocks',
    # I/O FUNCTIONS #
    r'load_training_example',
    r'read_wav_as_np',
    r'save_generated_example',
    r'write_np_as_wav',
    # NEURAL NETWORK FUNCTIONS #
    r'create_lstm_network',
    r'create_neural_network'
]


# SETTINGS #


NEURAL_NET_CONFIG: dict = {
    r'batch_size': 1,  # Number of training examples pushed to the GPU per batch
    r'block_size': 11025,  # Size of the input state (`sampling_freq / 4)
    r'clip_len': 8,  # Length of clips (in seconds)
    r'dataset_directory': r'./datasets/Music/',
    r'dropout_rate': 0.4,  # Gaussian dropout rate
    r'epochs': 16,  # Number of epochs for training
    r'hidden_dimension_size': 1800,  # Number of Hidden Dimensions
    r'loss': r'mean_squared_error',
    r'max_files': 16,  # Maximum number of files used for training
    r'max_seq_len': int(round((44100 * 8) / 11025)),  # Zero-padding track sequences (`round((sampling_freq * clip_len) / blocksize)`)
    r'model_basename': r'./datasets/NPWeights',  # The weights filename for saving/loading trained models
    r'model_file': r'./datasets/MusicNP',  # The model filename for the training data
    r'num_iters': 8,  # Number of iterations for training
    r'num_recurrent_units': 2,
    r'optimizer': r'adagrad',  # r'adam',
    r'output_filename': r'./generated_track.wav',
    r'sampling_frequency': 44100,
    r'seed_len': 8,
    r'sequence_length': 128  # Defines the length of the generated track (`samples = sequence_length * example_len`)
}


# GENERATION FUNCTIONS #


def generate_seed_sequence(seed_len: int, training_data: xp.array) -> xp.array:
    """Copies a random example's first seed_len sequences as input to the generation algorithm."""
    rand_idx: int = xp.random.randint(training_data.shape[0] - seed_len, size=1)[0]
    rand_seed: xp.array = xp.concatenate(tuple(training_data[rand_idx + i] for i in range(seed_len)), axis=0)
    return xp.reshape(rand_seed, (1, rand_seed.shape[0], rand_seed.shape[1]))  # pylint: disable=E1136


def generate_from_seed(model, seed: xp.array, seq_length: int, data_variance: xp.array = None, data_mean: xp.array = None) -> list:
    """Extrapolates from a given seed sequence to generate the audio."""
    output: list = []
    counter: int = 0
    # Generate audio
    for i in range(seq_length):
        counter += 1
        stdout.write(f'Processing sequence: {counter}/{seq_length}\n')
        seed_seq_new: xp.array = model.predict(  # Generate X_n + 1
            seed,
            batch_size=NEURAL_NET_CONFIG[r'batch_size'],
            callbacks=None,
            max_queue_size=8,
            steps=None,
            use_multiprocessing=False,
            verbose=0,
            workers=1
        )
        # Concatenate X_n + 1 onto output
        if i == 0:
            for j in range(seed_seq_new.shape[1]):
                output.append(seed_seq_new[0][j].copy())
        else:
            output.append(seed_seq_new[0][seed_seq_new.shape[1] - 1].copy())
        new_seq: xp.array = seed_seq_new[0][seed_seq_new.shape[1] - 1]
        seed = xp.concatenate((seed, xp.reshape(new_seq, (1, 1, new_seq.shape[0]))), axis=1)
    return postprocessing_audio(output, data_variance, data_mean)


def postprocessing_audio(output: list, data_variance: xp.array, data_mean: xp.array) -> list:
    """Post-process the generated sequence to have valid frequencies."""
    stdout.write('Post-processing generated audio\n')
    for i, value in enumerate(output):
        output[i] = (value * data_variance) + (data_mean)
    return output


# CONVERSION FUNCTIONS #


def convert_mp3_to_wav(filename: str, sample_freq: int = 44100) -> str:
    """Convert MP3 files to WAV."""
    if filename[-4:] != r'.mp3':
        return r''
    files: list = filename.split(r'/')
    orig_filename: str = files[-1][0:-4]
    new_path: str = r'/' if filename[0] == r'/' else r''
    for i in range(len(files) - 1):
        new_path += fr'{files[i]}/'
    tmp_path: str = fr'{new_path}tmp'
    new_path += r'wave'
    if not path.exists(new_path):
        makedirs(new_path)
    if not path.exists(tmp_path):
        makedirs(tmp_path)
    filename_tmp: str = fr'{tmp_path}/{orig_filename}.mp3'
    new_name: str = fr'{new_path}/{orig_filename}.wav'
    sample_freq_str: str = fr'{(float(sample_freq) / 1000.0):.1f}'
    system(fr'lame --quiet -a -m m {quote(filename)} {quote(filename_tmp)}')  # nosec
    system(fr'lame --quiet --decode {quote(filename_tmp)} {quote(new_name)} --resample {sample_freq_str}')  # nosec
    return new_name


def convert_flac_to_wav(filename: str, sample_freq: int = 44100) -> str:
    """Convert FLAC files to WAV."""
    if filename[-5:] != r'.flac':
        return r''
    files: list = filename.split(r'/')
    orig_filename: str = files[-1][0:-5]
    new_path: str = r'/' if filename[0] == r'/' else r''
    for i in range(len(files) - 1):
        new_path += fr'{files[i]}/'
    new_path += r'wave'
    if not path.exists(new_path):
        makedirs(new_path)
    new_name: str = fr'{new_path}/{orig_filename}.wav'
    system(fr'sox --buffer 262144 --multi-threaded --no-show-progress -V0 {quote(filename)} {quote(new_name)} channels 1 rate {sample_freq}')  # nosec
    return new_name


def convert_folder_to_wav(directory: str = r'./datasets/Music/', sample_freq: int = 44100) -> str:
    """Convert all of the audio files in the directory to WAV files."""
    for _file in listdir(directory):
        _filename: str = fr'{directory}{_file}'
        if _file.endswith(r'.mp3'):
            convert_mp3_to_wav(_filename, sample_freq)
        if _file.endswith(r'.flac'):
            convert_flac_to_wav(_filename, sample_freq)
    return fr'{directory}wave/'


def convert_np_audio_to_sample_blocks(song_xp: xp.array, block_size: int = 11025) -> list:
    """Convert the Numpy audio arrays to sample blocks."""
    block_lists: list = []
    samples_processed: int = 0
    while samples_processed < song_xp.shape[0]:
        block: xp.array = song_xp[samples_processed:samples_processed + block_size]
        if block.shape[0] < block_size:  # Add padding
            block = xp.concatenate((block, xp.zeros((block_size - block.shape[0],))))
        block_lists.append(block)
        samples_processed += block_size
    return block_lists


def time_blocks_to_fft_blocks(blocks_time_domain: xp.array) -> list:
    """Convert the time blocks to FFT blocks."""
    fft_blocks: list = []
    for block in blocks_time_domain:
        fft_block = xp.fft.fft(block)
        fft_blocks.append(xp.concatenate((xp.real(fft_block), xp.imag(fft_block))))
    return fft_blocks


def fft_blocks_to_time_blocks(blocks_ft_domain: xp.array) -> list:
    """Convert the FFT blocks to time blocks."""
    time_blocks: list = []
    for block in blocks_ft_domain:
        num_elems: int = int(block.shape[0] / 2)
        time_blocks.append(xp.fft.ifft((block[0:num_elems] + 1.0j) * block[num_elems:]))
    return time_blocks


def convert_wav_files_to_nptensor(files: list, block_size: int, max_seq_len: int, out_file: str) -> None:  # pylint: disable=R0914
    """Convert the WAV files to Numpy Tensors."""
    num_files: int = len(files)
    if num_files > 16:  # The maximum number of files used for learning is 16
        num_files = 16
    chunks_x: list = []
    chunks_y: list = []
    # Process each audio file
    for file_idx in range(num_files):
        _file = files[file_idx]
        stdout.write(f'Processing: {file_idx + 1}/{num_files}\n')
        stdout.write(f'Filename: {_file}\n')
        x_data, y_data = load_training_example(_file, block_size)
        cur_seq: int = 0
        total_seq: int = len(x_data)
        while cur_seq + max_seq_len < total_seq:
            chunks_x.append(x_data[cur_seq:cur_seq + max_seq_len])
            chunks_y.append(y_data[cur_seq:cur_seq + max_seq_len])
            cur_seq += max_seq_len
    num_examples: int = len(chunks_x)
    num_dims_out: int = block_size * 2
    x_data = xp.zeros((num_examples, max_seq_len, num_dims_out))
    y_data = xp.zeros((num_examples, max_seq_len, num_dims_out))
    for j in range(num_examples):
        for i in range(max_seq_len):
            x_data[j][i] = chunks_x[j][i]
            y_data[j][i] = chunks_y[j][i]
    # Preparing saved example files
    stdout.write(f'Data Shape: {x_data.shape}\nFlushing examples to disk...\n')
    mean_x: xp.array = xp.mean(xp.mean(x_data, axis=0), axis=0)  # Mean across num examples and num timesteps
    std_x = xp.maximum(1.0e-8, xp.sqrt(xp.mean(xp.mean(xp.abs(x_data - mean_x) ** 2, axis=0), axis=0)))  # STD across num examples and num timesteps; Clamp variance if too tiny
    xp.save(fr'{out_file}_mean', mean_x)
    xp.save(fr'{out_file}_var', std_x)
    xp.save(fr'{out_file}_x', (x_data[:][:] - mean_x) / std_x)
    xp.save(fr'{out_file}_y', (y_data[:][:] - mean_x) / std_x)
    stdout.write('Done!\n')


# I/O FUNCTIONS #


def read_wav_as_np(filename: str) -> tuple:
    """Read a WAV file as if it were a Numpy array and normalize 16-bit input to the [-1, 1] range."""
    data: tuple = wav.read(filename)
    return data[1].astype(r'float32') / 32767.0, data[0]


def write_np_as_wav(audio_array: xp.ndarray, sample_rate: int, filename: str) -> None:
    """Write the Numpy array as a WAV file."""
    x_new: xp.array = xp.real(audio_array) * 32767.0
    wav.write(filename, sample_rate, x_new.astype(r'int16'))


def load_training_example(filename: str, block_size: int = 11025) -> tuple:
    """Load the WAV files as Numpy arrays and then return a tuple of FFT blocks."""
    x_t: list = convert_np_audio_to_sample_blocks(read_wav_as_np(filename)[0], block_size)
    y_t: list = x_t[1:]
    y_t.append(xp.zeros(block_size))  # Add special end block composed of all zeros
    return time_blocks_to_fft_blocks(x_t), time_blocks_to_fft_blocks(y_t)


def save_generated_example(filename: str, generated_sequence: list, sample_freq: int = 44100) -> None:
    """Save the Numpy audio array."""
    time_blocks: list = fft_blocks_to_time_blocks(generated_sequence)
    write_np_as_wav(xp.concatenate(time_blocks), sample_freq, filename)


# NEURAL NETWORK FUNCTIONS #


def create_neural_network(num_freq_dims: int, num_hidden_dims: int):
    """Create a LSTM neural network."""
    model = Sequential()
    # Convert frequency space to hidden space
    model.add(TimeDistributed(Dense(num_hidden_dims, activation=r'tanh', use_bias=True, kernel_initializer=r'glorot_uniform', bias_initializer=r'zeros', kernel_regularizer=None, bias_regularizer=None, activity_regularizer=None, kernel_constraint=None, bias_constraint=None), input_shape=(None, num_freq_dims)))
    # Add Layers
    model.add(Conv1D(num_hidden_dims, kernel_size=2, strides=1, padding=r'causal', data_format=r'channels_last', dilation_rate=1, activation=r'tanh', use_bias=True, kernel_initializer=r'glorot_uniform', bias_initializer=r'zeros', kernel_regularizer=None, bias_regularizer=None, activity_regularizer=None, kernel_constraint=None, bias_constraint=None))
    cur_unit: int = NEURAL_NET_CONFIG[r'num_recurrent_units']
    while cur_unit:
        cur_unit -= 1
        model.add(Bidirectional(LSTM(num_hidden_dims, activation=r'tanh', recurrent_activation=r'sigmoid', use_bias=True, kernel_initializer=r'glorot_uniform', recurrent_initializer=r'orthogonal', bias_initializer=r'zeros', unit_forget_bias=True, kernel_regularizer=None, recurrent_regularizer=None, bias_regularizer=None, activity_regularizer=None, kernel_constraint=None, recurrent_constraint=None, bias_constraint=MinMaxNorm(min_value=-0.99, max_value=0.99, rate=1.0, axis=0), dropout=NEURAL_NET_CONFIG[r'dropout_rate'], recurrent_dropout=NEURAL_NET_CONFIG[r'dropout_rate'], implementation=1, return_sequences=True, return_state=False, go_backwards=False, stateful=False, unroll=False)))
        model.add(GaussianDropout(NEURAL_NET_CONFIG[r'dropout_rate']))
    # Convert hidden space back to frequency space
    model.add(TimeDistributed(Dense(num_freq_dims, activation=r'linear', use_bias=True, kernel_initializer=r'glorot_uniform', bias_initializer=r'zeros', kernel_regularizer=None, bias_regularizer=None, activity_regularizer=None, kernel_constraint=None, bias_constraint=MinMaxNorm(min_value=-0.99, max_value=0.99, rate=1.0, axis=0))))
    model.compile(optimizer=NEURAL_NET_CONFIG[r'optimizer'], loss=NEURAL_NET_CONFIG[r'loss'], metrics=None, loss_weights=None, sample_weight_mode=None, weighted_metrics=None, target_tensors=None)
    return model


def create_lstm_network(num_freq_dims: int, num_hidden_dims: int):
    """Create a neural network."""
    inputs = Input(shape=(None, num_freq_dims))
    conv_in = Conv1D(num_hidden_dims, kernel_size=2, strides=1, padding=r'causal', data_format=r'channels_last', dilation_rate=1, activation=r'tanh', use_bias=True, kernel_initializer=r'glorot_uniform', bias_initializer=r'zeros', kernel_regularizer=None, bias_regularizer=None, activity_regularizer=None, kernel_constraint=None, bias_constraint=None)(inputs)
    lstm_1 = Bidirectional(LSTM(num_hidden_dims, activation=r'tanh', recurrent_activation=r'sigmoid', use_bias=True, kernel_initializer=r'glorot_uniform', recurrent_initializer=r'orthogonal', bias_initializer=r'zeros', unit_forget_bias=True, kernel_regularizer=None, recurrent_regularizer=None, bias_regularizer=None, activity_regularizer=None, kernel_constraint=None, recurrent_constraint=None, bias_constraint=None, dropout=0.0, recurrent_dropout=0.0, implementation=2, return_sequences=True, return_state=False, go_backwards=False, stateful=False, unroll=False))(GaussianDropout(NEURAL_NET_CONFIG[r'dropout_rate'])(conv_in))
    lstm_2 = Bidirectional(LSTM(num_hidden_dims, activation=r'tanh', recurrent_activation=r'sigmoid', use_bias=True, kernel_initializer=r'glorot_uniform', recurrent_initializer=r'orthogonal', bias_initializer=r'zeros', unit_forget_bias=True, kernel_regularizer=None, recurrent_regularizer=None, bias_regularizer=None, activity_regularizer=None, kernel_constraint=None, recurrent_constraint=None, bias_constraint=None, dropout=0.0, recurrent_dropout=0.0, implementation=2, return_sequences=True, return_state=False, go_backwards=False, stateful=False, unroll=False))(GaussianDropout(NEURAL_NET_CONFIG[r'dropout_rate'])(lstm_1))
    conv_out = Conv1D(num_freq_dims, kernel_size=2, strides=1, padding=r'causal', data_format=r'channels_last', dilation_rate=1, activation=r'tanh', use_bias=True, kernel_initializer=r'glorot_uniform', bias_initializer=r'zeros', kernel_regularizer=None, bias_regularizer=None, activity_regularizer=None, kernel_constraint=None, bias_constraint=MinMaxNorm(min_value=-0.99, max_value=0.99, rate=1.0, axis=0))(lstm_2)
    model = Model(inputs=inputs, outputs=conv_out)
    model.compile(loss=NEURAL_NET_CONFIG[r'loss'], optimizer=NEURAL_NET_CONFIG[r'optimizer'])
    return model
