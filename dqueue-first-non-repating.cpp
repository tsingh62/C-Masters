

// g++ sample.cpp -std=c++11

#include<iostream>
#include<deque>
using namespace std;
 
void printFirstNonRepating()
{
	deque <int> q;

	int freq[256]={0};

	char data;
	// input data value
	cin >> data;

	while(data != '.')
	{
		// push in queue and add the freq
		q.push_back(data);
		freq[data] +=1;

		while(!q.empty())
		{
			char firstOption =q.front();
			
			if(freq[firstOption]>1)
			{
				q.pop_front();
			}
			else
			{
				cout << firstOption << " ";
				break;
			}
		}
		// if you are here 
		// eithre you break the loop or 
		// queue got empty
		if(q.empty())
		{
			cout << " -1 ";;
		}
		cin >> data; // take input for the next value agaon
	}
}


int main()
{
	printFirstNonRepating();

}

// g++ sample.cpp -std=c++11
// input 
// aabccbxhx.
