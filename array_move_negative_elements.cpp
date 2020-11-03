#include<iostream>
using namespace std;
#include<deque>
#include<vector>

int main()
{
    vector<int> arr = {-12,11,-13,-5,6,-7,5,-3,-6};
    int n = arr.size();
    deque <int> q;
    for(int i=0; i<n; i++)
    {
        if(!q.empty() && arr[i]>0)
        {
            q.push_back(i);
        }
        else
        {
            q.push_front(i);
        }
        
    }
    while(!q.empty())
    {
        cout << arr[q.front()] << " ";
        q.pop_front();
    }
    cout << endl;
}



// Input: -12, 11, -13, -5, 6, -7, 5, -3, -6
// Output: -12 -13 -5 -7 -3 -6 11 6 5

// OR - Option two

// void rearrange(int arr[], int n)
// {
//     int j = 0;
//     for (int i = 0; i < n; i++) {
//         if (arr[i] < 0) {
//             if (i != j)
//                 swap(arr[i], arr[j]);
//             j++;
//         }
//     }
// }
// void printArray(int arr[], int n)
// {
//     for (int i = 0; i < n; i++)
//         printf("%d ", arr[i]);
// }
 
// // Driver code
// int main()
// {
//     int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
//     int n = sizeof(arr) / sizeof(arr[0]);
//     rearrange(arr, n);
//     printArray(arr, n);
//     return 0;
// }