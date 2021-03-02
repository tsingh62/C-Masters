#include<iostream>
using namespace std;

int trappingRainWater(int height[], int n) {
	if (n == 0) {
		return 0;
	}

	int left[n];
	int right[n];

	left[0] = height[0];

	for (int i = 1; i < n; i++) {
		if (height[i] > left[i - 1]) {
			left[i] = height[i];
		} else {
			left[i] = left[i - 1];
		}
	}

	right[n - 1] = height[n - 1];

	for (int i = n - 2; i >= 0; i--) {
		if (height[i] > right[i + 1]) {
			right[i] = height[i];
		} else {
			right[i] = right[i + 1];
		}
	}

	int totalWater = 0;

	for (int i = 0; i < n; i++) {
		int val = min(left[i], right[i]) - height[i];
		totalWater += val;
	}

	return totalWater;
}

int main() {

   // int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int height [] = {7,4,0,9};
	int n = sizeof(height)/sizeof(int);
    cout << trappingRainWater(height, n) << endl;
	return 0;
}



/*
#include<iostream>
using namespace std;
int maxWater(int arr[], int n)  
{ 
      
    // To store the maximum water  
    // that can be stored 
    int res = 0; 
      
    // For every element of the array 
    for (int i = 1; i < n-1; i++) 
    { 
          
        // Find the maximum element on its left 
        int left = arr[i]; 
        for (int j=0; j<i; j++) 
           left = max(left, arr[j]); 
          
        // Find the maximum element on its right    
        int right = arr[i]; 
        for (int j=i+1; j<n; j++) 
           right = max(right, arr[j]);  
         
       // Update the maximum water     
       res = res + (min(left, right) - arr[i]);    
    } 
  
    return res;  
}  
  
// Driver code 
int main()  
{  
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};  
    int n = sizeof(arr)/sizeof(arr[0]);  
      
    cout << maxWater(arr, n);  
      
    return 0;  
} 
*/