#include<iostream>
#include<deque>
using namespace std;


/* Deque STL 

Functions on both end

pop-front -
push-front
get-front 

pop-back
push-back
get-back*/

int main()
{
    deque <int> q;

    q.push_back(12);
    q.push_back(13);
    q.push_back(14);
    q.push_back(15);

    cout << "Size of deck is " << q.size() << endl;

    cout << "Front is "<< q.front() << endl;

    cout << "Back is " << q.back() << endl;

    q.pop_front();
    cout << "Front is not after pop front " << q.front() << endl;
    
    return 0;
}