# demo

Pre-requisites:
- `Ninja` has been installed and added to PATH
- `arm-none-eabi` has been instaleld and added to PATH

To configure:
```
cmake -S . -B build -G Ninja -D CMAKE_TOOLCHAIN_FILE="arm-toolchain.cmake"
```

To build:
```
cmake --build build
```