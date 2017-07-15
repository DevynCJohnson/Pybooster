Collection of Python3 and C libraries
=====================================

- __Lead Developer:__ [Devyn Collier Johnson](http://dcjtech.info/members/devyncjohnson/)
- __Email:__ <DevynCJohnson@Gmail.com>
- __License:__ [LGPLv3](http://www.gnu.org/licenses/lgpl-3.0.txt)
- __GitHub:__ <https://github.com/DevynCJohnson/Pybooster>
- __Documentation:__ <http://dcjtech.info/Pybooster/>

This project is a rolling-release. The software is stable and suitable for use in other projects.

The C-libraries and Python libraries can be used with other projects.

Please consider donating to <http://dcjtech.info/> to help development (click the **Donate** button).


REQUIREMENTS
------------

- GNU-GCC or Clang (if the C source code will be built)
- POSIX system; Windows may not be fully supported
- Python3

PyBooster should work on most or all POSIX/UNIX operating systems. The make-files, shell scripts, and Python scripts will only work on most Unixoid systems.

The script `./tools/get-build-dependencies.sh` can be executed to install the needed software packages (Debian-based Linux distros only).


BUILDING
--------

To perform the listed build commands, open a terminal and type the given command:

- To compile everything, type `make all`.
- To generate the documentation, type `make doc`.
- To remove the temporary build files, type `make rmtmp` or `make clean`.
- To remove all generated files (but not documentation), type `make cleanall`.
- To remove all generated files and documentation, type `make cleanfull`.
- To build the code for a Haswell system, type `make all ARCH=haswell`.
- To build the code for a 64-bit system, type `make all BITS=64`.


INSTALLING
----------

- To install Pybooster, open a terminal and type `make install`.
- To uninstall PyBooster, open a terminal and type `make uninstall`.


DEVELOPING
----------

Follow the below guidelines when assisting the development of PyBooster.

### Code ###

- Keep code organized
- Keep files organized
  - C library source code belongs in `./src/`
  - Python library source code belongs in `./pylib/`
  - C program source code belongs in `./utilsrc/`
  - Compiled code belongs in `./bin/`
  - Project tools belong in `./tools/`
- Document/explain complicated algorithms using comments
  - C and Python source code uses Doxygen to document the code
- Languages: C-Standard-2011 (C11), Assembly (AT&T Syntax), and Python3
  - There are some shell-scripts (POSIX Shell) and makefiles
- License code under LGPLv3
- Optimize the code
  - Use `const` in C function parameters if the parameter is never changed
- Use the proper license header (see templates under `./tools/`) for each src file
  - Templates can be found in `./tools/`
- Version numbers use the format `YYYY.MM.DD` or `%Y.%m.%d`

#### C ####

- **Standard** - Use C11 or newer; Use Python3 or newer
- **Documentation** - Use Doxygen syntax for documentation [http://www.stack.nl/~dimitri/doxygen/manual/config.html](http://www.stack.nl/~dimitri/doxygen/manual/config.html)

### Adding New Code ###

- When adding a new C-library,
  - Add a rule to **makefile** under _`# Library Compiling #`_ in the _**RULES**_ section
  - List the added rule name to **makefile** with _``lib : ``_ under _**BUILD COMMANDS**_
