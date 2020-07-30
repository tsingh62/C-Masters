
#include<iostream>
using namespace std;

int minSubArray(int arr[], int s, int n)
{
    int left =0;
    int right =0;
    int minLen=INT_MAX;
    int sum=0;

    while(right<n)
    {
        sum = sum+arr[right];

        if(sum>=s)
        {
            int len = right-len+1;
            if(len < minLen)
            {
                minLen=len;
            }

            sum = sum-arr[left];
            left++;
        }
        right++;
    }
    if(minLen==INT_MAX)
    {
        return 0;
    }

    cout << endl;
    return minLen;
}


int main()
{
    int arr[]={2,3,1,2,4};
    int n = sizeof(arr)/sizeof(int);
    int s=7;
    cout << minSubArray(arr,n,s);
    return 0;
}