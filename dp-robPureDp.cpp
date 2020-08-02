

#include<iostream>
#include<vector>
using namespace std;

class solution
{
	public:
		// pure - Dp
	int rob(vector<int> &nums)
	{
		int n = nums.size();
	
		vector<int> dp(n+2);

		//base case
		dp[n+1]=0;
		dp[n]=0;

		for(int si=n-1; si>=0; si--)
		{
			// rec
			int include = nums[si]+dp[si+2];
			int skip = dp[si+1];

			int result = max(include, skip);

			dp[si]=result;
		}
		return dp[0];
		
	}

};

int main()
{
	vector <int> nums = {1,2,3,1};
	solution s;
	s.rob(nums);
	cout << s.rob(nums) << endl;
	
	return 0;
}
//g++ sample.cpp -std=c++11