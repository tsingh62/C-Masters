
// leteCode - 155
// min stack

int minStack(int arr[], int n)
{
	stack<int> s1;
	stack<int> s2;

	int push(int x)
	{
		if(s1.empty() || x<=s.s2.top())
		{
			return (s1.push(x) && s2.push(x));
		}
		else
		{
			s1.push();
		}
		

	}
	int pop()
	{
		if(s1.top()==s2.top())
		{
			return (s1.pop() && s2.pop());
		}
		else
		{
			return s1.pop();
		}
		
	}
	int top()
	{
		return s1.top();
	}
	int getMin()
	{
		return s2.top();
	}
}
int main()
{
	int arr[]={2,3,1,4,6,5,0};
	int n = sizeof(arr)/sizeof(int);

}