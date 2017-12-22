#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import commands
import re

argv = sys.argv
m = re.match('(\w+)\.(\w+)$', argv[1])
print "parsed input file: " + m.group(1) + ", " + m.group(2)

# check error
if m == None:
  exit()

inputfilepath = argv[1]
filename = m.group(1)
filetype = m.group(2)

# setting output directory
basedir = '/mnt/c/WorkSpace/<UNITYSAMPLEPROJECT>/'
subdir = 'Assets/Images/<SUBDIR>/'

pfdirs = [
  "hoge1",
  "hoge2"
]

pfsuffixes = [
  "_hg1",
  "_hg2",
]

# output
idx = 0
for pfdir in pfdirs:
  cmd = "cp " + inputfilepath + " " + basedir + subdir + "bg/" + filename + pfsuffixes[idx] + "." + filetype
  check = commands.getoutput(cmd)
  print(cmd)
  idx += 1
