# passwd-generator

Small tools to generate random strings to be used for passwords or other things.

## Tools

There are currently 2 tools:

- `passwd-generator`: A graphical program.
- `passwd-generator-cli`: A CLI program.

Both tools generate passwords the same way.

## Random string generation

The random strings are generated using `QRandomGenerator`.

## Building

This is a pure Qt project. You only need Qt to build and run this project.

### Linux or macOs
The build steps are:

    qmake
    make

### Windows
On Windows, you need depending if you are using MinGW or MSVC you need to replace `make`:

#### MinGW

    qmake
    mingw32-make -j

#### MSVC

    qmake
    nmake

or

    qmake
    jom

On Windows you can deploy Qt libraries into the output folder using the Makefile target `deployqt`:

    qmake CONFIG+=release
    mingw32-make -j
    mingw32-make -j deployqt