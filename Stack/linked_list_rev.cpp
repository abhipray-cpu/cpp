#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class rev
{
    public:
    list <int> L;
    stack <int> S;
    void reverse();
    void display(list<int> L);
};
void rev::reverse()
{
    list<int> ::iterator it;
    for(it=L.begin();it!=L.end();it++)
    {
        S.push(*it);
    }
    L.clear();
    while (!S.empty())
    {
        L.push_back(S.top());
        S.pop();
    }
}

void rev::display(list<int>L)
{
    list<int>::iterator it;
    for(it=L.begin();it!=L.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
int main()
{
   rev R;
   for(int i=0;i<100;i++)
   {
       R.L.push_front(i);
   }
   R.display(R.L);
   cout<<endl;


   R.reverse();
   cout<<"The reversed list is"<<endl;
   R.display(R.L);
}