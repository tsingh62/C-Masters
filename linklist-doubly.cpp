
//g++ sample.cpp -std=c++11

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
youtube video : 
https://www.youtube.com/watch?v=VOQNf1VxU3Q&ab_channel=mycodeschool
*/

// include list as a header
#include<iostream>
#include<list>

using namespace std;

int main()
{
	// doubly linked list
	list <int> ll;

	ll.push_back(3); // insert at tail
	ll.push_front(67); // insert at head

	ll.push_back(89);
	ll.push_back(12);
	ll.push_back(45);

	// now that we have inserted the element
	// we need to get that element now

	cout << ll.front() << endl; // get value at head -67

	cout << ll.back() << endl; // get value at tail -45

	// iterate over the link list
	// for each loop 

	for(int val : ll)
	{
		cout << val << " -> ";
	}
	cout << endl;

	ll.pop_back(); // delete at head
	ll.pop_back(); // delete at back

	cout << "after deleteion" << endl;

	for(int val : ll)
	{
		cout << val << "->";
	}
	cout << endl;

	ll.sort();

	for(int val : ll)
	{
		cout << val << "->";
	}
	cout << endl;

	return 0;
}