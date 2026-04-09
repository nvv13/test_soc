#!/usr/bin/bash

for file in *.dts; do
    if [ -f "$file" ]; then
        output="${file%.dts}.dtbo"
        echo "Compiling: $file -> $output"
        dtc -@ -I dts -O dtb -o "$output" "$file"
    fi
done
