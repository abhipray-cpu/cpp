/*Let's say we have a queue of voters
but the thing that people can be allowed in case they
are some  sort of vips to break the queue and vote first
lets implement this*/
#include<iostream>
#include<bits/stdc++.h>
#include<deque>
#define MAX 10
#define INTERVAL MAX/5 //offcourse interval will change as per the number
using namespace std;

class vote
{
    public:
    string name[MAX];//name of the person
    char status[MAX];//there status
    deque <int> Mydeque;
    void insert();
    void voting();
    void display(int n);//displays the info related to that person
    };

void vote::insert()
{
   for(int i=0;i<MAX;i++)
   {
       Mydeque.push_back(i);
   }
   name[0]="Bitcher";
   name[1]="Bhuttan";
   name[2]="Chuddapan";
   name[3]="Ikbaal";
   name[4]="Khazoor";
   name[5]="Chori chod";
   name[6]="mundal";
   name[7]="merecedez";
   name[8]="Uncle john";
   name[9]="Simp";
   status[0]='N';
    status[1]='N';
     status[2]='N';
      status[3]='N';
       status[4]='V';
        status[5]='N';
         status[6]='N';
          status[7]='N';
           status[8]='V';
            status[9]='N';
             


   //or this should be a dynamic container that fills as per someone registers as we are doing here by  pushing the late entries to back
//at this step we don't know anything about the status of the person.
}
void vote::voting()
{  //let's say I will be searching in a window of some niterval and if I find a vip I will swap it with the value in front
    for(int i=0;i<MAX;i++)
    {
      for(int j=i;j<MAX;j++)
      {
         if(status[j]=='V')
         {
             int temp=Mydeque[i];
             Mydeque[i]=Mydeque[j];
             Mydeque[j]=temp;//but this is creating a problem with the normal people as well so including weights might help
                      break;
                      }
//after evrey swap in the next loop we can sort as per the weights

      }
      display(Mydeque[i]);
    }
}
void vote::display(int n)
{
   cout<<"The voting chance is of :"<<endl;
   cout<<"Name: "<<name[n]<<endl;
   cout<<"Status: "<<status[n]<<endl;
   cout<<endl;
}
int main()
{
    vote V;
    V.insert();
    V.voting();
    return 0;
}

