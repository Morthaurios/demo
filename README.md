# Demo

## Description
This is dummy code to simulate an application reading information from a sensor and writing it to an memory device over I2C. This code has no real functionality.

The purpose of this repo is to showcase how an embedded project (including tests) could be organized using Git submodules and CMake.

## Pre-requisites:
The following programs need to be installed and added to `PATH` environment variable:
- Git
- CMake 3.26 or newer
- Generator (Make, Ninja, Visual Studio)
- Compiler

## Downloading
To download this repo:
```
git clone https://github.com/Morthaurios/demo.git
```

To download submodules:
```
git submodule update --init
```

## Configuring
For example, to configure a Microsoft Visual Studio based build system:
```
cmake -S . -B build -G "Visual Studio 17 2022" -D CMAKE_TOOLCHAIN_FILE="tools\windows-toolchain.cmake"
```

For example, to configure a Ninja build system to compile for ARM:
```
cmake -S . -B build -G Ninja -D CMAKE_TOOLCHAIN_FILE="arm-toolchain.cmake"
```

## Building
To build:
```
cmake --build build
```

## Testing
To run tests:
```
cd build
ctest .
```

Expected test output:
```
C:\Repos\demo\build>ctest .
Test project X:/Repos/demo/build/windows
    Start 1: I2C.Check_Init
1/2 Test #1: I2C.Check_Init ...................   Passed    0.01 sec
    Start 2: HelloTest.BasicAssertions
2/2 Test #2: HelloTest.BasicAssertions ........   Passed    0.01 sec

100% tests passed, 0 tests failed out of 2

Total Test time (real) =   0.02 sec
```

Note: GTest might not work when cross-compiling. Disable testing by adding `-DBUILD_TESTS=OFF` to `cmake` generate command.