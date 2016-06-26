# -*- coding:utf-8 -*-

import pygame
from pygame.locals import *

import sys
import time

#GRAVITY FACTOR
g = 9.8

#DIRECTION
UP	  = 0
RIGHT = 1
DOWN  = 2
LEFT  = 3

#ACTOR STATE
FIXED = 0
FALL = 1
JUMP = 2

ACTOR_STAT = [
  'FIXED',
  'FALL',
  'JUMP'
]

class Vector2:
  def __init__(self):
	self.x = 0
	self.y = 0

class Object:
  def __init__(self):
	self.id = 0
	self.name = "NO_NAME"
	self.pos = Vector2()
	self.scale = Vector2()

class ObjectManager:
  def __init__(self):
	self.list = Object()
  def add(self, obj):
	self.list += obj
  def delete(self, obj):	
	self.list -= obj

class GameManager:
  def __init__(self):
	self.STR_MODE = [
	  'TITLE',
	  'OPTION',
	  'MAIN'
	]

class Actor:
  def __init__(self):
	self.id = 0
	self.name = "tommy"
	self.v = Vector2()
	self.pos = Vector2()
	self.hp = 10
	self.stat = FIXED
	self.fall_start = 0

  def update(self):
	if self.v.y > 0.1:
	  self.stat = JUMP
	  self.pos.y += self.v.y
	  self.v.y *= 0.95
	elif self.v.y < -0.1:
	  self.stat = FALL
	  self.pos.y += self.v.y * (time.clock() - self.fall_start)
	  self.v.y += 0.02
	else:
	  self.stat = FIXED
	  self.fall_start = 0

  def shot(self):
	bullet = Object()

  def jump(self):
	if self.stat == FIXED:
	  self.stat = JUMP
	  self.v.y = 1

  def fall(self):
	if self.pos.y > -500:
	  self.stat = FALL
	  self.v.y = -10
	  self.fall_start = time.clock()

actor = Actor()

def main():
  pygame.init()
  screen = pygame.display.set_mode((400, 400))
  pygame.display.set_caption("Hello Pygame")
  font = pygame.font.Font(None, 25)
  #bg = pygame.image.load("rockman.jpg").convert_alpha()
  #rect_bg = bg.get_rect()

  #actor = pygame.image.load("rockman.jpg").convert_alpha()
  #rect_actor = actor.get_rect()

  x = y = z = 0

  while (1):

	# キー入力
	pressed_key = pygame.key.get_pressed()

	if pressed_key[K_LEFT]:
	  actor.pos.x-=0.1
	if pressed_key[K_RIGHT]:
	  actor.pos.x+=0.1
	if pressed_key[K_UP]:
	  actor.pos.y+=0.1
	if pressed_key[K_DOWN]:
	  actor.pos.y-=0.1

	if pressed_key[K_s]:
	  actor.shot()
	if pressed_key[K_x]:
	  actor.jump()
	if pressed_key[K_c]:
	  actor.fall()

	actor.update()

	#グラフィック処理
	screen.fill((0,0,0))
	text_clock = font.render("clock: " + str(time.clock()), True, (255,255,255))
	text_pos = font.render("pos: " + str(actor.pos.x) + ", " + str(actor.pos.y), True, (255,255,255))
	text_velocity = font.render("v: " + str(actor.v.x) + ", " + str(actor.v.y), True, (255,255,255))
	text_stat = font.render("stat: " + ACTOR_STAT[actor.stat], True, (255,255,255))
	#screen.blit(bg, rect_bg)
	#screen.blit(actor, rect_actor)
	pygame.draw.rect(screen, (0,80,0), Rect(10+actor.pos.x, 10-actor.pos.y, 50, 50))
	screen.blit(text_clock, [20, 20])
	screen.blit(text_pos, [20, 40])
	screen.blit(text_velocity, [20, 60])
	screen.blit(text_stat, [20, 80])
	pygame.display.update()

	# イベント処理
	for event in pygame.event.get():
	  if event.type == QUIT:
		pygame.quit()
		sys.exit()

if __name__ == "__main__":
    main()
