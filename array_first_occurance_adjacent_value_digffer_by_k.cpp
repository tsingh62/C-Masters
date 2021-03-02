// C++ program to search an element in an array 
// where difference between all elements is 1 
#include<iostream> 
using namespace std; 

/*
A step array is an array of integer where each 
element has a difference of at most k with its neighbor. 
Given a key x, we need to find the index value of x 
if multiple element exist return the first occurrence of the key.
*/

// x is the element to be searched in arr[0..n-1] 
// such that all elements differ by at-most k. 
int search(int arr[], int n, int x, int k) 
{ 
	// Traverse the given array starting from 
	// leftmost element 
	int i = 0; 
	while (i < n) 
	{ 
		// If x is found at index i 
		if (arr[i] == x) 
			return i; 

		// Jump the difference between current 
		// array element and x divided by k 
		// We use max here to make sure that i 
		// moves at-least one step ahead. 
		i = i + max(1, abs(arr[i]-x)/k); 

		// or int diff = abs(arr[start]- x)/k;
		// diff = max(1, diff);
		// start = start + diff;_
	} 

	cout << "number is not present!"; 
	return -1; 
} 

// Driver program to test above function 
int main() 
{ 
	int arr[] = {2, 4, 5, 7, 7, 6}; 
	int x = 6; 
	int k = 2; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	cout << "Element " << x << " is present at index "
		<< search(arr, n, x, k); 
	return 0; 
} 
