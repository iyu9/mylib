from PIL import Image

img = Image.open('sample.png', 'r')
resize_img = img.resize((100, 100))
resize_img.save('resize_img.png', 'PNG', quality=100, optimize=True)

