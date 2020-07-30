#include<iostream>
#include<stack>
using namespace std;

// inbuilt stack has the same functionalities 
// as the one defined by us

int main()
{	
	// // While using int
//	Stack s(5);

// while usig template
// in-buit stack is always a template type
	stack<int> s;

	s.push(5);
	s.push(2);
	s.push(4);
	s.push(6);
	s.push(8);

	s.push(78); 

	cout << s.top()<< endl; // 
	cout << "Size of the stack is " << s.size() << endl;

	while(!s.empty())
	{	cout << "Current top is" << s.top() << endl;
		s.pop();	
		cout << "Popped" << endl;
	}
 
	if(s.empty()) // true
	{
		cout << "Stack is empty"<< endl;
 	}
	 
	
	return 0;
}