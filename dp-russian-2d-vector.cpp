

#include<iostream>
#include<vector>
using namespace std;

class solution
{
	public:
	int maxEnvelope(vector<vector<int>> &envelopes)
	{
		int n = envelopes.size();
		if(n==0)
		{
			return 0;
		}
		sort(envelopes.begin(), envelopes.end());
		// input : (5,4)(6,4)(6,7)(2,3)
		//	soretd ->(2,3)(5,4)(6,4)(6,7)
				//	(i)(j)
				//	(1)(0)	

		vector<int> dp(n,1);

		for(int i=1; i<n; i++)
		{
			for(int j=0; j<i; j++)
			{
				if(envelopes[j][0]<envelopes[i][0]
				&& envelopes[j][1]<envelopes[i][1])
// the 0th index of any random envelope represents the
// width and the 1th index represents the height of the
// envelope				
				{
					dp[i]=max(dp[i],dp[j]+1);
	// appending the last value which is compated and
	// added to the subsequence	
				}
			}
		}
		int maxValue=1;
		for(int val : dp)
		{
			maxValue = max(val,maxValue);
		}
		return maxValue;
	}

};

int main()
{
	vector <vector<int>> envelopes = {{5,4},{6,4},{6,7},{2,3}};
	solution s;
	s.maxEnvelope(envelopes);
	cout << s.maxEnvelope(envelopes) << endl;
	return 0;
}
//g++ sample.cpp -std=c++11