#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int getMaxArea(int hist[], int n)
{
    stack<int>S;
    int max_area=0;
    int tp;
    int area_with_top;
    int i=0;
    while(i<n)
    {
        if(S.empty() || hist[S.top()] <= hist[i])
        {
            if(!S.empty())
            {
                 cout<<hist[S.top()]<<" "<<hist[i]<<endl;
            }
           
        
                S.push(i++);
    }
                
        else
        {
            tp=S.top();
            S.pop();
            area_with_top=hist[tp] * (S.empty() ? i: i-S.top()-1);
            if(max_area < area_with_top)
            max_area=area_with_top;
        }

         cout<<"The current stack is :";
            stack<int> temp=S;
            while(!temp.empty())
            {
                cout<<temp.top()<<" ";
                temp.pop();

            }
            cout<<endl;
        
    }
    while(!S.empty())
    {
        tp=S.top();
        S.pop();
        area_with_top=hist[tp] * (S.empty()? i:i-S.top()-1);
        if(max_area<area_with_top)
        max_area=area_with_top;
    }
    return max_area;
}

int main()
{
    int hist[] = {6,2,5,4,5,1,6};
    int n= sizeof(hist)/sizeof(hist[0]);
    cout<<"The max area is = "<<getMaxArea(hist,n);
    return 0;
}