/*we require to call differetn functions at different 
points of execution in our programm and we have to approaches to do so
we can directly pass the value or we can use a refrence to sotore the address associated with
that address*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class hell0
{
    public:
    int a,b;
    int *A,*B;
    void byValue(int c,int d)
    {
         a=d;
         b=c;
    }
    void byReference(int c,int d)
    {
        int *A=&c;
        int *B=&d;
    }
    void showAll()
    {
        cout<<"passed by value:"<<endl;
        cout<<a<<" "<<b<<endl;
        cout<<"passed by reference:"<<endl;
        cout<<"Adress values"<<endl;
        cout<<A<<" "<<B<<endl;
        


    }
    };
    int main()
    {
        hell0 H;
        H.byValue(12,34);
        H.byReference(12,34);
        H.showAll();
        return 0;
    }