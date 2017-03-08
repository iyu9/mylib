# -*- coding: utf-8 -*-
import os
import os.path

DIR_PATH = "hogepiyo"

fileHandler = open('sample.txt', 'r')

for row in fileHandler:
  print row
fileHandler.close()

# write
if os.path.exists(DIR_PATH):
  print('Found Directory')
else:
  print('NOT Found Directory')
  os.mkdir(DIR_PATH)
