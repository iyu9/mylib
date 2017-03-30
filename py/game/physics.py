#!/usr/bin/python
# -*- coding: utf-8 -*-

from vector import Vector2
from vector import Vector3

class Physics:

  def __init__(self):
	self.pos = Vector2()
	self.v   = Vector2()
	self.a   = Vector2()

  def Fall(self, t):
	self.pos.y += -0.5 * 9.8 * t * t

  def Move(self, t):
	self.pos.x += self.v.x * t 

  def IsCollision(self, target):
	x_element = (self.pos.x - target.pos.x) * (self.pos.x - target.pos.x)
	y_element = (self.pos.y - target.pos.y) * (self.pos.y - target.pos.y)
	return (x_element + y_element) > 10

if __name__ == '__main__':
	p = Physics()
	p.Fall(1)
	p.Move(1)
	print p.pos.x, p.pos.y
