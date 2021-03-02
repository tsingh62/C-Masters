#include<iostream>
using namespace std;
#include<set>



// *********** Correct Solution *************

int firstDuplicate(std::vector<int> a) {
    
    // return -1 if none found:
    int duplicate = -1;
    cout << a.size();
    
    // iterate through array and test for duplicates:
    for (int i = 0; i < a.size(); i++) {
        
        // hold current number and it's abs val:
        int currentNum = a[i];
        int absCurr = abs(currentNum) - 1;
        
        // check if the slot indexed by currentNum is positive,
        // if so, it hasn't been seen, so flip it:
        if ( a[absCurr] > 0) {
            a[absCurr] = a[absCurr] * -1;
        }
        // if it's negative, it's been seen, return it:
        else {
            return abs(a[i]);
        }
        
    }

    return duplicate;
}











/* C++ program to find first repeating element in arr[] */

// option 2
// This function prints the first repeating element in arr[]
void printFirstRepeating(int arr[], int n)
{
	// Initialize index of first repeating element
	int min = -1;

	// Creates an empty hashset
	set<int> myset;

	// Traverse the input array from right to left
	for (int i = n - 1; i >= 0; i--)
	{
		// If element is already in hash set, update min
		if (myset.find(arr[i]) != myset.end())
			min = i;

		else // Else add element to hash set
			myset.insert(arr[i]);
	}

	// Print the result
	if (min != -1)
		cout << "The first repeating element is " << arr[min] << endl;
	else
		cout << "There are no repeating elements";
}
// Option 1
// int func(int arr[], int n)
// {
// 	int sec_idx = n;
// 	for(int i=0; i<n; i++)
// 	{
// 		for(int j=i+1; j<n; j++)
// 		{
// 			if(arr[i]==arr[j])
// 			{
// 				sec_idx = min(sec_idx, j);
// 			}
// 		}
// 	}
// 	if(sec_idx == n)
// 		return -1;
// 	else 
// 		return arr[sec_idx];
// }


// Driver method to test above method
int main()
{
	int arr[] = {10, 5, 3, 4, 3, 5, 6};

	int n = sizeof(arr) / sizeof(arr[0]);
	printFirstRepeating(arr, n);
  
   // cout << func(arr, n) << endl;

}

