#include<iostream>
using namespace std;

int func(int arr[], int n, int m)
{
    sort(arr, arr+n);
    int minDiff = INT_MAX;
    // move the array with m size 
    for(int i=0; i+m-1<n; i++)
    {
        // difference bewteen the max chocolate and minim is minimum
        int diff = arr[i+m-1] - arr[i];
                  // max value  - min value  
        if(diff < minDiff)
        {
            minDiff = diff;
        }
    }
    return minDiff;
}
int main()
{
    int arr[] = {7,3,2,4,9,12,56};
    int n = sizeof(arr)/sizeof(int);
    int m = 3;
    cout << func(arr, n, m) << endl;// ans = 2
}