

#include<iostream>
#include<vector>
using namespace std;

class solution
{
	public:
	
	int longestCommonSubSequence(string s1, string s2)
	{
		int row = s1.length()+1;
		int col = s2.length()+1;
		vector<vector<int>> dp(row, vector<int>(col,-1));
		// row =i							// memoization
		// col = j
		// dp[i][j]
		return helper(0, s1, 0, s2,dp);
	}
	int helper(int i, string s1, int j, string s2,
	 vector<vector<int>> &dp)
	{
		// base case
		if(i==s1.length() || j==s2.length())
		{
			return 0;
		}
		if(dp[i][j]!=-1)
		{
			return dp[i][j];
		}
		// rec 
		int result;
		if(s1[i]==s2[j])
		{	// when both the strings are equal
			result = helper(i+1, s1, j+1, s2,dp)+1;
									// 1 is my work added 
		}
		else // what if the length of the 2 strings are not equal
		{
			int first = helper(i+1,s1,j,s2,dp);
			int second = helper(i, s1, j+1,s2,dp);

			result = max(first, second);
		}
		dp[i][j] = result;

		// printing the Dp

		for(int x=0; x<=s1.length(); x++)
		{
			for(int y=0; y<=s2.length(); y++)
			{
				cout << dp[x][y] << "\t";
			}
			cout << endl;
		}
		cout << "**************************" << endl;

		return result;
	}

};

int main()
{
//	vector <vector<int>> envelopes = {{5,4},{6,4},{6,7},{2,3}};
	solution s;
	string s1 = "abcdefg";
	string s2 = "hiklanbocpd";
	s.longestCommonSubSequence(s1, s2);
	cout << s.longestCommonSubSequence(s1, s2) << endl;
	return 0;
}
//g++ sample.cpp -std=c++11