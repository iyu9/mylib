import pyglet

pos_x = 0
pos_y = 0

# for Initializeing
window = pyglet.window.Window()
image  = pyglet.image.load('../cocos2d/sample.png')
sprite = pyglet.sprite.Sprite(image)

@window.event
def on_draw():
  image.blit(x, y)
  # sprite.draw()

@window.event
def on_key_press(symbol, modifiers):
  pos_x += 1
  pass

@window.event
def on_key_release(symbol, modifiers):
  pos_y += 1
  pass

pyglet.app.run()
