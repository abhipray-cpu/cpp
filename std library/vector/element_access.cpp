/*reference operator [g] – Returns a reference to the element at position ‘g’ in the vector
at(g) – Returns a reference to the element at position ‘g’ in the vector
front() – Returns a reference to the first element in the vector
back() – Returns a reference to the last element in the vector
data() – Returns a direct pointer to the memory array used internally by the vector to store its owned elements.*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    
    vector<int>V;
    for(int i=INT_MIN;i<=INT16_MAX;i=i+100)
    {
        V.push_back(i);
    }
    cout<<"Enter the position of element you want to access"<<endl;
    int pos;
    cin>>pos;
    cout<<"The element at position "<<pos<<"is : "<<V[pos]<<endl;
    cout<<"The element at position "<<pos<<"is : "<<V.at(pos)<<endl;
    cout<<"The first element is: "<<V.front()<<endl;
    cout<<"The last element is:"<<V.back()<<endl;;
    cout<<"Memmory array internally allocated to vector is"<<*(V.data())<<endl;
    return 0;


}