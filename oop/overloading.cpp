/*in cppp we can make operators to work for user defined calsses
i.e we have the poweer to modify the operators as per our needs and provide them with special
meanings specific to our needs here is an example*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Complex
{
     private:
     int real,imag;
     public:
     Complex(int r=0,int i=0)
     {
         real=r;
         imag=i;
     }
     Complex operator + (Complex const &obj)//in case you are wonderig we are passsing second complex number via pointer for the binary operation
     {
         Complex res;
         res.real=real+obj.real;
         res.imag=imag+obj.imag;
     }

       Complex operator - (Complex const &obj)
     {
         Complex res;
         res.real=real-obj.real;
         res.imag=imag-obj.imag;
     }


     void print()
     {
         cout<<"This number was obtained after addition of the complex numbers entered by you"<<endl;
         cout<<real<<"+"<<"i"<<imag<<endl;
     }
};

int main()
{
    Complex c1(10,15),c2(89,69);
    Complex c3=c1+c2;
    c3.print();
    Complex c4=c2-c1;
    c4.print();
    return 0; 
}