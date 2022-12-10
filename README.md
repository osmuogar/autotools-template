# my_program

Short_description

## Table of contents.

1. [Dependencies.](#1-dependencies)
2. [Installation.](#2-install)
3. [Uninstall.](#3-uninstall)
4. [Execution.](#4-execution)
5. [Directories.](#5-directories)
6. [Development.](#6-development)
    1. [Finding dependencies.](#61-finding-dependencies)
    2. [Debugging.](#62-debugging)
7. [Testing.](#7-testing)
    1. [Code coverage.](#71-code-coverage)
8. [Distribution.](#8-distribution)

## 1. Dependencies.

Developing:

* automake >= 1.16.5
* autoconf >= 2.71.0
* pkg-config >= 1.8.0
* clang-format >= 14.0.6

Testing dependencies:

* cmocka >= 1.1.5

Code coverage:

* lcov >= 1.14.0

Debugging:

* gdb >= 10.1.90.20210103-git
* valgrind >= 3.18.1

## 2. Install.

Run the following set of instructions:

```bash
autoreconf --install
./configure
make
make check
make install
sudo ldconfig
```

## 3. Uninstall.

Run `make uninstall`.

## 4. Execution.

Run `make start`.

## 5. Directories.

* include: header files.
* m4: m4 files.
* src: source files.
* tests: test files.

## 6. Development.

### 6.1. Finding dependencies.

The following instruction shows all dependencies to be added to `configure.ac`.

```bash
autoscan # Used to generate a preliminary configure.ac
```

### 6.2. Linting.

Run `make lint`.

### 6.2. Debugging.

[Valgrind](https://www.valgrind.org/) checks for memory leaks and other troubles
in C. You can enable valgrind in the project with
`./configure --enable-valgrind`. There are predefined rules to run valgrind in
execution, i.e., `make start-valgrind` or tests, i.e., `make check-valgrind`.
Results are outputed in the `tests` folder.

For general debugging set the configuration of the project
([more info](https://stackoverflow.com/a/4680578/8682584)):

```bash
./configure CPPFLAGS=-DDEBUG CFLAGS="-g -O0"
```

run the debugger
[more info](https://www.gnu.org/software/libtool/manual/html_node/Debugging-executables.html):

```bash
./libtool --mode=execute gdb src/my_program
```

> NOTE: Shared libraries are not initially loaded and the breakpoint has to be
> set as pending before running my_program

* 'watch <var>' to watch a variable and be notified about changes.
* 'step' to change continue until the next instruction.
* 'fin' to finish the actua function and see the retun value.
* 'info args/locals' gives information about agurments or locals.
* 'where' prints stack frames.
* 'list [start_line,end_line]' shows 10 lines of code centered around the
    current line.
* 'run' executes my_program, accepting args as space separated values.
* 'break' sets a breakpoint.
* 'continue' continues the execution.
* 'print <variable>' prints the variable.

To quickly check for a bug, commands can be written as aguments such as:

```bash
./libtool --mode=execute gdb \
-ex 'break -source file.c -function foo if bar > 10' \
-ex 'run' \
-ex 'info args' \
-ex 'info locals' \
-ex 'where' \
-ex 'list' \
src/my_program
```

## 7. Testing.

Run `make check`.

### 7.1. Code coverage.

Generates a folder containing the summary of the code coverage of the project.
It is recommended to clean project object files with `git clean -xdf` before and
after generating the code coverage report. This is due to the compiler options
to optimize code; code coverage requires no optimization.

```bash
make coverage
```

## 8. Distribution.

Generates a tar file ready to distribute.

```bash
./configure --enable-valgrind=no # Enabled by default.
make dist
```
