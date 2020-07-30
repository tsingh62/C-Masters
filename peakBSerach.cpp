#include<iostream>
using namespace std;


    int peak(int arr[], int start, int end, int n)
    {
       
        // base case
        if(start>end)
        {
            return -1;
        }

        // rec
        int mid=(start+end)/2;

        if((mid==0 || arr[mid-1]<arr[mid]) && (mid==n-1 || arr[mid]>arr[mid+1]))
        return mid;

        if(arr[mid]<arr[mid+1])
        {
            return peak(arr, mid+1, end, n);
        }
        else
        {
            return peak(arr, start, end-1, n);
        }
        
    }

int main()
{
    int arr[]={1,2,1,3,7,6,4};
    int n=sizeof(arr)/sizeof(int);
    int start = 1;
    int end = n-1;
    
    // this would return the index value
    cout << peak(arr,start, end, n) << endl;
    return 0;

}