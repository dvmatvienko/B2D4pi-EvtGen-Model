#!/bin/bash

find . \( -name "*.cpp" -o -name "*.hh" -o -name "*.cc" -o -name "*.C" \) -exec clang-format -i '{}' \;

