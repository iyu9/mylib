#!/usr/bin/python

import urllib

params = urllib.urlencode({'spam': 1, 'eggs': 2, 'bacon': 0})

#GET
#f = urllib.urlopen("http://google.co.jp%s" % params)
#POST
#f = urllib.urlopen("http://google.co.jp", params)

f = urllib.urlopen("http://google.co.jp")
print f.read()
