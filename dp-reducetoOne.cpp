
// Dynamic Programming
// g++ sample.cpp -std=c++11

#include<iostream>
using namespace std;



//*********** Reduced to one *****************//
int reduceToOneMemo(int n, int dp[])
{
	if (n==1)
	{
		return 0;
	}
	// if you have already computed the nth
	// value in your dp
	if(dp[n]!=-1) // -1 empty with -1 value
	{
		return dp[n];
		// if its not -1 then the dp is full
		// return that value
	}
	int count1 = INT_MAX;
	int count2 = INT_MAX;
	int count3 = INT_MAX;

	if(n%2==0)
	{
		count2 = reduceToOneMemo(n/2, dp);
	}
	if(n%3 == 0)
	{
		count3 = reduceToOneMemo(n/3, dp);
	}

	count1 = reduceToOneMemo(n-1, dp);
	int minValue = min(count1, min(count2,count3));

	minValue +=1;

	dp[n]=minValue;

	// print dp array at each moment of 
    // the function call as how is it getiing filled
    for(int i=1; i<=10; i++)
    {
        cout << dp[i] << "\t";
    }
    cout << endl << "**********************" << endl;

	return minValue;

}

// Pure Dp
int reduceToOnePureDp(int n)
{
	int dp[n+1];

	// base case
	dp[1]=0;
	dp[2]=1;
	dp[3]=1;

	for(int i=4 ; i<=n; i++)
	{
		// recursive case
		// reduceToOne(i); ->dp[i];
		

		int count1 = INT_MAX;
		int count2 = INT_MAX;
		int count3 = INT_MAX;

		if(i%2 == 0)
		{
			count2 = dp[i/2];
		}
		if(i % 3 ==0)
		{
			count3 = dp[i/3];
		}
		count1 = dp[i-1];

		int minValue = min(count1, min(count2,count3));

		minValue++;

		dp[i] = minValue;
	}
	return dp[n];

}

int main()
{
	int n=10;
	cout << reduceToOneMemo(n) << endl;

	int dp[n+1];
	// because  n is 10 - so we when we create n+1 (11)
    // that means we can easily fit an array of 
    // size 10 
	memset(dp, -1, sizeof(dp));
	cout << reduceToOneMemo(n,dp) << endl;

//********* Pure Dp ************//
	cout << reduceToOnePureDp(n) << endl;
	return 0;
}