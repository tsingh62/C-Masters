
// next smaller
// stack

#include<iostream>
#include<stack>
using namespace std;


void nextSmaller(int arr[], int n)
{
	int ans[n];
	stack<int> s;

	for(int i=0; i<n; i++)
	{
		while(!s.empty() && arr[s.top()>arr[i]])
		{
			int idx = s.top();
			s.pop();

			// assigning my value as
			// next smaller  to the 
			// index of current element
			ans[idx] = arr[i]; 
		}
		s.push(i);
	}
	while(!s.empty())
	{	
		int idx = s.top();
		s.pop();

		ans[idx]=-1;
	}

	for(int i=0; i<n; i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
}
int main()
{
	 int arr[]={2,3,1,4,6,5,0};
	 int n = sizeof(arr)/sizeof(int);

	 nextSmaller(arr, n);
	 
}