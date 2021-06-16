/*size() – Returns the number of elements in the vector.
max_size() – Returns the maximum number of elements that the vector can hold.
capacity() – Returns the size of the storage space currently allocated to the vector expressed as number of elements.
resize(n) – Resizes the container so that it contains ‘n’ elements.
empty() – Returns whether the container is empty.
shrink_to_fit() – Reduces the capacity of the container to fit its size and destroys all elements beyond the capacity.
reserve() – Requests that the vector capacity be at least enough to contain n elements.
*/

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
    cout<<"The size of vector(Number of elements) = "<<V.size()<<endl;
    cout<<"The max capacity for vector is "<<V.max_size()<<endl;
    cout<<"Capacity of vector at present: "<<V.capacity()<<endl;
    cout<<"Is the vector empty?? Your hypothesis is "<<V.empty()<<endl;
    cout<<"Enter the size you want to resize/shrink the vector"<<endl;
    int size;
    cin>>size;

    V.resize(size);
    V.shrink_to_fit();



}