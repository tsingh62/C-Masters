#include<iostream>
#include<stack>
using namespace std;


int stockSpan(stack<)
{
	stack <pair<int, int>> s;
	int step =1;
	
	// constuctor
	stockSpan()
	{
		s.push({INT_MAX,0});
	}
	int next(int price)
	{
		while(price>=s.top().first)
		{
			s.pop();
		}
		int diff = step - s.top.second;
		
		s.push({price, step});
		step++;
		return diff;
	}
	
}

int main()
{
	// to stork to values together
// ****************************************//
	// pair <int, string> p;
	// p.first =10; // int
	// p.second = "pranav";  // string
// ****************************************//
	// another way to define pair 

	// pair<string, int> p("pranav", 89);
	// cout <<"First value " << p.first << endl;
	// cout << "Second value " << p.second << endl;
// ****************************************//
	// another way to define pair 

	// pair<char, int> p;
	// p=make_pair('A,23);

	// cout << p.first << endl;
	// cout << p.second << endl;

// ****************************************//

	// to store stack pair
	stack <pair<int, int>>, s;
	cout << stockSpan();
	return 0;
}