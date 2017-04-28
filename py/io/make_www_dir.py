#!/usr/bin/python
# -*- coding: utf-8 -*-
import os
import os.path

RootDir = '_www/'
SubDir = ['html', 'css', 'js', 'cgi-bin']

os.mkdir(RootDir)
for subdir in SubDir:
  os.mkdir(RootDir + subdir)

f = open('./_www/html/index.html', 'w')
f.write('<html>test</html>')
f.close()
