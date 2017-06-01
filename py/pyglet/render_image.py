import pyglet

pos_x = 0
pos_y = 0

# for Initializeing
window = pyglet.window.Window()
image  = pyglet.image.load('../cocos2d/sample.png')
sprite = pyglet.sprite.Sprite(image)

@window.event
def on_draw():
  image.blit(pos_x, pos_y)
  # sprite.draw()

@window.event
def on_key_press(symbol, modifiers):
  global pos_x
  pos_x += 10

@window.event
def on_key_release(symbol, modifiers):
  global pos_y
  pos_y += 10

pyglet.app.run()
