/*
simple implementation
efficinent for small data
better than selection and bubble

Can sort the data as it receives it
if list is presorted than it takes onlt O(N+D) time where d= number of Inversions
Removes a data from list and enters in the correct position 
after k iterations we will have K+1 sorted elements
*/

#include<iostream>
#define MAX 1000
using namespace std;

class Sorting
{
    public:
    int arr[MAX];
    void sort();
};

void Sorting::sort()
{
   int i,j,v;
   for(i=1;i<MAX-1;i++)
   {
       v=arr[i];
       j=i;
       while(arr[j-1]>v && j>=1)
       {
           arr[j]=arr[j-1];
           j--;
       }
       arr[j]=v;
   } 
}

int main()
{
    Sorting S;
    for(int i=0;i<MAX;i++)
    {
        S.arr[i]=rand();
    }
    S.sort();
    for(int i=0;i<MAX;i++)
    {
        cout<<S.arr[i]<<" ";
    }
    return 0;
}