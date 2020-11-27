#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<set>
using namespace std;

/*
	Use - #include<map>
	key value store
	Traversing through iterators
	Search in log(n)
	size(), find(), clear
	---------------------------------------------
		// find the fequency of all the numbers

		Question 1 :

		Find fequency of numbers in an array
		exmaple : -  1 1 2 2 1 1 3 5 5
		1-4
		2-2
		3-1
		5-2 
	*/

int arr[1004];
int main()
{
	map<int, int> m;

	int n;
	cin >> n;

	for(int i=0; i<n; i++)
	{
		cin >> arr[i];
	}

	for(int i=0; i<n; i++)
	{	
		//key-arr[i] // value is ++
		m[arr[i]]++;
	}
	map<int, int> :: iterator it;
	// or we can us auto in for loop 
	for(it = m.begin(); it!= m.end(); it++)
	{			//prints key      // prints value 
		cout << it -> first << " " << it->second << endl;
	}
	// vip - it will print the key in sorted order
	// map stores key in osrted order
	// map does not store duplicate keys
	/***************************************/
	
	// How to search
	int x;
	cin >> x;

	it = m.find(x);
	if(it != m.end())
	{	
	
		cout << it->first << " " << it->second << endl;
		
	}

	unordered_map<int, string> mp ={{1,"Red"},
									{2, "Blue"},
									{3, "Green"}};
	for(const auto &n : mp)
	cout << n.first << " " << n.second << endl;
	// unordered map - the result is not sorted

	/******************** Sets ********************/
	// set <key> set_name
	// print only the distinct char
	// does not store duplicate value 
	// stores in sorted order
}	