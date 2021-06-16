#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class implement
{ public:
    deque<int>Dq;
    void insertion();
    void deletion();
    void display();
    void pointers();
    void remaining_fucntions();
};
void implement::display()
{
    deque<int>::iterator it;//so pointers are used here for referencing
    for(it=Dq.begin();it!=Dq.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

void implement::insertion()
{
 for(int i=INT_FAST16_MIN;i<=0;i=i+69)//INT_FAST16_MIN? e ka howat hai?
 {
        Dq.push_front(i);
 }
 for(int j=0;j<=INT16_MAX;j=j+69)
 {
     Dq.push_back(j);
 }
 cout<<"Inserting the element at begining:"<<endl;
 Dq.insert(Dq.begin(),69);
 cout<<"Inserting the element at end:"<<endl;
 Dq.insert(Dq.end(),69);
 Dq.assign(69,34);//first value is the size/number of time the value(second parametre) has to be inserted

}
void implement::pointers()
{
    cout<<"The pointer to the begining element"<<*Dq.begin()<<endl;
    cout<<"The pointer to the end/last element"<<*Dq.end()<<endl;
    cout<<"The revrese pointer to the end is "<<*Dq.rend()<<endl;
    cout<<"Thre revrese pointer to the begining is"<<*Dq.rbegin()<<endl;
    cout<<"The constant pointer to the begining is"<<*Dq.cbegin()<<endl;
    cout<<"The constant pointer to the end is"<<*Dq.cend()<<endl;
    cout<<"The constant revrese pointer to the end is "<<*Dq.crend()<<" ";
    cout<<"The constant reverse poiinter to the beginig is"<<*Dq.crbegin()<<endl;

}
void implement::deletion()
{
    for(int i=0;i<100;i++)
    {
        Dq.pop_back();
        Dq.pop_front();
    }
    cout<<"The statement that the dequeue is empty is"<<Dq.empty()<<endl;
   Dq.emplace_front(45);//inserti ka bhai but only at two p
   Dq.emplace_back(69);

}//emplace function?

void implement::remaining_fucntions()
{
    cout<<"The element at given position is:"<<Dq.at(4)<<endl;
}
int main()
{
    implement I;
    I.insertion();
    I.display();
    I.pointers();
    I.remaining_fucntions();
    I.deletion();
    I.Dq.resize(69);//this function is used to resize the dequeue to the given element
    return 0;

}