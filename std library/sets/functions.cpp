#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class kalki
{   public:
    set<int>S;
    void insert();
    void display();
    void all_pointers();
    void operator_set1();
    void operator_set2();
    void operator_set3();

};

void kalki::insert()
{
     for(int i=0;i<INT16_MAX;i++)
     {
         S.insert(i);
     }
}
void kalki::display()
{  cout<<"The element of set is: "<<endl;
    set<int>::iterator it;
    for(it=S.begin();it!=S.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void kalki::all_pointers()
{       
    for(int i=0;i<23;i++)
    {
        cout<<endl;
    }
    cout<<"Here are all the pointers: "<<endl;
        set<int>::iterator B,E,Cb,Ce;
        set<int>::reverse_iterator Rb,Re,Crb,Cre;
      B=S.begin();
      E=S.end();
      Rb=S.rbegin();
      Re=S.rend();
      Cb=S.cbegin();
      Ce=S.cend();
      Crb=S.crbegin();
      Cre=S.crend();
      cout<<*B<<endl<<*E<<endl<<*Rb<<endl<<*Re<<endl<<*Cb<<endl<<*Ce<<endl<<*Crb<<endl<<*Cre<<endl;


}
void kalki::operator_set1()
{
 cout<<"The current size of set is:"<<S.size()<<endl;
 cout<<"The max szie of set is: "<<S.max_size()<<endl;
 cout<<"The statement that the set is empty: "<<S.empty()<<endl;

 cout<<"Inseting a position at beginning:"<<endl;
S.insert(S.begin(),69);
 cout<<"Inseting a position at end:"<<endl;
S.insert(S.end(),78);
cout<<"Earsing the elment from the end"<<endl;
S.erase(S.end());
cout<<"Erasing the elemet from the begining"<<endl;
S.erase(S.end());
//S.clear clears/delete the entire set;

}

void kalki::operator_set2()
{
    cout<<"Enter the element to be found"<<endl;
    int num;
    cin>>num;
    set<int>::iterator it;
    it=S.find(num);
    if(*it)
    {
        cout<<"The number exists:"<<endl;
    }
    else
    {
        cout<<"No element is not present in the set:"<<endl;
    }
    int state=S.count(num);
    if(state == 1)
    {
        cout<<"Yes the element is present in set"<<endl;
    }
    else
    {
        cout<<"No the element is not present in the set:"<<endl;
    }

    cout<<"Enter the number you want to find bound for:"<<endl;
    int n;
    cin>>n;
    cout<<"The lower bound for the given number is:"<<endl;
    set<int>::iterator Lb,Ub;
    Lb=S.lower_bound(n);
    Ub=S.upper_bound(n);
    cout<<*Lb<<endl;
    cout<<"The upper bound for the given number is:"<<endl;
    cout<<*Ub<<endl;

    
    
}
void kalki::operator_set3()
{
       auto it=S.equal_range(45);
       cout<<"The lower bound for the given numbre is\n"<<*it.first<<endl;
       cout<<"The upper bound for the given numbre is\n"<<*it.second<<endl;
       S.emplace(69);//will insert the element only if this element is unique
    set<int>::iterator it=S.emplace_hint(S.begin(),69);//returns an iterator to the position where the insertion is done
       

}
int main()
{
    kalki K;
    K.insert();
    K.display();
    K.all_pointers();
    K.operator_set1();
    K.operator_set2();
    K.operator_set3();
    return 0;
    
    
}
// operator= – The ‘=’ is an operator in C++ STL which copies (or moves) a set to another set and set::operator= is the corresponding operator function.
// get_allocator()– Returns the copy of the allocator object associated with the set.
