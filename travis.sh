#!/usr/bin/env sh
set -evx
cmake .
make
./test/src/runColorFaderTests

