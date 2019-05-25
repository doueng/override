import struct
import os

# funs
# clear_stdin
# get_unum
# prog_timeout
# decrypt
# test
# main

# curr jmp
# 0x80489f0

# rodata
# 0x8048a00:      0x080487a5      0x080487b5    0x080487c5      0x080487d5
# 0x8048a10:      0x080487e2      0x080487ef    0x0804884a      0x0804884a
# 0x8048a20:      0x0804884a      0x0804884a    0x0804884a      0x0804884a
# 0x8048a30:      0x080487fc      0x08048809    0x08048816      0x08048823
# 0x8048a40:      0x08048830      0x0804883d    0x2a2a2a2a      0x2a2a2a2a


# 0x1337d00d        == 322424845

# There can only be 0x15 different keys so lets
# bruteforce it!!!
for i in range(0x15):
    cmd = "echo " + str(322424845 - i) +  " | ./level03"
    os.system(cmd)
    print cmd

# Look for the output without 'Invalid Password'
# ***********************************
# *               level03         **
# ***********************************
# Password:echo 322424827 | ~/level03
# then run it
#
# cat <(echo 322424827) -| ./level03
