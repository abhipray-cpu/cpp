// C++ program to demonstrate private
// access modifier

// #include<iostream>
// using namespace std;

// class Circle
// {
// 	// private data member
// 	private:
// 		double radius;
	
// 	// public member function
// 	public:
// 		double compute_area()
// 		{ // member function can access private
// 			// data member radius
// 			return 3.14*radius*radius;
// 		}
	
// };

// // main function
// int main()
// {
// 	// creating object of the class
// 	Circle obj;
	
// 	// trying to access private data member
// 	// directly outside the class
// 	obj.radius = 1.5;
	
// 	cout << "Area is:" << obj.compute_area();
// 	return 0;
// }

//how to access the privatte memebers you ask?
/*we can indirectly access them by using public
methods here is an exmaple*/


// #include<iostream>
// using namespace std;

// class Circle
// {
// 	// private data member
// 	private:
// 		double radius;
	
// 	// public member function
// 	public:
//         double assign(double Rad)
//         {
//             radius=Rad;
//         }
// 		double compute_area()
// 		{ // member function can access private
// 			// data member radius
// 			return 3.14*radius*radius;
// 		}
	
// };

// // main function
// int main()
// {
// 	// creating object of the class
// 	Circle obj;
	
// 	// trying to access private data member
// 	// directly outside the class
// 	obj.assign(1.5);
	
// 	cout << "Area is:" << obj.compute_area()<<endl ;
//     cout<<"Wallh problem solved threrfore we can access the private using public memmbers declared wiithin same class"<<endl;
// 	return 0;
// }

//protected access specifier
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class protect
{
    protected:
    int hoot;
    // void assign(int value)
    // {
    //     hoot=value;
    // }
};

class playboy:public protect
{
    public:
    void degi(int answer)
    {
        hoot=answer;
    }
    void kyaBoli()
    {
        cout<<"Bhai she said "<<hoot<<" To your answer"<<endl;
    }
};
int main()
{
    playboy P1;
    protect P2;
    P1.degi(1);
    P1.kyaBoli();
    // P2.assign(0);
    // P1.kyaBoli();
    return 0;
}