#!/usr/bin/python
# -*- coding: utf-8 -*-

import vector

class Physics:

  def __init__(self):
	self.pos = vector.Vector2()
	self.v   = vector.Vector2()
	self.a   = vector.Vector2()

  def fall(self, t):
	self.pos.y += -0.5 * 9.8 * t * t

  def move(self, t):
	self.pos.x += self.v.x * t 

  def is_collision(self, target):
	x_element = (self.pos.x - target.pos.x) * (self.pos.x - target.pos.x)
	y_element = (self.pos.y - target.pos.y) * (self.pos.y - target.pos.y)
	return (x_element + y_element) > 10

if __name__ == '__main__':
	p = Physics()
	p.fall(1)
	p.move(1)
	print p.pos.x, p.pos.y
