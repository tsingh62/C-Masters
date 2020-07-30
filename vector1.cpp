

#include<iostream>
#include<vector>
using std::vector;
using namespace std;

//********* to run this code
//  g++ sample.cpp -std=c++11
// ./a.out

int main()
{
	vector<int> d = {1,2,3,4,5};

	// push back O(1) for
	d.push_back(16);
	cout << d.size() << endl;

	// removes the last element 
	d.pop_back();

	// insert some elements in the middle 
	// insert value 100 in position 3
	d.insert(d.begin() + 3,100);
	// is correct - range of elements
	//d.insert(d.begin() + 3,4,100);


	// remove elements from the middle 
	d.erase(d.begin() + 2);

	// is correct - range of elements
	d.erase(d.begin() + 2, d.begin()+5);


    // to check if the vector is empty or not
    if(d.empty())
    {
        cout << "This is an empty vector" << endl;
    }

	for( int x:d)
	{
		cout << x << ", ";
	}
	cout << endl;
}