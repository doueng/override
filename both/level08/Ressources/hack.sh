#!/bin/sh
mkdir -p /tmp/backups/home/users/level09
cd /tmp
~/level08 /home/users/level09/.pass
cat ./backups/home/users/level09/.pass
