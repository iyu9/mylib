#!/usr/bin/python
# -*- coding: utf-8 -*-

from actor import Actor

if __name__ == '__main__':
  player = Actor()
  enemy  = Actor()

  player.SetDebugSetting()

  player.PrintStatus()
  enemy.PrintStatus()

  player.Attack(enemy)
