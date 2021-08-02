#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class disjoint_sets 
{
   private:
   int size;
   int *parent;
   int *rank;

   public:
   disjoint_sets(int n);
   void initialize();
   void display();
   int find_operation(int n);
   int find_rank(int n);
   void union_operation(int x,int y);
};

disjoint_sets::disjoint_sets(int n)
{
  size=n;
  parent=new int[size];
  rank=new int[size];
  initialize();
}

void disjoint_sets::initialize()
{
  for(int i=0;i<size;i++)
  {
    parent[i]=i;
    rank[i]=1;
}

}

void disjoint_sets::display()
{
  cout<<"parent"<<"\t"<<"rank"<<endl;
  for(int i=0;i<size;i++)
  {

      cout<<parent[i]<<"\t"<<rank[i]<<endl;
  }

}

int disjoint_sets::find_operation(int n)
{
   if(parent[n]==n)
   {
       return n;
   }
   else 
   { 
       return find_operation(parent[n]);
   }
   
}
int disjoint_sets::find_rank(int n)
{
    return rank[n];
}
void disjoint_sets::union_operation(int x,int y)
{

int x_parent=find_operation(x);
int y_parent=find_operation(y);
cout<<x_parent<<" "<<y_parent<<endl;
if(x_parent==y_parent)
{
    cout<<"A cycle is detevted here therforer exclude the brach consisting of vertex"<<x<<"&"<<y<<endl;
}
else
{
    int rank_x=find_rank(x_parent);
    int rank_y=find_rank(y_parent);
    cout<<";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;";
    cout<<rank_x<<"\t"<<rank_y;
    cout<<";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;";
if(rank_x>=rank_y)
{
   int sum_ranks=rank_y+rank_x;
   rank[x_parent]=sum_ranks;
   parent[y_parent]=x_parent;
}
else
{
  int sum_ranks=rank_y+rank_x;
  rank[y_parent]=sum_ranks;
  parent[x_parent]=y_parent;
}
}
}

int main()
{
    int n=10;
  disjoint_sets S(n);
  S.display();
  cout<<"These are the results of find operation as of now \n";
  for(int i=0;i<n; i++)
  {
      cout<<S.find_operation(i)<<endl;
  }
  S.union_operation(3,6);
//   S.display();
//   cout<<"These are the results of find operation as of now \n";
//   for(int i=0;i<n; i++)
//   {
//       cout<<S.find_operation(i)<<endl;
//   }
  S.union_operation(6,4);
  S.display();
  cout<<"These are the results of find operation as of now \n";
  for(int i=0;i<n; i++)
  {
      cout<<S.find_operation(i)<<endl;
  }
  
   return 0;
}
