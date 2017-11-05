#!/usr/bin/python

import socket

s = socket.socket()

host = '192.168.1.159'
port = 1234
s.bind((host, port))

print host, port
IPtable = [(host, port)]

s.listen(5)
while True:
	c, addr = s.accept()
	IPtable.append(addr)
	print 'c', c
	print addr
	print 'Got connection from', addr
	c.send('Thank you for connecting: ')
	c.send(IPtable)
	c.close()
