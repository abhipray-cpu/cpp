#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{     int n=69;
    int a[1000];
    for(int i=0;i<1000;i++)
    {
        a[i]=i;
            }
    

    int low=0,high=1000;
    int mid=(low+high)/2;
    int status=0;
    while(low<mid)
    {
        if(a[mid]==n)
        {
            cout<<"The number was found"<<endl;
            status=1;
            break;
        }
        else if(a[mid] > n)
        {
            high=mid-1;
        }
        else if(a[mid] < n)
        {
            low=mid+1;
        }
    }
    if(status == 0)
    {
        cout<<"The number was not found"<<endl;

    }
    else
    {
        cout<<"The number was found"<<endl;
    }
    return 0;
}