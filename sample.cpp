#include<iostream>
#include<list>
using namespace std;

// linked list has data and address of next node 
// value can be deleted , ddded at front end and back

// doubly linked list has to links
// one to the next node and one to the next 

/* class listNode
{
    int data;
    listNode *nodeNext;
    listNode *nodeprev;
} 
*/

int main()
{
    list <int> l;

    l.push_back(3);
    l.push_front(89);

    l.push_back(10);
    l.push_back(11);
    l.push_back(20);

    for(int val : l)
    {
        cout << val << " -> ";
    }
    cout << endl;
    l.pop_back();
    l.pop_front();

    l.sort();

    for(int val : l)
    {
        cout << val << " -> ";
    }

    cout << endl;
    return 0;
}