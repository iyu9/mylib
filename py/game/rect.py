#!/usr/bin/python

class Rect:

  def __init__(self):
	self.x = 0
	self.y = 0
	self.w = 0
	self.h = 0

  # from upper left
  def set(self, x, y, w, h):
	self.x = x;
	self.y = y;
	self.w = w;
	self.h = h;

  def set_center(self, x, y, w, h):
	skip

if __name__ == '__main__':
	rect = Rect()
	rect.set(120, 200, 500, 500)
	print rect.x, rect.y, rect.w, rect.h
