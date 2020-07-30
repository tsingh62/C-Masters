

//********* to run this code
//  g++ sample.cpp -std=c++11
// ./a.out

// vectors
#include<iostream>
#include<vector>

using namespace std;

void print(vector <int> d)
{
	int len = d.size();

	for(int i=0; i<len; i++)
	{
		cout << d[i] << " ";
	}
	cout << endl;
}
int main()
{
	vector <int> aa;
	vector <int> b(5,10);
	// means there are 5 integers in an array and they have value 10

	vector <int> c (b.begin(), b.end());
	vector <int> d{1,2,3,10,14};
//	print(b);

// taking input from the user
	vector <int> a;
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		int no;
		cin >> no;
		a.push_back(no);
	}

	for( int x:a)
	{
		cout << x << ", ";
	}

	return 0;
}