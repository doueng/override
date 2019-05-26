#!/bin/sh
nasm -f elf shell.s
objdump -d shell.o | grep '[0-9a-f]:' | tr -s ' ' | cut -f 2-2 | tr -d '\n' | sed 's/ /\\x/g'
