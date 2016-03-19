#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8

# python3 setup.py build_ext --inplace
"""Distutils setup file for building C-based modules"""

#pylibc : lib
#	export CC="$(CC)"; export XOPTMZ="$(XOPTMZ)"; export HARDWARE="$(ARCH) $(BITS)"; export PYTHVERSION="$(PYVERSION)"; python$(PYVERSION) ./setup.py build_ext --inplace && $(STRIP) $(STRIP_PARAMS) $(DIR)/*cpython-$(CPYTHON)m.so || true

from distutils.core import Extension, setup

from os import chdir, environ


chdir('./lib')

try:
    XOPTMZ = environ['XOPTMZ'].split(' ')
    if len(XOPTMZ[0]) == 0:
        XOPTMZ = ['-DPYCLIBNONE']
except:
    XOPTMZ = ['-DPYCLIBNONE']
try:
    HARDWARE = environ['HARDWARE'].split(' ')
    if len(HARDWARE[0]) == 0:
        HARDWARE = ['-DPYCLIBNONE']
except:
    HARDWARE = ['-DPYCLIBNONE']
try:
    PYTHVERSION = environ['PYTHVERSION']
except:
    PYTHVERSION = '3'


__author__ = 'Devyn Collier Johnson'
__email__ = 'DevynCJohnson@Gmail.com'
__url__ = 'http://dcjtech.info/'
__copyright__ = 'LGPLv3'
__version__ = '2016.03.18'

SRCDIR = './clib-src/'
INCLUDE_DIRS = [SRCDIR]
LIBRARY_DIRS = ['./clib/']


COMPILE_ARGS = [
    '-std=c11',
    '-O3',
    '-Wl,-O3',
    '-g0',
    '-ggdb0',
    '-funroll-loops',
    '-fstack-protector-strong',
    '-fwrapv',
    '-pipe',
    '-pthread',
    '-ffunction-sections',
    '-fdata-sections',
    '-D_FORTIFY_SOURCE=2',
    '-DNDEBUG',
    '-Wall',
    '-pedantic',
] + HARDWARE


LINK_ARGS = [
    '-std=c11',
    '-Wl,-O3',
    '-O3',
    '-g0',
    '-ggdb0',
    '-funroll-loops',
    '-fstack-protector-strong',
    '-fwrapv',
    '-pipe',
    '-pthread',
    '-ffunction-sections',
    '-fdata-sections',
    '-D_FORTIFY_SOURCE=2',
    '-DNDEBUG',
    '-Wall',
    '-pedantic',
] + HARDWARE


CLASSIFIERS = [
    'Development Status :: 5 - Production/Stable',
    'Intended Audience :: Developers',
    'License :: OSI Approved :: GNU Lesser General Public License v3 (LGPLv3)',
    'Operating System :: Android',
    'Operating System :: BeOS',
    'Operating System :: iOS',
    'Operating System :: MacOS',
    'Operating System :: Microsoft',
    'Operating System :: Other OS',
    'Operating System :: POSIX',
    'Operating System :: Unix',
    'Programming Language :: C',
    'Programming Language :: Python :: 3 :: Only',
    'Topic :: Software Development :: Libraries',
]


setup(
    name='chemistry',
    version=__version__,
    description='Chemistry-related Functions',
    author=__author__,
    author_email=__email__,
    maintainer=__author__,
    maintainer_email=__email__,
    url=__url__,
    license=__copyright__,
    classifiers=CLASSIFIERS,
    ext_modules=[Extension(
        'chemistry',
        sources=[SRCDIR + 'pychemistry.c'],
        include_dirs=INCLUDE_DIRS,
        library_dirs=LIBRARY_DIRS,
        libraries=['chemistry_types'],
        extra_compile_args=COMPILE_ARGS,
        extra_link_args=LINK_ARGS,
    )],
)


setup(
    name='geometry',
    version=__version__,
    description='Geometry Equations',
    author=__author__,
    author_email=__email__,
    maintainer=__author__,
    maintainer_email=__email__,
    url=__url__,
    license=__copyright__,
    classifiers=CLASSIFIERS,
    ext_modules=[Extension(
        'geometry',
        sources=[SRCDIR + 'pygeometry.c'],
        include_dirs=INCLUDE_DIRS,
        library_dirs=LIBRARY_DIRS,
        extra_compile_args=COMPILE_ARGS + XOPTMZ,
        extra_link_args=LINK_ARGS,
    )],
)


setup(
    name='mathconstants',
    version=__version__,
    description='Math Constants',
    author=__author__,
    author_email=__email__,
    maintainer=__author__,
    maintainer_email=__email__,
    url=__url__,
    license=__copyright__,
    classifiers=CLASSIFIERS,
    ext_modules=[Extension(
        'mathconstants',
        sources=[SRCDIR + 'pymathconstants.c'],
        include_dirs=INCLUDE_DIRS,
        library_dirs=LIBRARY_DIRS,
        libraries=['mathconstants'],
        extra_compile_args=COMPILE_ARGS,
        extra_link_args=LINK_ARGS,
    )],
)


setup(
    name='mathfunc',
    version=__version__,
    description='Math Functions',
    author=__author__,
    author_email=__email__,
    maintainer=__author__,
    maintainer_email=__email__,
    url=__url__,
    license=__copyright__,
    classifiers=CLASSIFIERS,
    ext_modules=[Extension(
        'mathfunc',
        sources=[SRCDIR + 'pymathfunc.c'],
        include_dirs=INCLUDE_DIRS,
        library_dirs=LIBRARY_DIRS,
        libraries=['mathfunc'],
        extra_compile_args=COMPILE_ARGS + XOPTMZ,
        extra_link_args=LINK_ARGS,
    )],
)


setup(
    name='physics',
    version=__version__,
    description='Physics Functions',
    author=__author__,
    author_email=__email__,
    maintainer=__author__,
    maintainer_email=__email__,
    url=__url__,
    license=__copyright__,
    classifiers=CLASSIFIERS,
    ext_modules=[Extension(
        'physics',
        sources=[SRCDIR + 'pyphysics.c'],
        include_dirs=INCLUDE_DIRS,
        library_dirs=LIBRARY_DIRS,
        extra_compile_args=COMPILE_ARGS + XOPTMZ,
        extra_link_args=LINK_ARGS,
    )],
)


setup(
    name='tools',
    version=__version__,
    description='Miscellaneous Functions',
    author=__author__,
    author_email=__email__,
    maintainer=__author__,
    maintainer_email=__email__,
    url=__url__,
    license=__copyright__,
    classifiers=CLASSIFIERS,
    ext_modules=[Extension(
        'tools',
        sources=[SRCDIR + 'pytools.c'],
        include_dirs=INCLUDE_DIRS,
        library_dirs=LIBRARY_DIRS,
        extra_compile_args=COMPILE_ARGS,
        extra_link_args=LINK_ARGS,
    )],
)


setup(
    name='typesize',
    version=__version__,
    description='Get the size (in bytes) of various C data-types',
    author=__author__,
    author_email=__email__,
    maintainer=__author__,
    maintainer_email=__email__,
    url=__url__,
    license=__copyright__,
    classifiers=CLASSIFIERS,
    ext_modules=[Extension(
        'typesize',
        sources=[SRCDIR + 'pytypesize.c'],
        include_dirs=INCLUDE_DIRS,
        library_dirs=LIBRARY_DIRS,
        extra_compile_args=COMPILE_ARGS,
        extra_link_args=LINK_ARGS,
    )],
)
