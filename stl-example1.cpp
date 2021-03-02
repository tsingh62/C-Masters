#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<set>
using namespace std;

// comparitor function  - for rev in vector
bool f(int x, int y) // for rev order
{
	return x > y;
}
int main()
{
	vector <int> a = {11,2,3,14};

	cout << a[1] << endl; // 2

	sort(a.begin(), a.end());

	for(int i=0; i<a.size(); i++)
	{
		cout << a[i] << " "; 
	}
	cout << endl;

	bool present = binary_search(a.begin(), a.end(), 3);// true
	// to find if 3 is there
	// when the value is not present
	present = binary_search(a.begin(), a.end(), 4); // false

	a.push_back(100);
	present = binary_search(a.begin(), a.end(), 100);
	// true

	a.push_back(100);
	a.push_back(100);
	a.push_back(100);
	a.push_back(100);
	// 11,2,3,14,100,100,100,100,100,123
	a.push_back(123);

	auto it = lower_bound(a.begin(), a.end(), 100); // >=
	vector<int>::iterator it2 = upper_bound(a.begin(), a.end(), 100);// >

	/*
	in place of --> vector<int>::iterator
	we can simplye take auto  - 
	  
	auto  it = lower_bound(a.begin(), a.end(), 100); // >=
	vector<int>::iterator it2 = upper_bound(a.begin(), a.end(), 100);// >
	*/
	

	cout << *it << " " << *it2 << endl;
	// diff between it - it2
	cout << it2 - it << endl;
	cout << endl;
	// this will give you the cout 
	// how many hundreds are there 5
	// lower bound - upper bound


	// sort in rev order - using comparitor function
	sort(a.begin(), a.end(), f);

	// print vector
	vector<int>::iterator it3;
	for(it3 = a.begin(); it3!=a.end(); it3++)
	{
		cout << *it3 << " ";
	}
	cout << endl;
	cout << endl;
	// or 
	for(int x : a)
	{
		cout << x << " ";
	}
	cout << endl;
	cout << endl;

	/*******************/
	// how to iterate with an address
	// in a vector

	for(int &x : a)
	{
		x++; // increases the value by 1 for each element
	}

	for(int x : a)
	{
		cout << x << " ";
	}
	cout << endl;
	cout << endl;
	cout << " ******* Sets *******" << endl;

	/************ Sets *************/ 

	set<int> s;
	// set internally maintains
	// ascending order sequence 
	s.insert(1);
	s.insert(2);
	s.insert(-1);
	s.insert(-10); // sorting in n log n

	for(int x : s)
	{
		cout << x << " "; // -10 -1 1 2 
	}
	cout << endl;

	auto it5 = s.find(-1);
	if(it5 == s.end())
	{
		cout << "Not present" << endl;
	}
	else
	{
		cout << " Value present " << *it5 << endl;
	}
	// find the 1st no greater than zero
	auto it6 = s.lower_bound(-1);
	auto it7 = s.upper_bound(0);

	cout << *it6 << " " << *it7 << endl;

	auto it8 = s.upper_bound(2);
	// no value for upper bound here
	if(it8 == s.end())
	{
		cout << " Not found " << endl;
	}

	s.erase(1);
	for(int x : s)
	{
		cout << x << " ";
	}
	cout << endl;
	cout << endl;

	cout << " ******* MAP *******" << endl;

	/************** Map *****************/
	// map one thing to another
	// here int to int
	map<int, int > m;
	m[1] = 100;
	m[2] = -1;
	m[3] = 200;
	m[10000235] = 1;

	map<char, int> cnt;
	string x = "Geeks for Geeks";
	for(char c : x)
	{
		cnt[c]++;
	}
	cout << cnt['e'] << " " << cnt['G'] << endl;
	// m.find
	// m.erase


	cout << " ******* Set Example *******" << endl;
		/*
		   [x,y]
		add[2,3]
		 add[10,20]
		  add[30,400]
		give me the interval which 
		contains the interval 13
		*/
		set<pair<int, int>> s1;
		s1.insert({2,3});
		s1.insert({10,20});
		s1.insert({30,400});
		s1.insert({401,450});

		/*
		Pair {a,b} is smaller than pair {c,d}
		if(a<b) or (a == b and c < d)
		*/
		//2,3
		//10,20
		//30,400
		//401, 250

		int point = 50;
		// since our set is 
		// a pair we need to pass
		// value as a pair
		auto itr1 = s1.upper_bound({point, INT_MAX});
		if(itr1 == s1.begin())
		{
			cout << " The given point is not lying in any interval " << endl;
			return 0;
		}
		itr1--;
		pair<int, int> current = *itr1;
		if(current.first <= point && point <= current.second)
		{
			cout << "yes its present " << current.first << " " << current.second << endl;

		}
		else
		{
			cout << " The given point is not lying in any interval " << endl;
		}

}