#!/usr/bin/python
# -*- coding: utf-8 -*-

# Common Functions
def PrintHTMLBegin():
  print "Content-Type: text/html\n\n"
  print '<html>'

def PrintHTMLEnd():
  print '</html>'

def PrintFile(filePath):
  fin = open(filePath)
  for row in fin:
    print row
  fin.close()

def PrintReadFile(filePath):
  fin = open(filePath)
  for row in fin:
    print row
  fin.close()

def WriteFile(strs, filePath):
  f = open(filePath, 'w')
  f.writelines(strs)
  f.close()

# Execute
if __name__ == '__main__':
  PrintHTMLBegin()
  print 'Please Input And Send Under.'
  print '<form action="write_three_req.cgi" method="POST">'
  PrintFile("sample.txt")
  print '</textarea>'
  print '<br/><br/>'
  print '<input type="submit" value="SEND">'
  print '</form>'
  PrintHTMLEnd()

