

#include<iostream>
#include<vector>
using namespace std;

class solution
{
	public:
	int uniquePath(int m, int n)
	{
		int row = m;
		int col = n;
		// 2 d vector
		vector <vector<int>> dp(row, vector<int>(col,-1));
		// -1 => is the value with which the vector 
		// is being filled

		return helper(0,0, m-1, n-1, dp);
	}
	int helper(int sr, int sc, int er, int ec, vector<vector<int>> &dp)
	{
		if(sr==er && sc == ec)
		{
			return 1;
		}
		if(sr>er || sc>ec)
		{
			return 0;
		}
		if(dp[sr][sc]!=-1)
		{
			return dp[sr][sc];
		}

		int rightPath = helper(sr, sc+1, er, ec, dp);
		int downPath = helper(sr+1, sc, er, ec, dp);

		int totalPath = rightPath+downPath;

		dp[sr][sc]=totalPath;

		return totalPath;
	}

};

int main()
{
	int m=3;
	int n=2;
	solution s;
	s.uniquePath(m,n);
	cout << s.uniquePath(m,n) << endl;
	
	return 0;
}
//g++ sample.cpp -std=c++11