
from SocketServer import TCPServer, ForkingMixIn, StreamRequestHandler

class Server(ForkingMixIn, TCPServer):
	pass

class Handler(StreamRequestHandler):
	def handle(self):
		addr = self.request.getpeername()
		print 'Got connection from ', addr
		self.wfile.write('Thank you for connecting')

if __name__ == '__main__':
	server = Server(('', 1234), Handler)
	server.serve_forever()
