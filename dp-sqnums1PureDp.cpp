

#include<iostream>
#include<vector>
using namespace std;

class solution
{
	public:
	// Pure Dp - Perfect Sq
	int numSquares(int n)
	{
		vector <int> dp(n+1);

		// Base case
		dp[0]=0;

		for(int problem =1; problem<=n; problem++)
		{
			int minValue = INT_MAX;
			for(int i=1; i*i<=problem; i++)
			{
				int minPerfectSquareSubproblem = dp[problem- i*i];
				minValue = min(minValue, minPerfectSquareSubproblem+1);
			}
			dp[problem]=minValue;
		}
		return dp[n];
	}

};

int main()
{
	int n = 12;
	solution s;
	s.numSquares(n);
	cout << s.numSquares(n) << endl;
	// vector <int> dp(n+1);
	// memset(dp, -1, sizeof(dp));
	
	return 0;
}
//g++ sample.cpp -std=c++11