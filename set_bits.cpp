#include<iostream>
using namespace std;

int func(int n)
{   
    int count=0;
    
    while(n)
    {
       count += n &1;
       n = n >> 1;
    }
    return count;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin  >> n;
        cout << func(n) << endl;
    }
}


/***************/
// max xor of two values
/*
#include<iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a;
    cin >> b;

    int i = 0;
    int last = 10005;

    int val = 0;

    if((i <= a && a<= b) && (b<= last))
    {
        val = a ^ b;
    }
    else
    {
        return 0;
    }
    
     cout << val << endl;
}
*/