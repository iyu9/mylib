# -*- coding:utf-8 -*-

import pygame
from pygame.locals import *

import sys
import time

g = 9.8

UP	  = 0
RIGHT = 1
DOWN  = 2
LEFT  = 3

FIXED = 0
FALL = 1
JUMP = 2

class Vector2:
  def __init__(self):
	self.x = 0
	self.y = 0

class Actor:

  def __init__(self):
	self.id = 0
	self.name = "tommy"
	self.v = Vector2()
	self.pos = Vector2()
	self.hp = 10
	self.stat = 0
	self.v_start_time = 0

  def update(self):
	if self.v.y > 0:
	  self.pos.y += self.v.y

  def jump(self):
	if stat==FIXED:
	  self.stat=JUMP
	  self.v.y=10


  def falldown(self):
	if self.pos.y>-100:
	  self.pos.y-=0.1

actor = Actor()

def main():
  pygame.init()
  screen = pygame.display.set_mode((400, 400))
  pygame.display.set_caption("Hello Pygame")
  font = pygame.font.Font(None, 25)
  #bg = pygame.image.load("bg.png").convert_alpha()
  #rect_bg = bg.get_rect()

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
	if pressed_key[K_x]:
	  print "press x"

	#物理演算
	actor.falldown()


	#グラフィック処理
	screen.fill((0,0,0))
	text_clock = font.render("clock: " + str(time.clock()), True, (255,255,255))
	text_pos = font.render("pos: " + str(actor.pos.x) + ", " + str(actor.pos.y), True, (255,255,255))

	#screen.blit(bg, rect_bg)
	pygame.draw.rect(screen, (0,80,0), Rect(10+actor.pos.x, 10-actor.pos.y, 50, 50))
	screen.blit(text_clock, [20, 20])
	screen.blit(text_pos, [20, 40])
	pygame.display.update()

	# イベント処理
	for event in pygame.event.get():
	  if event.type == QUIT:
		pygame.quit()
		sys.exit()

if __name__ == "__main__":
    main()
