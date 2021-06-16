#include<iostream>
#include<bits/stdc++.h>
#define MAX 100
using namespace std;

class QuickSort
{
    public:
    int arr[MAX];
    void Swap(int *a,int *b);
    int partition(int low,int high);
    void quickSort(int low,int high);
    void printArray();
};

void QuickSort::Swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void QuickSort::printArray()
{
   for(int i=0;i<MAX;i++)
   {
       cout<<arr[i]<<" ";
   }   
}

int QuickSort::partition(int low,int high)
{
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<=high;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            Swap(&arr[i],&arr[j]);
        }
        Swap(&arr[i+1],&arr[high]);
        return i+1;
    }
}

void QuickSort::quickSort(int low,int high)
{  int parti;
    if(low<high)
    {
        parti=partition(low,high);
        quickSort(low,parti-1);
        quickSort(parti+1,high);
    }
}

int main()
{
    QuickSort Q;
    for(int i=0;i<MAX;i++)
    {
        Q.arr[i]=rand();
    }
    Q.quickSort(0,MAX-1);
    Q.printArray();
    return 0;
}