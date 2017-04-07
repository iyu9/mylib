#!/usr/bin/python
# -*- coding: utf-8 -*-

class User:

  def __init__(self):
	self.id   = 0
	self.name = "hoge"
	self.age  = 99
	self.sex  = "man"
	self.pref = "fuga"
	self.city = "piyo"
	self.address = "hoge_address"
	self.phone = "114-514"
	self.mobilephone = "114-514"

  def __init__(self, id_, name_):
	self.id = id_
	self.name = name_
	self.age  = 99
	self.sex  = "man"
	self.pref = "fuga"
	self.city = "piyo"
	self.address = "hoge_address"
	self.phone = "114-514"
	self.mobilephone = "114-514"

  def Log(self):
	print "id => " + str(self.id)
	print "name => " + self.name
	print "age =>" + str(self.age)
	print "sex =>" + self.sex
	print "pref=> " + self.pref
	print "city =>" + self.city
	print "address =>" + self.address
	print "phone =>" + self.phone
	print "mobilephone =>" + self.mobilephone

  def CreateDB(self):
	print("CREATED")

  def DeleteDB(self):
	print("DELETED")

if __name__ == '__main__':
  user = User(1, "hoge")
  user.Log()

  user.CreateDB()
  user.DeleteDB()
