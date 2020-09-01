

// g++ sample.cpp -std=c++11

#include<iostream>
#include<deque>
using namespace std;

void maxSlidingWindow(int arr[], int n, int k)
{
	deque<int> q;
	// we need to do the task for the 1st k element
	for(int i=0; i<k; i++)
	{   // if value at the back is smaller than my value or not
		while(!q.empty() && arr[q.back()]<= arr[i])
		{	
			q.pop_back();

		}
		// once this work is done
		// either this stack is empty 
		// or work has to be done
		q.push_back(i);
	}
	// Once the max k sized for the 1stelement has been done
    // we need to do work for the next k sized elements
	
	// max value at the front of the deck
	for(int i=k; i<n; i++)
	{
		cout << arr[q.front()] << " ";
		if(!q.empty() && q.front()<=i-k)
		{
			q.pop_front();
		}
		// when you insert the values you need to check for the 
        // same conditions
		while(!q.empty() && arr[q.back()]<=arr[i])
		{
			q.pop_back();
		} 
		q.push_back(i);
	}
	// printing out the value for the ;ast index case 
	// once the code is complete
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
