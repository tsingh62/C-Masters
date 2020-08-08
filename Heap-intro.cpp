

#include<iostream>
#include<vector>
using namespace std;

class solution
{
	vector<int> v;
	bool minHeap;
	// private
	bool compare(int a, int b)
	{
		if(minHeap)
		{	// for min heap
			return a < b;
		}else
		{	// for max Heap
			return a > b;
		}
		

	}
	void heapify(int idx) // index of the node that w
							// what to heapify
	{
			int left = 2*idx;
			int right = left +1;

			int min_idx = idx;
			
			int last = v.size()-1;
			/*store the smallest element */
			if(left <= last && compare(v[left], v[idx]))
			{
				min_idx = left;
			}
			if(right <= last && compare(v[right], v[min_idx]))
			{
				min_idx = right;
			}
			if(min_idx!=idx)
			{
				swap(v[idx], v[min_idx]);
				heapify(min_idx);
			}
	}

public:
	
	Heap(int default_size=10, bool type = true)
	{
		v.reserve(default_size);
		// vector will not expand until 10 elements 
		// are added in the heap
		v.push_back(-1); // block the 0th index

		minHeap = type; // if its a minHeap
						// the variable is set to true
	}
	void push(int d)
	{
		v.push_back(d); // push the element at the last idx
		
		//v.size() will give 11 as the 0th idx is blocked
		// so we use -1 to know at the idx we did 
		// the insertion. Which is the last idx
		int idx = v.size()-1;

		// parent idx
		int parent = idx/2;

		// keep pushing the element to the top
		// until the element has not reached the
		// correct position- as per heap property
		// either u reach root node 
		// or you stop midway because current 
		// element is already greater than parent
		while(idx > 1 && compare(v[idx], v[parent]))
		{
			swap(v[idx], v[parent]);
			idx = parent;
			parent = parent/2;
		}
	}
	int top()
	{
		return v[1];
		// return the top most element 
	}
	void pop()
	{
		int last = v.size()-1;
	//	swap(v[1], v[last_idx]);
		swap(v[1], v[last]);
		v.pop_back();
		heapify(1);
		
	}
	bool empty()
	{
		return v.size()==1;
	}
	
};

int main()
{
	solution s;
	s::Heap  = h;
	int n;

	cin >> n;
	for(int i=0; i<n, i++)
	{
		int num;
		cin >> num;
		h.push(num);
	}

	// remove all the elements 
	while (!h.empty())
	{
		cout << h.top() << " ";
		h.pop();
	}

	
	return 0;
}
//g++ sample.cpp -std=c++11