

#include<iostream>
#include<vector>
using namespace std;

class solution
{
	public:
	
	int longestCommonSubSequence(string text1, string text2)
	{
		return helper(0, text1, 0, text2);
	}
	int helper(int i, string s1, int j, string s2)
	{
		// base case
		if(i==s1.length() || j==s2.length())
		{
			return 0;
		}
		// rec 
		int result;
		if(s1[i]==s2[j])
		{	// when both the strings are equal
			result = helper(i+1, s1, j+1, s2)+1;
									// 1 is my work added 
		}
		else // what if the length of the 2 strings are not equal
		{
			int first = helper(i+1,s1,j,s2);
			int second = helper(i, s1, j+1,s2);

			result = max(first, second);
		}
		return result;
	}

};

int main()
{
//	vector <vector<int>> envelopes = {{5,4},{6,4},{6,7},{2,3}};
	solution s;
	string text1 = "abcdefg";
	string text2 = "hiklanbocpd";
	s.longestCommonSubSequence(text1, text2);
	cout << s.longestCommonSubSequence(text1, text2) << endl;
	return 0;
}
//g++ sample.cpp -std=c++11