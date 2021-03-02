#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>

void func(vector<int>arr, int target)
{
	int n = arr.size();

	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			int left = j+1;
			int right = n-1;
			while(left < right)
			{
				if(arr[i]+arr[j]+arr[left]+arr[right]<target)
				{
					left++;
				}
				else if (arr[i]+arr[j]+arr[left]+arr[right]>target)
				{
					right--;
				}
				else
				{
					cout << i << " and  " << j << " and " << left << " and " << right << endl;
					left++;
					right--;
					break;
				}
				
			}
		}
	}
}

int main()
{
	 vector <int> arr = {1,2,3,4,5,6,7,8,9,10,11};
     int target = 20;

	func(arr, target);
	 
}


/*
#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>

vector<vector<int>> fourSum(vector<int> &arr, int target)
{
	vector<vector<int>> res;

	if(arr.empty())
	{
		return res;
	}
	int n = arr.size();
	// sort(arr.begin(), arr.end());

	for(int i=0; i<n; i++)
	{
		for(int j= i+1; j<n; j++)
		{
			int target_2 = target - arr[j] - arr[i];

			int front = j+1;
			int back = n-1;
			while(front < back)
			{
				int two_sum = arr[front] + arr[back];
				if(two_sum < target_2)
				front++;
				else if(two_sum > target_2)
				back--;
				else
				{
					vector<int>quadruplet(4,0);
					quadruplet[0] = arr[i];
					quadruplet[1] = arr[j];
					quadruplet[2] = arr[front];
					quadruplet[3] = arr[back];
					res.push_back(quadruplet);

					// processing the duplicates of number 3
					while (front < back && arr[front]==quadruplet[2]) front++;
					
					// processing the dupliacre of number 4
					while(front < back && arr[back]==quadruplet[3]) back--;
					
				}
				
			}
			// processing the duplicate of number 2
			while(j+1 < n && arr[j+1]==arr[j]) j++;
		}
		while(i+1 < n && arr[i+1]==arr[i]) i++;
	}
	return res;
}

int main()
{
	 vector <int> arr = {1,2,3,4,5,6,7,8,9,10,11};
     int target = 20;

	 vector<vector<int>> ans = fourSum(arr, target);

	 for(int i=0; i<ans.size(); i++)
	 {
		 for(auto it = ans[i].begin(); it!=ans[i].end(); it++)
		 {
			 cout << *it << " ";
		 }
		
		}
	cout << endl;
	 
}
*/

/*
// A hashing based CPP program 
// to find if there are 
// four elements with given sum. 
#include <bits/stdc++.h> 
using namespace std; 

// The function finds four 
// elements with given sum X 
void findFourElements(int arr[], int n, int X) 
{ 
	// Store sums of all pairs 
	// in a hash table 
	unordered_map<int, pair<int, int> > mp; 
	for (int i = 0; i < n - 1; i++) 
		for (int j = i + 1; j < n; j++) 
			mp[arr[i] + arr[j]] = { i, j }; 

	// Traverse through all pairs and search 
	// for X - (current pair sum). 
	for (int i = 0; i < n - 1; i++) { 
		for (int j = i + 1; j < n; j++) { 
			int sum = arr[i] + arr[j]; 

			// If X - sum is present in hash table, 
			if (mp.find(X - sum) != mp.end()) { 

				// Making sure that all elements are 
				// distinct array elements and an element 
				// is not considered more than once. 
				pair<int, int> p = mp[X - sum]; 
				if (p.first != i && p.first != j 
					&& p.second != i && p.second != j) { 
					cout << arr[i] << ", " << arr[j] << ", "
						<< arr[p.first] << ", "
						<< arr[p.second]; 
					return; 
				} 
			} 
		} 
	} 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 10, 20, 30, 40, 1, 2 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int X = 91; 
	
	// Function call 
	findFourElements(arr, n, X); 
	return 0; 
}

*/