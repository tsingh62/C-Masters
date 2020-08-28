#include<iostream>
#include<queue>
using namespace std;


// Queue
/* push - back
   pop - front
   front - just gives the value from the front
   empty - to see if the queue is empty or not
   full - to check if the queue is full or not
*/

int main()
{
    queue<int> q;

    for(int i=1; i<=5; i++)
    {
        q.push(i);
    }

    while(!q.empty())
    {
        cout << q.front() << "<-";
        q.pop(); // from the front 
    }
    cout << endl;

    return 0;
}