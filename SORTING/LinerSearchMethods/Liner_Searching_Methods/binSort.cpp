/*Bucket sort is mainly useful when input is uniformly distributed over a range. 
For example, consider the following problem. 
Sort a large set of floating point numbers which are in range
 from 0.0 to 1.0 and are uniformly distributed across the range.
  How do we sort the numbers efficiently?*/

/*bucketSort(arr[], n)
1) Create n empty buckets (Or lists).
2) Do following for every array element arr[i].
.......a) Insert arr[i] into bucket[n*array[i]]
3) Sort individual buckets using insertion sort.
4) Concatenate all sorted buckets.*/

#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#define MAX 6
using namespace std;

class BucketSort
{
    public:
    float arr[MAX];
    void bucketSort(int n);
    void printArray();

};
void BucketSort::bucketSort(int n)
{
      vector<float>b[n];
      //now we put array elements into different boxes
      for(int i=0;i<n;i++)
      {
          int bi=n*arr[i];
          b[bi].push_back(arr[i]);
      }
      //now we sort individual buckets
      for(int i=0;i<n;i++)
      {
          sort(b[i].begin(),b[i].end());
      }
      //now we concatenate all buckets into array
      int index=0;
      for(int i=0;i<n;i++)
      {
          for(int j=0;j<b[i].size();j++)
          {
              arr[index++]=b[i][j];
              
          }
      }
}

void BucketSort::printArray()
{
    for(int i=0;i<MAX;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    BucketSort Bs;
    Bs.arr[0]=0.897;
    Bs.arr[1]=0.565;
    Bs.arr[2]=0.656;
    Bs.arr[3]=0.1234;
    Bs.arr[4]=0.665;
    Bs.arr[5]=0.3434;
    cout<<"The elements before sorting :"<<endl;
    
   Bs.bucketSort(MAX);
   cout<<endl<<endl<<endl;
   cout<<"The array after sorting :"<<endl;
   Bs.printArray();
   return 0;
    
}