#!/usr/bin/python
# -*- coding: utf-8 -*-

import vector
import timer

G = 9.8;

class Physics:

  def __init__(self):
	self.pos = vector.Vector2()
	self.v   = vector.Vector2()
	self.a   = vector.Vector2()

  def add_force(self, vec):
	self.v.x = vec.x
	self.v.y = vec.y

  def fall(self, t):
	self.pos.y += -0.5 * G * t * t

  def move(self, t):
	self.pos.x += self.v.x * t 

  def is_collision(self, target):
	x = (self.pos.x - target.pos.x) * (self.pos.x - target.pos.x)
	y = (self.pos.y - target.pos.y) * (self.pos.y - target.pos.y)
	return (x + y) > 10

if __name__ == '__main__':
	p = Physics()

	t = 1000.0
	while t > 0:
	  p.fall(t)
	  t -= 0.01
	  print p.pos.x, p.pos.y
