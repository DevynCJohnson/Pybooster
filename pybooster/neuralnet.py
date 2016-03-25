#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
# pylint: disable=C0103,C0200,R0902,R0914,W1401
"""@brief A lightweight pure-Python neural network library
@file neuralnet.py
@package pybooster.neuralnet
@author Devyn Collier Johnson <DevynCJohnson@Gmail.com>
@copyright LGPLv3
@version 2016.03.25

@section DESCRIPTION
\code{.py}
from pybooster.neuralnet import NeuroCode

data = [  # The input and output of an XOR gate
    ([0, 0], [0]),
    ([0, 1], [1]),
    ([1, 0], [1]),
    ([1, 1], [0])
]  # Provide sample input and expected output

net = NeuroCode(
    data,
    layers = [4, 3],  # Number of nodes in each hidden layers (between input and output)
    iterations = 40000,   # Maximum training iterations
    rate = 0.1  # Learning rate
)

net.train()  # Returns (correctness, iterations)

output = net.run([1, 0])  # Execute neuralnet

net.writedump('xor_code.py')  # Save the generated code
\endcode

@section LICENSE
GNU Lesser General Public License v3
Copyright (c) Devyn Collier Johnson, All rights reserved.

The PyBooster Library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 3.0 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library.
"""


import math
import pickle
import zlib

from base64 import b64decode, b64encode
from random import random


__all__ = [
    'flatten',
    'NeuroCode',
]


def flatten(_lst: list):
    """Flatten list of lists"""
    for _sublist in _lst:
        if isinstance(_sublist, list):
            for _sublist in flatten(_sublist):
                yield _sublist
        else:
            yield _sublist


def _indent(txt: str, chars: int) -> str:
    """Indent the given code"""
    result = r''
    d = r' ' * chars
    for line in txt.split('\n'):
        result = result + (d + line + '\n')
    return result


