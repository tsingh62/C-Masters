#include<iostream>
#include<stack>
using namespace std;

//**********************//
// Stock span //

// Inbuilt stack has the same functionalities 
// as the one defined by us

void  stockSpan(int arr[], int n)
{
	// while usig template
// in-buit stack is always a template type
	stack <int> s;
	for(int i=0; i<n; i++)
	{							// value of the index
		while(!s.empty() && arr[s.top()]<arr[i])
		{						// value of index
								// we can also access the value and index
			// value at top is smaller than me pop it
			s.pop();
			// find the no of days
			// between your day and the best possible day
			int days;
			if(!s.empty())
			{
			days = i-s.top(); 
			}
			else
			{
				days = i+1;
			}
			cout <<  arr[i] << "->" << days;
			// psuh my index
			s.push(i);
			
			
		}
		
	}
}

int main()
{	
	int arr[]={100,80,60,70,60,75};
	int n=6;

	stockSpan(arr,n);
	return 0;
}