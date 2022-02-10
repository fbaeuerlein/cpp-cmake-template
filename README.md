<p align="center">

  <h2 align="center">Template project for CMake + C/C++</h3>

  <p align="center">
    This is a small template project to easily setup a CMake based C/C++ project together with googletest and google benchmark
    <br/>
    <br/>
  </p>
</p>


## Table of contents <!-- omit in toc -->

- [Quickstart](#quickstart)
- [Requirements](#requirements)
- [Project structure](#project-structure)
- [Configuration](#configuration)

## Quickstart

Simply clone the repository and start building demo tests and benchmarks.

    git clone https://github.com/fbaeuerlein/cpp-cmake-template.git
    
    cd cpp-cmake-template
    git submodule init && git submodule update

    mkdir build && cd build
    cmake .. 
    make

To check your compiler command line calls, simply use `make VERBOSE=1`.

You surely don't want this repositories history. To (re)initialize it, simply do

    ./reinit.sh

This will clear the complete repository history by removing the .git folder. Also the submodules will be re-added and initialized.

## Requirements

The requirements to build this project are derived from the build requirements of [Googletest 1.11.0](https://github.com/google/googletest/releases/tag/release-1.11.0) and [Benchmark 1.6.1](https://github.com/google/benchmark/releases/tag/v1.6.1). So just have a look at theirs.

To use the project version information in cmake, the minimum required version is set to 3.10.0. Remove the project version settings if you need a 2.x cmake version.

## Project structure

Besides the unittest and benchmark executables no other libraries or executables are defined within the cmake configuration. So adapt the rest according to your requirements.

```text
./
├── ext/
│    ├── benchmark/       -> submodule containing google benchmark
│    └── googletest/      -> submodule containing googletest/mock
│
└── test/
    ├── benchmark/
    │   ├── CMakeLists.txt        -> definitions of benchmark executables
    │   └── MyFirstBenchmark.cpp  -> example implementation of a benchmark
    └── unittests/
        ├── CMakeLists.txt        -> definitions of unittest executables
        └── MyFirstTest.cpp       -> example implementation of unittests
```
## Configuration

Project specific settings can be applied at the CMakeLists.txt file within the top level folder. Change the project name and compiler flags accordingly.

If you're using clang-format, update or overwrite the .clang-format file also.
