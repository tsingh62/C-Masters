
#include<iostream>
#include<vector>
// using in built hash map
#include <unordered_map> 
using namespace std;


int main()
{
	// using in built hash map
		unordered_map<int, int> mp;

		mp[1]=5;
		mp[2]=5;
		mp[3]=5;

		for(auto x : mp)
		{
			cout << x.first << " " << x.second << '\n';
		}
	// not in order but the values are getting hashed

    if(mp.count(1))
    {
        cout << "Yes present \n";
        cout << mp[1] << '\n';
    }	
    else
    {
        cout << "Not present \n";
    }
    
}
// g++ sample.cpp -std=c++11