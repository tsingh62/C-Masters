#include<iostream>
using namespace std;

int check1=0;
int fib(int n)
{
    check1++;
    if(n==0 || n==1)
    {
        return n;
    }
    int ans = fib(n-1) + fib(n-2);
    return ans;
}

int check2=0;
int fibMemo(int n, int dp[])
{   
    check2++;
    if(n==0 or n==1)
    {
         // store the value of dp for the base case as well
        dp[n] = n;
        return n;
    }
    // if you have already computed 
    // the nth value in ur dp
    if(dp[n] !=-1)
    {
        // if it is not containing -1 
        // we will fill it with dp[n]
        return dp[n];
    }
    // if it is containing -1 we wiil
    // recursively fill it -- before returing ---
    int ans = fibMemo(n-1, dp) + fibMemo(n-2, dp);
    // -- before returning 
    // store the ans in the dp array
    dp[n] = ans;

    return ans;
} 
int check3=0;
int fibPureDP(int n)
{
   
    // in dp - fib(n) is stored in dp[n]
    // in worst case n=5 and its ranging from n=0
    // we want the value of n as the indexed value
    // thats why we have created a size of n+1
    int dp[n+1]; // n+1 cause we want the ans to be
                // stored in dp[n]

    // base case
    dp[0] =0; // dp of 0 wil contain 0
    dp[1] =1; // dp of 1 wil contain 1


    for(int i=2; i<=n; i++)
    {
        check3++;
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}
int main()
{
    int n =10;
    cout << fib(n) << endl;

    // because  n is 10 - so we when we create n+1 (11)
    // that means we can easily fit an array of 
    // size 10 
    int dp[n+1];
    // if my array size is 0 to 5
    // we need to take n+1 as the size of the dp
    memset(dp, -1, sizeof(dp));
    // fill your whole dp array with -1
    
    cout << fibMemo(n, dp) << endl;

    cout << fibPureDP(n) << endl;

    cout << "Number of function call for fib : " << check1 << endl;
    cout << "Number of function call for fibMemo : " << check2 << endl;
    cout << "Number of function call for fibPureDP :  " << check3 << endl;

    return 0;
}