#include<iostream>
#include<stack>
using namespace std;

///**********************///
// Return if a string is balanced 

// inbuilt stack has the same functionalities 
// as the one defined by us

void  printNextGreater(int arr[], int n)
{
	// while usig template
// in-buit stack is always a template type
	stack <int> s;
	for(int i=0; i<n; i++)
	{
		while(!s.empty() && s.top()<arr[i])
		{				// value present at the top is less than 
						// my value
			// get that value	
			// remove that value
			int val = s.top();
			s.pop();
			// print that value
			cout << val << "->" << arr[i] << endl;
		}
		// once my work is done 
		// then just add me to the stack
		s.push(arr[i]);
	}
	while(!s.empty())
	{
		int val = s.top();
		s.pop();
		cout << val << "-> -1" << endl;
	}
}

int main()
{	
	int arr[]={54,5,3,6,2,10,14};
	int n=7;

	printNextGreater(arr,n);
	return 0;
}