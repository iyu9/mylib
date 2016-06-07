#!/usr/bin/python

import urllib

#class sample
#method needs self always
class MyURL:
	f = None
	url = None
	html = None

	def __init__(self, url_):
		url = url_
		self.f = urllib.urlopen(url)

	def get(self):
		html = self.f.read()
		print html

m = MyURL("http://google.co.jp")
m.get()

###
#params = urllib.urlencode({'spam': 1, 'eggs': 2, 'bacon': 0})
#GET
#f = urllib.urlopen("http://google.co.jp%s" % params)
#POST
#f = urllib.urlopen("http://google.co.jp", params)
#f = urllib.urlopen("http://google.co.jp")
#print f.read()
