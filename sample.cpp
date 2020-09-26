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
int linearSearch(int arr[],int si, int m, int key)
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
        int idx = linearSearch(arr,si+1, m, key);
        return idx;
    }
    
}
int sumTilln(int n)
{
    // base case
    if(n==0 || n==1)
    {
        return n;
    }

    return n + sumTilln(n-1);
}

void incDec(int n)
{
    if(n==0)
    {
        return;
    }
    cout<< n << " ";
    incDec(n-1);
    cout << n << " ";
}
int power2(int n, int p)
{
    // base case
    if(p==0)
    {
        return 1;
    }
    int subProblem = power2(n,p/2);
    if(p&1)
    {
        int ans = subProblem * subProblem * n;
        return ans;
    }
    else
    {
        int ans = subProblem * subProblem;
        return ans;
    }

}
void incDecOddEven(int n)
{
    //base case
    if(n==0)
    {
        return;
    }
    if(n&1)
    {
        cout << n << " ";
    }
    incDecOddEven(n-1);
    if(n%2==0)
    {
        cout << n << " ";
    }
}
int main() {
    int n = 5;
    printInc(n);
     //****//
    cout << endl;
    printDec(n);
     //****//
    cout << endl;
    //****//
    cout << power(2,8) << endl;
    //****//
    int arr[]={3,2,4,1,5,61,7};
    int m = 7;
    int key = 1;
    int si=0;
    cout << linearSearch(arr, si,m, key) << endl;
    //****//
    int p = 5;
    cout << sumTilln(p) << endl; 
     //****//
    incDec(n);
    cout << endl;
    //****//
    cout << power2(2,8) << endl;
     //****//
    incDecOddEven(n);
    cout << endl;
    return 0;
}