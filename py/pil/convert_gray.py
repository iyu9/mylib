#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
from PIL import Image

if __name__ == '__main__':
	fileName = sys.argv[1]
	img = Image.open(fileName)
	
	gray_img = img.convert('L')
	gray_img.save('gray_' + fileName)
	gray_img.show()
