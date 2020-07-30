#include<iostream>
using namespace std;



// void printIncDec(int n)
// {
//      if(n==0)
//         {
//             return;
//         }
//     cout << n << endl;
//     printIncDec (n-1);
//     cout << n << endl;

// }

// int sumTotal(int n)
// {
//     if(n==0)
//     {
//         return 0;
//     }
//     int subproblem = sumTotal(n-1);
//     int ans = n+ subproblem; 
//     return ans;
// }

//*********** new ***************
bool isSorted(int si, int arr[], int n)
{
// base 
if(si==n-1)
{
    // n-1 is the last single array
    // last single array is always sorted
    // therefore when si=n-1, it means 
    // si is on the last single array which is
    // by default sorted.
    // si =0 ... n=1(single length array)
    // si = n-1
    // so 0 = 1-1 is 0 (that means si)
    // that means the single length array 
    // if equal to si then it is TRUE and sorted.

    return true;
}

// recursive 
if(arr[si]>arr[si+1])
{
    return false;
}
else
{
        bool subprob_sorted = isSorted(si+1, arr,n);
        // if(subprob_sorted==true)
        // {
        //     return true;
        // }
        // else
        // {
        //     return false;
        // }
        return subprob_sorted;
    }
}

int main()
{
//printIncDec(5);
// cout << sumTotal(5) << endl;

//************* new ************** 
int arr[]={1,2,3,4,5,6};
int n=6;
int si=0;
cout << isSorted(si,arr,n) << endl;
return 0;    

}