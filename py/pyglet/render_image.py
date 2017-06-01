import pyglet

window = pyglet.window.Window()
image = pyglet.image.load('..\cocos2d\sample.png')
sprite = pyglet.sprite.Sprite(image)

@window.event
def on_draw():
  sprite.draw()

pyglet.app.run()
