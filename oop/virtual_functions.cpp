// // // /*it is a fucntion which we define in parent class abd expect it to be redefined in the children class*/
// // // #include<iostream>
// // // #include<bits/stdc++.h>
// // // using namespace std;

// // // class Chiranshu
// // // {
// // //     public:
// // //     virtual void introduce()
// // //     {
// // //         cout<<"Bhak bsdlk"<<endl;
// // //     }
// // // };

// // // class Chetan:public Chiranshu
// // // { 
// // //     public:
// // //     void introduce()
// // //     {
// // //         cout<<"Hi I am chetan and my father's name is chiranshu"<<endl;
// // //     }
// // // };

// // // class Mohan:public Chiranshu
// // // { 
// // //     public:
// // //     void introduce()
// // //     {
// // //         cout<<"Hi I am Mohan and my father's name is chiranshu"<<endl;
// // //         cout<<"My father has a crush on Tiwariji like all of his other batch mates"<<endl;
// // //     }
// // // };

// // // int main()
// // // {
// // //     Chetan C;
// // //     Mohan M;
// // //     C.introduce();
// // //     M.introduce();
// // //     return 0;
// // // }
// // //when a virtual function is inherited it's nature is also inherited
// // //pure virtual function
// // /*sometimes we don't the future posiibilities in which senese the function will work
// // therefore we just declare a virtual function in base class and then wait for it to be modified
// // in the base class*/

// // #include<iostream>
// // #include<bits/stdc++.h>
// // using namespace std;

// // class Bhuttan
// // {
// //     public:
// //     virtual void show() =0;
// //     Bhuttan()
// //     {
// //         cout<<"Roopa MC"<<endl;
// //     }
// // };

// // class Puttanpal:public Bhuttan
// // {
// //     public:
// //     void show(int a ,int b)
// //     {
// //         cout<<"Tau keh rha hai "<<a<<" baar teri gaand maruga aur "<<b<<" birju se marwauga"<<endl;
// //     }
// // };

// // class Dhaiya:public Bhuttan
// // {
// //     public:
// //     void show(bool ans)
// //     {
// //         cout<<"Ib baat aisis hai dekh bhai ldki ne mu pe "<<ans<<" bola hai aage tu dekhle"<<endl;
// //     }
// // };

// // int main()
// // {
// //     Puttanpal P;
// //     Dhaiya D;
// //     P.show(58,69);
// //     D.show(true);
// //     return 0;
// // }

// #include<iostream>
// using namespace std;

// class Base
// {
// int x;
// public:
// 	virtual void fun() = 0;
// 	int getX() { return x; }
// };

// // This class inherits from Base and implements fun()
// class Derived: public Base
// {
// 	int y;
// public:
// 	void fun() { cout << "fun() called"; }
// };

// int main(void)
// {
// 	Derived d;
// 	d.fun();
// 	return 0;
// }


