#!/bin/bash

test_03=(
    "0 1 2"
    "0 2 1"
    "1 0 2"
    "1 2 0"
    "2 0 1"
    "2 1 0"
    )

for i in "${test_03[@]}"; do
    ../push_swap $i
done