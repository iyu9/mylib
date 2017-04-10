#!/usr/bin/python
# -*- coding: utf-8 -*-

from timer import Timer

class Scene:

  def __init__(self):
	self.is_finished = False
	self.ObjectManager = None
	self.timer = Timer()
	print("initialize")

  def Update(self):
	print("Updated" + str(self.timer.getDelta()))

  def Render(self):
	print("Render")
	
if __name__ == '__main__':
  scene = Scene()
  scene.Update()
  scene.Render()
