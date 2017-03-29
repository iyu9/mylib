#!/usr/bin/python
# -*- coding: utf-8 -*-

class Scene:
  def __init__(self):
	self.is_finished = False
	print("initialize")

  def Update(self):
	print("Updated")

  def Render(self):
	print("Render")
	
if __name__ == '__main__':
  scene = Scene()
  scene.Update()
  scene.Render()
