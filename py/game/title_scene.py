#!/usr/bin/python
# -*- coding -*-

from scene import Scene

class TitleScene(Scene):
  def __init__(self):
	Scene.__init__(self)
	print("TitleScene initialize")

if __name__ == '__main__':
  title = TitleScene()
  title.Update()
