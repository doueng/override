#!/bin/bash
nasm -f elf -o xplt.o $1
echo "$(objdump -d xplt.o | grep '[0-9a-f]:' | cut -d $'\t' -f 2 | grep -v 'file' | tr -d " \n" | sed 's/../\\x&/g')" > shcode
