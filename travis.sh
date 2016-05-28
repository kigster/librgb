#!/usr/bin/env sh
set -evx
git submodule update --init --recursive
cmake .
make
./test/src/runColorFaderTests

