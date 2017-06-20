#!/usr/bin/python
# -*- coding: utf-8 -*-

import scene

class TitleScene(scene.Scene):

  def __init__(self):
	scene.Scene.__init__(self)
	print("TitleScene initialize")

  def update(self):
	print("update")

if __name__ == '__main__':
  title = TitleScene()
  title.Update()
