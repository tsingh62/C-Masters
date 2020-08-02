

#include<iostream>
using namespace std;

class solution
{
	public:

	int numSquares(int n)
	{
		return helper(n);
	}

	int helper(int n)
	{
		if(n==0)
		{
			return 0;
		}
		// recursive case
		int minValue = INT_MAX;

		for(int i=1; i*i<=n; i++)
		{
			int minPrefectSquareSubProblem = helper(n-i*i);
			minValue = min(minValue, minPrefectSquareSubProblem +=1) ;
		}
		// or +=1 as done in the previous line
		// minValue+=1;

		return minValue;
	}
};


int main()
{
	int n = 12;
	solution S;
	S.numSquares(n);
	cout << n << endl;
	return 0;
}