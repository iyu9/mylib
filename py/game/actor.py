#!/usr/bin/python
# -*- coding: utf-8 -*-

class Actor:
  name = "hoge"
  lv = 1
  hp = 10
  mp = 10

  rank = 1
  atk = 5
  mgc = 3
  dfc = 3
  mgc_dfc = 3
  skl = 3
  spd = 3
  luk = 3
  mov = 5

  stat = 'None'

  x = 0
  y = 0

  def shuffle_status(self):
	self.lv      = 1
	self.hp      = random.randint(10, 20)
	self.atk     = random.randint(5, 8) 	
	self.dfc     = random.randint(5, 8) 	
	self.spd     = random.randint(5, 8)
	self.luk     = random.randint(5, 8)

  def print_status(self):
	print("")
	print(self.name + " Status")
	print("name => "    + self.name)
	print("stat => "    + self.stat)
	print("hp => "      + str(self.hp))
	print("atk => "     + str(self.atk))
	print("dfc => "     + str(self.dfc))

  def attack(self, target):
	self.stat = 'ATACK'
	damage = self.atk - target.dfc
	target.hp -= damage
	print(self.name + " Attacked => " + target.name)
	print(target.name + " Damaged => " + str(damage))

	if target.hp <= 0:
	  target.hp = 0
	  print("Defeat " + target.name)

  def guard(self):
	self.stat = 'GUARD'

  def move(self, x_, y_):
	self.stat = 'MOVE'
	self.x = x_
	self.y = y_
	print(self.name + " Moved =>" 
	+ " (" + str(self.x)  + ", " + str(self.y) + ")")
	self.wait = True

  def set_debug_setting(self):
	self.atk = 999

if __name__ == '__main__':
  player = Actor()
  enemy = Actor()

  player.attack(enemy)
  player.move(2, 2)
  player.print_status()

  enemy.attack(player)
  enemy.move(2, 2)
  enemy.print_status()

