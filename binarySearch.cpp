#include<iostream>
using namespace std;

int binarySerach(int arr[], int n, int key)
{
    int start=0;
    int end=n-1;

    while (start<=end)
    {
       int mid = start + (end - start) / 2;

        if(arr[mid]==key)
        {
            return mid;
        }
        else if(arr[mid]>key)
        {
            end = mid-1;
        }
        else 
        {
            start = mid+1;
        }
        
    }
    // in my search space no element was found so return -1
    // no element was found so return -1
    return -1;
}
int main()
{
    int arr[] = {12, 23, 31, 45, 57, 69, 73, 82};
	int n = 8;
	int key = 31;
    cout << binarySerach(arr, n, key) << endl;
    return 0;
}