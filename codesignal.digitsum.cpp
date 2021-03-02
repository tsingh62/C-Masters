#include<iostream>
using namespace std;
#include<vector>

vector<string> split_string(string);

int superDigit(string n, int k)
{
    if(n.size() == 1) return stoi(n);
    long super = 0;
    for(char& c : n)
        super += c -48;


    super *= k;
    return superDigit(to_string(super), 1);
}