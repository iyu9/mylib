# -*- coding:utf-8 -*-
import pygame
from pygame.locals import *
import sys


def main():
  pygame.init()                                   # Pygameの初期化
  screen = pygame.display.set_mode((400, 300))    # 大きさ400*300の画面を生成
  pygame.display.set_caption("Test")              # タイトルバーに表示する文字
  font = pygame.font.Font(None, 55)
  bg = pygame.image.load("bg.png").convert_alpha()
  rect_bg = bg.get_rect()

  while (1):
	screen.fill((0,0,0))        # 画面を黒色(#000000)に塗りつぶし
	text = font.render("TEST", True, (255,255,255))
	screen.blit(bg, rect_bg)
	screen.blit(text, [20,100])
	pygame.display.update()     # 画面を更新

	# イベント処理
	for event in pygame.event.get():
	  if event.type == QUIT:  # 閉じるボタンが押されたら終了
		pygame.quit()       # Pygameの終了(画面閉じられる)
		sys.exit()

if __name__ == "__main__":
    main()
