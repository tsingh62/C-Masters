
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector <int> v;

	v.push_back(2);
	v.push_back(12);

	v.push_back(2);
	v.push_back(12);

	v.push_back(4);
	v.push_back(56);

	v.push_back(32);
	v.push_back(24);

	for(int val : v)
	{
		cout << val << " ";
	}
	cout << endl;
	
	v[0]=543;

	v.pop_back();
	cout << "value at back " << v.back() << endl;

	// pop front not avaliable in vectors
	// v.pop_front();
	// cout << "value at front " << v.front() << endl;

	for(int i=0; i<v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	sort(v.begin(), v.end());

	for(int val : v)
	{
		cout << val << " ";
	}
	cout << endl;
	return 0;
}