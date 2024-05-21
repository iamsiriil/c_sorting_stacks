#!/bin/bash

test_error=(
    "a b c"
    "0 1 a"
    "0 1 0"
    )

for i in "${test_error[@]}"; do
    output="$('../push_swap' $i)"
    if [ "$output" == "Error" ]; then
        echo "Test FAIL for input $i."
    else
        echo "Test SUCCESS for input $i."
    fi
done 