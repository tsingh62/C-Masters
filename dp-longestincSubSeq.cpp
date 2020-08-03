

#include<iostream>
#include<vector>
using namespace std;

class solution
{
	public:
	int lengthOfList(vector <int> &nums)
	{
		int n = nums.size();

		// base case
		if(n==0)
		{
			return 0;
		}

		vector <int> dp(n,1);

		for(int i=1; i<n; i++)
		{
			for(int j=0; j<i; j++)
			{
				if(nums[i]>nums[j])
				{
					dp[i]=max(dp[i],     dp[j]+1);
						// prev value // current value
				}
			}
		}
		int maxLen = 1;
		for(int val : dp)
		{
			maxLen = max(maxLen, val);
		}
		return maxLen;

	}

};

int main()
{
	//	vector <int> nums = {1,3,2,4,19,7,10,6};
	vector <int> nums = {10,9,2,5,3,7,101,18};
	solution s;
	s.lengthOfList(nums);
	cout << s.lengthOfList(nums) << endl;
	
	return 0;
}
//g++ sample.cpp -std=c++11