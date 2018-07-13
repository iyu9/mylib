import re
import sys
import csv

"""""""""""""""""""""""
CsvFile => UPSERT CSV
"""""""""""""""""""""""

IsUseHeader = False
Comment = '-- comment'
TableName = 'm_TABLENAME'
SchemeName = []

# Check Args
argvs = sys.argv
argc = len(argvs)

if argc < 2:
  print "Usage: python CSVtoSQL.py Csvfile [H]"
  quit()

# CHECK USE HEADER
if argc == 3:
  print argvs[2]
  if argvs[2] == 'H':
	IsUseHeader = True 

# ADD COMMNET
print Comment

# READ CSV 
csvfile = open(argvs[1], 'r');
reader = csv.reader(csvfile)

# CheckReadHeader
if IsUseHeader == True:
  # ReadHeader
  SchemeName = []
  for row in reader:
	for name in row:
	  SchemeName.append(name)
	break

# MainPrintFunction
if IsUseHeader == True:
  next(reader)
for row in reader:
  # Print InsertTarget
  print "INSERT INTO " + TableName + " (",
  idx = 0
  for name in SchemeName:
	print name,
	if idx < len(SchemeName)-1:
	  print ", ",
	idx += 1
  print ")",
  print "VALUES (",
  
  # Print Insert Values
  idx = 0
  for val in row:
	print "'" + val + "'",
	if idx < len(SchemeName)-1:
	  print ", ",
	idx += 1
  print ") ",

  # Update Values
  print "ON DUPLICATE KEY UPDATE ",
  idx = 0
  for name in SchemeName:
	if idx == 0:
	  idx += 1;
	  continue

	print name + " = '" + row[idx] + "' ",
	if idx < len(SchemeName)-1:
	  print ", ",
	idx += 1
  print ";"

csvfile.close()
