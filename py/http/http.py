#!/usr/bin/python
#-*- coding: utf-8 -*-

import sys
import urllib

# arg check
param = sys.argv
if len(param) != 2:
		print "invalid arg count" 
		sys.exit()
#print "Requesting: " + param[1]

# class sample
class MyURL:
	f = None
	url = None
	html = None

	def __init__(self, url_):
		url = url_
		self.f = urllib.urlopen(url_)

	def get(self):
		html = self.f.read()
		print html

m = MyURL(param[1])
m.get()

###
#params = urllib.urlencode({'spam': 1, 'eggs': 2, 'bacon': 0})
#GET
#f = urllib.urlopen("http://google.co.jp%s" % params)
#POST
#f = urllib.urlopen("http://google.co.jp", params)
#f = urllib.urlopen("http://google.co.jp")
#print f.read()
