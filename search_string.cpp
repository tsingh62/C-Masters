#include<iostream>
using std::cout;
using std::endl;
using std::string;

int main()
{
  
    string greet = "Hello Welcome back again";

    string::size_type position;

    // finding a string 
    position = greet.find("back");
   
    cout << position << endl;
    cout << "The position of back: " << greet.find('a') << endl;



}