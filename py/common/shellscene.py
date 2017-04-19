#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
sys.path.append('../game')

from timer import Timer

class ShellScene:
  inputValue = ""
  timer = Timer()
  is_exit = False

  def update(self):
	print("update")

  def input(self):
	inputValue = raw_input()
	self.decode_input(inputValue)

  def decode_input(self, cmd):
	if cmd == "clock":
	  print screen.timer.get_delta()
	if cmd == "exit" or cmd == "bye":
	  print "Bye!"
	  self.is_exit = True 
	else:
	  print "UNDEFINED_COMMAND"

if __name__ == '__main__':
  screen = ShellScene()

  while screen.is_exit == False:
	screen.input()
	screen.update()
