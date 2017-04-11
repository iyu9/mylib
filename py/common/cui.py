#!/usr/bin/python

import sys
sys.path.append('../game')

from timer import Timer

class Screen:
  inputValue = "hoge"
  timer = Timer()
  is_exit = False

  def update(self):
	print("update")

  def input(self):
	inputValue = raw_input()
	self.decode(inputValue)

  def decode(self, cmd):
	if cmd == "clock":
	  print screen.timer.getDelta()
	if cmd == "exit" or cmd == "bye":
	  print "byebye"
	  self.is_exit = True 

if __name__ == '__main__':
  screen = Screen()

  while screen.is_exit == False:
	screen.update()
	screen.input()
