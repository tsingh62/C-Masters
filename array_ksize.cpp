#include<iostream>
using namespace std;
#include<deque>

void maxSlidingWindown(int arr[], int n, int k)
{
    deque<int> q;
    // 1st k sized window
    for(int i=0; i<k; i++)
    {
       while(!q.empty() && arr[q.back()]<=arr[i]) 
       //value at the back is smaller than my value or not
       {
           // in that case pop_back my value
           q.pop_back();
           // do this until the value is greater or you deque is empty
       }
       // after this work is done - either the stack is empty
       // or the max value is found push_back your index
       q.push_back(i);
    // Now the max value is in the front of the deque
    }
    // Now the max value is in the front of the deque
    for(int i=k; i<n; i++)
    {
        cout << arr[q.front()] << " ";
        // this is the maximum value at the front of the deque

        if(!q.empty() && q.front()<=i-k)
        // if the front value of the queue is 
        // in the range (if the front value is less than the
        // 4 th index value (if k size is 3) then pop the value)
        {
            q.pop_front();
        }
        while(!q.empty() && arr[q.back()]<arr[i])
        {
            q.pop_front();
        }
        q.push_back(i);
    }
    cout << arr[q.front()] << endl;
}

int main()
{
    int arr[]= {1,2,3,0,4,5,2};
    int n = sizeof(arr)/sizeof(int);
    int k =3;
    maxSlidingWindown(arr, n, k);
}