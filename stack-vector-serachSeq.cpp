#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool searchSeq(vector<int> &pushed, vector <int> &popped)
{
	stack <int> s;
	int popIdx =0;

	for(int val : pushed)
	{
		// push the value before checking it
		s.push(val);
		while(!s.empty() && s.top()==popped[popIdx])
		{
			s.pop();
			popIdx++;
		}
	 
	}
	// if(s.empty())
	// {
	// 	return true
	// }
	// return false; // or just writ ethe below line
	return s.empty();
}
int main()
{
	vector <int> pushed = {1,2,3,4,5};
	vector <int> popped = {4,5,3,2,1};
	cout << searchSeq(pushed, popped);
	cout << endl;
	return 0;
 }