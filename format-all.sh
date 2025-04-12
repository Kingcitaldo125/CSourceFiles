#!/bin/bash

find . -type f \( -name "*.c" -name "*.cpp" -o -name "*.hpp" \) -print0 | while IFS= read -r -d '' file; do
    clang-format -i "$file"
done
