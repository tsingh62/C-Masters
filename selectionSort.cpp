#include<iostream>
using namespace std;

int main()
{
    int arr[] = {5,4,1,2,3};
    int n= 5;
    int minIndex=0;

    // min index less than last value
    while(minIndex< n-1)
    {   
        int minVal = arr[minIndex];
        int replaceIdx = minIndex;        
    
    for(int i=minIndex+1; i<n; i++)
    {
        if(arr[i] < minVal)
        {
            replaceIdx=i; // store the index
            minVal =arr[i];
        }
    }
     swap(arr[minIndex], arr[replaceIdx]);
     minIndex++;
    }
    // print array after sorting 
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
   
}