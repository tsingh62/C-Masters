#include<iostream>
using namespace std;

int lis(int arr[], int n)
{
    int *lis, i, j, maxLen = 0;
    lis = (int *) malloc (sizeof(int) *n);

    // Initialize LIS value for all indexes
    for(i=0; i<n; i++)
    {
        lis[i] = 1;
    }
    // compute optimisex LIS vales in bottom up manner
    for(i=1; i<n; i++)
    {
        for(j = 0; j<n; j++)
        {
            if(arr[i] > arr[j] && lis[i] < lis[j]+1)
            lis[i] = lis[j]+1;
        }
    }
    // pick max of all lis values
    for(int i=0; i<n; i++)
    {
        if( maxLen < lis[i])
        maxLen = lis[i];
    }
    // free memory to avoid memory leak
    free(lis);

    return maxLen;
}

int main()
{
    int n;
    cin >>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    cout << lis(arr, n) << endl;
    return 0;
}