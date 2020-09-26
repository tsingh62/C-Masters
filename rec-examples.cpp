#include<iostream>
using namespace std;

void printInc(int n) {
    if(n==0) {
        return; 
    }
    // n-1 will rec to the base that is n==0(return)
    printInc(n-1); // will goto the base & from there print
    cout << n << " "; // while returing 
        // we are actually printing 
}
void printDec(int n) {
    if(n==0) {
        return;
    }
    cout << n << " "; // printing while building
    printDec(n-1); // the call
}

int power(int n, int p){
    //Base Case
    if(p==0) {
        return 1;
    }
    // rec
    int subProblem = power(n, p-1);
    int ans = n * subProblem;
    return ans;

}

// void function(int parameter)
// {
//     //base case will always be the 1st check priority

//     // Work done here (before the recursion call)
//     // while we are are moving up to the -base case
//     //                                   (or call stack)
//     function(subproblem);
//     // Work done here (After the recursion call)
//     // while we are are moving down to the - call stack

// }
int linearSearch(int arr[], int si, int m, int key)
{   
    // Base case
    if(si == m)
    {
        return -1;
    }
    if(arr[si]==key)
    {
        return si;
    }
    else
    {
        int idx = linearSearch(arr, si+1, m, key);
        return idx;
    }
    
}
int main() {
    int n = 5;
    printInc(n);
    cout << endl;
    printDec(n);
    cout << endl;
    //****//
    cout << power(2,8) << endl;
    //****//
    int arr[]={3,2,4,1,5,61,7};
    int m = 7;
    int key = 1;
    int si=0;
    cout << linearSearch(arr,si, m, key) << endl;
    //****//
    return 0;
}