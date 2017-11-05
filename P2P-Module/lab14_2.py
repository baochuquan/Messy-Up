#!/usr/bin/python

import socket

s = socket.socket()

host = '192.168.1.159'
port = 1234

print host, port

s.connect((host, port))
print s.recv(1024)
