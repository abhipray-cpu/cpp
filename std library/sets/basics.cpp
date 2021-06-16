/*Sets are a type of associative containers in which each element
 has to be unique, because the value of the element identifies it. 
 The value of the element cannot be modified once
 it is added to the set, though it is possible to remove 
 and add the modified value of that element. */

 //some basic methods
 /*begin() – Returns an iterator to the first element in the set.
   end() – Returns an iterator to the theoretical element that follows last element in the set.
   size() – Returns the number of elements in the set.
   max_size() – Returns the maximum number of elements that the set can hold.
   empty() – Returns whether the set is empty.
filter_none*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{      set<int>n;
for(int i=0;i<=INT16_MAX;i++)
{
    n.insert(i);
}
    set<int>::iterator it,it1;
    it=n.begin();
    cout<<"The first element is: "<<*it<<endl;
    it1=n.end();
    cout<<"The last element of  set is: "<<*it1<<endl;
    cout<<"The size of set is: "<<n.size()<<endl;
    cout<<"The maximum allowes size of set is : "<<n.max_size()<<endl;
    cout<<"The statement that our set is empty: "<<n.empty()<<endl;
    return 0;
}

