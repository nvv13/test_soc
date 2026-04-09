#!/usr/bin/bash

# Обрабатываем все файлы с расширением .dtbo в текущей директории
for file in *.dtb; do
    # Проверяем, существуют ли вообще такие файлы
    if [ -f "$file" ]; then
        output="${file%.dtb}.dts"
        echo "Converting: $file -> $output"
        dtc -I dtb -O dts -o "$output" "$file"
    else
        echo "No .dtb files found in current directory"
        break
    fi
done

echo "Done!"
