// #include<iostream> 
// using namespace std; 
  
// int countTriplets(int arr[], int n, int sum) 
// { 
//     // Sort input array 
//     sort(arr, arr+n); 
  
//     // Initialize result 
//     int ans = 0; 
  
//     // Every iteration of loop counts triplet with 
//     // first element as arr[i]. 
//     for (int i = 0; i < n-2; i++) 
//     { 
//         // Initialize other two elements as corner elements 
//         // of subarray arr[j+1..k] 
//         int j = i + 1, k = n - 1; 
  
//         // Use Meet in the Middle concept 
//         while (j < k) 
//         { 
//             // If sum of current triplet is more or equal, 
//             // move right corner to look for smaller values 
//             if (arr[i] + arr[j] + arr[k] <= sum) 
//                 j++; 
// 			// for >=sum,  j++ becomes k++

//             // Else move left corner 
//             else
//             { 
//                 // This is important. For current i and j, there 
//                 // can be total k-j third elements. 
//                 ans += (k - j); 
//                 k--; 
// 				// for >= k-- becomes j++;
//             } 
//         } 
//     } 
//     return ans; 
// } 
  
// Driver program 
// int main() 
// { 
//     int arr[] = {5, 1, 3, 4, 7}; 
//     int n = sizeof(arr)/sizeof(arr[0]); 
//     int sum = 12; 
//     cout << countTriplets(arr, n, sum) << endl; 
//     return 0; 
// } 

/*
#include <iostream>
#include <algorithm>
using namespace std;
 
// Function to print all distinct triplets in the array with sum
// less than or equal to given number
void printAllTriplets(int A[], int n, int sum)
{
    // sort the array in ascending order
    sort(A, A + n);
 
    // check if triplet is formed by A[i] and a pair from
    // sub-array A[i+1..n)
    for (int i = 0; i <= n - 3; i++)
    {
        // maintain two indexes pointing to end-points of the
        // sub-array A[i+1..n)
        int low = i + 1, high = n - 1;
 
        // loop till low is less than high
        while (low < high)
        {
            // decrement high is total is more than the remaining sum
            if (A[i] + A[low] + A[high] > sum)
                high--;
 
            else
            {
                // if total is less than or equal to the remaining sum,
                // print all triplets
                for (int x = low + 1; x <= high; x++)
                    cout << "(" << A[i] << ", " << A[low] << ", " << A[x] << ")";
 
                low++;  // increment low
            }
        }
    }
}
 
int main()
{
    int A[] = { 2, 7, 4, 9, 5, 1, 3 };
    int sum = 10;
 
    int n = sizeof(A) / sizeof(A[0]);
 
    printAllTriplets(A, n, sum);
 
    return 0;
}
*/


// C++ program to print triplets with sum smaller
// than a given value
#include <iostream>
using namespace std;

void printTriplets(int arr[], int n, int sum)
{
	// Sort input array
	sort(arr, arr + n);

	// Every iteration of loop counts triplet with
	// first element as arr[i].
	for (int i = 0; i < n - 2; i++) {

		// Initialize other two elements as corner
		// elements of subarray arr[j+1..k]
		int j = i + 1, k = n - 1;

		// Use Meet in the Middle concept
		while (j < k) {

			// If sum of current triplet is more or equal,
			// move right corner to look for smaller values
			if (arr[i] + arr[j] + arr[k] >= sum)
				k--;

			// Else move left corner
			else {

				// This is important. For current i and j,
				// there are total k-j third elements.
				for (int x = j + 1; x <= k; x++)
					cout << arr[i] << ", " << arr[j]
						<< ", " << arr[x] << endl;
				j++;
			}
		}
	}
}

// Driver program
int main()
{
	int arr[] = {-2, 0, 1, 3};
	int n = sizeof arr / sizeof arr[0];
	int sum = 2;
	printTriplets(arr, n, sum);
	return 0;
}
