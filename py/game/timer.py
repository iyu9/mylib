
import time

class Timer:

  def __init__(self):
	self.startSeconds = self.getSeconds()
	self.lastSeconds = self.startSeconds

  def getSeconds(self):
	return time.clock()

  def getMinutes(self):
	return time.clock() / (60.0)

  def getHours(self):
	return time.clock() / (60.0 * 60.0)

  def getDays(self):
	return time.clock() / (24.0 * 60.0 * 60.0)

  def getDelta(self):
	res = self.getSeconds() - self.lastSeconds
	self.lastSeconds = self.getSeconds()
	return res

if __name__ == "__main__":
  timer = Timer()

  print str(timer.getSeconds()) + " secs"
  print str(timer.getMinutes()) + " mins"
  print str(timer.getHours())   + " hours"
  print str(timer.getDays())    + " days"

  print str(timer.getDelta())   + " from Prev Frame"
