#include<vector>
#include<iostream>
using namespace std;
/*Piyush and Nimit are playing a coin game. They are given n coins with values x1, x2 …. xn where 'n' is always even. 
They take alternate terms. In each turn, a player picks either the first coin or the last coin from the row and removes it from the row. 
The value of coin is received by that player. Determine the maximum value that Piyush can win with if he moves first. Both the players play optimally.

Input Format
First line contains the number of coins 'n'.
Second line contains n space separated integers where ith index denotes the value of ith coin.

Constraints
1 < N <= 30 , N is always even
0 <= Ai <= 1000000

Output Format
Print a single line with the maximum possible value that Piyush can win with.

Sample Input
4
1 2 3 4
Sample Output
6
Explanation
Piyush will pick the coin 4. Then Nimit can pick either 1 or 3. In both the cases piyush picks coin 2 and wins with a total of 6.*/

#define ll long long int

ll coins[40];

ll optimalGame(ll i,ll j)
    {
    if(i > j){
        return 0;
    }

    // Consider both the possibilities. You can pick either the first or the last coin.
    // Since the opponent plays optimally , we would get the minimum of the remaining coins for each choice.
    ll pickFirst = coins[i] + min( optimalGame(i+2,j) , optimalGame(i+1,j-1) ) ;
    ll pickLast = coins[j] + min( optimalGame(i,j-2) , optimalGame(i+1,j-1) ) ;

    // Pick the max of two as your final result
    ll ans = max(pickFirst,pickLast);

    return ans;
}
// *********************************** 2 ***************************** //

/*Take as input str, a string. str represents keys pressed on a nokia phone keypad. 
We are concerned with all possible words that can be written with the pressed keys.

Assume the following alphabets on the keys: 1 -> abc , 2 -> def , 3 -> ghi , 4 -> jkl , 5 -> mno , 6 -> pqrs , 7 -> tuv , 8 -> wx , 9 -> yz

E.g. “12” can produce following words “ad”, “ae”, “af”, “bd”, “be”, “bf”, “cd”, “ce”, “cf”

a. Write a recursive function which returns the count of words for a given keypad string. Print the value returned.

b.Write a recursive function which prints all possible words for a given keypad string (void is the return type for function).

Input Format
Single line input containing a single integer.

Constraints
1 <= Length of string <= 10^3

Output Format
Print all the words in a space separated manner. Also print the count of these numbers in next line.

Sample Input
12
Sample Output
ad ae af bd be bf cd ce cf
9
Explanation
1 can correspond to 'a' , 'b' or 'c' .
2 can correspond to 'd', 'e' or 'f'.
We print all combinations of these
==========================================//
Approach Discussion
Here, we use recursion.

Create a database table to store all characters correspond to digit i in the keyboard.

We store all possible words that can be obtained by input string[] of size n.

We store words in output[].

Try all possible characters for current digit and recursion for remaining digits.

We print the final output array.

C++ Code
*/


#include <cstring>


string keypad[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wx", "yz"};

int count1 = 0;

void keypadCode(string inp, string out, int i)
{
    //Base case
    if (i == inp.size())
    {
        cout << out << " ";
        count1++;
        return;
    }

    //Rec case
    int r = inp[i] - '0';
    for (int k = 0; k < keypad[r].size(); k++)
    {
        char ch = keypad[r][k];
        keypadCode(inp, out + ch, i + 1);
    }
}
/******************** 3 *********************/
// Given a long vector of strings, print the strings that contain the strings generated by numeric string str.

// string searchIn [] = {
//             "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
//             "utkarsh", "divyam", "vidhi", "sparsh", "akku"
//     };
// For example, if the input is 26 and the string is coding, then output should be coding since 26 can produce co which is contained in coding.

// Input Format
// A numeric string str

// Constraints
// len(str) < 10
// No of strings in the vector < 10

// Output Format
// Each matched string from the given vector.

// Sample Input
// 34
// Sample Output
// vidhi
// divyam
// sneha
// Explanation
// 34 will result into combinations :

// *dg         *eg         *fg
// *dh            *eh         *fh
// *di            *ei         *fi
// Corresponding strings are output.

// vidhi contains dh
// divyam contains di
// sneha contains eh
 vector<string> table = {" ", ".+@$", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

vector<string> searchIn = {
    "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
    "utkarsh", "divyam", "vidhi", "sparsh", "akku"};

void phoneKeypad(string inp, string out)
{
    //Base case
    if (inp.size() == 0)
    {
        for (string ss : searchIn)
        {
            if (ss.find(out) != ss.npos) /* npos = no position - stores a constant value -1
                                        what is does is when you look for a string and its not thete
                                        it will help prevent an exception - error from generating,
                                        static - constant - all strings have access to it*/
            {
                cout << ss << endl;
            }
        }
        return;
    }

    //Rec case
    char ch = inp[0];
    string ros = inp.substr(1);
    string code = table[ch - '0'];

    for (int i = 0; i < code.length(); i++)
        phoneKeypad(ros, out + code[i]);
}

// *****************************  4  ************************************ //

bool subsetSumEasy(const vector<int> &v, int i = 0, int sum = 0, bool included = false)
{
    if (i == v.size())
    {
        return (sum == 0 && included);
    }

    bool inc = subsetSumEasy(v, i + 1, sum + v[i], true);
    bool exc = subsetSumEasy(v, i + 1, sum, included);

    return inc || exc;
}

/************************** 5 ******************************/
// Quick sort

#include<iostteam>
using namespace std;
// Quick sort --

// function for doing partition in array
long long int partition(long long int a[],long long int be,long long int end)
{
    srand(time(NULL));

    //taking pivot as random element of the array use inbuilt rand function 
   //generating a random number between beginning and ending index
    int pivotIndex = be + rand() % (end - be+1);
    int pivot;
    pivot = a[pivotIndex];

    swap(a[pivotIndex], a[end]);
    pivotIndex = end;
    int k = be - 1;
    for (int i = be; i <end; i++)
    {
        if (a[i] <= pivot)
        {
            k++;
            swap(a[i], a[k]);
        }
    }
    swap(a[k + 1], a[pivotIndex]);
    return (k + 1);
}

// function for quick sort
void quicksort(long long int a[],long long  int be,long long  int end)
{
    if (be < end)
    {
        long long int p = partion(a, be, end);
        quicksort(a, be, p-1);
        quicksort(a, p + 1, end);
    }
}



int main() 
{
    int n;
    cin >> n;   

    for(int i=0;i<n;i++){
        cin >> coins[i];
    }

    cout << optimalGame(0,n-1);

    // *********** 2 ***************//

    string inp;
    cin >> inp;
    string output;
    keypadCode(inp, output, 0);
    cout << endl << count1;

    // **************** 3 ******************* //
    string input;
    cin >> input;

    string output;
    phoneKeypad(input, output);


    // ***************** 4 ******************** //
    // int testCases;
    // cin >> testCases;
    // while (testCases--)
    // {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        if (subsetSumEasy(v))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    // }



    return 0;
}