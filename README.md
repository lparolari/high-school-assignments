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

  - Math

    - [Galton Machine](galton-machine)
    - [Smallest Multiple](smallest-multiple)
    - [Big Integer](big-integer)
    - [Thousandth Pair Primes](thousandth-pair-primes)

  - Recursion
    - [Num Word](num-word)

- OOP programming

  - [Person](person-oop)
  - [Library](library-oop)
  - [Matrix](matrix-oop)
  - [Strongbox](strongbox-oop)
  - [Binary Criteria](binary-criteria-oop) (also with inheritance)
  - [Metric Conversion](metric-conversions-oop) (also with inheritance)
  - [Geometric Drawer](geometric-drawer-oop) (inheritance)

- Projects

  - [Snake](snake)
  - [Binary String Transmitter](binary-string-transmitter)
  - [Battleship](battleship)

## Usage

In order to compile all the source run the following command

```
python build.py
```

It will create a folder `.dist` with all the exercises built.
The script uses the command `make pdf` in order to build an exercise and copies to the target output
directory all the `.pdf` and `.cpp` files from the source directory.

## Strucutre

The repository is a collection of exercises and it uses some conventions in order
to simplify some task such as build or delivery.

### Strict Conventions

- every exercise is a directory with the name of exercise with this format `name-of-exercise--variant` (see more about naming conventions below)
- every exercise in its main directory has a latex source with the text of the exercise
- every latex project has a `Makefile` with the `pdf` target

### Weak Conventions

- if the exercise has a written solution, it should be contained in the `solution` directory
- if the exercise has a base solution with some code, it should be contained in the `exercise` directory
- if `.cpp` files are unique they should be called `exercise.cpp`
- relations between exercises and they context should be excluded from exercise names, list them in the readme instead

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
