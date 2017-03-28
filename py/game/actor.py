class Actor:

  def __init__(self):
	self.id = 1
	self.name = "hoge"
	self.hp = 10
	self.atk = 2
	self.defence = 1

	self.x = self.y = 0
	self.stat = 0
	self.is_dead = 0

  def Log(self):
	print(str(self.id) + ", " + self.name)

  def Attack(self, opt):
	opt.hp -= self.atk - opt.defence
	print("optHP: " + str(opt.hp))

  def Move(self, x_, y_):
	self.x = x_
	self.y = y_

player = Actor()
enemy = Actor()
player.Attack(enemy)
