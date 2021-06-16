#include<iostream>
#include<bits/stdc++.h>
#define MAX 10000
#define threshold 10
using namespace std;

class cafe
{
    public:
    list<list<vector<int>>>Order;
    void cater();
    void display_Order(int n);
};
void cafe::cater()
{
    list<list<vector<int>>>::iterator it;
    for(it=Order.begin();it!=Order.end();it++)
    {    int stats;
         cout<<"Is the order perpared"<<endl;
         cin>>stats;
         if(stats==1)
         {
            list<vector<int>>curr=*it;
            vector<int>order;
            vector<int>items;
            cout<<"The oreder number "<<order[0]<<" is ready"<<endl;
            cout<<"Your total bill is "<<order[1]<<" SO kindly pay it or else fuck off"<<endl;
            order[2]=1;
            cout<<"The status of your order is "<< order[2]<<endl;
            cout<<"These are the items you ordered :"<<endl;
            for(auto it=items.begin();it!=items.end();it++)
            {
                cout<<*it<<endl;
            }

Order.remove(*it);
         }
         else
         {
             continue;
         }
    }
}

int main()//a timer or while loop can be used to keep the orders running
{
    cafe C;
    int total_orders=0;
    int bill;
    int total_revenue=0;
    int i=0;
    while(i<=threshold)
    {
        vector<int>order;
        //first value will be order number and second will be the total bill and third will be items
        int order_number;
        int bill;
        cout<<"Order number"<<endl;
        cin>>order_number;
        total_orders=order_number;
        cout<<"Total bill amount"<<endl;
        cin>>bill;
        total_revenue+=bill;
        order.push_back(order_number);
        order.push_back(bill);//(order_number,bill,status)this will be our vector unit
        int status=0;//by deafult it will be 0 and will be assigned 1 when the order is prepared and served
        order.push_back(status);
        vector<int>items;
        int n;
        cout<<"Number of items"<<endl;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            int m;
            cout<<"Enter item"<<endl;
            cin>>n;
            items.push_back(n);//orders will be encoded in the billing machine
        }
        list<vector<int>>Unit;
        Unit.push_back(order);
        Unit.push_back(items);
        //this will be our basic (order_vector,items_vector);
        i++;
        C.Order.push_back(Unit);
        

    }
      C.cater();
    cout<<"Total number of orders place today : "<<total_orders<<endl;
    cout<<"Total revenue made today: "<<total_revenue<<endl;
    return 0;
}
