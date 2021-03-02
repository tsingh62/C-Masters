#include<iostream>
using namespace std;
#include<set>

bool isSubset(int arr1[], int m, 
              int arr2[], int n)
{
 
    // Using STL set for hashing
    set<int> hashset;
 
    // hset stores all the values of arr1
    for (int i = 0; i < m; i++)
    {
        hashset.insert(arr1[i]);
    }
 
    // loop to check if all elements of arr2 also
    // lies in arr1
    for (int i = 0; i < n; i++) {
        if (hashset.find(arr2[i]) == hashset.end())
            return false;
    }
    return true;
}
 
// Driver Code
int main()
{
    int arr1[] = { 11, 1, 13, 21, 3, 7 };
    int arr2[] = { 11, 3, 7, 1 };
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
 
    if (isSubset(arr1, m, arr2, n))
        cout << "Yes "
             << "\n";
    else
        cout << "No "
             << "\n";
    return 0;
}