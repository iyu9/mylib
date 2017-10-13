#!/usr/bin/python
#-*- coding:utf-8 -*-

from pyquery import PyQuery
from lxml import etree
import urllib

# scraping
doc = PyQuery(url='http://google.com/')
print doc("p:first")
