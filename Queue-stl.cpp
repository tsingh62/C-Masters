

#include<iostream>
#include<queue>
using namespace std;


int main()
{
	queue <int> q;

	q.push(2);
	q.push(5);
	q.push(16);
	q.push(8);
	q.push(45);

	cout << "Front is having value" << q.front() << endl;

	q.pop();
	q.pop();

	cout << "Front value" << q.front() << endl;

	cout << "************** Loop **********" << endl;
	while(!q.empty())
	{
		cout << q.front() << endl;
		q.pop();
	}
	return 0;
}