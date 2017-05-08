#!/usr/bin/python
# -*- coding: utf-8 -*-

from timer import Timer

class Scene:
	self.is_finished = False
	self.ObjectManager = None

  def __init__(self):
	self.timer = Timer()
	print("initialize")

  def update(self):
	print("Updated" + str(self.timer.getDelta()))

  def render(self):
	print("Render")
	
if __name__ == '__main__':
  scene = Scene()

  while True:
	scene.update()
	scene.render()
