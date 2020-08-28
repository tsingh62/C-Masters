#include<iostream>
#include<stack>
using namespace std;

///**********************///
// Return if a string is balanced 

// inbuilt stack has the same functionalities 
// as the one defined by us

bool isBalanced(string str)
{
	// while usig template
// in-buit stack is always a template type
	stack <char> s;
	for(int i=0; i<str.length(); i++)
	{
		char ch = str[i];

		if(ch == '(')
		{
			s.push(ch);
		}
		else
		{
			if(s.empty())
			{
				return false;
			}
			s.pop();

		}
		
	}

	return s.empty(); // if stack is not empty return false
						// else it will return true.

}




int main()
{	
	
	cout << isBalanced("((()))(") << endl; // false
	cout << isBalanced("(())()") << endl; //true
	cout << isBalanced("((())") << endl; // false
	cout << isBalanced("()()()()") << endl; // true

	return 0;
}