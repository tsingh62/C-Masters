

#include<iostream>
#include<vector>
using namespace std;

class solution
{
	public:
	int uniquePath(int m, int n)
	{
		return helper(0,0, m,n);
		return 1;
	}
	int helper(int sr, int sc, int er, int ec)
	{
		if(sr==er && sc == ec)
		{
			return 1;
		}
		if(sr>er || sc>ec)
		{
			return 0;
		}

		int rightPath = helper(sr, sc+1, er, ec);
		int downPath = helper(sr+1, sc, er, ec);

		int totalPath = rightPath+downPath;

		return totalPath;
	}

};

int main()
{
	int m=2;
	int n=2;
	solution s;
	s.uniquePath(m,n);
	cout << s.uniquePath(m,n) << endl;
	
	return 0;
}
//g++ sample.cpp -std=c++11