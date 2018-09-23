Coding Standards
================


By Devyn Collier Johnson <DevynCJohnson@Gmail.com>


Case Style Definitions
----------------------

- **ALLCAPS:** Capitalize/Uppercase all letters, but do not use underscores nor hyphens
    - Also known as ALLUPPERCASE or UPPERCASE
- **camelCase:** Capitalize all words except the first, but do not use underscores nor hyphens
    - Acronyms like "HTTP" may be all uppercase (unless it begins the name), unless it is the beginning of the name
    - Also known as bumpyCase or lowerCamelCase
- **css-case:** Use all lowercase letters and use hyphens (but no underscores) between words
- **German_Style_Sentence_Case :** Capitalize first letter of all nouns and the first letter of the name and use underscores (but no hyphens) between words
    - Acronyms like "HTTP" may be all uppercase
- **Kebab-case:** Uppercase first letter and use hyphens (but no underscores) between words
    - Also known as Spinal-case, Lisp-case, or Dash-case
- **lowercase:** Use all lowercase letters without underscores and hyphens
- **PascalCase:** Capitalize all words, but do not use underscores nor hyphens
    - Acronyms like "HTTP" may be all uppercase
    - Also known as DromedaryCase or UpperCamelCase
- **PRIME-MODIFIER-CLASS:** Capitalize all letters and use hyphens (but no underscores) between words
- **SCREAMING_SNAKE_CASE:** Capitalize all letters and use underscores (but no hyphens) between words
- **Sentencecase:** Uppercase the initial letter, but do not use underscores nor hyphens
- **snake_case:** Lowercase all letters and use underscores (but no hyphens) between words
- **Start_Case:** Capitalize all words and use underscores (but no hyphens) between words
    - Acronyms like "HTTP" may be all uppercase
    - Unlike Title_Case, the first letter of articles, short prepositions, and conjunctions will be capitalized
- **StUdLyCaPs:** Capitalize every other letter in the name; hyphens and/or underscores may be used between words
- **Title_Case:** Capitalize all words and use underscores (but no hyphens) between words
    - Acronyms like "HTTP" may be all uppercase
    - Do not capitalize articles, short prepositions, nor conjunctions (minor words like "a", "the", "of", etc.) unless such a word begins the name
    - Also known as Capital_Case or Headline_Style
- **Upper_snake_case:** Uppercase the initial letter and use underscores (but no hyphens) between words
- **WikiCase:** Capitalize all words, but do not use underscores nor hyphens
    - Acronyms like "HTTP" may be all uppercase
    - This is similar to PascalCase except that one-letter words (like "a") are removed from the name

**Notes**

- The hyphen is `U+002D - HYPHEN-MINUS`
- Unless otherwise specified, names must use the following ASCII letters only: `abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789`
    - Obfuscated code is a general exception to the above rule


General Rules
-------------

### General Practices

