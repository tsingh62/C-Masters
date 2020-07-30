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

		if(ch != ')')
		{
			s.push(ch);
		}
		else
		{
			if(s.top()=='(')
			{
				return true;
			}
			while(s.top()!='(')
			{
				s.pop();
			}
			s.pop();

		}
		
	}

	return false; 

}




int main()
{	
	


	
	cout << isBalanced("((a+b))") << endl; // true
	cout << isBalanced("(a+b") << endl; //true
	 cout << isBalanced("(a+b)+c") << endl; // false
	// cout << isBalanced("()") << endl; // true

	return 0;
}