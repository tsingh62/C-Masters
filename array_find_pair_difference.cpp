// C++ program to find a pair with the given difference 
#include <iostream> 
using namespace std; 

// The function assumes that the array is sorted 
// bool findPair(int arr[], int size, int n) 
// { 
// 	// Initialize positions of two elements 
// 	int i = 0; 
// 	int j = 1; 

// 	// Search for a pair 
// 	while (i < size && j < size) 
// 	{ 
// 		if (i != j && arr[j] - arr[i] == n) 
// 		{ 
// 			cout << "Pair Found: (" << arr[i] <<  ", " << arr[j] << ")"; 
// 			return true; 
// 		} 
// 		else if (arr[j]-arr[i] < n) 
// 			j++; 
// 		else
// 			i++; 
// 	} 

// 	cout << "No such pair"; 
// 	return false; 
// } 

// Driver program to test above function 
// int main() 
// { 
// 	int arr[] = {1, 8, 30, 40, 100}; 
// 	int size = sizeof(arr)/sizeof(arr[0]); 
// 	int n = 60; 
// 	findPair(arr, size, n); 
// 	return 0; 
// } 




#include<iostream>
using namespace std;
void displayPair(int arr[], int size, int n) {
   int i = 0;
   int j = 1;
   while (i < size && j < size) {
      if (i != j && arr[j] - arr[i] == n) {
         cout << "(" << arr[i] << ", " << arr[j] << ")"<<endl;
         i++; j++;
      }
      else if (arr[j]-arr[i] < n)
         j++;
      else
         i++;
   }
}
int main() {
   int arr[] = {10, 15, 26, 30, 40, 70};
   int size = sizeof(arr)/sizeof(arr[0]);
   int n = 30;
   displayPair(arr, size, n);
}


