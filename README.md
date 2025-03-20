# demo

Pre-requisites:
- Generator (Make, Ninja, Visual Studio)
- Compiler

To download this repo:
```
git clone https://github.com/Morthaurios/demo.git
```

To download submodules:
```
git submodule update --init
```

For example, to configure a Microsoft Visual Studio based build system:
```
cmake -S . -B build -G "Visual Studio 17 2022" -D CMAKE_TOOLCHAIN_FILE="tools\windows-toolchain.cmake"
```

For example, to configure a Ninja build system to compile for ARM:
```
cmake -S . -B build -G Ninja -D CMAKE_TOOLCHAIN_FILE="arm-toolchain.cmake"
```

To build:
```
cmake --build build
```