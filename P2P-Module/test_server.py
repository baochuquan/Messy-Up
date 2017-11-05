#!/usr/bin/python

import sys
import time
import socket

def main(port):
  s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
  s.bind(('', port))
  try:
    while True:
      data, addr = s.recvfrom(4096)
      back = 'Your address is %r\n' % (addr,)
      s.sendto(back.encode(), addr)
      print (time.strftime('%Y-%m-%d %H:%M:%S'), addr, 'just sent us a message:', data.decode('utf-8', 'replace'), end='')
  except KeyboardInterrupt:
    print()

if __name__ == '__main__':
  try:
    main(int(sys.argv[1]))
  except (ValueError, IndexError):
    sys.exit('which port to listen?')
