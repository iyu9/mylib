#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Ref: http://qiita.com/yubais/items/dd143fe608ccad8e9f85
from requests_oauthlib import OAuth1Session
import json

CK = ''         # Consumer Key
CS = ''         # Consumer Secret
AT = ''         # Access Token
AS = ''         # Accesss Token Secert

# ^CC擾pURL
url = "https://api.twitter.com/1.1/statuses/home_timeline.json"

# ƂɃp[^
params = {}

# OAuth  GET
twitter = OAuth1Session(CK, CS, AT, AS)
req = twitter.get(url, params = params)

if req.status_code == 200:
  # X|XJSON`Ȃ parse 
  timeline = json.loads(req.text)
  # ecC[g{\
  for tweet in timeline:
	print(tweet["text"])

else:
  # G[ꍇ
  print ("Error: %d" % req.status_code)
