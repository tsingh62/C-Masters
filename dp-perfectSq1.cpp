

#include<iostream>
#include<vector>
using namespace std;

class solution
{
	public:

	int numSquares(int n)
	{
		// just like end+1
		// we use the same logic for n+1
		// -1 specifies that the values have
		// not been filled and we fill it with -1
		// this is how you initialize single 
		// dimension array
		vector <int> dp(n+1, -1);
		return helper(n, dp);
	}

	int helper(int n, vector<int> &dp)
	{
		if(n==0)
		{
			dp[n]=0;
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
// Pure Dp
// in pure dp we go from bottom to up
class Solution1
{
	public:
	int numSqrs(int n)
	{
		vector <int> dp(n+1,-1);
		
		// base case
		dp[0] = 0;

		for(int problem=1; problem <= n; problem++)
		{
			int minValue = INT_MAX;

			for(int i=1; i*i<=problem; i++)
			{
				int minPerfectSqSubProblem = dp[problem-i*i];
				minValue = min(minValue, minPerfectSqSubProblem+1);
			}
			dp[problem] = minValue;
		}
		return dp[n];
	}	
};

int main()
{
	int n = 12;
	// we dont need to do this 
	// when defining the vector dp
	// we have already put dp(n+1)
	// and initialized the dp to -1
	// |
	// V
	// int dp[n+1];  // this is for array
	// memset(dp, -1, sizeof(dp));
	solution S;
	cout << S.numSquares(n) << endl;

	// pure dp
	Solution1 s1;
	cout << s1.numSqrs(n) << endl;
	return 0;
}