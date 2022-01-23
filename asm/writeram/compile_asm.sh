#!/usr/bin/env bash
if [ -z $1 ]; then
    echo "usage: $0 <filename.asm>"
    exit
fi

gpasm -o main.hex ./$1

./bin/intel2readmemh ./main.hex > main.rom
