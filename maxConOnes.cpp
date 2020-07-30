
#include<iostream>
using namespace std;

int longestSum(int arr[], int n, int k)
{
    int left =0;
    int right =0;
    int utilize =0;
    int maxLen = 0;

    while(right < n)
    {
        if(arr[right]==0)
        {
            utilize++;
        }
       while(utilize > k)
       {
           if(arr[left]==0)
           {
               utilize--;
           }
            left++;
           
       }
       int len = right -left+1;
       if(len>maxLen)
       {
           maxLen=len;
       }
        right++;
    }
    return maxLen;
}

int main()
{
    int arr[] = {0,1,1,1,0,0,1,1,1,1,0,0,1,1,1};
    int n = sizeof(arr)/sizeof(int);
    int k=2;
    cout << longestSum(arr,n,k) << endl;
    return 0; 

}