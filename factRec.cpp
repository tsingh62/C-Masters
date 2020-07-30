
#include<iostream>
using namespace std;

int fact(int n)
{
    // base case
    if(n==0)
    {
        return 1;
    }
    // Recursion call
    int small_problem=fact(n-1);
    int ans = n*small_problem;
    return ans;
}
int main()
{
    int n=5;
    cout << fact(n) << endl;
    return 0;
}