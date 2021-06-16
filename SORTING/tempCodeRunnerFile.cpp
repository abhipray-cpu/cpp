#include<iostream>
#include<bits/stdc++.h>
#define MAX 100
using namespace std;
class sortingIt
{
    public:
    int arr[MAX];
    void merge(int l,int r,int m);
    void mergeSort(int l,int r);
    void printArray();
};
void sortingIt::mergeSort(int l,int r)
{
   if(l>=r)
   {
       return;
   }
   else
   {
       int m=(l+r)/2;
       mergeSort(l,m);
       mergeSort(m+1,r);
       merge(l,m,r);
   }
}
void sortingIt::merge(int l,int r,int m)
{
      int n1=m-l+1;
      int n2=r-m;
      int L[n1],R[n2];

      for(int i=0;i<n1;i++)
      {
          L[i]=arr[i+l];
      }
      for(int j=0;j<n2;j++)
      {
          R[j]=arr[m+j+1];
      }
      int j=0;
      int i=0;
      int k=l;

      while(i<n1 && j<n2)
      {
          if(L[i]=R[j])
          {
              arr[k]=L[i];
              i++;
          }
          else
          {
              arr[k]=R[j];
              j++;
          }
          k++;
      }
 while(i<n1)
 {
     arr[k]=L[i];
     i++;
     k++;
 }
 while(j<n2)
 {
     arr[k]=R[j];
     j++;
     k++;
 }
}
void sortingIt::printArray()
{
for(int i=0;i<MAX;i++)

{
    cout<<arr[i]<<" ";
}
cout<<endl;
}
int main()
{
  sortingIt St;
  for(int i=0;i<MAX;i++)
  {
      St.arr[i]=rand();
  }
  St.mergeSort(0,MAX-1);
  St.printArray();
  return 0;
}