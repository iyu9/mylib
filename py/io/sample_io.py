# -*- coding: utf-8 -*-
import os
import os.path

FILE_PATH = "sample.txt"
DIR_PATH = "hogepiyo"

fileHandler = open(FILE_PATH, 'r')

for row in fileHandler:
  print row
fileHandler.close()

# write
if os.path.exists(DIR_PATH):
  print('Found Directory')
else:
  print('NOT Found Directory')
  os.mkdir(DIR_PATH)
