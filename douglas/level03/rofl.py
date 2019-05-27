import struct
import os

# 0x1337d00d        == 322424845

# There can only be 0x15 different keys so lets
# bruteforce it!!!
for i in range(0x15):
    cmd = "echo " + str(322424845 - i) +  " | ./level03"
    os.system(cmd)
    print cmd

# Look for the output without 'Invalid Password'
# ***********************************
# *               level03         **
# ***********************************
# Password:echo 322424827 | ~/level03
# then run it
#
# cat <(echo 322424827) -| ./level03
