`libphutil` is a collection of utility classes and functions for PHP. Some
features of the library include:

**libphutil Library System**
A system for organizing, loading and introspecting PHP classes and functions.
Uses static analysis to generate, validate and update library contents and
includes. Based on Facebook's similar `flib` system.

**Futures**
Futures (also known as "promises") are objects which act as placeholders for
some future result of computation. They let you express parallel and
asynchronous execution with a natural syntax. There are three provided
concrete `Future` implementations: `ExecFuture` for executing system commands,
`HTTPFuture` for making HTTP requests, and `QueryFuture` for executing database
queries.

**Filesystem**
The builtin PHP filesystem functions return error codes and emit warnings. It is
tedious to check these consistently. The `Filesystem` class provides a simple
API for common filesystem operations that throws exceptions on failure.

**xsprintf**
This module allows you to build `sprintf()`-style functions that have arbitrary
conversions. This is particularly useful for escaping data correctly. Three
concrete implementations are provided:

  - `csprintf()`: safely escape data for system commands
  - `jsprintf()`: safely escape data for Javascript
  - `qsprintf()`: safely escape data for MySQL

**AAST/PHPAST**
An abstract, abstract syntax tree which can make it easier to perform simple
static analysis, and a concrete AST for PHP.

**Remarkup**
A Markdown-like lightweight markup language. Remarkup's syntax is defined by
parser plugins and fairly easy to extend and configure.

**Daemons**
Enables running PHP scripts as stable, long-lived daemons.

**Utilities**
A handful of solid utility functions.

`libphutil` is used by
 - [Phabricator](https://secure.phabricator.com/diffusion/P/)
 - [Arcanist](https://secure.phabricator.com/diffusion/ARC/)
 - [Diviner](https://secure.phabricator.com/book/phabricator/article/diviner/)


----------


**BUG REPORTS**

Please update `libphutil` to **HEAD** before filing bug reports. Follow our [bug reporting guide](https://secure.phabricator.com/book/phabcontrib/article/bug_reports/) for complete instructions.


**PULL REQUESTS**

We do not accept pull requests through GitHub. If you would like to contribute code, please read our [Contributor's Guide](https://secure.phabricator.com/book/phabcontrib/article/contributing_code/) for more information.

**LICENSE**

`libphutil` is released under the Apache 2.0 license except as otherwise noted.
