

#include<iostream>
#include<deque>
using namespace std;


int main()
{
	deque <int> q;

	q.push_back(2);
	q.push_back(5);
	q.push_back(16);
	q.push_back(8);
	q.push_back(45);

	cout << "Size of deque " << q.size() << endl;

	cout << "Front is " << q.front() << endl;

	cout << "back is  " << q.back() << endl;

	q.pop_front();
	

	cout << "Front now after pop front " << q.front() << endl;

	// cout << "************** Loop **********" << endl;
	// while(!q.empty())
	// {
	// 	cout << q.front() << endl;
	// 	q.pop();
	// }
	return 0;
}