#!/usr/bin/python
# -*- coding: utf-8 -*-

import json

class SaveManager:

  def __init__(self):
    self.data = None

  def remote_load(self):
	pass

  def remote_save(self):
	pass

  def save(self):
	self.data = {'name':'hoge', 'map':1}
	strjson = json.dumps(self.data)
	f = open('data.txt', 'w')
	f.write(strjson)
	f.close()
	print "saved: " + strjson

  def load(self):
	strjson = json.dumps(self.data)
	f = open('data.txt', 'r')
	self.data = json.load(f)
	f.close()
	print "loaded: " + json.dumps(self.data)

if __name__ == '__main__':
  savemanager = SaveManager()
  savemanager.save()
  savemanager.load()
