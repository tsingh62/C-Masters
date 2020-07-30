#include<iostream>
using namespace std;



bool isPossible(int board[], int n, int painters, int ptime)
{
    int countPainters =1;
    int painterTime =0;
    for(int i=0; i<n; i++)
    {
        painterTime +=board[i];

        if(painterTime > ptime)
        {
            countPainters++;

            painterTime = board[i];

            if(countPainters > painters)
            {
                return false;
            }

        }
    }
    return true;
}

int paintProb(int arr[], int n, int painter, int ptime)
{
    int mintime = INT_MIN;
    int maxtime =0;

    for(int i=0; i<n; i++)
    {
        maxtime += arr[i];
        mintime=(max (arr[i], mintime));
    }

    int start = mintime;
    int end = maxtime;
    
    int ans = maxtime;
 

    while(start < end)
    {
        int mid = (start+end)/2;

        if(isPossible(arr,n,painter,mid))
        {
            ans=mid;
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }
        
    }
    return ans;
}
int main()
{
    int arr[] ={10,20,30,40};
    int n = sizeof(arr)/sizeof(int);
    int painters=2;
    //int ptime=;
    cout << paintProb(arr, n, painters, 1) << endl;
    return 0;
}