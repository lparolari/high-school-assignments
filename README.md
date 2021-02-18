# High School Assignments

This repository is a collection of exercises for computer science
course in high school classes (2hrs of lectures per week). All
exercises have their own description provided with a pdf file that can
be delivered as an assignment and optionally some resources. The
description should be self-contained.

## Contents

| Category                      | Topic     | Exercise                                                 |
| ----------------------------- | --------- | -------------------------------------------------------- |
| Imperative programming \[^2\] | Base      | [Date Checker](date-checker)                             |
|                               |           | [Print Rectangle](print-rectangle)                       |
|                               |           | [Second Grade Equations](second-grade-eq)                |
|                               |           | [Weighted Average](weighted-average)                     |
|                               | Array     | [Search Date](search-date)                               |
|                               |           | [Strings Array](strings-array)                           |
|                               |           | [Dynamic Array](dynamic-array)                           |
|                               |           | [Check Sorted](check-sorted)                             |
|                               |           | [Array Analysis](array-analysis)                         |
|                               | File      | [File Splitter](file-splitter)                           |
|                               | Struct    | [Football Betting](football-betting)                     |
|                               |           | [ADT Optional Int](optional-int-adt--struct)             |
|                               | Math      | [Galton Machine](galton-machine)                         |
|                               |           | [Smallest Multiple](smallest-multiple)                   |
|                               |           | [Big Integer](big-integer)                               |
|                               |           | [Thousandth Pair Primes](thousandth-pair-primes)         |
|                               |           | [Largest Palindrome Product](largest-palindrome-product) |
|                               | Recursion | [Num Word](num-word)                                     |
|                               | Projects  | [Snake](snake)                                           |
|                               |           | [Binary String Transmitter](binary-string-transmitter)   |
|                               |           | [Battleship](battleship)                                 |
| OOP programming               |           | [Library](library-oop)                                   |
|                               |           | [Matrix](matrix-oop)                                     |
|                               |           | [Strongbox](strongbox-oop)                               |
|                               |           | [Binary Criteria](binary-criteria-oop) \[^1\]            |
|                               |           | [Metric Conversion](metric-conversions-oop) \[^1\]       |
|                               |           | [Geometric Drawer](geometric-drawer-oop) \[^1\]          |
| Web Programming               | Projects  | [Acme Missiles: Falcon-10](acme-website-falcon10)        |
|                               |           | [Solar System Simulation](solar-system-simulation)       |

\[^1\]: also with inheritance \[^2\]: imperative and procedural
programming

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

You may install docker package, see
https://github.com/blang/latex-docker.

## Usage

**Requirements**

- make
- python (>= 3.8)
- docker
- latex (optional, depending on the build system you choose)

**Compile sources**

In order to compile all the source run the following command

```
python build.py
```

This will generate two directories

- `.dist` where you can find a pdf file with the assigmnet
  instructions, some resources in `exercise` folder and the solution
  in the `solution` folder, and
- `.dist-pdf` where you can find all assigmnet instructions in one
  folder.

The script uses the command `make pdf` in order to build an exercise
and copies to the target output directory all the `.pdf` files from
the source directory plus the folder `exercise` and the folder
`solution` if existing.

Please use `python build_new.py --help` for more informations.

```
$ python build.py  --help
usage: build_new.py [-h] [--dry-run] [-v]

Welcome to the building script for the high school assignments.
You can build assignments source with a single command.
(C) Luca Parolari <luca.parolari23@gmail.com>

optional arguments:
  -h, --help     show this help message and exit
  --dry-run      Do a trial run with actions performed.
  -v, --verbose  Increase output verbosity.

As an alternative to the commandline, params can be placed in a
file, one per line, and specified on the commandline like
'build_new.py @params.conf'.
```

## Strucutre

The repository is a collection of exercises and it uses some
conventions in order to simplify some task such as build or delivery.
If you can, please use strict conventions and also weak conventions.

### Strict Conventions

- every exercise is a directory with the name of exercise in the
  format `name-of-exercise--variant`
- every latex project has a `Makefile` with the `pdf` target

### Weak Conventions

- if the exercise has a written solution, it should be contained in
  the `solution` directory
- if the exercise has a base solution with some code, it should be
  contained in the `exercise` directory
- relations between exercises and their context should be excluded
  from exercise names, list them in the readme instead

## Contributing

> Pull requests are welcome, every contribute will build a better
> world for computer science teachers.

### Adding an exercise

In order to add an exercise you should follow conventions above.
However, every exercise can be different from the other but it...

**must provide**

- a `Makefile` with the target `pdf`

**should provide**

- an `exercise` directory with resources for the assigment
- a `solution` directory with exercise's solution

### Assigment templates

**programming-exercise-template**

A latex template for exercises. You can find the source code at
[https://github.com/lparolari/programming-exercise-template](https://github.com/lparolari/programming-exercise-template).

For a quick start run

```
git clone git@github.com:lparolari/programming-exercise-template.git exercise-name
cd exercise-name
rm -rf .git .travis.yml LICENSE README.md
```

For more info, please refer to
[programming-exercise-template/README.md](https://github.com/lparolari/programming-exercise-template#readme).

**markdown-exercise**

WIP (for now, use as an example
[solar-system-simulation](solar-system-simulation))

## Author

Luca Parolari <<luca.parolari23@gmail.com>>. Computer Science teacher
at Liceo Golgi of Breno, Italy.

## Disclaimer

> :warning: This repository is not intended to be a complete and
> professional support to teachers. It is only a collection of some
> exercises with solutions and eventually some notes. The repository
> may (and probably is) full of imprecision and errors. Take this as
> is.

## License

See [LICENSE](LICENSE) file.

---

## Usage (LEGACY)

Build C++ assigment and copy `.cpp` files.

```bash
python build.py
```
