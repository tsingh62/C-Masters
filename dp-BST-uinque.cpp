
#include<iostream>
#include<vector>
using namespace std;


class Solution
{
    public:

    int numTrees(int n)
    {
        vector <int> dp(n+1, -1);
        return helper(n, dp);
    }
    int helper(int n, vector<int> &dp)
    {
        // base case
        if(n==0 || n==1)
        {
            return 1;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        int ans =0;
        for(int i=1; i<=n; i++)
        {
            int leftBSTCount = helper(i-1, dp);
            int rightBSTCOunt = helper(n-i, dp);

            int myCountAsRootNode = leftBSTCount*rightBSTCOunt;

            ans+=myCountAsRootNode;
        }

        dp[n] = ans;

        return ans;
    }
        
};

int main()
{
	int n = 3;
	Solution s;
	cout << s.numTrees(n) << endl;
	
	return 0;
}