#include<bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int>max_heap;//this is how we declare a max heap
priority_queue<int,vector<int>,greater<int>>min_heap;//this is how we declare a min heap
for(int i=0;i<INT_MAX;i++)
    {
        max_heap.push(rand());
    }
     for(int i=0;i<INT_MAX;i++)
    {
        min_heap.push(rand());
    }
    while(!min_heap.empty())
    {
        cout<<min_heap.top()<<"\t";
        min_heap.pop();
    }
    while(!max_heap.empty())
    {
        cout<<max_heap.top()<<"\t";
        max_heap.pop();
    }
    return 0;
}