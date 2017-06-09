#!/usr/bin/python
# -*- coding:utf-8 -*-
import socket

host = "153.126.153.59"
port = 11451

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((host, port))
while True:
  client.send("client sendmessage")
  response = client.recv(4096)
  print response
