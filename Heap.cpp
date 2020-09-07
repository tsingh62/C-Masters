

// #include<iostream>
// //#include<vector>
// //#include<bits/stdc++.h>
// using namespace std;

// int main()
// {
// 	/* lines are just to take input and write
// 	output */
// 	#ifndef ONLINE_JUDGE
// 		freopen("input.txt", "r", stdin);
// 		freopen("output.txt", "w", stdout);
// 	#endif

// 	int x;
// 	cin >> x;
// 	cout << x;
// }

#include<iostream>
#include<vector>
using namespace std; 

// default value of struct is public unlike 
// class in c++

// left binary tree
struct minheap 
{
	vector<int> v;

	minheap(vector<int> a) 
	{
		// passing the value of a to v
		v = a;
		// print to check
		// for(auto x : v) 
		// {
		// 	cout << x << " ";
		// }
	}

	void heapify(int idx) 
	// call for the inde to heapify the whole structure
	{
		int left = 2 * idx + 1, right = 2 * idx + 2;
		int min_idx = idx;
		// if left value is smaller than cur value
		// then make left as min
		if (left < v.size() && v[left] < v[min_idx]) 
		{ // or left <=v.size()-1
			min_idx = left; // assuming current idx is the minimum
		}
		// if right is smaller than left and idx
		// combined then make right as smallest
		if (right < v.size() && v[right] < v[min_idx]) {
			min_idx = right;
		}

		if (min_idx != idx) {
			// min_idx contains either left or right
			swap(v[idx], v[min_idx]);
			heapify(min_idx);
			return;
		}

		return;
	}
	void build_heap() {
		//	int last_parent = ((v.size()-1)-1)/2;
					       //last node
		// or can be written as
		int last_par = (v.size() - 2) / 2;
		// v.size()-1 is the last node - so the parent of last node
        // will be (lastnode-1)/2

		// call heapify for all non-leaf nodes
		for (int i = last_par; i >= 0; i--) {
			heapify(i);
		}
	}
	// return topmost element of heap - as this is the min-heap
	int top() {
		return v[0];
	}
	// clear
	void clear() {
		v.clear();
	}
	bool empty() {
		return v.empty();
	}
	// remove the smallest value of the heap
	void pop() 
	{
		// will remove the minimum node
        // for min heap it will be the top node 
		swap(v[0], v.back()); 	//last of v - // v.back - last element 
		v.pop_back();// last one is removed
		// after swapping pops the last element
		heapify(0);
	}
	// insert the the value into the heap
	// at the last node
	void push(int val) {
		// made a new node and pushed it
		v.push_back(val);
		int idx = v.size() - 1; // last idx
		int par = (idx - 1) / 2;

		while (idx > 0 && v[par] > v[idx]) {
			swap(v[idx], v[par]);
			idx = par; // make the idx the parent
			par = (idx - 1) / 2;
		}
		return;
	}
};

// O(n+n+n*logn)
// O(nlogn)
void heap_sort(vector<int> &a) {
	// copy O(n)
	minheap H(a);
			// taking a min heap and 		
	// (n)		// build it
	H.build_heap();

	for (int i = 0; i < a.size(); i++) {
		// O(1)
		a[i] = H.top();
		// O(logn)
		// O(log(a.size()-i))
		H.pop();
	}
}

int main() {

// lines are just to take input and write output
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int n;
	cin >> n;
	//  vector<int> a;
	//  a.resize(n);
	//  // or
	vector<int> a(n);
	 // we resize as initially the vector was empty 
    // so we define the size with n by resizing it
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	 heap_sort(a);

	for (auto x : a) cout << x << " ";

	minheap H(a);
	H.build_heap();
	cout << endl;
	cout << H.top() << '\n';

	H.pop();
	
	cout << H.top() << '\n';

	H.push(0);

	cout << H.top() << '\n';
}

//g++ sample.cpp -std=c++11