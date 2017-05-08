#!/usr/bin/python
# -*- coding: utf-8 -*-

class Vector2:
  
  def __init__(self):
	self.x = 0
	self.y = 0

  def add(self, v):
	self.x += v.x
	self.y += v.y

  def minus(self, v):
	self.x -= v.x
	self.y -= v.y

  def times(self, v):
	self.x *= v.x
	self.y *= v.y

  def divs(self, v):
	self.x /= v.x
	self.y /= v.y

class Vector3:

  def __init__(self):
	self.x = 0
	self.y = 0
	self.z = 0

  def add(self, v):
	self.x += v.x
	self.y += v.y
	self.z += v.z

  def minus(self, v):
	self.x -= v.x
	self.y -= v.y
	self.z -= v.z

  def times(self, v):
	self.x *= v.x
	self.y *= v.y
	self.z *= v.z

  def divs(self, v):
	self.x /= v.x
	self.y /= v.y
	self.z /= v.z

if __name__ == '__main__':
  v2 = Vector2()
  v3 = Vector3()
  print v2.x, v2.y
  print v3.x, v3.y, v3.z
