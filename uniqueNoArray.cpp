


#include<iostream>
using namespace std;

int main()
{
    int arr[]={1,2,4,2,3,1,4};
    int n = sizeof(arr)/sizeof(int);
    int val=0;
    for(int i=0; i<n; i++)
    {
        val=val^arr[i];
    }
    cout << val << endl;
    
}