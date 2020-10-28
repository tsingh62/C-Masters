/*
Deepak and Gautam are having a discussion on a new type of 
number that they call Coding Blocks Number or CB Number. 
They use following criteria to define a CB Number.

0 and 1 are not a CB number.
2,3,5,7,11,13,17,19,23,29 are CB numbers.
Any number not divisible by the numbers in point 2( Given above) are also CB numbers.
Deepak said he loved CB numbers.Hearing it, Gautam throws a challenge to him.

Gautam will give Deepak a string of digits. Deepak's task is to 
find the number of CB numbers in the string.

CB number once detected should not be sub-string or super-string of any other CB number.
Ex- In 4991, both 499 and 991 are CB numbers but you can choose either 499 or 991, not both.

Further, the CB number formed can only be a sub-string of the string.
Ex - In 481, you can not take 41 as CB number because 41 is not a sub-string of 481.

As there can be multiple solutions, Gautam asks Deepak to find the maximum 
number of CB numbers that can be formed from the given string.

Deepak has to take class of Launchpad students. Help him by solving Gautam's challenge.

Input Format
First line contain size of the string.

Next line is A string of digits.

Constraints
1 <= Length of strings of digits <= 17

Output Format
Maximum number of CB numbers that can be formed.

Sample Input
5
81615
Sample Output
2
Explanation
61 and 5 are two CB numbers.
*/

#include<iostream>
using namespace std;
// #define ll long long int
#include<cmath>



long stoint(string s)
{
    long i,j=0;
    i = 0;
    while(s[j] >= '0' && s[j] <= '9')
    {
        i = i * 10 + (s[j] - '0');
        j++;
    }
    return i;
}

bool is_cb_number(string s)
{
    long long num = stoint(s);
    if (num == 0 || num == 1) {
        return false;
    }
    int arr[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };

        for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
            if (num == arr[i]) {
                return true;
            }
        }

        for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
            if (num % arr[i] == 0) {
                return false;
            }
        }

    return true;
}

