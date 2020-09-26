#include<iostream>
#include<stack>
using namespace std;


void transfer(stack <int> &s1, stack<int> &s2, int n)
{                           // we has to transfer n no if elements

    for(int i=0; i<n; i++)
    {
            s2.push(s1.top());
            s1.pop();
    } 
}

void revStack(stack <int> &s1)
{
    // helper stack
    stack <int> s2;

    int n = s1.size();

    for(int i=0; i<n; i++)
    {
        // pick the element at top and insert it at the bottom
        int x = s1.top();
        s1.pop();

        // transfer n-i-1 elements from stack s1 and s2
        transfer(s1,s2,n-i-1);
        // insert the element x in s1
        s1.push(x);

        // transfer n-i-1 elements from s2 to s1
        transfer(s2,s1,n-i-1);
    }


     
}
int main()
{
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    revStack(s);

    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}