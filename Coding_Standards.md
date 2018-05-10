Coding Standards
================


By Devyn Collier Johnson <DevynCJohnson@Gmail.com>


General Rules
-------------

- Version numbers use the format `YYYY.MM.DD` or `%Y.%m.%d`
- Strip trailing line-spaces
- One (and only one) trailing line is required at the end of the file
- Document/Explain complicated algorithms via comments (mostly Doxygen comments)
- Keep the source code highly organized and optimized
- Try to reduce or eliminate third-party dependencies
- Many files (such as Assembly, C, Posix script, and Python source files) begin with a file header
    - The first line (where applicable) is a hashpling
    - The following line is an Emacs Magic Comment
        - Example for C: `// -*- coding: utf-8-unix; Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-`
    - The next line is a Vim Magic Comment
        - Example for C: `// vim: set fileencoding=utf-8 filetype=c syntax=c.doxygen fileformat=unix tabstop=4 :`
    - The third magic comment is a Kate Magic Comment
        - Example for C: `// kate: encoding utf-8; bom off; syntax c; indent-mode cstyle; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;`
    - In Python scripts, an entry-point comment may be present after the magic comments
    - In the next line, the Doxygen information comment-block follows
        1. `brief`
            - For Python files, a blank line follows `brief`
        - `file`
            - Use the full filename, including the file-extension (if present)
            - For Python modules, `package` follows `file`
        - `version`
        - `author`
        - `copyright`
            - All source code files must specify its software license in the doxygen comment header
        - _Optional:_ `section DESCRIPTION`
        - _Optional:_ `section LICENSE`
            - When including a license header in a source code file, use the proper/official license header
    - In C, Doxygen comments use the delimiter `/** */`
    - In Posix Shell, Doxygen comments use the delimiter `# `
    - In Python, Doxygen comments use the delimiter `""" """`
    - Two blank lines must follow the file header, then the code begins
- When possible and where applicable, divide a file of code into sections
    1. Primary/Main Section
        - Primary/Main sections are given a header that begins and ends with the comment delimiter
        - The section title is in all caps
        - Two blanks lines must procede and follow the section header (such headers in functions may use zero to two blank lines)
        - Example line (in C): `/* PRIMARY TITLE */`
        - Example line (in Python & Posix Shell): `# PRIMARY TITLE #`
    2. Secondary Section
        - Secondary sections use a header consisting of a beginning comment delimter and a title in all caps
        - Two blank line procede and one blank line follows the section header
        - Example (in C): `// SECONDARY TITLE`
        - Example (in Python & Posix Shell): `# SECONDARY TITLE`
    3. Ternary Sections
        - Ternary sections use a header consisting of a beginning comment delimter
        - The section title is capitalized like the title of a book (or any other work of literature)
        - One blank line procedes the section header, and one blank line may follow
        - Example (in C): `// Ternary Title`
        - Example (in Python & Posix Shell): `# Ternary Title`


Assembly
--------

- On x86 targets, use _AT&T Style Syntax_


C
-

