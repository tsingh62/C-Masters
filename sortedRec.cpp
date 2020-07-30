// check if an array is sorted with recurssion
#include<iostream>
using namespace std;

bool isSorted(int arr[], int n)
{
    // base case
    if(n==1||n==0)
    {
        return true;
    }
    // rec
    if(arr[0]<arr[1] && isSorted(arr+1, n-1))
    {
        return true;
    }
    return false;
}

int main()
{
    //int arr[]={2,3,1,4,5};
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(int);
    cout << isSorted(arr,n) << endl;;
    return 0;
}