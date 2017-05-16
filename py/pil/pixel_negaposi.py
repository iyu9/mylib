#coding:utf-8
from PIL import Image

#画像の読み込み
im = Image.open("./achan.jpg")

#RGBに変換
rgb_im = im.convert('RGB')

#画像サイズを取得
size = rgb_im.size

#取得したサイズと同じ空のイメージを新規に作成
im2 = Image.new('RGBA',size)

#loop
#x
for x in range(size[0]):
    #y
    for y in range(size[1]):
        #ピクセルを取得
        r,g,b = rgb_im.getpixel((x,y))

        #反転処理
        r = 255 - r
        g = 255 - g
        b = 255 - b

        #set pixel
        im2.putpixel((x,y),(r,g,b,0))

#show
im2.show()
