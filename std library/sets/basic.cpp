/*The pair container is a simple container defined in <utility> header consisting of two data elements or objects. 
The first element is referenced as ‘first’ and the second element as ‘second’ and the order is fixed (first, second).
Pair is used to combine together two values which may be different in type. Pair provides a way to store two 
heterogeneous objects as a single unit.
Pair can be assigned, copied and compared.
The array of objects allocated in a map or hash_map are of
type ‘pair’ by default in which all the ‘first’ elements are unique keys associated with their ‘second’ value objects.
To access the elements, we use variable name followed by dot operator followed by the keyword first or second.*/


//The syntax for the pair is:
//pair (data_type1, data_type2) Pair_name
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int,char>>P;
    // P.first=69;
    // P.second='A';
    // cout<<"The given pair is "<<P.first<<":"<<P.second<<endl;
    char ch='A';
    for(int i=0;i<26;i++)
    {
        pair<int,char>par;
        par.first=i;
        par.second=ch++;
        P.push_back(par);
    }
    vector<pair<int,char>>::iterator it;
    for(it=P.begin();it!=P.end();it++)
    {
        pair<int,char>kisko=*it;
        cout<<kisko.first<<":"<<kisko.second<<endl;
    }
    cout<<endl;
    
    return 0;
}