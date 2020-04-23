# [CMake Tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/index.html#id1)

<!-- TOC -->

- [[CMake Tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/index.html#id1)](#cmake-tutorialhttpscmakeorgcmakehelplatestguidetutorialindexhtmlid1)
- [Cmake](#cmake)
    - [[Introduction](https://cmake.org/cmake/help/latest/manual/cmake-toolchains.7.html#id8)](#introductionhttpscmakeorgcmakehelplatestmanualcmake-toolchains7htmlid8)
    - [[Languages](https://cmake.org/cmake/help/latest/manual/cmake-toolchains.7.html#id9)](#languageshttpscmakeorgcmakehelplatestmanualcmake-toolchains7htmlid9)
    - [[Variables and Properties](https://cmake.org/cmake/help/latest/manual/cmake-toolchains.7.html#id10)](#variables-and-propertieshttpscmakeorgcmakehelplatestmanualcmake-toolchains7htmlid10)
    - [[Toolchain Features](https://cmake.org/cmake/help/latest/manual/cmake-toolchains.7.html#id11)](#toolchain-featureshttpscmakeorgcmakehelplatestmanualcmake-toolchains7htmlid11)
    - [[Cross Compiling](https://cmake.org/cmake/help/latest/manual/cmake-toolchains.7.html#id12)](#cross-compilinghttpscmakeorgcmakehelplatestmanualcmake-toolchains7htmlid12)
- [Basic](#basic)
    - [[hello-cmake](https://github.com/ttroy50/cmake-examples/blob/master/01-basic/A-hello-cmake)](#hello-cmakehttpsgithubcomttroy50cmake-examplesblobmaster01-basica-hello-cmake)
        - [Introduction](#introduction)
        - [Concepts](#concepts)
        - [CMakeLists.txt](#cmakeliststxt)
    - [Installing](#installing)
    - [Build Type](#build-type)
        - [Set Default Build Type](#set-default-build-type)
    - [Compile Flags](#compile-flags)
        - [Set Per-Target C++ Flags](#set-per-target-c-flags)
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



## Installing

CMake offers the ability to add a `make install` target to allow a user to install binaries, libraries and other files. The base install location is controlled by the variable CMAKE_INSTALL_PREFIX which can be set using ccmake or by calling cmake with `cmake .. -DCMAKE_INSTALL_PREFIX=/install/location`

The files that are installed are controlled by the [install()](https://cmake.org/cmake/help/v3.0/command/install.html) function.

```
install (TARGETS cmake_examples_inst_bin
    DESTINATION bin)
```

Install the binary generated from the target cmake_examples_inst_bin target to the destination ${CMAKE_INSTALL_PREFIX}/bin

```
install (TARGETS cmake_examples_inst
    LIBRARY DESTINATION lib)
```

Install the shared library generated from the target cmake_examples_inst target to the destination ${CMAKE_INSTALL_PREFIX}/lib

| Note | This may not work on windows. On platforms that have DLL targets you may need to add the following`install (TARGETS cmake_examples_inst    LIBRARY DESTINATION lib    RUNTIME DESTINATION bin)` |
| ---- | ------------------------------------------------------------ |
|      |                                                              |

```
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
    DESTINATION include)
```

Install the header files for developing against the cmake_examples_inst library into the ${CMAKE_INSTALL_PREFIX}/include directory.

```
install (FILES cmake-examples.conf
    DESTINATION etc)
```

Install a configuration file to the destination ${CMAKE_INSTALL_PREFIX}/etc

After `make install` has been run, CMake generates an install_manifest.txt file which includes details on all installed files.

| Note | If you run the `make install` command as root, the install_manifest.txt file will be owned by root. |
| ---- | ------------------------------------------------------------ |
|      |                                                              |

## Build Type

CMake has a number of built in build configurations which can be used to compile your project. These specify the optimization levels and if debug information is to be included in the binary.

The levels provided are:

- Release - Adds the `-O3 -DNDEBUG` flags to the compiler
- Debug - Adds the `-g` flag
- MinSizeRel - Adds `-Os -DNDEBUG`
- RelWithDebInfo - Adds `-O2 -g -DNDEBUG` flags

### Set Default Build Type

The default build type provided by CMake is to include no compiler flags for optimization. For some projects you may want to set a default build type so that you do not have to remember to set it.

To do this you can add the following to your top level CMakeLists.txt

```
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message("Setting build type to 'RelWithDebInfo' as none was specified.")
  set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release"
    "MinSizeRel" "RelWithDebInfo")
endif()
```



## Compile Flags

CMake supports setting compile flags in a number of different ways:

- using target_compile_definitions() function
- using the CMAKE_C_FLAGS and CMAKE_CXX_FLAGS variables.

### Set Per-Target C++ Flags

The recommended way to set C++ flags in modern CMake is to use per-target flags which can be populated to other targets through the target_compile_definitions() [function](https://cmake.org/cmake/help/v3.0/command/target_compile_definitions.html?highlight=target_compile_definitions). This will populate the [INTERFACE_COMPILE_DEFINITIONS](https://cmake.org/cmake/help/v3.0/prop_tgt/INTERFACE_COMPILE_DEFINITIONS.html#prop_tgt:INTERFACE_COMPILE_DEFINITIONS) for the library and push the definition to the linked target depending on the scope.

```
target_compile_definitions(cmake_examples_compile_flags
    PRIVATE EX3
)
```

This will cause the compiler to add the definition -DEX3 when compiling the target.

In the target was a library, and the scope PUBLIC or INTERFACE has been chosen the definition would also be included in any executables that link this target.

For compiler options you can also use the target_compile_options() [function](https://cmake.org/cmake/help/v3.0/command/target_compile_options.html).

## Building with ninja

- Ninja

  Ninja is a small build system with a focus on speed. It differs from other build systems in two major respects: it is designed to have its input files generated by a higher-level build system, and it is designed to run builds as fast as possible.

  ### Calling a Generator

  To call a CMake generator you can use the `-G` command line switch, for example:

  ```
  cmake .. -G Ninja
  ```

## Imported Targets

Imported targets are read-only targets that are exported by FindXXX modules.

To include boost filesystem you can do the following:

```
  target_link_libraries( imported_targets
      PRIVATE
          Boost::filesystem
  )
```

This will automtaically link the Boost::filesystem and Boost::system libraries while also including the Boost include directories.

## C++ Standard Common Method

### Checking Compile flags

CMake has support for attempting to compile a program with any flags you pass into the function `CMAKE_CXX_COMPILER_FLAG`. The result is then stored in a variable that you pass in.

For example:

```
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
```

This example will attempt to compile a program with the flag `-std=c++11` and store the result in the variable `COMPILER_SUPPORTS_CXX11`.

The line `include(CheckCXXCompilerFlag)` tells CMake to include this function to make it available for use.

### Adding the flag

Once you have determined if the compile supports a flag, you can then use the [standard cmake methods](https://github.com/ttroy50/cmake-examples/blob/master/01-basic/G-compile-flags) to add this flag to a target. In this example we use the `CMAKE_CXX_FLAGS` to propegate the flag to all targets .

```
if(COMPILER_SUPPORTS_CXX11)#
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)#
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()
```

## Set C++ Standard

### Using target_compile_features

Calling the [target_compile_features](https://cmake.org/cmake/help/v3.1/command/target_compile_features.html) function on a target will look at the passed in feature and determine the correct compiler flag to use for your target.

```
target_compile_features(hello_cpp11 PUBLIC cxx_auto_type)
```

As with other `target_*` functions, you can specify the scope of the feature for the selected target. This populates the [INTERFACE_COMPILE_FEATURES](https://cmake.org/cmake/help/v3.1/prop_tgt/INTERFACE_COMPILE_FEATURES.html#prop_tgt:INTERFACE_COMPILE_FEATURES) property for the target.

The list of available features can be found from the [CMAKE_CXX_COMPILE_FEATURES](https://cmake.org/cmake/help/v3.1/variable/CMAKE_CXX_COMPILE_FEATURES.html#variable:CMAKE_CXX_COMPILE_FEATURES) variable. You can obtain a list of the available features using the following code:

```
message("List of compile features: ${CMAKE_CXX_COMPILE_FEATURES}")
```

# sub-projects

## Adding a Sub-Directory

A CMakeLists.txt file can include and call sub-directories which include a CMakeLists.txt files.

```
add_subdirectory(sublibrary1)
add_subdirectory(sublibrary2)
add_subdirectory(subbinary)
```

## Referencing Sub-Project Directories

When a project is created using the `project()` command, CMake will automatically create a number of variables which can be used to reference details about the project. These variables can then be used by other sub-projects or the main project. For exampe, to reference the source directory for a different project you can use.

```
    ${sublibrary1_SOURCE_DIR}
    ${sublibrary2_SOURCE_DIR}
```

The variables created by CMake include:

| Variable           | Info                                                         |
| ------------------ | ------------------------------------------------------------ |
| PROJECT_NAME       | The name of the project set by the current `project()`.      |
| CMAKE_PROJECT_NAME | the name of the first project set by the `project()` command, i.e. the top level project. |
| PROJECT_SOURCE_DIR | The source director of the current project.                  |
| PROJECT_BINARY_DIR | The build directory for the current project.                 |
| name_SOURCE_DIR    | The source directory of the project called "name". In this example the source directories created would be `sublibrary1_SOURCE_DIR`, `sublibrary2_SOURCE_DIR`, and `subbinary_SOURCE_DIR` |
| name_BINARY_DIR    | The binary directory of the project called "name". In this example the binary directories created would be `sublibrary1_BINARY_DIR`, `sublibrary2_BINARY_DIR`, and `subbinary_BINARY_DIR` |



# code-generation

# static-analysis

# unit-testing

# installer

# package-management

# dockerfiles