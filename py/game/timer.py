#!/usr/bin/python
# -*- coding:utf-8 -*-

import time

class Timer:
  is_update_frame = False

  start_seconds = 0
  last_seconds = 0

  start_timer = 0
  finish_timer = 0

  def __init__(self):
	self.start_seconds = self.get_seconds()
	self.last_seconds = self.start_seconds

  def get_seconds(self):
	return time.clock()

  def get_minutes(self):
	return time.clock() / (60.0)

  def get_hours(self):
	return time.clock() / (60.0 * 60.0)

  def get_days(self):
	return time.clock() / (24.0 * 60.0 * 60.0)

  def get_delta(self):
	res = self.get_seconds() - self.last_seconds

	if self.is_update_frame == False:
	  # for check frame loop
	  self.is_update_frame = True
	  self.last_seconds = self.get_seconds()
	return res

  def start(self, finish_seconds):
	self.start_timer = self.get_seconds()
	self.finish_timer = finish_seconds

  def stop(self):
	self.finish_timer = 0

  def is_finish(self):
	return self.get_seconds() >= self.finish_timer

if __name__ == '__main__':
  timer = Timer()

  print str(timer.get_seconds()) + " secs"
  print str(timer.get_minutes()) + " mins"
  print str(timer.get_hours())   + " hours"
  print str(timer.get_days())    + " days"
  print str(timer.get_delta())   + " from Prev Frame"

  timer.start(1.0)
  while timer.is_finish() == False:
	print timer.get_seconds()
  print 'finished'
