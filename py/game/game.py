#!/usr/bin/python
# -*- coding: utf-8 -*-

import random
import actor

def calc_damage(attacker, defencer):

  hit = 100

  is_hit = True
  if hit > randint(0, 100):
	is_hit = False
	return 0

  dfc = defencer.dfc
  if defencer.stat == 'GUARD':
	dfc = 2 * defencer.dfc

  baseDamage = attacker.atk - defencer.dfc

  is_critical = False
  if attacker.skl <= randint(0, 100):
	is_critical = True
	baseDamage *= 3

  return baseDamage

if __name__ == '__main__':
  player = actor.Actor()
  enemy  = actor.Actor()

  player.set_debug_setting()

  player.print_status()
  enemy.print_status()

  player.attack(enemy)
