PyBooster - collection of Python3 and C libraries
======================================

- __Lead Developer:__ [Devyn Collier Johnson](http://dcjtech.info/members/devyncjohnson/)
- __Email:__ <DevynCJohnson@Gmail.com>
- __License:__ [LGPLv3](http://www.gnu.org/licenses/lgpl-3.0.txt)
- __GitHub:__ <https://github.com/DevynCJohnson/Pybooster>
- __Documentation:__ <http://dcjtech.info/Pybooster/>

The C-libraries can be compiled as Python modules or linked in other projects.

EzWin is also included in PyBooster. Ezwin is a collection of GTK windows.

Please consider donating to http://dcjtech.info/ to help development (click the **Donate** button).


REQUIREMENTS
------------

- Python3.4 or greater
- GNU-GCC or Clang (if the C source code will be built)
- PyGObject (gi.repository) is needed for using EzWin
- POSIX system; Windows may not be fully supported

PyBooster should work on all operating systems that support Python3. The make-files and shell scripts will only work on most Unixoid systems. However, it is not mandatory that the source code be built (the Python script will still work).

The scripts `./_MISC/get-build-dependencies.sh` and `./_MISC/get-dependencies.sh` can be executed to install the needed software packages (Debian-based Linux distros only).


BUILDING
--------

To perform the listed build commands, open a terminal and type the given command:

- To compile the C-modules for Python, type `make pylibc`.
- To compile the Python scripts as byte-code, type `make byte`.
- To compile the C-libraries, type `make lib`.
- To compile everything, type `make all`.
- To generate the documentation, type `make doc`.
- To remove the `-.o` files and temporary build files, type `make rmtmp`.
- To remove all compiled files and temporary build files, type `make clean`.
- To remove all generated files (but not documentation), type `make cleanall`.
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
  - C source code belongs in `./lib/clib-src/`
  - Compiled C libraries belong in `./lib/clib/`
  - Python modules (`*.py` and `*.so`) belong in `./lib/`
- Document/explain complicated algorithms using comments
  - C src uses Doxygen to document the code. In-line comments are also used
- Languages: C-Standard-2011 (C11), Python3.4 (or newer), and Assembly (AT&T Syntax)
  - There are some shell-scripts (POSIX Shell), Glade files (XML), and makefiles
- License code under LGPLv3
- Optimize the code
  - Use `const` in function parameters if the parameter is never changed
- Use the proper license header (see templates under `./_MISC`) for each src file
  - Templates can be found in `./_MISC`
- Version numbers use the format `YYYY.MM.DD` or `%Y.%m.%d`

#### C ####

- **Standard** - Use C11 or newer

#### Python ####

- **Check code** - Check the code using `pep8`, `pylint`, `pytest`, and `flake8`
  - Execute `pip3 install --upgrade astkit astroid flake8 mccabe pep8 pylint pytest`
- **Formatting** - Follow the below listed PEP Standards
  - **PEP8 (Style Guide for Python Code)** - [https://www.python.org/dev/peps/pep-0008/](https://www.python.org/dev/peps/pep-0008/)
  - **PEP20 (The Zen of Python)** - [https://www.python.org/dev/peps/pep-0020/](https://www.python.org/dev/peps/pep-0020/)
  - **PEP257 (Docstring Conventions)** - [https://www.python.org/dev/peps/pep-0257/](https://www.python.org/dev/peps/pep-0257/)
  - **PEP484 (Type Hints)** - [https://www.python.org/dev/peps/pep-0484/](https://www.python.org/dev/peps/pep-0484/)
  - **PEP488 (Elimination of PYO files)** - [https://www.python.org/dev/peps/pep-0488/](https://www.python.org/dev/peps/pep-0488/)
  - **PEP498 (Literal String Interpolation)** - [https://www.python.org/dev/peps/pep-0498/](https://www.python.org/dev/peps/pep-0498/)
  - **PEP3107 (Function Annotations)** - [https://www.python.org/dev/peps/pep-3107/](https://www.python.org/dev/peps/pep-3107/)
- **Non-Followed PEPs** - Do not follow the below listed PEP Standards
  - **PEP287 (reStructuredText Docstring Format)** - [https://www.python.org/dev/peps/pep-0287/](https://www.python.org/dev/peps/pep-0287/)

### Adding new modules ###

- When adding a new `*.py` file, add the name of the module to _``__all__``_ in **``__init__.py``** and _`lib`_ in **./makedoc.sh**
- When adding a new `*.so` Python module, add the name of the module to _``__all__``_ in **``__init__.py``** and _`lib`_ in **./makedoc.sh**
- When adding a new C-library,
  - Add a rule to **makefile** under _`# Library Compiling`_ in the _**RULES**_ section
  - List the added rule name to **makefile** with _``lib : ``_ under _**BUILD COMMANDS**_
