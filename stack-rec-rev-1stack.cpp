#include<iostream>
#include<stack>
using namespace std;


void insertAtBottom(stack<int> &s, int x)
{
    // base case
    if(s.empty())
     {
        s.push(x); // suppose x=5 which we need to add at the bottom
        return; 
     }
     // rec case
     int data = s.top();
     s.pop();
    
     insertAtBottom(s,x);// x remains 5 here 
     s.push(data); // now we push the rest of the data into the stack
}
void recRev(stack<int> &s)
{
    int n = s.size();

    // base case
     if(s.empty())
     {
         return;
     }
     // otherwise
     /* Pop out the top element and insert it at the bottom
     of the 'reversed smaller stack' */

     int x = s.top();
     s.pop();

     // Rec rev the smaller stack
     recRev(s);
     insertAtBottom(s,x);

     
}

int main()
{
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    recRev(s);
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}