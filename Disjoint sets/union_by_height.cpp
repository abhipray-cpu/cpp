#include<bits/stdc++.h>
using namespace std;

class disjoint_set{
public:
int size;
vector<int>arr;
void MakeSet(vector<int>s,int size);
void Union(vector<int>s,int size,int root1,int root2);
int Find(vector<int>s,int size,int X);
};
void disjoint_set::MakeSet(vector<int>S,int size)
{
for(int i=size-1;i>=0;i--)
{
    S[i]=-1;
}
}
void disjoint_set::Union(vector<int>S,int size,int root1,int root2)
{
if((Find(S,size,root1) == Find(S,size,root2)) && Find(S,size,root1)!=-1 )
{
return;
}
if(S[root1]<S[root2])
{
    S[root1]=root2;
    S[root2]+=-1;
}
else
{
  S[root2]=root1;
    S[root1]+=-1;   
}
}
int disjoint_set::Find(vector<int>S,int size,int X){
if(!(X>=0 && X<size))
return -1;
if(S[X]<0)
return X;
else
return Find(S,size,S[X]);
}
int main()
{
disjoint_set S;
S.size =10000;
S.MakeSet(S.arr,S.size);
//some find opearations

//some union operations

//some find operations again

return 0;

}