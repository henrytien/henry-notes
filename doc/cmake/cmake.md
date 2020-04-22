# [CMake Tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/index.html#id1)

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

# basic



# sub-projects

# code-generation

# static-analysis

# unit-testing

# installer

# package-management

# dockerfiles