# CMake Tutorial

<!-- TOC -->

- [CMake Tutorial](#cmake-tutorial)
- [Cmake](#cmake)
  - [Introduction](#introduction)
  - [Languages](#languages)
  - [Variables and Properties](#variables-and-properties)
  - [Cross Compiling](#cross-compiling)
- [Basic](#basic)
  - [hello-cmake](#hello-cmake)
    - [Introduction](#introduction-1)
    - [Concepts](#concepts)
    - [CMakeLists.txt](#cmakeliststxt)
  - [Installing](#installing)
  - [Build Type](#build-type)
    - [Set Default Build Type](#set-default-build-type)
  - [Compile Flags](#compile-flags)
    - [Set Per-Target C++ Flags](#set-per-target-c-flags)
  - [Building with ninja](#building-with-ninja)
    - [Calling a Generator](#calling-a-generator)
  - [Imported Targets](#imported-targets)
  - [C++ Standard Common Method](#c-standard-common-method)
    - [Checking Compile flags](#checking-compile-flags)
    - [Adding the flag](#adding-the-flag)
  - [Set C++ Standard](#set-c-standard)
    - [Using target_compile_features](#using-targetcompilefeatures)
- [sub-projects](#sub-projects)
  - [Adding a Sub-Directory](#adding-a-sub-directory)
  - [Referencing Sub-Project Directories](#referencing-sub-project-directories)
- [code-generation](#code-generation)
    - [Protocol Buffers](#protocol-buffers)
- [static-analysis](#static-analysis)
    - [CppCheck Static Analysis](#cppcheck-static-analysis)
    - [scan-build](#scan-build)
- [unit-testing](#unit-testing)
- [installer](#installer)
- [package-management](#package-management)
- [dockerfiles](#dockerfiles)

<!-- /TOC -->
# Cmake

Recently, I've created a [simple library](https://github.com/marker68/simple-k-means) in C++. I want to use CMake as the building system so it’s the time to learn a new tool.

## Introduction

CMake is a tool to manage building of source code. Originally, CMake was designed as a generator for various dialects of `Makefile`, today CMake generates modern buildsystems such as `Ninja` as well as project files for IDEs such as Visual Studio and Xcode.

CMake is widely used for the C and C++ languages, but it may be used to build source code of other languages too.

People encountering CMake for the first time may have different initial goals. To learn how to build a source code package downloaded from the internet, start with the [`User Interaction Guide`](https://cmake.org/cmake/help/latest/guide/user-interaction/index.html#guide:User Interaction Guide). This will detail the steps needed to run the [`cmake(1)`](https://cmake.org/cmake/help/latest/manual/cmake.1.html#manual:cmake(1)) or [`cmake-gui(1)`](https://cmake.org/cmake/help/latest/manual/cmake-gui.1.html#manual:cmake-gui(1)) executable and how to choose a generator, and how to complete the build.

The [`Using Dependencies Guide`](https://cmake.org/cmake/help/latest/guide/using-dependencies/index.html#guide:Using Dependencies Guide) is aimed at developers wishing to get started using a third-party library.

For developers starting a project using CMake, the [`CMake Tutorial`](https://cmake.org/cmake/help/latest/guide/tutorial/index.html#guide:CMake Tutorial) is a suitable starting point. The [`cmake-buildsystem(7)`](https://cmake.org/cmake/help/latest/manual/cmake-buildsystem.7.html#manual:cmake-buildsystem(7)) manual is aimed at developers expanding their knowledge of maintaining a buildsystem and becoming familiar with the build targets that can be represented in CMake. The [`cmake-packages(7)`](https://cmake.org/cmake/help/latest/manual/cmake-packages.7.html#manual:cmake-packages(7)) manual explains how to create packages which can easily be consumed by third-party CMake-based buildsystems.



## Languages

Languages are enabled by the [`project()`](https://cmake.org/cmake/help/latest/command/project.html#command:project) command.

## Variables and Properties

Several variables relate to the language components of a toolchain which are enabled.

## Cross Compiling

If [`cmake(1)`](https://cmake.org/cmake/help/latest/manual/cmake.1.html#manual:cmake(1)) is invoked with the command line parameter `-DCMAKE_TOOLCHAIN_FILE=path/to/file`, the file will be loaded early to set values for the compilers. 

# Basic

## hello-cmake

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

Code generation can be useful to create source code in different languages from a common description file. This can reduce the amount of manual code to write and increase interoperability.

Examples showing code generation using variables from CMake and also using some common tools.

- [configure-file](https://github.com/ttroy50/cmake-examples/blob/master/03-code-generation/configure-files) - Using the CMake configure_file function to inject CMake variables.
- [Protocol Buffers](https://github.com/ttroy50/cmake-examples/blob/master/03-code-generation/protobuf) - Using Google Protocol Buffers to generate C++ source.

### Protocol Buffers

```cmake
cmake_minimum_required(VERSION 3.5)

# Set the project name
project (protobuf_example)

# find the protobuf compiler and libraries
find_package(Protobuf REQUIRED)

# check if protobuf was found
if(PROTOBUF_FOUND)
    message ("protobuf found")
else()
    message (FATAL_ERROR "Cannot find Protobuf")
endif()

# Generate the .h and .cxx files
PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS AddressBook.proto)

# Print path to generated files
message ("PROTO_SRCS = ${PROTO_SRCS}")
message ("PROTO_HDRS = ${PROTO_HDRS}")

# Add an executable
add_executable(protobuf_example
    main.cpp
    ${PROTO_SRCS}
    ${PROTO_HDRS})

target_include_directories(protobuf_example
    PUBLIC
    ${PROTOBUF_INCLUDE_DIRS}
    ${CMAKE_CURRENT_BINARY_DIR}
)

# link the exe against the libraries
target_link_libraries(protobuf_example
    PUBLIC
    ${PROTOBUF_LIBRARIES}
)

```

configure-file

# static-analysis

The examples here include using the following tools:

- [CppCheck](http://cppcheck.sourceforge.net/)
- [Clang Static Analyzer](https://clang-analyzer.llvm.org/)
- [Clang Format](https://clang.llvm.org/docs/ClangFormat.html) 

Static analysis is the analysis of code without executing it. It can be
used to find common programming errors and enforce coding guidelines.
Examples of errors that can be found using static analysis tools
include:

* Out of bounds errors
* Memory leaks
* Usage of uninitialized variables
* Use of unsafe functions

### CppCheck Static Analysis

* Introduction

  This example shows how to call the
  http://cppcheck.sourceforge.net/[CppCheck] tool to do static analysis.
  This shows how to make an analysis target for each project in your repository.

  ```
  $ tree
  .
  ├── cmake
  │   ├── analysis.cmake
  │   └── modules
  │       └── FindCppCheck.cmake
  ├── CMakeLists.txt
  ├── subproject1
  │   ├── CMakeLists.txt
  │   └── main1.cpp
  └── subproject2
      ├── CMakeLists.txt
      └── main2.cpp
  ```

### scan-build

To run clang static analyzer you can use the tool `scan-build` to run the analyzer when you also run the compiler. This overrides the CC and CXX environment variables and replaces them with it’s own tools. To run it you can do

```
$ scan-build-3.6 cmake ..
$ scan-build-3.6 make
```

By default this will run the standard compiler for your platform, i.e. `gcc` on linux. However, if you want to override this you can change the command to:

```
$ scan-build-3.6 --use-cc=clang-3.6 --use-c++=clang++-3.6 -o ./scanbuildout/ make
```

# unit-testing

Unit testing is a software development process in which the smallest testable parts of an application, called units, are individually and independently scrutinized for proper operation. This can involve taking a class, function, or algorithm and writing test cases that can be run to verify that the unit is working correctly.

CMake includes a tool called [CTest](https://cmake.org/Wiki/CMake/Testing_With_CTest) which allows you to enable the `make test` target to run automated tests such as unit tests.

There are many unit-testing frameworks available which can be used to help automate and ease the development of unit tests. In these examples I show how to use some of these frameworks and call them using the CMake testing utility CTest.

The examples here include using the following frameworks:

- [Boost Unit Test Framework](http://www.boost.org/doc/libs/1_56_0/libs/test/doc/html/utf/user-guide.html)
- [Google Test - Download](https://github.com/google/googletest)
- [Catch2](https://github.com/catchorg/Catch2) 



# installer

# package-management

# dockerfiles