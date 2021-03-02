
#include<iostream>
using namespace std;

int minLenSumSubArray(int arr[], int n, int s)
{
    int left =0;
    // the movement of left pointer is 
    // conditional
    int right =0;
    // the right pointer will increment 
    // all the time
    int minLen=INT_MAX;
    int sum=0;

    while(right < n)
    {
        sum = sum+arr[right];
        while(sum > s)
        {
            int len = right - left + 1;
            if(len < minLen)
            {
                minLen = len;
            }
            sum = sum-arr[left];
            left++;
        }
       right++;
    }
    if(minLen == INT_MAX)
    return 0;

    return minLen;
    
}
int main()
{
    int arr [] ={1, 4, 45, 6, 0, 19};
    int n = sizeof(arr)/sizeof(int);
    int s = 51;
    cout << minLenSumSubArray(arr, n, s) << endl;
}