
import socket, SocketServer, threading, thread, time

CLIENT_PORT = 4321
SERVER_IP = '127.0.0.1'
SERVER_PORT = 1234

user_list = {}

local_ip = socket.gethostbyname(socket.gethostname())
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
sock.bind(('', CLIENT_PORT))

print 'local_ip:   ', local_ip
print 'local_port: ', CLIENT_PORT 

def server_handle():
	print 'Client thread has launched, waitting for other client connection'
	while True:
		data, addr = sock.recvfrom(8192)
		data_str   = data.split('#')
		data_type  = data_str[0]
		data_info  = data_str[1:]
		if data_type == 'info':
			del data_str[0]
		elif data_type == 'getalluser':
			data_sp = data_info
			user_name = data_sp[0].split(':')[1]
			del data_sp[0]
			
			user_list[user_name] = {}
			for one_line in data_sp:
				arg = one_line.split(':')
				user_list[user_name][arg[0]] = arg[1]
			print 'user_list == ', user_list
		elif data_type == 'type:echo':
			print data_info
		elif data_type == 'keepconnect':
			msg = 'type:alive'
			sock.sendto(msg, addr)

if __name__ == '__main__':
	thread.start_new_thread(server_handle, ())
	time.sleep(0.1)
	to_user_name = ' ' 
	to_user_ip   = ' '
	to_user_port = 0
	cmd = raw_input('Input command(format:xxx#xxx): ')	#format: login#bao / getalluser	/ connect#bao / echo$fasdfadfas
	while True:
		args = cmd.split('#')
		if args[0] == 'login':
			user_name  = args[1]
			local_name = args[1] 
			#address = "private_ip:%s private_port:%d" % (local_ip, CLIENT_PORT)
			loginfo = "type:login#user_name:%s#private_ip:%s#private_port:%d" % (user_name, local_ip, CLIENT_PORT)
			sock.sendto(loginfo, (SERVER_IP, SERVER_PORT))

		elif args[0] == 'getalluser':
			loginfo = "type:getalluser#blabla:asd"
			sock.sendto(loginfo, (SERVER_IP, SERVER_PORT))
			print 'Collecting all users list...'
			time.sleep(5)		#waitting thread gain IP info
			for one_user in user_list:
				print 'user_name:%s cli_pub_ip:%s cli_pub_port:%s private_ip:%s private_port:%s' % (one_user, user_list[one_user]['cli_pub_ip'], user_list[one_user]['cli_pub_port'], user_list[one_user]['private_ip'], user_list[one_user]['private_port'])

		elif args[0] == 'connect':	#format: connect#zhang
			user_name    = args[1]
			to_user_name = user_name
			to_user_ip   = user_list[user_name]['cli_pub_ip']
			to_user_port = int(user_list[user_name]['cli_pub_port'])

		elif args[0] == 'echo':
			m = ''.join(args[1:])
			Smsg = 'type:echo#From %s: %s' % (local_name, m)
			print 'to_user_name ==== ', to_user_name
			print 'to_user_ip   ==== ', to_user_ip
			print 'to_user_port ==== ', to_user_port
			sock.sendto(Smsg, (to_user_ip, to_user_port))
			sock.sendto(Smsg, (SERVER_IP, SERVER_PORT))
		time.sleep(0.1)
		cmd = raw_input('Input command(format:xxx#xxx): ')

			
