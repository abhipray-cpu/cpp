//in this code I will be implementing a bloom filter

#include<bits/stdc++.h>
#define l1 long long 
using namespace std;

int h1(string S,int arrSize)
{
    l1 int hash=0;
    for(int i=0;i<S.size();i++)
    {
        hash=(hash+(int)S[i]);
        hash=hash%arrSize;
    }

return hash;
}
int h2(string S,int arrSize)
{
    l1 int hash=1;
    for(int i=0;i<S.size();i++)
    {
        hash=hash+pow(19,i)*S[i];
        hash=hash%arrSize;
    }
    return hash;
}
int h3(string S,int arrSize)
{
    l1 int hash=7;
    for(int i=0;i<S.size();i++)
    {
        hash=(hash*31 + S[i])%arrSize;
        hash=hash%arrSize;
    }
    return hash;
}
int h4(string S,int arrSize)
{
    l1 int hash=3;
    int p=7;
    for(int i=0;i<S.size();i++)
    {
        hash=hash*7 + S[0]*pow(p,i);
        hash=hash%arrSize;
    }
    return hash;
}

bool loopUP(bool *bitArray,int arrSize,string S)
{
    int a = h1(S,arrSize);
    int b = h2(S,arrSize);
    int c = h3(S,arrSize);
    int d = h4(S,arrSize);
 if(bitArray[a]&&bitArray[b]&&bitArray[c]&&bitArray[d])
 {
     return true;
 }
 else
 return false;
}

void insert(bool *bitArray,int arrSize,string S)
{
    if(loopUP(bitArray,arrSize,S))
    {
        cout<<S<<"is probably already present"<<endl;
    }
    else
    {
        int a = h1(S,arrSize);
        int b = h2(S,arrSize);
        int c = h3(S,arrSize);
        int d = h4(S,arrSize);
        bitArray[a]=bitArray[b]=bitArray[c]=bitArray[d]=true;
        cout<<S<<"is inserted"<<endl;
    }
}
int main()
{
    bool bitArray[100]={false};
    int arrSize=100;
    //in here enter a list of numbers you want to test for
    // string Sarray[33]={};
    // for(int i=0;i<Sarray.size();i++)
    // {
    //    insert(bitArray,arrSize,Sarray[i]);
    // }
    // return 0;
}