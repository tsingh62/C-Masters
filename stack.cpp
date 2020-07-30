#include<iostream>
using namespace std;

// if you want to make it generic for any DS 
template <typename T>

class Stack
{
	int top;
	int maxSize;
	//int *arr; 	
	T *arr;
			
public:
	// parameterized constructor
	Stack(int maxSize)
	{
		// initialize our array in const
		// when new obj is created
		this->maxSize = maxSize;
	//	this->arr= new int[this ->maxSize]; // dynamic array	
		this->arr= new T[this ->maxSize];
		this ->top =-1;
	}
//	void push(int data)
	void push(T data)
	{
		if(this->top == this->maxSize -1)
		{
				cout << "Stack overflow!" << endl;
		}
		this->top++;
		this->arr[this->top] = data;
	}
	void pop()
	{	// this can also be used with functions
		if(this->empty())
		{
			cout << "Stack underflow" << endl;
			return;
		}
		this->top--;
	}
//	int gettop()
	T gettop()
	{
		return this->arr[this->top];
	}
	int size()
	{
		return this->top+1;
	}
	bool empty()
	{
		// if(this->top==-1)
		// {
		// 	return true;
		// }
		// else
		// {
		// 	return false;
		// }
		//or
		return this->top == -1;
		
	}
};

int main()
{	
	// // While using int
//	Stack s(5);

// while usig template
	// Stack<int> s(5);

	// s.push(5);
	// s.push(2);
	// s.push(4);
	// s.push(6);
	// s.push(8);

	// s.push(78); // overflow

	// cout << s.gettop()<< endl; // 8

	// while(!s.empty())
	// {	cout << "Current top is" << s.gettop() << endl;
	// 	s.pop();	
	// 	cout << "Popped" << endl;
	// }
 
	// if(s.empty()) // true
	// {
	// 	cout << "Stack is empty"<< endl;
 	// }
	 
	 // we can also crate a char stack as well
	 Stack <char> s(4);

	 s.push('A');
	 s.push('B');
	 s.push('C');
	 s.push('D');
	 
	 s.push('E');


	while(!s.empty())
	{	cout << "Current top is" << s.gettop() << endl;
		s.pop();	
		cout << "Popped" << endl;
	}
 
	return 0;
}