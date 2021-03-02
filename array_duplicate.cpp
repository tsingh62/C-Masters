#include<iostream>
using namespace std;



// correct sol :

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






// int func(vector<int>&arr, int n)
// {
// 	int index = -1;
// 	for(int i=0; i<n; i++)
//     {
//         if(arr[abs(arr[i])] >= 0)
// 		{
//         arr[abs(arr[i])] = -arr[abs(arr[i])];
// 		}
//         else{
//        		index =  abs(arr[i]);
// 		}
//     }
// 	return index;
// }
// void func(int arr[], int n)
// {
//     for(int i=0; i<n; i++)
//     {
//         if(arr[abs(arr[i])] >= 0)
//         arr[abs(arr[i])] = -arr[abs(arr[i])];
//         else
//         cout << abs(arr[i]) << " ";
//     }
// }
int main()
{
    int arr[] = {1,2,3,1,3,6,4,6};
    int n = sizeof(arr)/sizeof(int);
    func(arr, n);
}


// Better solution >>>>>>>>>>>>>

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
         for(int i=0; i<nums.size(); i++)
    {
        int index = abs(nums[i]);

        if(nums[index]<0)
        {
            return index;
        }
        else
        {
            nums[index] =  - nums[index];
        }
        
    }
    return -1;
    }
}
/*
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
         for(int i=0; i<nums.size(); i++)
    {
        int index = abs(nums[i]);

        if(nums[index]<0)
        {
            return index;
        }
        else
        {
            nums[index] =  - nums[index];
        }
        
    }
    return -1;
        
    }
};

int main()
{
    int arr[] = {1,2,1,3,4,5,1,1};
    int n = sizeof(arr)/sizeof(int);
    cout << duplicate(arr, n) << endl;
}
*/

