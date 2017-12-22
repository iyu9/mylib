import cocos
import pyglet

class HelloWorld(cocos.layer.Layer):

  is_event_handler = True

  def __init__(self):
	super(HelloWorld, self).__init__()

	# sprite
	image = cocos.sprite.Sprite('gakuenmap.jpg', scale=2)
	image.position = 0,0
	self.add(image)

	image = cocos.sprite.Sprite('santa.png')
	image.position = 100,100
	self.add(image)

	self.pos_x = 0
	self.pos_y = 0

	# label
	label = cocos.text.Label(
	  'Title Your Name',
	  font_name='Times New Roman',
	  font_size=32,
	  anchor_x='center',
	  anchor_y='center'
	)

	label.position = 320,240
	self.add(label)

	# key event
	self.text = cocos.text.Label("Input:", x=20, y=460)
	self.keys_pressed = set()
	self.update_text()
	self.add(self.text)

  def update_text(self):
	key_names = [pyglet.window.key.symbol_string(k) for k in self.keys_pressed]
	text = 'keys: ' + ','.join(key_names)
	self.text.element.text = text

	# if 'RIGHT' in key_names:
	# if 'LEFT' in key_names:
	# if 'UP' in key_names:
	# if 'DOWN' in key_names:

	self.text.position = self.pos_x, self.pos_y

  def on_key_press(self, key, modifiers):
	self.keys_pressed.add(key)
	self.update_text()

  def on_key_release(self, key, modifiers):
	self.keys_pressed.discard(key)
	self.update_text()

if __name__ == '__main__':
  cocos.director.director.init()
  hello_layer = HelloWorld()
  main_scene = cocos.scene.Scene(hello_layer)
  cocos.director.director.run(main_scene)
