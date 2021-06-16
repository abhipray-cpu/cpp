//it is basically used to destruct or destroy an object
//it is automatically revoked when an object is deleted
/*A destructor is called when
A destructor function is called automatically when the object goes out of scope: 
(1) the function ends 
(2) the program ends 
(3) a block containing local variables ends 
(4) a delete operator is called  */


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class destruct
{
    public:
    int a,b;
    destruct()
    {
        a=69;
        b=60;
    }
    ~destruct()
    {
        cout<<"Hey man sorry to inform you but the values that you stored ib the variables are now deleted"<<endl;
    }
    void printIt()
    {
        cout<<a<<endl<<b;
    }
    void deleteIt()
    {
        delete &a;
        delete &b;
        cout<<"The values stored in the variables a and b are deleted"<<endl;
    }

};

int main()
{
    destruct D;
    destruct();
    D.printIt();
    D.deleteIt();
    D.printIt();
    return 0;
}