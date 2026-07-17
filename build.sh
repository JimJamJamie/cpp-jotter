#!/bin/bash

clean=0

if [[ $1 == "--clean" ]]; then
    clean=1
fi

cmake \
--fresh \
-S . \
-B build \
-G Ninja \
-Dclean=$clean \
-DCMAKE_BUILD_TYPE="MinSizeRel" \
-DCMAKE_CXX_FLAGS="-Wall -Wextra -pedantic -flto"

nproc=$(($(nproc)/2+2))
ninja -C build -j$nproc
