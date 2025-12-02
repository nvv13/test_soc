#! /usr/bin/bash

FILE=$1

echo $FILE
echo ${FILE%.*}.dts

dtc -I dtb -O dts -o ${FILE%.*}.dts $FILE


