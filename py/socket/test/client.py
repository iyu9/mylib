#!/usr/bin/python
# -*- coding:utf-8 -*-
import socket

host = "localhost"
port = 11451

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((host, port))
client.send("client sendmessage")
response = client.recv(4096)

print response
