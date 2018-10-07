Contributing
============

Follow the below guidelines when contributing to the development of PyBooster.
Also, refer to _[Coding_Standards.md](./Coding_Standards.md)_ (in this same directory) for further guidelines.

- Keep code and files organized
    - C Library/Header Source-Code: `./include/`
    - C Program Source-Code: `./src/`
    - Compiled Binaries: `./bin/`
    - Data Files (CSV, JSON, SQLite, YAML, etc.): `./databases/`
    - Glade Files (for Programs): `./accessory/`
    - GTK Source-View Language Specs: `./accessory/lang-specs/`
    - Man Pages: `./doc/man/`
    - Menu & \*.desktop Files: `./accessory/menu_files/`
    - NanoRC Files: `./accessory/nanorc/`
    - Project Tools: `./tools/`
    - Python Egg Modules: `./pyegg/`
    - Python Libraries: `./pylib/`
    - Script Programs (Including Python): `./scripts/`
    - Shell RC Files & Addons/Modules: `./shrc/`
    - Themes, Skins, Icons, and Cursors: `./themes/`
    - Wallpapers: `./themes/wallpapers/`
    - XKB Files: `./themes/XKB/`
    - XML Schemas: `./accessory/schemas/`
- License code under LGPLv3, Public Domain, or any other compatible license
- Adding New Code
    - When adding a new C program, add the rule to **makefile** under the appropriate _```## * PROGRAM RULES ##```_ header
    - When adding a new ```*.py``` file, add the name of the module to _```__all__```_ in **```__init__.py```** and _`makedoc`_ in **makefile**
    - When adding programs, scripts, or libraries, you may need to add the filename to the appropriate list in **makefile** under `File Lists` when applicable
    - Commit and submit changes to the `dev` branch; the `master` branch is for stable releases only
