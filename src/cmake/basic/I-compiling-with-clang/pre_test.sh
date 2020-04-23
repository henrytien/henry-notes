#!/bin/bash

ROOT_DIR=`pwd`
#dir="01-basic/I-compiling-with-clang"

if [ -d "$ROOT_DIR/build.clang" ]; then
    echo "deleting $dir/build.clang"
    rm -r build.clang
fi
