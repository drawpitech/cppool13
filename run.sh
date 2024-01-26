#!/usr/bin/env bash

cflags="-W -Wall -Wextra -g3 -fsanitize=leak,undefined,address"
cc="g++ -std=c++20"

for i in {0..4}; do
    $cc $cflags *.cpp "bonus/ex0$i.cpp" || exit $?
    ./a.out | diff "bonus/out0$i.txt" - || exit $?
    echo -e "Test $i: \033[1;32mOK\033[00m"
done
