#include "queue.h"
#include <cstdlib>

Queue::Queue(int qs):qsize (qs)
{
	front = rear = NULL;
	items = 0;
}

Queue::~Queue()
{
	Node * temp;
	while(front != NULL)\
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}

bool Queue::isempty()const
{
	return items == 0;
}
bool Queue::isfull()const
{
	return items == qsize;
}

int Queue::queuecount()const
{
	return items;
}

bool Queue::enqueue(const Item & item)
{
	if(isfull())
		return false;
	Node * add = new Node;
	if(add == NULL)
		return false;
	add->item = item;

}
