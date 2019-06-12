# env -i $(python env.py) /home/users/level05/level05
import os

rows, columns = os.popen('stty size', 'r').read().split()
pwd = os.getcwd()

print "COLUMNS=" + columns
print "PWD=" + pwd
print "LINES=" + rows