- Use C Standard-2011 (C11) or newer
- Files must use tab-indentation, Unix-newlines (`\n`), and UTF-8
- Indentation is one tab per level
- Use Doxygen for documentation [http://www.stack.nl/~dimitri/doxygen/manual/config.html](http://www.stack.nl/~dimitri/doxygen/manual/config.html)
- The Doxygen comments must use the Javadoc format (i.e. `@keyword`)
- For inlined Assembly on x86 targets, use _AT&T Style Syntax_


Changelog
---------

- Dates must use the format `YYYY-MM-DD`
- Changelogs must use tab-indentation, Unix-newlines (`\n`), and UTF-8
- Do not use form-feeds, vertical-tabs, carriage-returns, nor double/multi-line blank lines
- All changes by the same author on the same date are listed under the same non-indented header
- Do not place multiple authors and/or change dates under the same change-header
- Changes by a group of authors will be listed under a change-header separately from the headers of the individual authors
- All headers will use the format `YYYY-MM-DD  AUTHOR NAME  <username@email.com>`
- If the author does not have or wish to list an email, use `NULL` as the email
- One blank line goes after headers
- One blank line goes before headers if the header is not at the beginning of the file
- Documented changes (change-entries) to a file will use the format `* FILE:  BRIEF DESCRIPTION`
- Documented changes to a group of files will use the format `* GROUPNAME:  BRIEF DESCRIPTION`
- Documented changes to the project's infrastructure will use the format `* PROJECT:  BRIEF DESCRIPTION`
- Documented changes to a particular function in a file will use the format `* FILE  (FUNCTION):  BRIEF DESCRIPTION`
- In a change-entry, conditionals will be listed before the filename and separated by two spaces, such as `[LINUX_X86_64]  (drivers.c)`
- Documented changes to conditional code (such as code within macros) will use the format `* FILE  [POWERPC]:  BRIEF DESCRIPTION`; this indicates that code specific to PowerPC targets was changed
- Wildcards are allowed for the filename or group name of a change-entry
- Each change-entry listed under a change-header is indented one level
- Begin a change-entry with `* FILENAME:` followed by a space and then the details of the changes
- Single-line summaries are permitted and optional; some VCS expect such summaries
- Single-line summaries (if used) must be placed between the header and the first change-entry
- A single blank line must come before and after the summary
- The summary must use the same indentation as the change-entries


CoffeeScript
------------

- Indentation is two-spaces per level
- Always put spaces around operators and after commas
- Always end a simple statement with a semicolon
- Type global variable names in all uppercase
- Type variable and function names in camelcase or lowercase


Config Files (INI)
------------------

- Files must use space-indentation, Unix-newlines (`\n`), and UTF-8
- One blank line preceeds the section headers (unless the section header is at the beginning of the file)
- The assignment operator (equal sign) must not be padded on either side with whitespace
- Comments must begin with a semicolon, not the octothorpe (`#`)
- Alphabetical sorting is preferred, but not mandatory
- Multi-item assignments that on on multiple lines must be indented using four-spaces per indent level


DTD
---

- The file must be encoded in UTF-8
- All code must be standards compliant and pass XML and DTD validators
- Refer to the _XML_ section for further guidelines


HTML
----

- The document is encoded in UTF-8
- Indentation is two-spaces per level (except for minified code)
- Newlines must be line-feeds, never carriage-returns
- A `DOCTYPE` tag must be the first line of the file and `DOCTYPE` must be uppercased
- Always include `<meta content="application/xhtml+xml; charset=utf-8" http-equiv="Content-Type" />`
- Always include `<meta content="width=device-width, initial-scale=1.0" name="viewport">`
- Lowercase attribute names
- Quote all attribute values using double-quotes
- Do not use spaces around attribute equal-signs
- `<br/>`, `<hr/>`, and other self-closing (empty) tags without attributes must not have a space preceeding `/>`
- Close all tags and self-closing (empty) tags
- Embed SVG using `<object>`
- For a long quotation, use `<blockquote>`
- For a short quotation, use `<q>`
- For a very short quotation within a paragraph or a sentence, use `<cite>`
- All `<a>` tags must use the `title` attribute
- For abbreviations or acronyms, use `<abbr title="text">`
- Do not use `<b>` in any HTML5 code (use `<strong>` instead)
- For a general title or caption of a table, use `<caption>` not `<h1>` through `<h6>`
- To define words, use `<dfn>` or `<dl>`
- Use `<figcaption>` within all `<figure>` blocks
- All `<img>` tags must use the "alt" attribute
- Use `<pre>` for all preformatted text
- All `<script>` tags must use the "type" attribute
- Any HTML file that utilizes `<script>` must use `<noscript>` for fallback


JavaScript
----------

- Indentation is two-spaces per level (except for minified code)
- Use Doxygen for documentation [http://www.stack.nl/~dimitri/doxygen/manual/config.html](http://www.stack.nl/~dimitri/doxygen/manual/config.html)
- The Doxygen comments must use the Javadoc format (i.e. `@keyword`)
- Always put spaces around operators and after commas
- Always end a simple statement with a semicolon
- For compound-statements (like if-constructs), put the opening bracket at the end of the first line
- For compound-statements (like if-constructs), use one space before the opening bracket
- Do not end a compound-statement with a semicolon
- Type global variable names in all uppercase
- Type variable and function names in camelcase or lowercase


Markdown
--------

- Use four spaces per indentation level, Unix-newlines (`\n`), and UTF-8
- For bold text, use double-asterisks
- For italic text, use underscores


Python
------

- Use Python3.6 or newer
- Indentation is four-spaces per level
- Use Doxygen for documentation [http://www.stack.nl/~dimitri/doxygen/manual/config.html](http://www.stack.nl/~dimitri/doxygen/manual/config.html)
- The Doxygen comments must use the javadoc format (i.e. `@keyword`)
- Unused variables must begin with one underscore (i.e. `_var`)
- Check the code using `pycodestyle`, `pylint`, `pytest`, and `flake8`
    - Install, execute `pip3 install --upgrade astkit astroid flake8 mccabe pycodestyle pylint pytest`
- Follow the below listed PEP Standards
    - **PEP8 (Style Guide for Python Code)** - [https://www.python.org/dev/peps/pep-0008/](https://www.python.org/dev/peps/pep-0008/)
    - **PEP20 (The Zen of Python)** - [https://www.python.org/dev/peps/pep-0020/](https://www.python.org/dev/peps/pep-0020/)
    - **PEP257 (Docstring Conventions)** - [https://www.python.org/dev/peps/pep-0257/](https://www.python.org/dev/peps/pep-0257/)
        - However, disregard the rule "_1 blank line required before class docstring_" (D203)
        - However, disregard the rule "_Multi-line docstring summary should start at the second line_" (D213)
        - However, disregard the rule "_First line should end with a period_" (D400)
    - **PEP263 (Defining Python Source Code Encodings)** - [https://www.python.org/dev/peps/pep-0263/](https://www.python.org/dev/peps/pep-0263/)
    - **PEP484 (Type Hints)** - [https://www.python.org/dev/peps/pep-0484/](https://www.python.org/dev/peps/pep-0484/)
    - **PEP488 (Elimination of PYO files)** - [https://www.python.org/dev/peps/pep-0488/](https://www.python.org/dev/peps/pep-0488/)
    - **PEP498 (Literal String Interpolation)** - [https://www.python.org/dev/peps/pep-0498/](https://www.python.org/dev/peps/pep-0498/)
    - **PEP526 (Syntax for Variable Annotations)** - [https://www.python.org/dev/peps/pep-0526/](https://www.python.org/dev/peps/pep-0526/)
    - **PEP3107 (Function Annotations)** - [https://www.python.org/dev/peps/pep-3107/](https://www.python.org/dev/peps/pep-3107/)
- Do not follow the below listed PEP Standards
    - **PEP287 (reStructuredText Docstring Format)** - [https://www.python.org/dev/peps/pep-0287/](https://www.python.org/dev/peps/pep-0287/)
- To make MyPy ignore a particular line, use `  # type: ignore` at the end of the line


RelaxNG
-------

- The file must be encoded in UTF-8
- All code must be standards compliant and pass XML and RelaxNG validators
- Refer to the _XML_ section for further guidelines


ReStructuredText
----------------

- Use four spaces per indentation level, Unix-newlines (`\n`), and UTF-8


Shell Script
------------

- If Posix Shell, do not use extensions (remain Posix compliant)
- If Bash Shell, try to avoid extensions
- Comments used to describe the use/purpose of a shell must be on the line preceding the function declaration
- Use four spaces per indentation level


SVG
---

- Use SVG version 1.1 and UTF-8 encoding
- All SVG code must be standards compliant and pass XML and SVG validators
- Refer to the _XML_ section for further guidelines


XML
---

- The document is encoded in UTF-8
- Indentation is two-spaces per level (except for minified code)
- Newlines must be line-feeds (Unix newlines), never carriage-returns
- The XML declaration is the first line of the file
- The XML declaration must include version, encoding, and standalone (in that order)
- `DOCTYPE` must be uppercased (if a `DOCTYPE` is used)
- Quote all attribute values using double-quotes
- Do not use spaces around attribute equal-signs
- `<br/>`, `<hr/>`, and other self-closing (empty) tags without attributes must not have a space preceeding `/>`
- Close all tags and self-closing (empty) tags
- Double newlines (one blank line) can only be used to divide large or important code sections
- A comment line may be used to name and divide code sections, but a blank newline must be used above and below the comment line
- Character and parsed entity references are replaced (unless it is an attribute value)
- `CDATA` sections are replaced with their character content
- Superfluous namespace declarations are removed from each element
- Empty elements are converted to start-end tag pairs
- Attribute values are enclosed in double-quotes
- Default attributes are added to each element
- Lexicographic order is applied to the attributes and namespace declarations of each element
- The beginning and end tags must match exactly in case-sensitive manner
- Tag names cannot contain any of the characters ```!"#$%&'()*+,/;<=>?@[\]^`{|}~```, nor a space character, and cannot start with `-`, `.`, or a numeric digit


Coding Philosophies
===================


Unix Philosophy
---------------

_Unix Philosophy_ by Doug McIlroy; Later summarized by Peter H. Salus in _A Quarter-Century of Unix_ (1994)

>Write programs that do one thing and do it well.

>Write programs to work together.

>Write programs to handle text streams, because that is a universal interface.


Eric Raymond's 17 Unix Rules
----------------------------

_The Art of Unix Programming_ (2003) by Eric S. Raymond

1. **Rule of Clarity**
    - Developers should write programs as if the most important communication is to the developer who will read and maintain the program, rather than the computer. This rule aims to make code as readable and comprehensible as possible for whoever works on the code in the future.
- **Rule of Composition**
    - Developers should write programs that can communicate easily with other programs. This rule aims to allow developers to break down projects into small, simple programs rather than overly complex monolithic programs.
- **Rule of Diversity**
    - Developers should design their programs to be flexible and open. This rule aims to make programs flexible, allowing them to be used in ways other than those their developers intended.
- **Rule of Economy**
    - Developers should value developer time over machine time, because machine cycles today are relatively inexpensive compared to prices in the 1970s. This rule aims to reduce development costs of projects.
- **Rule of Extensibility**
    - Developers should design for the future by making their protocols extensible, allowing for easy plugins without modification to the program's architecture by other developers, noting the version of the program, and more. This rule aims to extend the lifespan and enhance the utility of the code the developer writes.
- **Rule of Generation**
    - Developers should avoid writing code by hand and instead write abstract high-level programs that generate code. This rule aims to reduce human errors and save time.
- **Rule of Least Surprise**
    - Developers should design programs that build on top of the potential users' expected knowledge; for example, ‘+’ in a calculator program should always mean 'addition'. This rule aims to encourage developers to build intuitive products that are easy to use.
- **Rule of Modularity**
    - Developers should build a program out of simple parts connected by well defined interfaces, so problems are local, and parts of the program can be replaced in future versions to support new features. This rule aims to save time on debugging code that is complex, long, and unreadable.
- **Rule of Optimization**
    - Developers should prototype software before polishing it. This rule aims to prevent developers from spending too much time for marginal gains.
- **Rule of Parsimony**
    - Developers should avoid writing big programs. This rule aims to prevent overinvestment of development time in failed or suboptimal approaches caused by the owners of the program’s reluctance to throw away visibly large pieces of work. Smaller programs are not only easier to write, optimize, and maintain; they are easier to delete when deprecated.
- **Rule of Repair**
    - Developers should design programs that fail in a manner that is easy to localize and diagnose or in other words “fail noisily”. This rule aims to prevent incorrect output from a program from becoming an input and corrupting the output of other code undetected.
- **Rule of Representation**
    - Developers should choose to make data more complicated rather than the procedural logic of the program when faced with the choice, because it is easier for humans to understand complex data compared with complex logic. This rule aims to make programs more readable for any developer working on the project, which allows the program to be maintained.
- **Rule of Robustness**
    - Developers should design robust programs by designing for transparency and discoverability, because code that is easy to understand is easier to stress test for unexpected conditions that may not be foreseeable in complex programs. This rule aims to help developers build robust, reliable products.
- **Rule of Separation**
    - Developers should separate the mechanisms of the programs from the policies of the programs; one method is to divide a program into a front-end interface and a back-end engine with which that interface communicates. This rule aims to prevent bug introduction by allowing policies to be changed with minimum likelihood of destabilizing operational mechanisms.
- **Rule of Silence**
    - Developers should design programs so that they do not print unnecessary output. This rule aims to allow other programs and developers to pick out the information they need from a program's output without having to parse verbosity.
- **Rule of Simplicity**
    - Developers should design for simplicity by looking for ways to break up program systems into small, straightforward cooperating pieces. This rule aims to discourage developers’ affection for writing “intricate and beautiful complexities” that are in reality bug prone programs.
- **Rule of Transparency**
    - Developers should design for visibility and discoverability by writing in a way that their thought process can lucidly be seen by future developers working on the project and using input and output formats that make it easy to identify valid input and correct output. This rule aims to reduce debugging time and extend the lifespan of programs.


Standard Error Message Formats
==============================

| Event | Message |
| :---: | :---: |
| _Character/String encoding issues_ | `Unable to determine and process data encoding!\n` |
| _Command not found_ | `%s: command not found\n` |
| _Invalid parameter flag_ | `Unknown parameter!\n` |
| _Missing parameter flag_ | `ERROR: A parameter is required!\n` |
| _Multiple or undetermined parameter issues_ | `ERROR: Parameters are missing or invalid!\n` |
| _Requires Root privileges_ | `Root permissions are required!\n` |
| _Specified directory not found_ | `The specified directory is non-readable or non-existent!\n` |
| _Specified file is a directory_ | `%s: This "file" is actually a directory!\n` |
| _Specified file not found_ | `%s: The specified file is non-readable or non-existent!\n` |
| _Unable to change directory_ | `Unable to change directory to "%s"!\n` |
| _Unable to write file_ | `Unable to write to "%s"!\n` |
| _Unable to write file due to permissions_ | `Permission Error: Unable to write to "%s"!\n` |
| _Unable to write in directory_ | `Unable to write file in "%s"!\n` |