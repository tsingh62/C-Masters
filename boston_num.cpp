/*The Question is Very Simple but needs a little extra concentration. As many students do not consider that in the Question it said the sum of digits of the given number is Equals to the sum of digits of its prime numbers is equal only when the number is Boston number.
For e.g.., n = 22
Prime Factors = 2 x 11
Sum of Digits = 2 + 2 = 4
Sum of Digits of Factors = 2 + (1 + 1) -> 4
Hence it is a Boston number.

Algorithm
Generate All prime Factors of the number.
Write a Function that calculates the sum of digits of passed number.
Pass each generated Prime Factor to this digits sum function till you can generate prime factors.
At last equate your sum with the sum of digits of given number.
4.1 If yes print 1.
4.2 otherwise print 0.
Note -> Make your code a little Efficient otherwise you will get TLE with brute force approach. By making code efficient is either you need to make your prime factor generator efficient or prime checker efficient in order to pass the test cases.

Lang - Cpp
Required Code is given below : */


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n, sum=0, sum_n=0;  
    cin>>n;
    int temp=n;
    while(temp>0)
    {
        sum_n=sum_n+(temp%10);
        temp/=10;
    }
    while (n%2 == 0)
    {
        sum+=2;
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        while (n%i == 0)
        {
           int temp1=i;
            while(temp1>0)
    {
        sum=sum+(temp1%10);
        temp1/=10;
    }

            n = n/i;
        }
    }

    if (n > 2)
    {  while(n>0)
    {
        sum=sum+(n%10);
        n/=10;
    }}

    if(sum_n==sum)
        cout<<"1";
    else
        cout<<"0";
    return 0;
}