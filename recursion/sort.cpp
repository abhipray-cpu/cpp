#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int sort(int A[],int n)
{
 if(n==1)
 {
     return 1;
 }
 return (A[n-1]<A[n-2])?0:sort(A,n-1);

}
int main()
{
    int n=100;
    int A[n];
    int temp;
    for(int i=0;i<100;i++)
    {
      A[i]=rand();
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(A[i]>A[j])
            {
                temp=A[i];
                A[i]=A[j];
                A[j]=temp;
            }
        }
    }
    int val=sort(A,n);
    if(val==1)
    cout<<"The array is sorted"<<endl;
    else
    cout<<"The array is not sorted"<<endl;
    return 0;
}