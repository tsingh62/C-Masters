
// Queue

// fifo
// opposite of stack

// push is from back
// pop is from front

#include<iostream>
#include<list>
using namespace std;

class Queue
{
	// double linked list
	list<int> storage;
	// list does not require a size you can just input 
	// value unlike arrays

	public:
	// push is from back
	void push(int data)
	{
		this->storage.push_front(data);
	}
	void pop()
	// pop is from front
	{
		this->storage.pop_front();
	}

	int getfront()
	{
		this->storage.front();
	}
	int size()
	{
		return this->storage.size();
	}
	int empty()
	{
		return this->storage.empty();
	}

};

int main()
{
	Queue q;

	q.push(2);
	q.push(5);
	q.push(16);
	q.push(8);
	q.push(45);

	cout << "Front is having value" << q.getfront() << endl;

	q.pop();
	q.pop();

	cout << "Front value" << q.getfront() << endl;

	cout << "************** Loop **********" << endl;
	while(!q.empty())
	{
		cout << q.getfront() << endl;
		q.pop();
	}
	return 0;
}
