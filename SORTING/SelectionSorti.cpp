// #include<iostream>
// #define MAX 1000
// using namespace std;
// //this method requires no auxillary space but the time is O(n2)
// class SelectionSort
// {
//     public:
//     int arr[MAX];
//     void sorting();
// };

// void SelectionSort::sorting()
// {
//     int i,j,temp,min;
//     for(i=0;i<MAX;i++)
//     {
//         min=i;
//         for(j=i+1;j<MAX;j++)
//         {
//             if(arr[j]<arr[min])
//             min=j;
//         }
//         //swapping elements
//         temp=arr[min];
//         arr[min]=arr[i];
//          arr[i]=temp;

//     }
// }

// int main()
// {
//     SelectionSort Sort;
//     for(int i=0;i<MAX;i++)
//     {
//         Sort.arr[i]=rand();
//     }
//     Sort.sorting();
//     for(int i=0;i<MAX;i++)
//     {
//         cout<<Sort.arr[i]<<" ";
//     }
//     return 0;
// }
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{  int a[1000];
    for(int i=0;i<1000;i++)
    {
        a[i]=rand();
    }
    cout<<"The original array is"<<endl;
    for(int i=0;i<1000;i++)
    {
        cout<<a[i]<<" ";
    }
    int min,temp;
    for(int i=0;i<1000;i++)
{
    min=i;
    for(int j=i+1;j<1000;j++)
    {
        if(a[j]<a[min])
        {
            min=j;
        }
        temp=a[min];
        a[min]=a[j];
        a[j]=temp;

    }
}
cout<<"this is the sorted array "<<endl;`
 for(int i=0;i<1000;i++)
    {
        cout<<a[i]<<" ";
    }

}