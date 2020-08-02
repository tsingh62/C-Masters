

#include<iostream>
using namespace std;

// Count board path

int countBoardPath(int start, int end)
{
	if(start == end)
	{
		return 1;
	}
	if(start > end)
	{
		return 0;
	}
	int count =0;
	for(int jump=1; jump<=6; jump++)
	{
		count +=countBoardPath(start + jump, end);
	}
	return count;
}
// memoziation
int countBoardPathMemo(int start, int end, int dp[])
{
	if(start == end)
	{
		dp[start]=1;
		return 1;
	}
	if(start > end)
	{
		return 0;
	}
	// check of the given value
	// input/state already exists in your 
	// dp or not
	if(dp[start]!=-1)
	{
		return dp[start];
	}
	int count =0;
	for(int jump=1; jump<=6; jump++)
	{
		count +=countBoardPathMemo(start + jump, end, dp);
	}
	dp[start] = count;
	// before returning to your parent call
	// just store the answer for this input/state in your dp

	// for printing values
	for(int i=0; i<=end; i++)
	{
		cout << dp[i] << "\t";
	}
	return count;
}
// Pure Dp
int countBoardPathPureDp(int start, int end)
{
	int dp[end+1];

	// Base case
	dp[end]=1;

	for(int i=end-1; i>=start; i--)
	{
		// recurssive case
		int count =0;
		for(int jump=1; jump<=6; jump++)
		{
			if(jump+i <= end)
			{
				count+=dp[i+jump];
			}
			else
			{
			break;
			}
			
		}
		dp[i]=count;
	}
	return dp[start];
}

int main()
{
	int start=0;
	int end =10;
	int dp[end+1];
	memset(dp,-1, sizeof(dp));
	cout << countBoardPathMemo(start, end, dp) << endl;
	cout << "************************" << endl;
	cout << countBoardPathPureDp(start, end) << endl;
	return 0;
}