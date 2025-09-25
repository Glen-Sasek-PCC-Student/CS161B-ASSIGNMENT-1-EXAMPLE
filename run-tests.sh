#!/bin/bash

# RUN COMMAND  ./run-tests.sh

do_tests() {
    for i in {1..3}; do
        echo -e "\n\nTEST $i"
        ./a.out < "test$i.txt"
    done
}

cleanup() {
    if [ -f "a.out" ]; then
        rm a.out
    fi
}

cleanup

g++ main.cpp && do_tests

cleanup
