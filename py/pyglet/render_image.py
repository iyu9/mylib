#!/usr/bin/python
# -*- coding utf-8

import pyglet

x = 0
y = 0

# for Initializeing
window = pyglet.window.Window()
image  = pyglet.image.load('../cocos2d/sample.png')
sprite = pyglet.sprite.Sprite(image)

@window.event
def on_draw():
  window.clear()
  image.blit(x, y)

@window.event
def on_key_press(symbol, modifiers):
  global x
  x += 10

@window.event
def on_key_release(symbol, modifiers):
  global y
  y += 10

pyglet.app.run()
