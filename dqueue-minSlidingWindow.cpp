

// g++ sample.cpp -std=c++11

#include<iostream>
#include<deque>
using namespace std;

void maxSlidingWindow(int arr[], int n, int k)
{
	deque<int> q;

	for(int i=0; i<k; i++)
	{
		while(!q.empty() && arr[q.back()]<= arr[i])
		{	
			q.pop_back();

		}
		// once this work is done
		// either this stack is empty 
		// or work has to be done
		q.push_back(i);
	}
	// max value at the front of the deck
	for(int i=k; i<n; i++)
	{
		cout << arr[q.front()] << " ";
		if(!q.empty() && q.front()<=i-k)
		{
			q.pop_front();
		}
		while(!q.empty() && arr[q.back()]<=arr[i])
		{
			q.pop_back();
		} 
		q.push_back(i);
	}
	cout << arr[q.front()] << endl;
}

int main()
{
	int arr[]={1,3,2,0,-1,5,2};
	int n=sizeof(arr)/sizeof(int);
	int k=3;
	maxSlidingWindow(arr,n,k);
	return 0;
}
