# def
class MyClass:
  
  def __init__(self):
	self.uid  =  0
	self.name = "NO_NAME"

  def getName(self):
	return self.name

  def setName(self, name):
	self.name = name

  def getUserID(self):
	return self.uid

  def setUserID(self, uid):
	self.uid = uid

# Usage
a = MyClass()
a.setName("hoge")
print(a.getName())
