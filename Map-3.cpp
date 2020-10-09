#include<iostream>
using namespace std;
#include<map>
#include<vector>


int main()
{   // less for ascending order
     map<string, int, less<string>> Map;
   // map<string, int> Map;
  //  map<string, int, greater<string>> Map;

    // using greater here as we need to print 
    // in descending order we can select<string or int>
    // here
    Map["Chotu"]= 1001;
    Map["Amit"]=1002;
    Map.insert(make_pair("Bot",1003));

    // for loop
    for(auto val : Map)
    {
        cout << val.first << "  " << val.second << endl;
        // this will sort it 
        // The greater paramter over rules the 
        // val.first and val.second code
    }
    cout << endl;
// example - 2

    map<int , string> Map1;   
    Map1[1001]="Chotu";
    Map1[1002]="Amit";
    Map1.insert(make_pair(1003,"Bot"));

    // for loop
    for(auto val1 : Map1)
    {
        cout << val1.first << "  " << val1.second << endl;
        // this will sort it 
    }
    cout << endl;
    // using vector 
    map<string, vector<int>> Map2;
    Map2["Chotu"].push_back(10001);
    Map2["Amit"].push_back(1002);
    Map2["Amit"].push_back(1003);
  //  Map2.insert(make_pair(1003,"Bot"));

    for(auto val2 : Map2)
    {
        cout << val2.first << " ";
        for(auto nbr : val2.second)
        {
            cout << nbr << endl;
        }
    }
    
    return 0;
}