class NeuroCode:
    """Neurocode class"""
    def __init__(self, data: list, layers: list, iterations: int=40000, rate: float=0.4):
        """Initiate Neurocode-learning

         - layers: Hidden neural layers (neurocodes between the input and output layers); Specify the number of hidden layers in the network and the size of each layer. For example, `layers = [3, 4]` makes two hidden layers, the first with 3 nodes and the second with 4 nodes. By default, one hidden layer is used with a size proportionate to the size of the input array.
         - error_thresh: Error threshold goal (float less than 1.0)
         - rate: Learning rate (float less than 1.0)
        """
        input_size = len(data[0][0])
        output_size = len(data[0][1])
        if not layers:
            self.hidden_layers = [max(3, math.floor(input_size / 2))]
        else:
            self.hidden_layers = layers
        self.sizes = list(flatten([input_size, self.hidden_layers, output_size]))
        self.iterations = iterations
        self.rate = rate
        self.io_rules = data
        self.io_rules_len = len(data)
        self.outputlayer = len(self.sizes) - 1
        # Training State
        self.deltas = [[]] * (self.outputlayer + 1)
        self.changes = [[]] * (self.outputlayer + 1)
        self.errors = [[]] * (self.outputlayer + 1)
        self.outputs = [[]] * (self.outputlayer + 1)
        self.biases = [[]] * (self.outputlayer + 1)
        self.weights = [[]] * (self.outputlayer + 1)
        for layer in range(self.outputlayer + 1):
            _size = self.sizes[layer]
            self.deltas[layer] = [0] * _size
            self.errors[layer] = [0] * _size
            self.outputs[layer] = [0] * _size
            if layer > 0:
                self.biases[layer] = [(random() * 0.4) - 0.2 for i in range(_size)]
                self.weights[layer] = [0] * _size
                self.changes[layer] = self.weights[layer]
                for node in range(_size):
                    _prev_size = self.sizes[layer - 1]
                    self.weights[layer][node] = [(random() * 0.4) - 0.2 for j in range(_prev_size)]
                    self.changes[layer][node] = [0] * _prev_size

    def train(self) -> tuple:  # noqa C901
        """Main Neurocode training"""
        error = 1.0
        used_iterations = 0
        for i in range(self.iterations):
            used_iterations = i
            if error <= 0.0001:  # Error Threshold
                break
            _sum = 0.0
            for d in self.io_rules:
                self.run(d[0])
                self._calculate_deltas(d[1])
                # Adjust Weights
                for layer in range(1, self.outputlayer + 1):
                    incoming = self.outputs[layer - 1]
                    for node in range(self.sizes[layer]):
                        delta = self.deltas[layer][node]
                        for k in range(len(incoming)):
                            change = self.changes[layer][node][k]
                            change = (self.rate * delta * incoming[k]) + (0.1 * change)  # 0.1 = momentum
                            self.changes[layer][node][k] = change
                            self.weights[layer][node][k] = change + self.weights[layer][node][k]
                        self.biases[layer][node] = self.biases[layer][node] + (self.rate * delta)
                _errsum = 0.0
                for err in self.errors[self.outputlayer]:
                    _errsum = _errsum + (err ** 2.0)
                err = _errsum / len(self.errors[self.outputlayer])
                _sum = _sum + err
            error = _sum / self.io_rules_len
        return (error, used_iterations)  # (float, int)

    def run(self, _input) -> list:
        """Forward Propagation; Execute neuralnet"""
        output = self.outputs[0] = _input  # Set output state of input layer
        for layer in range(1, self.outputlayer + 1):
            for node in range(self.sizes[layer]):
                weights = self.weights[layer][node]
                _sum = self.biases[layer][node]
                for k in range(len(weights)):
                    _sum = _sum + (weights[k] * _input[k])
                self.outputs[layer][node] = 1 / (1 + math.exp(-_sum))
            _input = self.outputs[layer]
            output = _input
        return output

    def _calculate_deltas(self, target: list):
        """Backward Propagation"""
        layer = self.outputlayer
        while layer >= 0:
            for node in range(self.sizes[layer]):
                output = self.outputs[layer][node]
                error = 0.0
                if layer == self.outputlayer:
                    error = target[node] - output
                else:
                    deltas = self.deltas[layer + 1]
                    for k in range(len(deltas)):
                        error = error + (deltas[k] * self.weights[layer + 1][k][node])
                self.errors[layer][node] = error
                self.deltas[layer][node] = (error * output) * (1 - output)
            layer -= 1

    def bestof(self, generations: int=16) -> bytes:
        """Return the best neuralnet from the given amount produced as a byte string"""
        rounds = generations
        best_result = 1.0  # Store the best error-rate
        best_neuralnet = b''
        while rounds != 0:
            result = self.train()
            if result[0] < best_result:
                best_result = result[0]
                best_neuralnet = self.dump()
            rounds -= 1
        return best_neuralnet

    def dump(self) -> bytes:
        """Pickle neural-network and compress it using Zlib"""
        return b64encode(zlib.compress(pickle.dumps(self), 9))

    def writedump(self, _filename: str) -> None:
        """Pickle neural-network, compress it using Zlib, and then write it to a file"""
        with open(_filename, mode='wb') as _file:
            _file.write(b64encode(zlib.compress(pickle.dumps(self), 9)))
        return None

    def neurocode2pythonfile(self, _filename: str, _neuroname: str) -> None:
        """Write the Neurocode to a file as Python code"""
        with open(_filename, mode='wt', encoding='utf-8') as _code:
            _code.write(self.to_function(_neuroname))
        return None

    def neurocode2cfile(self, _filename: str, _neuroname: str) -> None:
        """Write the Neurocode to a file as C code"""
        with open(_filename, mode='wt', encoding='utf-8') as _code:
            _code.write(self.to_c_function(_neuroname))
        return None

    def neurocode2javafile(self, _filename: str, _neuroname: str) -> None:
        """Write the Neurocode to a file as Java code"""
        with open(_filename, mode='wt', encoding='utf-8') as _code:
            _code.write(self.to_java_method(_neuroname))
        return None

    @staticmethod
    def load(s):
        """Load the given compressed+pickled neural-network"""
        return pickle.loads(zlib.decompress(b64decode(s)))

    def to_function(self, fnname: str='nn_run', indent: int=0):
        """Convert the neural-network to Python code"""
        fn = 'def {fnname}(i):\n'.format(fnname=fnname)
        for l in range(1, self.outputlayer + 1):
            if l < self.outputlayer:
                fn += '    o = [\n'
            else:
                fn += '    return [\n'
            size = self.sizes[l]
            for n in range(size):
                term = str(-self.biases[l][n])
                length = len(self.weights[l][n])
                for k in range(length):
                    w = self.weights[l][n][k]
                    term = term + (r'-' if w > 0 else r'+') + str(abs(w)) + r'*i[' + str(k) + r']'
                fn += r'        1/(1+math.exp(' + term + r'))' + (r',' if n != size - 1 else r'') + '\n'
            fn += '    ]\n'
            if l != self.outputlayer:
                fn += '    i = o\n'
        return _indent(fn, indent)

    def to_java_method(self, fnname: str='nn_run', static=False, scope='protected', indent: int=4):
        """Convert the neural-network to Java code"""
        fn = scope + (r' static ' if static else r' ') + 'double[] {fnname}(double[] i)'.format(fnname=fnname) + '{\n'
        fn += '    double[] o;\n'
        for l in range(1, self.outputlayer + 1):
            if l < self.outputlayer:
                fn += '    o = new double[]{\n'
            else:
                fn += '    return new double[]{\n'
            size = self.sizes[l]
            for n in range(size):
                term = str(-self.biases[l][n])
                length = len(self.weights[l][n])
                for k in range(length):
                    w = self.weights[l][n][k]
                    term = term + (r'-' if w > 0 else r'+') + str(abs(w)) + r'*i[' + str(k) + r']'
                fn += r'        1/(1+Math.exp(' + term + r'))' + (r',' if n != size - 1 else '') + '\n'
            fn += '    };\n'
            if l != self.outputlayer:
                fn += '    i = o;\n'
        fn += r'}'
        return _indent(fn, indent)

    def to_c_function(self, fnname: str='nn_run', indent: int=0):
        """Convert the neural-network to C code"""
        fn = 'void {fnname}(double *i, double *o)'.format(fnname=fnname) + '{\n'
        terms = {}
        oterms = {}
        lterms = []
        for k in range(self.sizes[0]):
            lterms.append(r'o0_' + str(k))
            terms[lterms[-1]] = r'i[' + str(k) + r']'
        for l in range(1, self.outputlayer + 1):
            size = self.sizes[l]
            for n in range(size):
                term = str(-self.biases[l][n])
                length = len(self.weights[l][n])
                for k in range(length):
                    w = self.weights[l][n][k]
                    term = term + (r'-' if w > 0 else r'+') + str(abs(w)) + r'*o' + str(l - 1) + r'_' + str(k)
                v = r'(1/(1+exp(' + term + r')))'
                for k in lterms:
                    v = v.replace(k, terms[k])
                lterms.append(r'o' + str(l) + r'_' + str(n))
                terms[lterms[-1]] = v
                if l == self.outputlayer:
                    oterms[r'o' + str(l) + r'_' + str(n)] = r'o[' + str(n) + r']'
        for k, v in oterms.items():
            fn += r'    ' + v + r' = ' + terms[k] + ';\n'
        fn += '}\n'
        return _indent(fn, indent)
