PyBooster - Various Extras for Python3
======================================

 * **Developer (Primary):** Devyn Collier Johnson
 * **Email:** DevynCJohnson@Gmail.com
 * **License:** LGPLv3
 * **GitHub:** https://github.com/DevynCJohnson/Pybooster
 * **Documentation:** http://dcjtech.info/Pybooster/

PyBooster is a collection of Python and C libraries.

The C-libraries can be compiled as Python modules or linked in other projects.

EzWin is also included in PyBooster. Ezwin is a collection of GTK windows.


REQUIREMENTS
------------

 * Python3.4 or greater
 * A C compiler (if the C source code will be built)
 * PyGObject (gi.repository) is needed for using EzWin
 * POSIX system; Windows may not be fully supported

PyBooster should work on all operating systems that support Python3. The make-files and shell scripts will only work on most Unixoid systems. However, it is not mandatory that the source code be built (the Python script will still work).


BUILDING
--------

To perform the listed build commands, open a terminal and type the given command:

 * To compile the C-modules for Python, type "make pylibc".
 * To compile the Python scripts as byte-code, type "make byte".
 * To compile the C-libraries, type "make lib".
 * To compile everything, type "make all".
 * To generate the documentation, type "make doc".
 * To remove the *.o files and temporary build files, type "make rmtmp".
 * To remove all compiled files and temporary build files, type "make clean".
 * To remove all generated files (but not documentation), type "make cleanall".
 * To build the code for a Haswell system, type "make all ARCH=haswell".
 * To build the code for a 64-bit system, type "make all BITS=64".


INSTALLING
----------

 * To install Pybooster, open a terminal and type "make install".
 * To uninstall PyBooster, open a terminal and type "make uninstall".


DEVELOPING
----------

Follow the below guidelines when assisting the development of PyBooster.

### Code ###

 * Keep code organized
 * Keep files organized
  * C-src: ./lib/clib-src/
  * C-libraries: ./lib/clib/
  * Python modules (*.py and *.so): ./lib/
 * Document/explain complicated algorithms
 * Languages: C11 (or newer) and Python3
  * There are some shell-scripts, Glade files (XML), makefiles, and perhaps some Assembly files (*.S)
 * License code under LGPLv3
 * Optimize the code
 * Templates can be found in ./_MISC
 * Use the proper license header (see templates under ./_MISC) for each src file
 * Version numbers use the format YYYY.MM.DD or %Y.%m.%d

#### C ####

 * Standard - Use C11 or newer

#### Python ####

 * Check code - Check the code using "pep8", "pylint", and "flake8"
 * Formatting - Follow the PEP8 standard

### Adding new modules ###

 * When adding a new *.py file, add the name of the module to ``__all__`` in ``__init__.py`` and "lib" in **./makedoc.sh**
 * When adding a new `*.so` Python module,
  * Add the name of the module to ``__all__`` in ``__init__.py`` and `lib` in **./makedoc.sh**
 * When adding a new C-library,
  * Add a rule to **makefile** under `Library Compiling` in the **RULES** section
  * List the added rule name to **makefile** with **lib : ** under **BUILD COMMANDS**
