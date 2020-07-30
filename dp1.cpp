
// Dynamic Programming
// g++ sample.cpp -std=c++11

#include<iostream>
using namespace std;
int check1 =0;

int fib(int n)
{	
	check1++;
	if(n==0 || n==1)
	{
		return n;
	}

	int fib1= fib(n-1);
	int fib2= fib(n-2);

	int fibn = fib1+fib2;
	return fibn;
}

// Dp
int check2=0;
int fibmemo(int n, int dp[])
{
	check2++;
	if(n==0 || n==1)
	{
		return n;
	}

	// if you have already computed the nth
	// value in your dp
	if(dp[n]!=-1) // -1 empty with -1 value
	{
		return dp[n];
		// if its not -1 then the dp is full
		// return that value
	}
	int fibn1 = fibmemo(n-1, dp);
	int fibn2 = fibmemo(n-2, dp);

	int fibn = fibn1+fibn2;
	// befre returing we will store the ans in 
	// dp
	dp[n]=fibn; // store your value in dp
	// while returing the value to 
	// parent, storing the same value in dp
	return fibn;

}

// Pure Dp
int fibPureDp(int n)
{
	int dp[n+1];
	dp[0]=0;
	dp[1]=1;

	for(int i=2; i<=n; i++)
	{
		dp[i]=dp[i-1]+dp[i-2];
	}
	return dp[n];
}

int main()
{
	int n=10;
	// cout << fib(n) << endl;

	// int dp[n+1];
	 
	// // take your dp array // get the size of your dp array
	// memset(dp,-1,      sizeof(dp));
	// // fill your dp with -1
	// // memset key word inbuilt function

	// cout << fibmemo(n,dp) << endl;

	// cout << "Number of function call for fib " << check1 << endl;
	// cout << "Number of fucction call for fib " << check2 << endl;
	
	//***************** fib pure dp ******************//
	// for pure Dp

	cout << fibPureDp(n) << endl;
	return 0;
}