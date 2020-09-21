// rotated array
#include<iostream>
using namespace std;

int func(int arr[], int start, int end, int target)
{

    if(start>end)
    {
        return -1;
    }


    int mid = start+(end-start)/2;

    if(arr[mid]==target)
    {
        return mid;
    }

    if(arr[mid]>=arr[start])
    {
        if(target>=arr[start]&& target< arr[mid])
        {
            return func(arr, start, mid, target);
        }
        else
        {
            return func(arr, mid+1, end,target);
        }
        
    }
    else
    {
        if(target> arr[mid] && target <=arr[end])
        {
            return func(arr, mid+1, end, target);
        }
        else
        {
            return func(arr, start, mid, target);
        }
        
    }
    
}
int main()
{
    int arr[]={4,5,6,7,01,2,3};
    int n = sizeof(arr)/sizeof(int);
    int target = 0;
    cout << func(arr, 0, n-1, target) << endl;
    return 0;
}