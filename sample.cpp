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
    if(n&1)//odd
    {
        cout << n << " ";
    }
    incDecOddEven(n-1);
    if((n&1)==0) // even
    {
        cout << n << " ";
    }
}
// is sorted
bool isSorted(int si, int arr[], int n)
{
    if(si==n-1)
    {
        return true;
    }
    if(arr[si]>arr[si+1])
    {
        return false;
    }
    else
    {
        bool isSubproblem = isSorted(si+1,arr,n);
        if(isSubproblem==true)
        {
            return true;
        }
        else
        {
            return false;
        }
        return isSubproblem;
    }
    
}

// powerBetter
int powerBetter(int n, int p)
{
    if(p==1)
    {
        return n;
    }
    int subProblem = powerBetter(n,p/2);
    if(n&1)
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
// last idx of repeating no - my code
// int lastIdx(int si, int arr[], int n, int key)
// {
//     int startIdx = 0;
//     if(si == startIdx) 
//     {
//         // when you have reached the 
//                 // end of the array 
//                 // return -1, means the key was not found
//         return -1;
//     }
//     // when si == n
//     if(arr[si]==key)
//     {
//         return si;
//     }
//     else
//     {
//         int subproblem = lastIdx(si-1,arr,n,key);
//         return subproblem;
//     }
    
// }
//pranav's code
int lastIdx(int si, int arr[], int n, int key)
{
    if(si==n)
    {
        return -1;
    }
    // starting from the subproblem
    int index = lastIdx(si+1, arr, n, key);
    if(index!=-1)
    {
        return index;
    }
    else
    {
        if(arr[si]==key)
        {
            return si;
        }
        else
        {
            return -1;
        }
    }
}

int fib(int n)
{
    if(n==0 || n==1)
    {
        return n;
    }
    int ans = fib(n-1)+fib(n-2);
    return ans;
}
// count the no od binary strings - -Review again
// where there are no consecutive ones
int consec(int n)
{
    int count = 0;
    if(n==1 || n==2)
    {
        return n+1;
    }

    int withZero = consec(n-1);
    int withOne = consec(n-2);

    int total = withZero + withOne;
    return total;
}
int paringProblem(int n)
{
    if(n == 1 || n==0)
    {
        return n;
    }
    // n-1 = last value
    int ans = paringProblem(n-1)+(n-1)*paringProblem(n-2);
    return ans;
}
// My code
// int countBoradPath(int n)
// {
//     int start = 0;
//     int end =n;
//     int count =0;
//     if(start == end)
//     {
//         return 1;
//     }
//     if(start > end)
//     {
//         return 0;
//     }
//     count += countBoradPath(n-1)+(n-1)+(n-2)+(n-3)+(n-4)+(n-5)+(n-6);
//     return count;
// }
// Pranav's code
int countBoradPh(int start, int end)
{
    if(start == end)
    {
        return 1;
    }
    if(start > end)
    {
        return 0;
    }
    int count =0;
    for(int jump=1; jump<=6; jump++)
    {
        count += countBoradPh(start+jump, end);
    }
    return count;
}
int countMazePath(int sr, int sc, int er, int ec)
{   
    if(sr == ec && sc == ec)
    {
        return 1;
    }
    if(sr > er || sc > ec)
    {
        return 0;
    }
    int right = countMazePath(sr, sc+1, er, ec);
    int left = countMazePath(sr+1, sc, er, ec);
    int total = right + left;
    return total;
}
// String Questions
// if there are duplicate chars 
// add a start between them - abbcdde
// - ab*bcd*de
string addStar(string str)
{
    if(str.length()==0)
    {
        return str;
    }
    
    char ch = str[0];
    // rest of the string 
    string ros = str.substr(1);// starts from 1
    // we can assume that we have extracted the 
    // sub problem from str 
    // we are calling the sub-problem in rec
    string recresult = addStar(ros);

    string star ="*";
    // my work
    if(ch == recresult[0])
    {
        // if my character is equal to the 
    // 1st character presnt in the substring
    // the return 
    return ch + star + recresult;
    }
    else
    {
        return ch + recresult;
    }   
}

int main() 
{
    // int n = 5;
    // printInc(n);
    //  //****//
    // cout << endl;
    // printDec(n);
    //  //****//
    // cout << endl;
    // //****//
    // cout << power(2,8) << endl;
    // //****//
    // int arr[]={3,2,4,1,5,61,7};
    // int m = 7;
    // int key = 1;
    // int si=0;
    // cout << linearSearch(arr, si,m, key) << endl;
    // //****//
    // int p = 5;
    // cout << sumTilln(p) << endl; 
    //  //****//
    // incDec(n);
    // cout << endl;
    // //****//
    // cout << power2(2,8) << endl;
    //  //****//
    // incDecOddEven(n);
    // cout << endl;
    // is sorted or not
    // int arr[]={1,2,3,4,5,6,7};
    // int n = sizeof(arr)/sizeof(int);
    // int si =0;
    // cout << isSorted(si,arr,n) << endl;

    // ************** //
    cout << powerBetter(2,8) << endl;

     // ************** //
    int arr[]={1,3,2,3,5,6,7,3,10};
    int n = sizeof(arr)/sizeof(int);
    // in my code maks si == n
    //int si = n;
    int si = 0;
    int key = 3;
    cout << lastIdx(si,arr,n,key) << endl;

    // fibonacci
    cout << fib(10) << endl;

    // consec ones
    cout << consec(3) << endl;

    // Paring problem
    cout << paringProblem(3) << endl;

    // count Board path
    // cout << countBoradPath(10) << endl;

    // count borad path - Pranav
    cout << countBoradPh(0,10) << endl;

    // count maze path
    int a = 2;
    int b = 2;
    cout << countMazePath(0,0,a,b);
    cout << endl;
    // string 
    cout << addStar("addbbcnddhhf") << endl;
    return 0;
}