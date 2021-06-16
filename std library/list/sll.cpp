#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//note yhaan iterator use hoga since list stroes the pointer to value and not actual values

void showlist(list <int> g)
{
    list <int>::iterator it;
    for(it=g.begin();it!=g.end();it++)
    {
        cout<<'\t'<<*it;
        cout<<'\n';
            }
}
int main()
{
    
    list <int> gqlist1, gqlist2; 
  
  
    for (int i = 0; i < 10; ++i) 
    { 
        gqlist1.push_back(i * 2); 
        gqlist2.push_front(i * 3); 
    } 
    cout << "\nList 1 (gqlist1) is : "; 
    showlist(gqlist1);//function to prin the list 
  
    cout << "\nList 2 (gqlist2) is : "; 
    showlist(gqlist2); 
  
    cout << "\ngqlist1.front() : " << gqlist1.front();//gives the first element 
    cout << "\ngqlist1.back() : " << gqlist1.back(); //gives the last element
  
    cout << "\ngqlist1.pop_front() : "; 
    gqlist1.pop_front(); //pops the first element
    showlist(gqlist1); 
  
    cout << "\ngqlist2.pop_back() : "; 
    gqlist2.pop_back(); //pops the last element
    showlist(gqlist2); 
  
    cout << "\ngqlist1.reverse() : "; 
    gqlist1.reverse(); //this function is used to revrese the list
    showlist(gqlist1); 
  
    cout << "\ngqlist2.sort(): "; 
    gqlist2.sort(); //this function is used to sort the list
    showlist(gqlist2); 
  
    return 0; 
}