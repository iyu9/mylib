import pyglet

x = 0
y = 0

# for Initializeing
window = pyglet.window.Window()
image  = pyglet.image.load('../cocos2d/sample.png')
sprite = pyglet.sprite.Sprite(image)

@window.event
def on_draw():
  image.blit(x, y)
  # sprite.draw()

@window.event
def on_key_press():
  x+=1
  pass

@window.event
def on_key_release():
  pass

pyglet.app.run()
