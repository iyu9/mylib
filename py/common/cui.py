#!/usr/bin/python

class CUIScreen:
  w = 40
  h = 20
  lines = ['aaaaa','bbbbb','ccccc']
  inputValue = "hoge"

  def __init__(self):
	print("__init__")

  def update(self):
    for line in self.lines:
	  print(line)

  def input(self):
	inputValue = raw_input()
	print inputValue

if __name__ == '__main__':
  screen = CUIScreen()

  while True:
	screen.update()
	screen.input()
