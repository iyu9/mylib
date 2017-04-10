#/usr/bin/python
# -*- coding: utf-8 -*-

import cgi
import os
import sys

if os.environ['REQUEST_METHOD'] != "POST":
	print '不正'
	sys.exit()

form = cgi.FieldStorage()

if not form.has_key("textarea"):
	print 'no_key'
	sys.exit()

textbuffer = form["textarea"].value

print "Content-Type:text/html\n\n"
print "書き込み内容："
print textbuffer

fout = open("../html/three_test.py", "w")
fout.write(textbuffer)



