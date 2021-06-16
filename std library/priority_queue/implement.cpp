#include<iostream>
#include<bits/stdc++.h>
#define MAX 100
using namespace std;

int main()
{
   string arr[MAX];
   for(int i=0;i<100;i++)
   {
       arr[i]="-1";
   }
    string str;
       int pri;
   priority_queue<int>Pri;
   string sentence[10];
   int prior[10];
   for(int i=0;i<10;i++)
   {
       cout<<"Enter the priority and the sentence"<<endl;
       cin>>str;
       sentence[i]=str;
       cin>>pri;
       prior[i]=pri;

}
for(int i=0;i<10;i++)
{
      arr[prior[i]]=sentence[i];
      Pri.push(prior[i]);
}
cout<<"The elements as per your priority are"<<endl;
for(int i=0;i<100;i++)
{
    while(!Pri.empty())
    {
        int priority=Pri.top();
        Pri.pop();
        cout<<arr[priority]<<endl;
    }
}



    return 0;
}