bool is_valid(bool * visited, int l, int r)
{
    for(int i=l;i<r;i++)
    {
        if(visited[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    long count = 0;
    bool* visited = new bool[n];
  for(int i=0; i<s.length(); i++)
    {
        visited[i]=false;
    }
    for(int i=1; i <= s.length(); i++)
    {
        for(int j=0; j<=s.length()-i; j++)
        {   int e = j+i;
            string sub = s.substr(j, e-j);
            if(is_cb_number(sub) && is_valid(visited,j,e))
            {
                count++;
                for(int k=j;k<e;k++)
                {
                    visited[k]=true;
                }
            }
        }
    }
    cout<<count<<endl;
    return 0;
}


/************* 2 ***************/
/*
Prateek is an extremely gifted student. He is great at everything 
including Combinatorics, Algebra, Number Theory, Geometry, Calculus, 
etc. He is not only smart but extraordinarily fast!.

One day Prateek was trying to find out if any one can possibly do 
calculations faster than him. As a result he made a very great 
contest and asked every one to come and take part.

In his contest he gave the contestants many different pairs of numbers. 
Each number is made from digits 0 or 1. The contestants should write a 
new number corresponding to the given pair of numbers. The rule is simple: 
The i-th digit of the answer is 1 if and only if the i-th digit of the two 
given numbers differ. In the other case the i-th digit of the answer is 0.

Prateek made many numbers and first tried his own speed. He saw that he can 
perform these operations on numbers of length ∞ (length of a number is number 
of digits in it) in a glance! He always gives correct answers so he expects the
 contestants to give correct answers, too. He is a good fellow so he won't give 
 anyone very big numbers and he always gives one person numbers of same length.

Now you are going to take part in Shapur's contest. See if you are faster and more accurate.

Input Format
The first line contains an integer t , the no. of testcases. There are two inputs 
in each line. Each of them contains a single number. It is guaranteed that the numbers are made 
from 0 and 1 only and that their length is same. The numbers may start with 0.

Constraints
The length of each number doesn't exceed 100.

Output Format
Write t lines — the corresponding answer to the corresponding input. Do not omit the leading 0s.

Sample Input
1
10111 10000
Sample Output
00111
Explanation
For the given example, Let str1 = "10111" and str2 = "10000", Value at 
first position of str1 is 1 and first position str2 is 1, 
hence according to the rule there will be 0 at the first position of 
the final ans.Similarly, for second position the value at second position of 
both of the strings is 0,so , there will be 0 at the second position of the 
final ans.Similarly, for third position the value at third 
position of str1 is 1 and str2 is 0,so , there will be 1 at the third 


position of the final ans and So, on.*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        string s1, s2;
        cin >> s1 >> s2;
        for (size_t i = 0; i < s1.length(); ++i)
        {
            if (s1[i] == s2[i])
            {
                s1[i] = '0';
            }
            else
            {
                s1[i] = '1';
            }
        }
        cout << s1 << endl;
    }
    return 0;
}
/************** 3 ****************/

/*
Take as input S, a string. Write a function that does basic string compression. 
Print the value returned. E.g. for input “aaabbccds” print out a3b2c2d1s1.

Input Format
A single String S

Constraints
1 < = length of String < = 1000

Output Format
The compressed String.

Sample Input
aaabbccds
Sample Output
a3b2c2d1s1
Explanation
In the given sample test case 'a' is repeated 3 times 
consecutively, 'b' is repeated twice, 'c' is repeated twice and 'd and 's' occurred only once.
*/
#include<iostream>
using namespace std;

string compress(string str)
{
    if (str.size() == 0)
    {
        return "";
    }

    char ch = str[0];
    int i = 1;
    while (i < str.size() && str[i] == ch)
    {
        i++;
    }

    string ros = str.substr(i);
    ros = compress(ros);

    string charCount = to_string(i);
    return ch + charCount + ros;
}

int main()
{
    string s;
    cin >> s;

    cout << compress(s) << endl;

    return 0;
}

/******************** 4 ********************/
/*
One of the important aspect of object oriented programming is 
readability of the code. To enhance the readability of code, 
developers write function and variable names in Camel Case. 
You are given a string, S, written in Camel Case. FindAllTheWordsContainedInIt.

Input Format
A single line contains the string.

Constraints
|S|<=1000

Output Format
Print words present in the string, in the order in which it appears in the string.

Sample Input
IAmACompetitiveProgrammer
Sample Output
I
Am
A
Competitive
Programmer
Explanation
There are 5 words in the string.
*/
#include<iostream>
using namespace std;
int main()
{
    int n;

    string s;
    cin>>s;
    
    n=s.length();

    string pr;
    
    for(int i=0;i<n;i++)
    {
        pr.push_back(s[i]);
        if(i==n-1) //last letter
            cout<<pr<<endl;
        else if(s[i+1]>='A' && s[i+1]<='Z') //s[i+1] is a capital letter.
        {
            cout<<pr<<endl;
            pr.clear();
        }
    }
    return 0;
}


/***************** 5 *****************/
/*
Take as input S, a string. Write a function that returns 
the character with maximum frequency. Print the value returned.

Input Format
String

Constraints
A string of length between 1 to 1000.

Output Format
Character

Sample Input
aaabacb
Sample Output
a
Explanation
For the given input string, a appear 4 times. Hence, it is the most frequent character.
*/

#include <iostream>
using namespace std;
int main() 
{
    char str[1000];
    int freq[256];
    cin>>str;

    for(int x=0;str[x]!='\0';x++)
    {
        freq[str[x]]++;
    }
    
    int ans=0;
    char ch;
    for(int x=0;x<256;x++)
    {
        if(freq[x]>0)
        {
            if(freq[x]>ans)
            {
                ans=freq[x];
                ch=char(x);
            }
        }
    }
    cout<<ch;
}

/********************* 6 ***********************/

/*You can solve this problem in O(n) time using 
the two pointer approach.

Make two variabes , say i and j .
i defines the beginning of a window and j defines its end.
Start i from 0 and j from k.
Let’s talk about the singular case when we are 
considering the max window for only 'a’s and
consider only the swapping of b-> a. 
If we are able to get the answer for max window of
consecutive 'a’s , we can simply implement the same 
algo for the max ‘b’ window as well.
So we started i from 0 and j from k.
Move j ahead freely as long as there are ‘a’ 
characters at s[ j ] position.
Maintain a count variable which counts the number 
of swaps made or the number of 'b’s in our A window.
If you encounter a ‘b’ char at s[ j ] position , 
increment the count variable. Count should never exceed k .
Take the size of the window at every point using length = j - i + 1;
Compute the max size window this way and do the same for ‘b’ as well.
Output the maximum size window of ‘a’ and ‘b’.
C++ Code */

#include <iostream>
#include <cstring>
using namespace std;

//Function to count the length of window which can be made of char ch with <= k swaps
int countMaxWindowSize(const string &s, char ch, int k)
{
    int i = 0; //Left pointer
    int j = 0; //Right pointer

    //First move the right pointer forward by k steps.
    //If the character is already ch , do not count a swap and move freely

    int c = 0; //Variable to count the swaps so far

    int ans = 0; //Variable to store the final answer

    for (j; c < k && j < s.size() - 1; j++)
    {
        if (s[j] != ch)
        {
            //If s[j] is not ch then count it as a swap and move forward
            c++;
        }
        if (c == k)
        {
            //If no of swaps has reached k, stop moving j any more forward
            break;
        }
    }

    while (i < j)
    {

        //Move j ahead if next element is ch as it doesn't count as a swap
        while (j < s.size() - 1 && s[j + 1] == ch)
        {
            j++;
        }

        //Store the maximum length of all windows
        int currentLength = j - i + 1;
        ans = max(ans, currentLength);

        //Move left pointer by one to slide the window
        i++;

        //If the char at previous position of left pointer was not ch, then that position must
        //have counted as a swap earlier. Now we have a free swap available.
        //Iterate right pointer forward to use that one free swap
        if (j < s.size() - 1 && s[i - 1] != ch)
        {
            j++;
        }
    }

    return ans;
}

int main()
{
    int k;
    cin >> k;
    string s;
    cin >> s;

    if (k >= s.size())
    {
        //If k is larger than s.size() then we can swap all the elements to either A or B
        //and obtain the answer equal to length of string
        cout << s.size();
        return 0;
    }

    //First let us check for longest perfect string of A's then we will find the same for B's and compare
    int ansForA = countMaxWindowSize(s, 'a', k);

    //Now we do the same for B's
    int ansForB = countMaxWindowSize(s, 'b', k);

    //Final answer is max of the two answers obtained above
    cout << max(ansForA, ansForB);

    return 0;
}


/*************** 7 *****************/

/*
Take as input S, a string. 
Write a program that inserts between each pair 
of characters the difference between their ascii codes and print the ans.

Input Format
String

Constraints
Length of String should be between 2 to 1000.

Output Format
String

Sample Input
acb
Sample Output
a2c-1b
Explanation
For the sample case, the Ascii code of a=97 and c=99 ,
the difference between c and a is 2.Similarly ,the Ascii code of b=98 and c=99 and their difference is -1. So the ans is a2c-1b.
*/

#include <iostream>
#include <string>
using namespace std;

int main() 
{
    char str[1000];
    int nstr[2000];

    cin>>str;

    int i=1;
    
    cout<<str[0];
    
    while(str[i]!='\0')
    {
        nstr[i]=int(str[i])-int(str[i-1]);
        cout<<nstr[i]<<str[i];
        i++;
    }
    return 0;
}
