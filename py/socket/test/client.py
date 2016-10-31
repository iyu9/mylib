# -*- coding:utf-8 -*-
import socket

host = "localhost" #お使いのサーバーのホスト名を入れます
port = 11451 #適当なPORTを指定してあげます

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM) #オブジェクトの作成をします

client.connect((host, port)) #これでサーバーに接続します

client.send("from tom") #適当なデータを送信します届く側にわかるように

response = client.recv(4096) #レシーブは適当な2進数にします大きすぎるとダメ

print response
