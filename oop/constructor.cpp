//constructor in cpp are basically used for assigning the values to variables
/*palin constructor and parameterized constructor and last but not thhe least copy constructor*/

// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// class bhuttan
// {
//    public:
//    int a,b;
//     bhuttan(int c,int d)//parameterized
//    {
//        a=c;
//        b=d;
//    }
//    bhuttan()//default
//    {
//        a=69;
//        b=79;
//    }
  
//    //copy constructor?
//    void printIt()
//    {
//        cout<<"The first number is "<<a<<" and the second number is "<<b<<endl;
//    }
// };
// int main()
// {   bhuttan B;
//     bhuttan();
//     B.printIt();
//     bhuttan(59,23);
//     B.printIt();
//     return 0;
// }

//copyy constructor
/*A copy constructor is a constructor which initializes one constructor ussing anotheer constructor*/
// Illustration
#include "iostream"
using namespace std;

class point
{
private:
double x, y;

public:

// Non-default Constructor &
// default Constructor
point (double px, double py)
{
	x = px, y = py;
}
};

int main(void)
{

// Define an array of size
// 10 & of type point
// This line will cause error
// point a[10];

// Remove above line and program
// will compile without error
point b = point(5, 6);
}
