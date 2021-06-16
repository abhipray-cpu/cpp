/*assign() – It assigns new value to the vector elements by replacing old ones
push_back() – It push the elements into a vector from the back
pop_back() – It is used to pop or remove elements from a vector from the back.
insert() – It inserts new elements before the element at the specified position
erase() – It is used to remove elements from a container from the specified position or range.
swap() – It is used to swap the contents of one vector with another vector of same type. Sizes may differ.
clear() – It is used to remove all the elements of the vector container
emplace() – It extends the container by inserting new element at position
emplace_back() – It is used to insert a new element into the vector container, the new element is added to the end of the vector
.*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>v;
    for(int i=INT16_MIN;i<=INT16_MAX;i++)
    {
        v.push_back(i);
    }

    cout<<"The gaand phaad vector is: "<<endl;
    vector<int>::iterator it;
    for(it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    //insert
    //erase
    //clear
    v.assign(v.begin(),v.begin()+3456);
    vector<int>ilahi;
    ilahi.assign(23,69);
    for(it=ilahi.begin();it!=ilahi.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    cout<<"erasing elemets"<<endl;
    v.erase(v.begin());
    v.erase(v.end());
    cout<<"erasing the entire vector /clear"<<endl;
    v.erase(v.begin(),v.end());
    cout<<"Is the vector empty?"<<"Your hypothesis is"<<v.empty()<<endl;

v.insert(v.begin(),2);
return 0;


    
}