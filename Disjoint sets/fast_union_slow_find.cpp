#include<bits/stdc++.h>
using namespace std;
class set_disjoint{
public:
int size;
vector<int>set_arr;
void MakeSet(vector<int>S,int size);
int Find(vector<int>S,int size,int X);
void Union(vector<int>S,int size,int root1,int root2);

};

void set_disjoint::MakeSet(vector<int>S,int size)
{
  for(int i=size-1;i>=0;i--)
  {
    S[i]=i;
  }
}
void set_disjoint::Union(vector<int>S,int size,int root1,int root2)
{
if(Find(S,size,root1) == Find(S,size,root2))
{
  return;
}
if(!((root1>=0 && root1<size)&&(root2>=0 && root2<size)))
{
  return;
}
S[root1]=root2;
}
int set_disjoint::Find(vector<int>S,int size,int X)
{
  if(!(X>=0 && X< size))
  {
    return -1;
  }
  if(S[X]==X)
  {
    return X;
  }
  else
  {
    return Find(S,size,S[X]);
  }
}

int main()
{
    set_disjoint S;
    S.size =100;
    S.MakeSet(S.set_arr,S.size);
    for(int i=0;i<S.set_arr.size();i++)
    {
        cout<<S.set_arr[i]<<" ";
    }
     
     S.Find(S.set_arr,S.size,33);
     S.Find(S.set_arr,S.size,43);
     S.Find(S.set_arr,S.size,53);
     S.Find(S.set_arr,S.size,63);
     S.Find(S.set_arr,S.size,73);
     // do union and find operations next

   


}

