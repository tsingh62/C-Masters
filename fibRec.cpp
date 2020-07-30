
#include<iostream>
using namespace std;

// fibonacci series
int fib(int n)
{
    // base case
    if(n==0||n==1)
    {
        return n;
    }
    // rec
    int sub_problem=fib(n-1);
    int sub_problem2=fib(n-2);
    int ans = sub_problem+sub_problem2;
    return ans;
}
int main()
{
    int n=10;
    cout << fib(n) << endl;
    return 0;

}