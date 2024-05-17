#!/bin/bash

# Check if a numeric argument is provided
if [ $# -eq 0 ]; then
    echo "Usage: $0 <number_of_values>"
    exit 1
fi

num_values=$1

# Generate a list of unique random integers using awk
list_of_values=$(awk -v min=-2147483648 -v max=2147483647 -v count=$num_values '
BEGIN {
    srand(); # Seed random number generator with the current time
    for (i = 0; i < count; i++) {
        do {
            num = int(rand() * (max - min + 1) + min);
        } while (num in numbers);
        numbers[num]; # mark this number as used
        printf "%d ", num;
    }
}')

echo $list_of_values

