#include<iostream>
#include<vector>
using std::vector;
using std::cout;
using std::endl;

//********* to run this code
//  g++ sample.cpp -std=c++11
// ./a.out

int main ()
{
   vector<int> data = {1,2,3};

   data.push_back(12); // insert element 
   cout << data.size() << endl;

   cout << data[3] << endl;
   
   cout << data[data.size()-1] << endl;

   data.pop_back(); // delete element

    cout << data.size() << endl;

}