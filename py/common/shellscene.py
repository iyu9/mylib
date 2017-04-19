#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
sys.path.append('../game')

from timer import Timer

class ShellScene:
  timer = Timer()

  is_interrupted = True
  is_accepted = False
  is_exit = False
  input_value = None

  # @Override
  def check_update(self):
	if self.is_accepted:
	  print("update")

  def check_input(self):
	if self.is_interrupted:
	  self.input_value = raw_input()
	  self.decode_input(self.input_value)

  # @Override
  def decode_input(self, cmd):
	if cmd == "clock":
	  self.is_accepted = True
	  print screen.timer.get_delta()
	if cmd == "exit" or cmd == "bye":
	  print "Bye!"
	  self.is_exit = True 
	else:
	  print "UNDEFINED_COMMAND"

if __name__ == '__main__':
  screen = ShellScene()

  while screen.is_exit == False:
	screen.check_input();
	screen.check_update()
