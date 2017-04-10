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

  def render(self):
	print("render")

if __name__ == "__main__":
  obj = Object()
  obj.render()
