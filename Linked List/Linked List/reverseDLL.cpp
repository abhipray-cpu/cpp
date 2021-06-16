#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *prev;
};
class DLL
{
    private:
    Node *head;
    public:
    DLL()
    {
        head=NULL;
    }
    Node *getnewnnode(int data);
    void insertB(int data);
    void insertL(int data);
    void insert(int data,int position);
    void deleteB();
    void deleteL();
    void deletePos(int position);
    void display();
    void reversePointer(Node *head);
    void reverseStack(Node *head);
    Node *gethead();
    ~DLL()
    {
        cout<<"destructor is called because madamji ne bola"<<endl;
        while(head != NULL)
        {
            deleteL();
        }
    }
};
Node* DLL::getnewnnode(int data)
{
    Node *newnode=new Node;
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}

void DLL::display()
{
    Node *temp=head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void DLL::insertB(int data)
{
    Node *newnode=getnewnnode(data);
    newnode->next=head;
    newnode->prev=head;
    head=newnode;
}
void DLL::insertL(int data)
{  if(head == NULL)
     insertB(data);
     else
     {
         Node *newnode=getnewnnode(data);
    Node *temp=head;
    while(temp->next != NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    newnode->next=NULL;
     }
     
    
}
void DLL::insert(int data,int position)
{

    if(position == 0)
    {
        insertB(data);
    }
    else
    {
        
    Node *newnode=getnewnnode(data);
    Node *temp=head;
    for(int i=0;i<position-1;i++)
    {
        temp=temp->next;
    }
    Node *agla=temp->next;
    temp->next=newnode;
    newnode->prev=temp;
    newnode->next=agla;
    agla->prev=newnode;
    }
    
}

void DLL::deleteB()
{
    if(head == NULL)
    {
        cout<<"Underflow the list is empty"<<endl;
    }
    Node *temp=head;
    head=head->next;
    delete(temp);
}
void DLL::deleteL()
{
    Node *temp=head;
    while(temp->next->next != NULL)
    {
        temp=temp->next;
    }
    Node *del=temp->next;
    temp->next=NULL;
    delete(del);
}
void DLL::deletePos(int position)
{
    Node *temp=head;
    for(int i=0;i<position-1;i++)
    {
        temp=temp->next;
    }
    Node *del=temp->next;
    Node *agla=temp->next->next;
    temp->next=agla;
    agla->prev=temp;
    delete(del);
}
Node* DLL::gethead()
{
    return head;
}
void DLL::reversePointer(Node *head)
{ 
    //Maa ki chut is method kis
}

void DLL::reverseStack(Node *head)
{
       stack<Node*>s;
       Node *temp=head;
       while (temp != NULL)
       {
           s.push(temp);
           temp=temp->next;
       }
       DLL d2;
         while (! s.empty())
         {
             Node *curr=s.top();
             d2.insertL(curr->data);
             s.pop();
         }
         d2.display();
         
       
}

int main()
{
    DLL d1;
    d1.insertL(69);
    d1.insertB(1);
    d1.insertB(2);
    d1.insertL(3);
    d1.insertB(4);
    d1.insertB(5);
    d1.insertB(6);
    d1.insertB(7);
    d1.insertB(8);
    d1.insertB(9);
    d1.insertB(10);
    d1.insertB(11);
    d1.insertB(12);
    d1.insertB(13);
    d1.insertB(14);
    d1.insertB(15);
    d1.insertB(22);
    d1.insertB(244);
    d1.insertB(25);
    d1.insertB(26);
    d1.insertB(92);
    d1.display();
    d1.reverseStack(d1.gethead());

    return 0;
}