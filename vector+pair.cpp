

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int, int>p1, pair<int,int> p2
{
	int d1 = p1.first*p1.first + p1.second*p1.second;
	int d2 = p2.first*p1.first + p2.second*p1.second;

	if(d1==d2)
	{
		return p1.first < p2.first;
	}
}
int main()
{
	int n;
	cin >> n;

	vector <pair <int,int> a;

	for(int i=0; i<n; i++)
	{
		int x,y;
		cin >> x >> y;
		a.push_back(make_pair(x,y));
	}
	sort(a.begin(), a.end(), compare);

	for (auto p:a)
	{
		cout << "car " << p.first "," << p.second << endl;
	}

	return 0;
}