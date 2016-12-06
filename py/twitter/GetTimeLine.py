#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Ref: http://qiita.com/yubais/items/dd143fe608ccad8e9f85
from requests_oauthlib import OAuth1Session
import json

CK = ''         # Consumer Key
CS = ''         # Consumer Secret
AT = ''         # Access Token
AS = ''         # Accesss Token Secert

url = "https://api.twitter.com/1.1/statuses/home_timeline.json"

params = {}

twitter = OAuth1Session(CK, CS, AT, AS)
req = twitter.get(url, params = params)

if req.status_code == 200:
  timeline = json.loads(req.text)
  for tweet in timeline:
	print(tweet["text"])

else:
  print ("Error: %d" % req.status_code)
