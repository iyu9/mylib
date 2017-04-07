#!/usr/bin/python
# -*- coding: utf-8 -*-

class User:

  def __init__(self):
	self.id = 0
	self.name = "hoge"

  def __init__(self, id_, name_):
	self.id = id_
	self.name = name_

  def Log(self):
	print self.id, self.name

  def CreateDB(self):
	print("sending...")

if __name__ == '__main__':
  user = User(1, "hoge")
  user.Log()

  user.CreateDB()
