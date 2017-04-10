#!/usr/bin/python

from scene import Scene

if __name__ == '__main__':
  scene = Scene()

  while scene.is_finished == False:
	scene.Update()

