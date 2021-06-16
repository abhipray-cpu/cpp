#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int main()
{
    vector<int>V;
    for(int i=0;i<INT16_MAX;i=i+100)
    {
        V.push_back(i);
    }
    cout<<"The first element is: "<<*(V.begin())<<endl;
    cout<<"The last element is :"<<*(V.end())<<endl;
    cout<<"The reverse order start/end is:"<<*(V.rbegin())<<endl;
cout<<"The reverse order end /start is :"<<*(V.cbegin())<<endl;

vector<int>::iterator it;
cout<<"The list is as it in original order"<<endl;
for(it=V.begin();it!=V.end();it++)
{
    cout<<*it<<" ";
}
cout<<endl;
cout<<"The list in reverse order can be defined as :"<<endl;
vector<int>::reverse_iterator rev;//you require a reverse iterator as a refrence operator for the rev
for(rev=V.rbegin();rev!=V.rend();rev++)
{
    cout<<*rev<<" ";

}
cout<<endl;
return 0;
}

//available iterators
/*begin() – Returns an iterator pointing to the first element in the vector
end() – Returns an iterator pointing to the theoretical element that follows the last element in the vector
rbegin() – Returns a reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
rend() – Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)
cbegin() – Returns a constant iterator pointing to the first element in the vector.
cend() – Returns a constant iterator pointing to the theoretical element that follows the last element in the vector.
crbegin() – Returns a constant reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
crend() – Returns a constant reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)
*/