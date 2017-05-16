#coding:utf-8
from PIL import Image


img = Image.open("./sample.png")
rgb_img = img.convert('RGB')
size = rgb_img.size
convert_img = Image.new('RGBA', size)

for x in range(size[0]):
    for y in range(size[1]):
        r,g,b = rgb_img.getpixel((x,y))

        r = 255 - r
        g = 255 - g
        b = 255 - b

        convert_img.putpixel((x,y), (r,g,b,0))

convert_img.show()
