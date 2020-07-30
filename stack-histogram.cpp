#include<iostream>
#include<stack>
using namespace std;

int histrogramArea(int arr[], int n)
{
	stack <int> s;
	int maxArea =0;
	int i=0;

	while(i<n)
	{
		if(s.empty() || arr[s.top()]<=arr[i])
		{
			s.push(i);
			i++;
		}
		else
		{
			// if you are here means your index value
			// is acting as the next smaller for the
			// current stack top element
			// next smaller for the current wlement on the top
			int extactTop = s.top();
			s.pop();
			int height = arr[extactTop];

			int nextSmallerIdx = i;
			int previousSmallerIdx = s.top();
			int currArea;
			if(s.empty())
			{
				int width = nextSmallerIdx;
				currArea = width * height;  
			}
			else
			{
				int prevSmallerIndex = s.top();
				int width = nextSmallerIdx - prevSmallerIndex-1;

				currArea = width * height;
			}
			maxArea = max(maxArea, currArea);
		}
	}

	// now when you i reaches to the last index n
		// now you will consider the nth bar as the 0 ht bar
		// so that it could act as the next smaller element for
		// the remanining value in my stack

		while(s.empty())
		{
			int extactTop = s.top();
			s.pop();
			int height = arr[extactTop];

			int nextSmallerIdx = i;
			int previousSmallerIdx = s.top();
			int currArea;
			if(s.empty())
			{
				int width = nextSmallerIdx;
				currArea = width * height;  
			}
			else
			{
				int prevSmallerIndex = s.top();
				int width = nextSmallerIdx - prevSmallerIndex-1;

				currArea = width * height;
			}
			maxArea = max(maxArea, currArea);
		}
	return maxArea;
}
int main()
{
	int arr[]={1,2,3,1,2};
	int n = 5;
	cout << histrogramArea(arr,n)<< endl;
	return 0;
}