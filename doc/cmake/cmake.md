# [CMake Tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/index.html#id1)

<!-- TOC -->

- [CMake Tutorial](#cmake-tutorial)
- [Cmake](#cmake)
  - [Introduction](#introduction)
  - [Languages](#languages)
  - [Variables and Properties](#variables-and-properties)
  - [Toolchain Features](#toolchain-features)
  - [Cross Compiling](#cross-compiling)
- [basic](#basic)
- [sub-projects](#sub-projects)
- [code-generation](#code-generation)
- [static-analysis](#static-analysis)
- [unit-testing](#unit-testing)
- [installer](#installer)
- [package-management](#package-management)
- [dockerfiles](#dockerfiles)

<!-- /TOC -->
# Cmake

Recently, I've created a [simple library](https://github.com/marker68/simple-k-means) in C++. I want to use CMake as the building system so it’s the time to learn a new tool.

## [Introduction](https://cmake.org/cmake/help/latest/manual/cmake-toolchains.7.html#id8)

CMake is a tool to manage building of source code. Originally, CMake was designed as a generator for various dialects of `Makefile`, today CMake generates modern buildsystems such as `Ninja` as well as project files for IDEs such as Visual Studio and Xcode.

CMake is widely used for the C and C++ languages, but it may be used to build source code of other languages too.

People encountering CMake for the first time may have different initial goals. To learn how to build a source code package downloaded from the internet, start with the [`User Interaction Guide`](https://cmake.org/cmake/help/latest/guide/user-interaction/index.html#guide:User Interaction Guide). This will detail the steps needed to run the [`cmake(1)`](https://cmake.org/cmake/help/latest/manual/cmake.1.html#manual:cmake(1)) or [`cmake-gui(1)`](https://cmake.org/cmake/help/latest/manual/cmake-gui.1.html#manual:cmake-gui(1)) executable and how to choose a generator, and how to complete the build.

The [`Using Dependencies Guide`](https://cmake.org/cmake/help/latest/guide/using-dependencies/index.html#guide:Using Dependencies Guide) is aimed at developers wishing to get started using a third-party library.

For developers starting a project using CMake, the [`CMake Tutorial`](https://cmake.org/cmake/help/latest/guide/tutorial/index.html#guide:CMake Tutorial) is a suitable starting point. The [`cmake-buildsystem(7)`](https://cmake.org/cmake/help/latest/manual/cmake-buildsystem.7.html#manual:cmake-buildsystem(7)) manual is aimed at developers expanding their knowledge of maintaining a buildsystem and becoming familiar with the build targets that can be represented in CMake. The [`cmake-packages(7)`](https://cmake.org/cmake/help/latest/manual/cmake-packages.7.html#manual:cmake-packages(7)) manual explains how to create packages which can easily be consumed by third-party CMake-based buildsystems.



## [Languages](https://cmake.org/cmake/help/latest/manual/cmake-toolchains.7.html#id9)

Languages are enabled by the [`project()`](https://cmake.org/cmake/help/latest/command/project.html#command:project) command.

## [Variables and Properties](https://cmake.org/cmake/help/latest/manual/cmake-toolchains.7.html#id10)

Several variables relate to the language components of a toolchain which are enabled.

## [Toolchain Features](https://cmake.org/cmake/help/latest/manual/cmake-toolchains.7.html#id11)

## [Cross Compiling](https://cmake.org/cmake/help/latest/manual/cmake-toolchains.7.html#id12)

If [`cmake(1)`](https://cmake.org/cmake/help/latest/manual/cmake.1.html#manual:cmake(1)) is invoked with the command line parameter `-DCMAKE_TOOLCHAIN_FILE=path/to/file`, the file will be loaded early to set values for the compilers. 

# Basic

## [hello-cmake](https://github.com/ttroy50/cmake-examples/blob/master/01-basic/A-hello-cmake)

```cmake
# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.5)

# Set the project name
project (hello_cmake)

# Add an executable
add_executable(hello_cmake main.cpp)
```



Main.cpp

```c++
#include <iostream>

int main(int argc, char *argv[])
{
   std::cout << "Hello CMake!" << std::endl;
   return 0;
}
```



### Introduction

Shows a very basic hello world example.

The files in this tutorial are below:

```
A-hello-cmake$ tree
.
├── CMakeLists.txt
├── main.cpp
```

  * link:CMakeLists.txt[CMakeLists.txt] - Contains the CMake commands you wish to run
  * link:main.cpp[main.cpp] - A simple "Hello World" cpp file.

### Concepts

### CMakeLists.txt

CMakeLists.txt is the file which should store all your CMake commands. When
cmake is run in a folder it will look for this file and if it does not exist cmake
will exit with an error.



| Variable                 | Info                                                         |
| ------------------------ | ------------------------------------------------------------ |
| CMAKE_SOURCE_DIR         | The root source directory                                    |
| CMAKE_CURRENT_SOURCE_DIR | The current source directory if using sub-projects and directories. |
| PROJECT_SOURCE_DIR       | The source directory of the current cmake project.           |
| CMAKE_BINARY_DIR         | The root binary / build directory. This is the directory where you ran the cmake command. |
| CMAKE_CURRENT_BINARY_DIR | The build directory you are currently in.                    |
| PROJECT_BINARY_DIR       | The build directory for the current project.                 |

# sub-projects

# code-generation

# static-analysis

# unit-testing

# installer

# package-management

# dockerfiles