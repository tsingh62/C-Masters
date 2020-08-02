

#include<iostream>
using namespace std;

class solution
{
	public:

	int numSquares(int n)
	{
		// just like end+1
		// we use the same logic for n+1
		// -1 spwcifies that the values have
		// not been filled
		vector <int> dp(n+1, -1);
		return helper(n, dp);
	}

	int helper(int n, vector<int> &dp)
	{
		if(n==0)
		{
			return 0;
		}
		if(dp[n]!=-1)
		{
			return dp[n];
		}
		// recursive case
		int minValue = INT_MAX;

		for(int i=1; i*i<=n; i++)
		{
			int minPrefectSquareSubProblem = helper(n-i*i,dp);
			minValue = min(minValue, minPrefectSquareSubProblem +=1) ;
		}
		// or +=1 as done in the previous line
		// minValue+=1;
		dp[n] = minValue;
		return minValue;
	}
};


int main()
{
	int n = 12;
	int dp[n+1];
	memset(dp, -1, sizeof(dp));
	solution S;
	S.numSquares(n);
	cout << n << endl;
	return 0;
}