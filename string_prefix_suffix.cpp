// CPP program to find length of the
// longest prefix which is also suffix
#include <iostream>
using namespace std;

// Function to find largest prefix 
// which is also a suffix
int largest_prefix_suffix(const std::string 
									&str) 
{

int n = str.length();

// if n is less than 2
if(n < 2) {
	return 0;
}

int len = 0;
int i = (n + 1)/2;

// Iterate i till n
while(i < n)
{
	
	// If str[i] is equal to 
	// str[len]
	if(str[i] == str[len]) 
	{
        ++len;
        ++i;
	}
	else
	{
        i = i - len + 1;
        len = 0;
	}
}

// Return len
return len;

}

// Driver code
int main() 
{
	
string s = "blablabla";

// Function Call
cout << largest_prefix_suffix(s);
return 0;
}
