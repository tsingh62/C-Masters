// // C++ program to counts Palindromic Subsequence
// // in a given String using recursion
// #include <iostream>
// using namespace std;

// int n, dp[1000][1000];
// string str = "abcb";

// // Function return the total
// // palindromic subsequence
// int countPS(int i, int j)
// {

// 	if (i > j)
// 		return 0;

// 	if (dp[i][j] != -1)
// 		return dp[i][j];

// 	if (i == j)
// 		return dp[i][j] = 1;

// 	else if (str[i] == str[j])
// 		return dp[i][j] = countPS(i + 1, j) + countPS(i, j - 1) + 1;

// 	else
// 		return dp[i][j] = countPS(i + 1, j) + countPS(i, j - 1) - countPS(i + 1, j - 1);
// }

// // Driver code
// int main()
// {
// 	memset(dp, -1, sizeof(dp));
// 	n = str.size();
// 	cout << "Total palindromic subsequence are :  " << countPS(0, n - 1) << endl;
// 	return 0;
// }

/*********************************/
#include<iostream>
using namespace std;

int countPS(string str)
{
	int n = str.length();
	int dp[n+1][n+1];

	for(int i=0; i<=n; i++)
	{
		for(int j=0; j<=n; j++)
		{
			dp[i][j] = 0;
		}
	}

	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(str[i-1] == str[j-1])
			dp[i][j] = 1 + dp[i-1][j-1];

			else 
			dp[i][j] = max(dp[i][j-1], max(dp[i-1][j],dp[i-1][j-1]));

		}
	}
	return dp[n][n];
}

int main()
{
	string str = "abcd";
	cout << countPS(str) << endl;
	
}