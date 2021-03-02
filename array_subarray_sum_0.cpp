// // A C++ program to find if there is a zero sum 
// // subarray 
// #include <iostream> 
// using namespace std;
// #include<unordered_set>

// bool subArrayExists(int arr[], int n) 
// { 
// 	unordered_set<int> sumSet; 

// 	// Traverse through array and store prefix sums 
// 	int sum = 0; 
// 	for (int i = 0 ; i < n ; i++) 
// 	{ 
// 		sum += arr[i]; 

// 		// If prefix sum is 0 or it is already present 
// 		if (sum == 0 || sumSet.find(sum) != sumSet.end()) 
// 			return true; 

// 		sumSet.insert(sum); 
// 	} 
// 	return false; 
// } 

// // Driver code 
// int main() 
// { 
// 	int arr[] = {-3, 2, 3, 1, 6}; 
// 	int n = sizeof(arr)/sizeof(arr[0]); 
// 	if (subArrayExists(arr, n)) 
// 		cout << "Found a subarray with 0 sum"; 
// 	else
// 		cout << "No Such Sub Array Exists!"; 
// 	return 0; 
// } 

#include<iostream>
using namespace std;
#include<unordered_set>
#include<vector>

int func(vector<int> arr, int i= 0, int sum =0, bool included = false)
{
	if(i == arr.size())
		return (sum==0 && included);

	int inc = func(arr, i+1, sum + arr[i], true);
	int dec = func(arr, i+1, sum, included);

	return inc || dec;
}

int main()
{
	vector<int> arr = {-3,2,3,1,6};
	cout << func(arr) << endl;
}