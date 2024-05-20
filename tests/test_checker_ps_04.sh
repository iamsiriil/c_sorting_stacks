#!/bin/bash

test_04=(
    "0 1 2 3"
    "0 1 3 2"
    "0 2 1 3"
    "0 2 3 1"
    "0 3 2 1"
    "0 3 1 2"
    "1 0 2 3"
    "1 0 3 2"
    "1 2 0 3"
    "1 2 3 0"
    "1 3 0 2"
    "1 3 2 0"
    "2 0 1 3"
    "2 0 3 1"
    "2 1 0 3"
    "2 1 3 0"
    "2 3 0 1"
    "2 3 1 0"
    "3 0 1 2"
    "3 0 2 1"
    "3 1 0 2"
    "3 1 2 0"
    "3 2 0 1"
    "3 2 1 0"
)

for i in "${test_04[@]}"; do
    if [ "$('../push_swap' $i | '../utils/checker_linux' $i)" != "OK" ]; then
        echo "ERROR for input $i!"
    else
        echo "Test size 4 SUCCESS for inout $i!"
    fi
done