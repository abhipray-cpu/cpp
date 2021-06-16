#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class implement
{
    public:
    deque<int>Dq;
    void show();
};
void implement::show()
{
    deque<int> temp=Dq;
    deque<int>::iterator it;
    for(it=temp.begin();it!=temp.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

int main()
{
    implement I;
    for(int i=0;i<10000;i++)
    {
        I.Dq.push_front(i);
    }
    for(int j=INT_MIN;j<=0;j=j+100)
    {
         I.Dq.push_back(j);
    } 

    I.show();
    return 0;
    
}