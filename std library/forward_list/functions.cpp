//1. merge() :- This function is used to merge one
// forward list with other. If both the lists are sorted then the resulted list returned is also sorted.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    forward_list<int>F1,F2,F3,F4;
    for(int i=0;i<100;i++)
    {
        F1.push_front(rand());
        F2.push_front(rand());
         F3.push_front(rand());
          F4.push_front(rand());
    }
    cout<<"merging list before sorting them"<<endl;
    F2.merge(F1);
    F3.sort();
    F4.sort();
    cout<<"The lists after sorting"<<endl;
    forward_list<int>::iterator it;
    for(it=F2.begin();it!=F2.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    for(it=F3.begin();it!=F3.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    for(it=F4.begin();it!=F4.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    cout<<"Deleting all the repeated occurence"<<endl;
    F3.unique();
    F4.unique();
    F2.unique();
    for(it=F2.begin();it!=F2.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    for(it=F3.begin();it!=F3.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    for(it=F4.begin();it!=F4.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    cout<<"Reversing the forward list"<<endl;
    F2.reverse();
    F3.reverse();
    F4.reverse();
    for(it=F2.begin();it!=F2.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    for(it=F3.begin();it!=F3.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    for(it=F4.begin();it!=F4.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    cout<<"Swapping forward list 3 and list 4"<<endl;
    F3.swap(F4);
    for(it=F2.begin();it!=F2.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    for(it=F3.begin();it!=F3.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    for(it=F4.begin();it!=F4.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    F3.clear();
    F2.clear();
    cout<<"F2 is empty"<<F2.empty()<<endl;
     cout<<"F3 is empty"<<F3.empty()<<endl;
      cout<<"F4 is empty"<<F4.empty()<<endl;
    return 0;
}