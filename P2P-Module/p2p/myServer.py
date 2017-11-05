
import socket, sys, SocketServer, threading, thread, time

SERVER_PORT = 1234	#set server port

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
#before bind, call setsockopt, to make socket reuseable
sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
sock.bind(('', SERVER_PORT))

user_list = []		#store user info

def server_handler():
	while True:
		cli_data, cli_pub_addr = sock.recvfrom(8192)
		now_user = []		
		loginfo = []
		cli_str = {}
		loginfo = cli_data.split('#')
		#format: type:login#user_name:XX#
		for info_seg in loginfo:	#between # #
			string = {}
			string = info_seg
			args = string.split(':')
			cli_str[args[0]] = args[1]	#format: type:login
		if cli_str['type'] == 'echo':
			print cli_data
		
		if cli_str['type'] == 'login':
			del cli_str['type']
			now_user = cli_str
			print cli_pub_addr, ' login...'
			now_user['cli_pub_ip']   = cli_pub_addr[0]
			now_user['cli_pub_port'] = cli_pub_addr[1]	#int type
			user_list.append(now_user)
			print '[ user list ]\n', user_list	
			
			toclient = 'info#%s login success!' % now_user['user_name']
			sock.sendto(toclient, cli_pub_addr)	#send to C
			print "****%s already login!" % now_user['user_name']
			print "****Public Network IP: %s Port: %d" % (now_user['cli_pub_ip'], now_user['cli_pub_port'])
		
		elif cli_str['type'] == 'alive':
			print cli_data
			pass
		
		elif cli_str['type'] == 'logout':
			pass

		elif cli_str['type'] == 'getalluser':
			for one_user in range(len(user_list)):
				print 'IP table: \nuser_name:%s#cli_pub_ip:%s#cli_pub_port:%d#private_ip:%s#private_port:%s' % (user_list[one_user]['user_name'], user_list[one_user]['cli_pub_ip'], user_list[one_user]['cli_pub_port'], user_list[one_user]['private_ip'], user_list[one_user]['private_port']) 
				toclient = 'getalluser#user_name:%s#cli_pub_ip:%s#cli_pub_port:%d#private_ip:%s#private_port:%s' % (user_list[one_user]['user_name'], user_list[one_user]['cli_pub_ip'], user_list[one_user]['cli_pub_port'], user_list[one_user]['private_ip'], user_list[one_user]['private_port']) 
				sock.sendto(toclient, cli_pub_addr)

##########################
if __name__ == '__main__':
	thread.start_new_thread(server_handler, ())
	print "Server process has been launched, waitting client connection..."
	time.sleep(1)
	while True:
		try:
			for one_user in range(len(user_list)):
				toclient = 'keepconnect#111'
				sock.sendto(toclient, (user_list[one_user]['cli_pub_ip'], user_list[one_user]['cli_pub_port']))
				print 'Broadcasting... to (%s,%s)' % (user_list[one_user]['cli_pub_ip'], user_list[one_user]['cli_pub_port'])
		except KeyError, e:
			print e
		time.sleep(10)
