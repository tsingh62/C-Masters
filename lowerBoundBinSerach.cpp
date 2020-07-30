#include<iostream>
using namespace std;
// array duplicates - return lower bound
int aDuplicates(int arr[], int n, int key)
{
    int start=0;
    int end=n-1;

    int ans =-1;
    while(start<end)
    {
        int mid = (start+end)/2;
        if(arr[mid]==key)
        {
          ans=mid;
          // for upper bound
        //  start=mid+1;
          // for lower bound 
         end = mid-1;
         
        }
         else if(arr[mid]>key)
        {
            end = mid-1;
        }
        else
        {
            start=mid+1;
        }
        
    }
    return ans;
}
int main()
{
    int arr[] = {11,11,12,12,12,12,12,14,14};
    int n= sizeof(arr)/sizeof(int);
    int key =12;
    cout << aDuplicates(arr,n,key) << endl;
    return 0;
}