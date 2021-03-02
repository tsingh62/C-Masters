#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>

vector<vector<string>>groupAnagram(vector<string> &str)
{
	unordered_map<string, vector<string>> myMap;

	int n = str.size();
	string temp;

	for(int i=0; i<n; i++)
	{
		temp = str[i];
		sort(str[i].begin(), str[i].end());
		// sorted string - pushback the temp list 
		myMap[str[i]].push_back(temp);
		// bucket
		/*
		| sotred str[i] - follwed by array/vector of string temp
		|     "			  pushback(temp) - string that has
		|     "			  all the sorted values common
		| 	 key - sotred[i] - value is the vector of 
	    |					string values that are common to it
		|					that make the anagram			
		*/ 
		
	}
	vector<vector<string>> result;

	for(auto it = myMap.begin(); it!=myMap.end(); it++)
	result.push_back(it->second);

	return result;
	
}
int main()
{
	vector<string> str = {"act","god","cat","dog","tac"};
	
	vector<vector<string>> ans = groupAnagram(str);
	for(int i=0; i<ans.size(); i++)
	{
		for(auto it = ans[i].begin(); it!=ans[i].end(); it++)
		{
			cout << *it << " ";
		}
	}
	cout << endl;
}