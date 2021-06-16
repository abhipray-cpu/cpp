/*this is just a basic refresher for details refere the copy*/
#include<iostream>
#include<bits/stdc++.h>
#define Max 100
using namespace std;

class point
{
    public:
    int a,b,c,d;
    int arrr[Max];
    int *A,*B,*C,*D;
    //declaring an array using pointers
    void byValue(int a,int b,int c,int d)
{
    a=a;
    b=b;
    c=c;
    d=d;
}

void byAddress(int a,int b,int c,int d)
{
    A=&a;
    B=&b;
    C=&c;
    D=&d;

}

int sum1()
{
    return a+b+c+d;
}

int sum2()
{
    return *A+*B+*C+*D;
}
void assign()
{
    for (int i=0;i<Max;i++)
    {
        arrr[i]=rand();
    }
}
void traverse()
{
    int *p=arrr;
   

}
};
int main()
{
  point P;
  P.byValue(78,45,34,34);
  P.byAddress(12,34,123,54);
  cout<<P.sum1()<<endl;
  cout<<P.sum2()<<endl;
  P.assign();
  P.traverse();
  return 0;

}