#!/usr/bin/python
# -*- coding: utf-8 -*-

class Actor:

  def __init__(self):
	self.id = 1
	self.name = "hoge"
	self.lv = 1
	self.hp = 10
	self.mp = 10

	self.atk = 2
	self.defence = 1
	self.spd = 1
	self.luk = 1

	self.x = self.y = 0
	self.stat = 0
	self.is_dead = 0

  def ShuffleStatus(self):
	self.hp      = random.randint(10, 20)
	self.lv      = 1
	self.atk     = random.randint(5, 8) 	
	self.defence = random.randint(5, 8) 	
	self.spd     = random.randint(5, 8)
	self.luk     = random.randint(5, 8)

  def PrintStatus(self):
	print(self.name + " Status")
	print("name => "    + self.name)
	print("hp => "      + str(self.hp))
	print("atk => "     + str(self.atk))
	print("defence => " + str(self.defence))

  def Attack(self, target):
	damage = self.atk - target.defence
	target.hp -= damage
	print(self.name + " Attacked => " + target.name)
	print(target.name + " Damaged => " + str(damage))

	if target.hp <= 0:
	  target.hp = 0
	  print("Defeat " + target.name)

  def Move(self, x_, y_):
	self.x = x_
	self.y = y_
	print(self.name + " Moved =>" 
	+ " (" + str(self.x)  + ", " + str(self.y) + ")")

  def SetDebugSetting(self):
	self.atk = 999

if __name__ == '__main__':
  player = Actor()
  enemy  = Actor()
  player.Attack(enemy)
  player.Move(2, 2)
  player.PrintStatus()
  enemy.PrintStatus()

