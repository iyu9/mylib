#!/usr/bin/python

import requests

# GET
r = requests.get('https://github.com/timeline.json')
print(r.text)

# POST
r = requests.post("http://httpbin.org/post")
print(r.text)
