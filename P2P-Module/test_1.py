#!/usr/bin/python
#######################################NUM7
def factorial(n):
	if n is 1: return 1
	else: return factorial(n-1) * n
print factorial(4)
print "The next program..."
#######################################NUM7
def func(param): print param + ex
ex = 'b'
print func('a')
print "The next program..."
#######################################NUM7
def story(**kwds):
	return 'Once upon a time, there was a %(job)s called %(name)s.			 ' % kwds
def power(x, y, *others):
	if others:
		print 'Received redunment parameters:', others
	return pow(x, y)
def interval(start, stop = None, step = 1):
	'imitate range() for step > 0'
	if stop is None:
		start, stop = 0, start
	print start, stop
	result = []
	i = start
	while i < stop:
		result.append(i)
		i += step
	return result
print story(job='king', name='Gumby')
params = {'job': 'language', 'name': 'Python'}
print story(**params)
params = (5,) * 2
print power(*params)
interval(10)

print "The next program..."
#######################################NUM7
def hello_3(greeting='hello', name='world'):
	print '%s, %s!' % (greeting, name)
hello_3(name='bao', greeting='hello')
print "The next program..."

#######################################NUM7
def init(data):
	data['first'] = {}
	data['middle'] = {}
	data['last'] = {}
def lookup(data, label, name):
	return data[label].get(name)

def store(data, full_name):
	names = full_name.split()#divide full_name
	if len(names) == 2: names.insert(1, '')
	labels = 'first', 'middle', 'last'
	for label, name in zip(labels, names):
		people = lookup(data, label, name)
		if people:
			people.append(full_name)
		else:
			data[label][name] = [full_name]

MyNames = {}
init(MyNames)
store(MyNames, 'Magnus Lie Hetland')
print lookup(MyNames, 'middle', 'Lie')
print "The next program..."

#######################################NUM7
def fibs(num) : 
	'caculate fibnacci array'
	fab = [0, 1]
	for i in range(num) :
		fab.append(fab[-2] + fab[-1])
	return fab
#fibs._doc__
num = input('how many : ')
print fibs(num)
print "The next program..."
#######################################NUM7
fabs = [0, 1]
num = raw_input('enter a num: ')
num = int(num)
#cuan1 = raw_input('string1: ')
#cuan2 = input('string2: ')
for i in range(num):
	fabs.append(fabs[-2] + fabs[-1])
print fabs
#print cuan1
#print cuan2
print "The next program..."

#######################################NUM7
girls = ['alice', 'bernice', 'claric']
boys = ['chris', 'arnold', 'bob']
letterGirls = {}
for girl in girls:
		letterGirls.setdefault(girl[0], []).append(girl)
print [b+'+'+g for b in boys for g in letterGirls[b[0]]]
print "The next program..."

#######################################NUM6
name = ['anne','beth','george','damon']
ages = [12,45,32,102]
for i in range(len(name)):
		print name[i], 'is', ages[i], 'years old'
zip(name, ages)
for nam, age in zip(name, ages):
		print nam, 'is', age, 'years old'

print "The next program..."

#######################################NUM5
name = raw_input('what is your name?')
if name.endswith('Gumby'): 
		print 'Hello, Mr.Gumby.'

print "The next program..."

#######################################NUM4
people = {
				'Alice':{
							'phone': '2341',
							'addr': 'Foo drive 23'
						},
				'Beth': {
							'phone': '9012',
							'addr': 'Bar street 42'
						},
				'Cecil':{
							'phone': '3157',
							'addr': 'Baz avanue 90'
						}
				}

labels = {
				'phone': 'phone number',
				'addr': 'address'
				}
name = raw_input('Name: ')

request = raw_input('phone number(p) or address(a)?')

key = request
if request == 'p': key = 'phone'
if request == 'a': key = 'addr'
person = people.get(name,{})
label = labels.get(key,key)
result = person.get(key,'not available')

print "%s %s is %s." % (name, label, result)

print "The next program..."

#######################################NUM3
people = {
				'Alice':{
							'phone': '2341',
							'addr': 'Foo drive 23'
						},
				'Beth': {
							'phone': '9012',
							'addr': 'Bar street 42'
						},
				'Cecil':{
							'phone': '3157',
							'addr': 'Baz avanue 90'
						}
				}
labels = {
				'phone': 'phone number',
				'addr': 'address'
				}
name = raw_input('Name: ')

request = raw_input('Phone number(p) or adderss(a)?')

if request == 'p': key = 'phone'
if request == 'a': key = 'addr'

if name in people: print "%s's %s is %s." % \
				(name, labels[key], people[name][key])

if request == 'p': key = 'phone'

print "The next program..."

#######################################NUM2
sentence = raw_input("Sentence: ")
screen_width = 80
text_width = len(sentence)
box_width = text_width + 6
left_margin = (screen_width - box_width) // 2

print 
print ' ' * left_margin + '+' + '-' * (box_width-2) + '+'
print ' ' * left_margin + '|' + ' ' * text_width    + '|'
print ' ' * left_margin + '|' +       sentence      + '|'
print ' ' * left_margin + '|' + ' ' * text_width    + '|'
print ' ' * left_margin + '+' + '-' * (box_width-2) + '+'

print "The next program..."

#######################################NUM1
print 'Hello, World!'
name = raw_input("What is your name? ")
print 'Hello,' + name + '!'
raw_input("press <enter>")
