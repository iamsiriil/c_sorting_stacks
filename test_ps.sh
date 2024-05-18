test_03=(
    "0 1 2"
    "0 2 1"
    "1 0 2"
    "1 2 0"
    "2 0 1"
    "2 1 0"
)

for i in "${test_03[@]}"; do
    if [ "$(./push_swap $i | ./checker_linux $i)" != "OK" ]; then
        echo "ERROR for input $i"
    else
        echo "Test size 3 SUCCESS for input $i!"
    fi
done
