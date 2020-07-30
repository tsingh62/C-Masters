#include<iostream>
using namespace std;

int main()
{
    // bubble sort 
    int arr[] = {2,1,5,4,8};
    int n=5;
    int counter = 1;
    // counter for logic
    // n-1. n-2. n-3 and so on
    while(counter < n)
    {
        for(int i=0; i<n-counter; i++)
        {
            if(arr[i]>arr[i+1])
            {
                swap(arr[i], arr[i+1]);
            }
        }
        counter++;
    }
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}