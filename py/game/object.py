#!/usr/bin/py
  

class Object:

  (
	PLANE,
	POLYGON,
  ) = range(0,2)

  def __init__(self):
	self.id = 0
	self.name = "NO_NAME"
	self.renderType = 0
	self.x = self.y = self.z = 0
	self.vertices = []

  def destroy(self):
	print("destroy")

  def render(self):
	print("render")

class Object2D:
  def __init__(self, x, y, w, h):
	self.x = x
	self.y = y
	self.w = w
	self.h = h

  def create(self, x, y, w, h):
	self.x = x
	self.y = y
	self.w = w
	self.h = h

  def destroy(self):
	print("destroy")

  def render(self):
	print("render")

if __name__ == "__main__":
  obj = Object()
  obj.render()