- The file encoding of files must be UTF-8 (without BOM) unless otherwise specified for a specific language, filetype, or need
- Strip trailing line-spaces
- Unless otherwise specified for a particular language, use line-feeds (Unix newlines - `\n`) not carriage-returns (Windows newlines - `\c\n`)
- Avoid form-feeds (`\f` or `^L`) and vertical-tab (`\v` or `^K`) where possible
- One (and only one) trailing line is required at the end of the file
- Document/Explain complicated algorithms via [Doxygen comments](http://www.stack.nl/~dimitri/doxygen/manual/config.html) (where applicable)
- Keep the source code highly organized and optimized
- Try to reduce or eliminate third-party dependencies
- Hexadecimal sequences mush use all uppercase letters

### File Headers

- Many files (such as Assembly, C, Posix script, and Python source files) begin with a file header
- The first line (where applicable) is a hashpling
- The following line is an Emacs Magic Comment
    - Example for C: ```// -*- coding: utf-8-unix; Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-```
- The next line is a Vim Magic Comment
    - Example for C: ```// vim: set fileencoding=utf-8 filetype=c syntax=c.doxygen fileformat=unix tabstop=4 :```
- The third magic comment is a Kate Magic Comment
    - Example for C: ```// kate: encoding utf-8; bom off; syntax c; indent-mode cstyle; eol unix; replace-tabs off; indent-width 4; tab-width 4; remove-trailing-space on; line-numbers on;```
- In Python scripts, an entry-point comment may be present after the magic comments
- In the next line, the Doxygen information comment-block follows (see the _Doxygen_ section for further guidelines)
- For JavaScript, next comes `goog.module` statements and then `goog.require` statements
- Two blank lines must follow the file header, then the code begins

### File Divisions

- When possible and where applicable, divide a file of code into sections
- Primary/Main Section
    - Primary/Main sections are given a header that begins and ends with the comment delimiter
    - The section title is in all caps
    - Two blanks lines must procede and follow the section header (such headers in functions may use zero to two blank lines)
    - Example line (in C): ```/* PRIMARY TITLE */```
    - Example line (in Python & Posix Shell): ```# PRIMARY TITLE #```
- Secondary Section
    - Secondary sections use a header consisting of a beginning comment delimter and a title in all caps
    - Two blank line procede and one blank line follows the section header
    - Example (in C): ```// SECONDARY TITLE```
    - Example (in Python & Posix Shell): ```# SECONDARY TITLE```
- Ternary Sections
    - Ternary sections use a header consisting of a beginning comment delimter
    - The section title is capitalized like the title of a book (or any other work of literature)
    - One blank line procedes the section header, and one blank line may follow
    - Example (in C): ```// Ternary Title```
    - Example (in Python & Posix Shell): ```# Ternary Title```


Doxygen
-------

- All of Doxygen's commands/keywords must use the Javadoc format (i.e. `@keyword` and never backslashes)
- The Doxygen information comment-block (placed in the file header of source code) must be structured as follows
    1. `@brief`
        - For Python files, a blank line follows `@brief`
    2. `@file`
        - Use the full filename (without the path), including the file-extension (if present)
        - For Python modules, `@package` follows `@file`
    3. `@version`
    4. `@author`
    5. `@copyright`
        - All source code files must specify its software license in the doxygen comment header
    6. `@section DESCRIPTION` (Optional)
    7. `@section LICENSE` (Optional)
        - When including a license header in a source code file, use the proper/official license header
- When
- To provide inline documentation for individual members of a struct, union, class, enum, etc., place the documentation line after the member instead of before
    - For this purpose you have to put an additional ```<``` marker in the comment line (i.e. ```int var;  /**< DESCRIPTION */```)
    - Two spaces must be between the code and comment
- For function parameters and output, use ```@param``` document the parameters and then use ```[in]```, ```[out]```, ```[in,out]``` to document the direction
    - This documentation must go in the function's main block documentation (before or after the language depending on the language)

### Documentation Comment Styles

Below is a list of documentation comment styles (multiline and single-line, where applicable) with examples on how they should be formatted.

#### Block Style

```c
/********************************************//**
Multiline Comment
***********************************************/
```

#### C++ Style

```c
///
/// Multiline
/// Comment
///

/// Single-line Comment ///
```

#### C++ Style (Alternative)

```c
//!
//! Multiline
//! Comment
//!

//! Single-line Comment !//
```

#### CoffeeScript Style

```python
###!
Multiline Comment
###

###! Single-line Comment ###
```

#### D Style

```c
//' Single-line Comment
```

#### Erlang Style

```erlang
%% ----------------------------------
%% Multiline
%% Comment
%% ----------------------------------
```

#### Fortran Style

```fortran
!> Multiline
!! Comment

!> Single-line Comment
```

#### JavaDoc Style

```c
/**
Multiline Comment
*/

/** Single-line Comment */
```

#### Pascal Style

```pascal
(**
Multiline Comment
*)
(** Single-line Comment *)
```

#### Python/PyDoc Style

Notice that the text begins on the same line as the first ```"""``` with a space in between (this is where ```@brief``` is placed). Then, there is a blank line followed by the rest of the block. The closing ```"""``` is on its own line.

```python
""" Multiline

Comment
Additional text
"""
```

#### Qt Style

```c
/*!
Multiline Comment
*/

/*! Single-line Comment */
```

#### R Style

```python
#' Multiline
#' Comment

#' Single-line Comment
```

#### Slash Block Style

```c
/////////////////////////////////////////////////
/// Multiline Comment
/////////////////////////////////////////////////
```

#### Tcl Style

```python
## Multiline
# Comment

## Single-line Comment
```

#### VHDL Style

```vhdl
--! Multiline
--! Comment

--! Single-line Comment
```

#### Windows Batch File Style

```batch
REM ! Multiline
REM ! Comment

REM ! Single-line Comment
```

### Doxygen Language Specifics

- **Awk Scripts:** R Style
    - A multi-lined-function's Doxygen comment goes right after the function's opening-brace, but detailed comments go on the line after the function definition
    - A single-lined-function's Doxygen comment goes right after the function's closing-brace
- **C/C++:** JavaDoc Style
    - A function's Doxygen comment goes on the line before the function definition
- **CoffeeScript:** CoffeeScript Style
    - A function's Doxygen comment goes on the line before the function definition
- **D:** D Style
- **Erlang:** Erlang Style
- **Fortran:** Fortran Style
- **JavaScript:** JavaDoc Style
    - A function's Doxygen comment goes on the line before the function definition
- **Pascal:** Pascal Style
- **Posix Shell:** R Style
    - A multi-lined-function's Doxygen comment goes right after the function's opening-brace, but detailed comments go on the line after the function definition
    - A single-lined-function's Doxygen comment goes right after the function's closing-brace
- **Python:** PyDoc Style
    - A function's Doxygen comment goes on the line after the function definition
- **R:** R Style
    - A function's Doxygen comment goes on the line before the function definition
- **Ruby:** R Style
- **Sed Scripts:** R Style
- **Tcl Scripts:** Tcl Style
- **Windows Batch Files:** Windows Batch File Style
- **XCompose:** R Style


Language-Specific Rules
=======================


Assembly
--------

- On x86 targets, use _AT&T Style Syntax_


C
-

- Use C Standard-2011 (C11) or newer
- Files must use tab-indentation (one tab per level)
- For inlined Assembly, refer to the _Assembly_ section in this document


Changelog
---------

- Changelogs must use tab-indentation
- Each change-entry listed under a change-header is indented one level
- One blank line goes after headers
- One blank line goes before headers if the header is not at the beginning of the file
- A single blank line must come before and after the summary
- The summary must use the same indentation as the change-entries
- Wildcards are allowed for the filename or group name of a change-entry
- Single-line summaries are permitted and optional; some VCS expect such summaries
- Single-line summaries (if used) must be placed between the header and the first change-entry

### Formatting Rules

- Dates must use the format `YYYY-MM-DD`
- All headers will use the format `YYYY-MM-DD  AUTHOR NAME  <username@email.com>`
- Begin a change-entry with `* FILENAME:` followed by a space and then the details of the changes
- Documented changes (change-entries) to a file will use the format `* FILE:  BRIEF DESCRIPTION`
- Documented changes to a group of files will use the format `* GROUPNAME:  BRIEF DESCRIPTION`
- Documented changes to the project's infrastructure will use the format `* PROJECT:  BRIEF DESCRIPTION`
- Documented changes to a particular function in a file will use the format `* FILE  (FUNCTION):  BRIEF DESCRIPTION`
- In a change-entry, conditionals will be listed before the filename and separated by two spaces, such as ```[LINUX_X86_64]  (drivers.c)```
- Documented changes to conditional code (such as code within macros) will use the format ```* FILE  [POWERPC]:  BRIEF DESCRIPTION```; this indicates that code specific to PowerPC targets was changed

### Author Rules

- All changes by the same author on the same date are listed under the same non-indented header
- Do not place multiple authors and/or change dates under the same change-header
- Changes by a group of authors will be listed under a change-header separately from the headers of the individual authors
- If the author does not have or wish to list an email, use `NULL` as the email


CoffeeScript
------------

- Indentation is two-spaces per level
- Always put spaces around operators and after commas
- Always end a simple statement with a semicolon
- Type global variable names in all SCREAMING_SNAKE_CASE
- Type variable and function names in snake_case or lowercase
- Type hints use the format ```###: TYPE ###```


Config Files (INI)
------------------

- Indentation is four-spaces per level
- One blank line preceeds the section headers (unless the section header is at the beginning of the file)
- Two blank lines follow the file header (if any is present)
- The assignment operator (equal sign) must not be padded on either side with whitespace
- Comments must begin with a semicolon, not the octothorpe ( ```#``` ) unless the software reading the file will not recognize semicolons
- Alphabetical sorting is preferred, but not mandatory
- Multi-item assignments that are on multiple lines must be indented using four-spaces per indent level


DTD
---

- All code must be standards compliant and pass XML and DTD validators
- Refer to the _XML_ section for further guidelines


HTML
----

### File Basics

- Indentation is two-spaces per level (except for minified code)
    - The indentation rule above applies to elements within the `<head>` tag
    - The rule also applies to secondary elements within the `<body>` tag
    - For instance, elements within `<header>`, `<main>`, and `<footer>` would be indented, but not those tags themselves
- One newline must come before the `<html>` tag
- Apply two blank lines (but never more)
    - Before and after `<body>`, `<header>`, and `<footer>` (and their respective closing tags)
    - After `<html>`
    - Before `</html>`
- All PHP, Django, and other template manipulating code must adhere to the coding standards in this document (where applicable)
- A `DOCTYPE` tag must be the first line of the file and `DOCTYPE` must be uppercased
- Special file comments (like Doxygen comments and licensing) must be placed on the line after the `DOCTYPE` tag
- All HTML5 files (except partial template snippets) must properly use the `<html>`, `<head>`, and `<body>` tags

### Head

The tags within the `<head>` tag must go in the following order

- ```<meta charset="*">```, ```<meta http-equiv="*" *>```, and ```<meta name="viewport" *>``` (in that order and are required to be present)
    - Must be within the first 1024 bytes of the file in order to take effect
    - Always include ```<meta content="application/xhtml+xml;charset=utf-8" http-equiv="Content-Type"/>```
    - Always include ```<meta content="width=device-width,initial-scale=1.0" name="viewport"/>```
- `<base>`
    - There can be at maximum one `<base>` tag in a document, and it must be inside the `<head>` element
- `<title>` (required to be present)
    - There can be at maximum one `<title>` tag in a document, and it must be inside the `<head>` element
- `<meta>` (All other `<meta>` tags)
    - ```property="fb:*"```, ```property="og:*"```, ```name="twitter:*"```, and other similar special `<meta>` tags must be the last set of `<meta>` tags
- `<link>`
    - Must always use the attributes `href`, `rel`, and `type`
- `<style>`
    - Must always use the attribute `type`
- `<script>`
    - Must always use the attribute `type`
- `<noscript>`
    - Any HTML file that utilizes `<script>` must use `<noscript>` for fallback
    - `<noscript>` must only contain `<link>`, `<style>`, and `<meta>` when used inside the `<head>` element
    - `<noscript>` can be used in both `<head>` and `<body>`

### Attributes

- Lowercase attribute names
- Quote all attribute values using double-quotes
- Alphabetize all attributes within the tag (except for `<meta>`)
- Do not use spaces around attribute equal-signs
- Use one space between attributes and after the opening tags name
- No space goes between an attribute and `>` or `/>`, unless it is a valueless attribute such as ```<input name="order_id" type="number" autofocus />```
- `class` names must use snake_case; however, the BEM naming convention( Block, Element, Modifier) is also acceptable
- Alphabetize all `class` names within the attribute value
- `id` names must use Kebab-case
- Alphabetize all `id` names within the attribute value

### Tag Styling

- Tag names must be lowercase
- `<br/>`, `<hr/>`, and other self-closing (empty) tags without attributes must not have a space preceeding `/>`
- Tags must not have whitespace following `<`
- Close all tags and self-closing (empty) tags

### List & Table Specifics

- For a general title or caption of a table, use `<caption>` not `<h1>` through `<h6>`

### Individual Tag Specifics

- All `<a>` tags must use the `title` attribute
- For abbreviations or acronyms, use `<abbr title="text">`
- Do not use `<b>` in any HTML5 code (use `<strong>` instead)
- For a long quotation, use `<blockquote>`
- For a very short quotation within a paragraph or a sentence, use `<cite>`
- To define words, use `<dfn>` or `<dl>`
- Use `<figcaption>` within all `<figure>` blocks
- All `<img>` tags must use the "alt" attribute
- All `<input>` tags using `type="date"` must not use the "placeholder" attribute
- Embed `<svg>` using `<object>`
- Use `<pre>` for all preformatted text
- For a short quotation, use `<q>`


JavaScript
----------

- Indentation is two-spaces per level (except for minified code)
- Use ES6 (ECMAScript 2015)
- Do not use JSX
- Filenames must be lowercase and may include underscores or hyphens
- Always put spaces around operators and after commas
- Always end a simple statement with a semicolon
- Do not end a compound-statement with a semicolon
- For compound-statements (like if-constructs), put the opening bracket (with a preceeding space) at the end of the first line
- Braces are required for all control structures, even if the body contains only a single statement
- An empty block or block-like construct may be closed immediately after it is opened (i.e. ```{}```), unless it is a part of a multi-block statement, such as if/else or try/catch/finally statements
- Put a space between reserved words (such as `if`, `for`, or `catch`) and an open parenthesis
- Put a space between reserved word (such as `else` or `catch`) and a closing curly brace
- Put a space between any open curly brace, except for:
    - Array literals (i.e. ```foo({a: [{c: d}]})```)
    - Template expansions (i.e. ```abc${1 + 2}def```)
- Type global variable names in all SCREAMING_SNAKE_CASE
- Type variable and function names in snake_case or lowercase
- Declare all local variables with either `const` or `let`
    - Use `const` by default, unless a variable needs to be reassigned
    - The `var` keyword must not be used
- One variable per declaration
- Declare datatypes of variables inline (i.e. ```const /** !Array<number> */ data = [];```)
- Do not use the Object constructor; Use an object literal instead (i.e. ```{}``` or ```{a: 0, b: 1, c: 2}```)
- Enumerations are defined by adding the @enum annotation to an object literal
- Additional properties may not be added to enumerations after they are defined and enums must be constant with immutable values
- Follow any additional rules that are specified in [Google's Style Guide](https://google.github.io/styleguide/jsguide.html), unless they conflict with document

### Magic Comments

- In ESLint-Env magic comments (i.e. ```/* eslint-env node, mocha */```), place a space after every comma and on the inside of the comment
- ESLint magic comments for global variables uses the following formats ```/* global var1, var2 */``` and ```/* global var1:false, var2:true */```
- ESLint rule magic comments use the format ```/* eslint curly: "error", eqeqeq: "off", quotes: ["error", "double"] */```


JSON
----

- Use four spaces per indentation level
- Use double-quotes around strings, not single-quotes
- A single space must follow a colon in a key-value pair, but no whitespace should preceeed the colon


Markdown
--------

- Use four spaces per indentation level
- For bold text, use double-asterisks
- For italic text, use underscores
- Two newlines must proceed Header-1 and Header-2 lines (unless it is at the beginning of the file) and one newline must follow
- Two newlines must follow Header-1 lines
- One newline must follow Header-2 lines
- One newline must proceed and follow Header-3, Header-4, Header-5, and Header-6 lines


Python
------

- Use four spaces per indentation level
- Private variables and unused variables must begin with one underscore (i.e. `_var`)
- Class names must use the PascalCase naming convention
- Method attributes must use the snake_case naming convention
- Models in Django must use names that are singular
- View-functions in Django must use names that use the lowercase naming convention
- Check the code using `pycodestyle`, `pylint`, `pytest`, `flake8`, `mccabe` (the Python packages _astkit_ and _astroid_ will need to be installed)
    - Optimally, use `pyanalysis` which is included in PyBooster

### PEP Standards

Follow the below listed PEP Standards

- **[PEP8 (Style Guide for Python Code)](https://www.python.org/dev/peps/pep-0008/)**
- **[PEP20 (The Zen of Python)](https://www.python.org/dev/peps/pep-0020/)**
- **[PEP257 (Docstring Conventions)](https://www.python.org/dev/peps/pep-0257/)**
    - However, disregard the  following rules
        - "_1 blank line required before class docstring_" (D203)
        - "_Multi-line docstring summary should start at the second line_" (D213)
        - "_First line should end with a period_" (D400)
- **[PEP263 (Defining Python Source Code Encodings)](https://www.python.org/dev/peps/pep-0263/)**
- **[PEP484 (Type Hints)](https://www.python.org/dev/peps/pep-0484/)**
- **[PEP488 (Elimination of PYO files)](https://www.python.org/dev/peps/pep-0488/)**
- **[PEP498 (Literal String Interpolation)](https://www.python.org/dev/peps/pep-0498/)**
- **[PEP526 (Syntax for Variable Annotations)](https://www.python.org/dev/peps/pep-0526/)**
- **[PEP3107 (Function Annotations)](https://www.python.org/dev/peps/pep-3107/)**

Do not follow the below listed PEP Standards

- **[PEP287 (reStructuredText Docstring Format)](https://www.python.org/dev/peps/pep-0287/)**

### Special Comments

- To make Flake8 ignore a particular line, use ```# noqa: CODE``` at the end of the line (with two preceeding spaces)
- To make MyPy ignore a particular line, use ```# type: ignore``` at the end of the line (with two preceeding spaces)
- To make PyLint ignore a particular line, use ```# pylint: disable=CODE``` at the end of the line (with two preceeding spaces)


R
-

- Indentation must be two-spaces per level
- Always place the hashpling (```#!/usr/bin/env Rscript```) on the first line
- Place spaces around all binary operators
- Do not place a space before a comma, but always place one space after a comma
- Place a space before a left parenthesis (except in a function call)
- Never omit curly braces
- An opening curly brace should never go on its own line, but a closing curly brace should always go on its own line
- Use ```<-``` for assignment, not ```=```


RelaxNG
-------

- All code must be standards compliant and pass XML and RelaxNG validators
- Refer to the _XML_ section for further guidelines


ReStructuredText
----------------

- Use four spaces per indentation level


Shell Script
------------

- Use four spaces per indentation level
- Use one space between redirections and the file (For instance, use ```2> /dev/null``` **not** ```2>/dev/null```)

### Bourne-Again Shell (BASH)

- Try to avoid extensions

### Posix Shell

- Do not use extensions (remain Posix compliant)


SQL
---

- Use four spaces per indentation level
- A single space must be on each side of mathematical operators (especially in expressions & predicates)
- Statements must end in a semicolon without a space on either side of the semicolon
- Datatypes & major commands (i.e. `UPDATE` & `SELECT`) must be in all capital letter
- Table names & column names should use snake_case or PascalCase (unless not permitted by the SQL implementation)


SVG
---

- Use SVG version 1.1
- All SVG code must be standards compliant and pass XML and SVG validators
- Refer to the _XML_ section for further guidelines


XML
---

- Indentation is two-spaces per level (except for minified code)
- The XML declaration is the first line of the file
- The XML declaration must include the attributes `version`, `encoding`, and `standalone` (in that order)
- `DOCTYPE` must be uppercased (if a `DOCTYPE` is used)
- Double newlines (one blank line) can only be used to divide large or important code sections
- A comment line may be used to name and divide code sections, but a blank newline must be used above and below the comment line
- Superfluous namespace declarations are removed from each element
- Empty elements are converted to start-end tag pairs
- Lexicographic order is applied to the attributes and namespace declarations of each element (except for `<meta>`)
- Default attributes are added to each element
- Attribute values are enclosed in double-quotes
- Do not use spaces around attribute equal-signs
- Character and parsed entity references are replaced (unless it is an attribute value)
- `CDATA` sections are replaced with their character content
- The beginning and end tags must match exactly in case-sensitive manner
- Tag names cannot contain any of the characters ```!"#$%&'()*+,/;<=>?@[\]^`{|}~```, nor a space character, and cannot start with ```-```, ```.```, nor a numeric digit
- `<br/>`, `<hr/>`, and other self-closing (empty) tags without attributes must not have a space preceeding `/>`
- Close all tags and self-closing (empty) tags


YAML
----

- Indentation is two-spaces per level


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
2. **Rule of Composition**
    - Developers should write programs that can communicate easily with other programs. This rule aims to allow developers to break down projects into small, simple programs rather than overly complex monolithic programs.
3. **Rule of Diversity**
    - Developers should design their programs to be flexible and open. This rule aims to make programs flexible, allowing them to be used in ways other than those their developers intended.
4. **Rule of Economy**
    - Developers should value developer time over machine time, because machine cycles today are relatively inexpensive compared to prices in the 1970s. This rule aims to reduce development costs of projects.
5. **Rule of Extensibility**
    - Developers should design for the future by making their protocols extensible, allowing for easy plugins without modification to the program's architecture by other developers, noting the version of the program, and more. This rule aims to extend the lifespan and enhance the utility of the code the developer writes.
6. **Rule of Generation**
    - Developers should avoid writing code by hand and instead write abstract high-level programs that generate code. This rule aims to reduce human errors and save time.
7. **Rule of Least Surprise**
    - Developers should design programs that build on top of the potential users' expected knowledge; for example, '+' in a calculator program should always mean 'addition'. This rule aims to encourage developers to build intuitive products that are easy to use.
8. **Rule of Modularity**
    - Developers should build a program out of simple parts connected by well defined interfaces, so problems are local, and parts of the program can be replaced in future versions to support new features. This rule aims to save time on debugging code that is complex, long, and unreadable.
9. **Rule of Optimization**
    - Developers should prototype software before polishing it. This rule aims to prevent developers from spending too much time for marginal gains.
10. **Rule of Parsimony**
    - Developers should avoid writing big programs. This rule aims to prevent overinvestment of development time in failed or suboptimal approaches caused by the owners of the program's reluctance to throw away visibly large pieces of work. Smaller programs are not only easier to write, optimize, and maintain; they are easier to delete when deprecated.
11. **Rule of Repair**
    - Developers should design programs that fail in a manner that is easy to localize and diagnose or in other words "fail noisily". This rule aims to prevent incorrect output from a program from becoming an input and corrupting the output of other code undetected.
12. **Rule of Representation**
    - Developers should choose to make data more complicated rather than the procedural logic of the program when faced with the choice, because it is easier for humans to understand complex data compared with complex logic. This rule aims to make programs more readable for any developer working on the project, which allows the program to be maintained.
13. **Rule of Robustness**
    - Developers should design robust programs by designing for transparency and discoverability, because code that is easy to understand is easier to stress test for unexpected conditions that may not be foreseeable in complex programs. This rule aims to help developers build robust, reliable products.
14. **Rule of Separation**
    - Developers should separate the mechanisms of the programs from the policies of the programs; one method is to divide a program into a front-end interface and a back-end engine with which that interface communicates. This rule aims to prevent bug introduction by allowing policies to be changed with minimum likelihood of destabilizing operational mechanisms.
15. **Rule of Silence**
    - Developers should design programs so that they do not print unnecessary output. This rule aims to allow other programs and developers to pick out the information they need from a program's output without having to parse verbosity.
16. **Rule of Simplicity**
    - Developers should design for simplicity by looking for ways to break up program systems into small, straightforward cooperating pieces. This rule aims to discourage developers' affection for writing "intricate and beautiful complexities" that are in reality bug prone programs.
17. **Rule of Transparency**
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


Git Commit Messages
===================

- All commit messages must have a title and a body that are both specific and descriptive
- The title must not be more than 80 characters in length (but more than 16) and must not end with punctuation
- The body must not contain a line that is more than 120 characters in length
- Any changes to project files must be mentioned and explained (except for minor changes effecting many files such as changes to coding standards or documentation)
