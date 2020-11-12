# Assignments

TODO: make this description better.

## Contents

- Imperative programming

  - Base

    - [Date Checker](date-checker)
    - [Print Rectangle](print-rectangle)
    - [Second Grade Equations](second-grade-eq)
    - [Weighted Average](weighted-average)

  - Array

    - [Search Date](search-date)
    - [Strings Array](strings-array)
    - [Dynamic Array](dynamic-array)
    - [Check Sorted](check-sorted)

  - File

    - [File Splitter](file-splitter)

  - Struct

    - [Football Betting](football-betting)
    - [ADT Optional Int](optional-int-adt--struct)

  - Math

    - [Galton Machine](galton-machine)
    - [Smallest Multiple](smallest-multiple)
    - [Big Integer](big-integer)
    - [Thousandth Pair Primes](thousandth-pair-primes)

  - Recursion

    - [Num Word](num-word)

  - Projects

    - [Snake](snake)

- OOP programming

  - [Person](person-oop)
  - [Library](library-oop)
  - [Matrix](matrix-oop)
  - [Strongbox](strongbox-oop)
  - [Binary Criteria](binary-criteria-oop) (also with inheritance)
  - [Metric Conversion](metric-conversions-oop) (also with inheritance)
  - [Geometric Drawer](geometric-drawer-oop) (inheritance)

  - Projects

    - [Binary String Transmitter](binary-string-transmitter)
    - [Battleship](battleship)

- Web Programming

  - Projects

    - [Acme Missiles: Falcon-10](acme-website-falcon10)

## Installation

Download the repository

```
git clone git@github.com:lparolari/high-school-assignments.git
```

(Optional) Add a python virtualenv and install dependencies

```
# add the virtual environment
virtualenv .venv
# or, with
python3 -m virtualenv .venv

# activate it
source .venv/bin/activate

# install dependencies
pip install dryable
```

You may install docker package, see https://github.com/blang/latex-docker.

## Usage

In order to compile all the source run the following command

```
python build.py

# or, with
./build.py
```

It will create a folder `.dist` with all the exercises built.
The script uses the command `make pdf` in order to build an exercise and copies to the target output
directory all the `.pdf` and `.cpp` files from the source directory.

Please use `python build.py --help` for more informations.

```
$ python build.py  --help
usage: build.py [-h] [--read-from source] [--path path] [--list list]
                [--dry-run] [-v]

Welcome to the building script for the high school assignments. You can build
assignments source with a single command. (C) Luca Parolari
<luca.parolari23@gmail.com>

optional arguments:
  -h, --help          show this help message and exit
  --read-from source  Source from which reading the targets. Options are `ls`,
                      `list` and `file`.
  --path path         The sources path. (Used with `--read-from` argument with
                      `ls`, `file`).
  --list list         The sources list. (Used with `--read-from list`).
  --dry-run           Do a trial run with actions performed.
  -v, --verbose       Increase output verbosity.

As an alternative to the commandline, params can be placed in a file, one per
line, and specified on the commandline like 'build.py @params.conf'.
```

If you need to add some assignments please use the latex template
[programming-exercise-template](https://github.com/lparolari/programming-exercise-template)
In order to use is run the following commands

```
git clone git@github.com:lparolari/programming-exercise-template.git exercise-name
cd exercise-name
rm -rf .git .travis.yml LICENSE README.md
```

See more at _programming-exercise-template/README.md_.

## Strucutre

The repository is a collection of exercises and it uses some conventions in order
to simplify some task such as build or delivery. If you can, please use strict conventions
and also weak conventions.

### Strict Conventions

- every exercise is a directory with the name of exercise with this format `name-of-exercise--variant` (see more about naming conventions below)
- every exercise in its main directory has a latex source with the text of the exercise
- every latex project has a `Makefile` with the `pdf` target

### Weak Conventions

- if the exercise has a written solution, it should be contained in the `solution` directory
- if the exercise has a base solution with some code, it should be contained in the `exercise` directory
- if `.cpp` files are unique they should be called `exercise.cpp`
- relations between exercises and their context should be excluded from exercise names, list them in the readme instead

## Contributing

Pull requests are welcome, every contribute will build a better
world for computer science teachers.

## Author

Luca Parolari <<luca.parolari23@gmail.com>>. Computer Science teacher
at Liceo Golgi of Breno, Italy.

## Disclaimer

> :warning: This repository is not intended to be a complete and
> professional support to teachers. It is only a collection of some
> exercises with solutions and eventually some notes. The repository
> may (and probably is) full of imprecision and errors. Take this
> as is.

## License

See [LICENSE](LICENSE) file.
