#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *prev;
};
class DCLL
{
    private:
    Node *head;
    public:
    DCLL()
    {
        head=NULL;
    }
    Node *getnewnode(int data);
    Node *getfirst();
    Node *getlast();
    void insert(int data,int position);
    void insertB(int data);
    void insertL(int data);
    void deletePos(int position);
    void deleteB();
    void deleteL();
    void update(int data,int position);
    int getsize();
    void display();
    bool search(int value);
};
Node* DCLL::getnewnode(int data)
{
Node *newnode=new Node;
   newnode->data=data;
   newnode->next=newnode->prev=NULL;
   return newnode;
}
Node* DCLL::getfirst()
{
     Node *temp=head;
     return temp;
}
Node* DCLL::getlast()
{
  Node *temp=head;
  return temp->prev;
}
int DCLL::getsize()
{
    if(head == NULL)
    return 0;
    else
    {
       int count =0;
       Node *temp=head;
       do
       {
           temp=temp->next;
           count++;
       } while (temp != head);
       return count;
    }
    
}
void DCLL::insert(int data,int position)
{
    if(position == 0)
    insertB(data);
    else
    {
        Node *temp=head;
        Node *newnode=getnewnode(data);
        for(int i=0;i<position-1;i++)
        {
            temp=temp->next;
        }
        Node *agla=temp->next;
        temp->next=newnode;
        newnode->next=agla;
    }
    
}
void DCLL::insertB(int data)
{
    Node *newnode=getnewnode(data);
    if(head == NULL)
    {   head=newnode;
        newnode->next=head;
        newnode->prev=head;
    }
    else
    {
        newnode->next=head;
        Node *last=getlast();
        newnode->prev=last;
        head=newnode;
        last->next=newnode;
    }
    
}
void DCLL::insertL(int data)
{
    if(head == NULL)
    {
        cout<<"underflow the list is empty"<<endl;
        return;
    }
    else
    {
        Node *last=getlast();
        Node *newnode=getnewnode(data);
        last->next=newnode;
        newnode->prev=last;
        newnode->next=getfirst();
        getfirst()->prev=newnode;
    }
    
}
void DCLL::deleteB()
{
    if(head == NULL)
    {
        cout<<"Underflow the list is empty"<<endl;
        return;
    }
    else
    {
        Node *temp=head;
        head=head->next;
        Node *first=getfirst();
        Node *last=getlast();
        first->prev=last;
        last->next=first;
        delete(temp);
    }
    
}
void DCLL::deleteL()
{
    if(head == NULL)
    {
        cout<<"Underflow the list is empty"<<endl;
        return;
    }
    else
    {
        Node *temp=head;
        while (temp->next->next != head)
        {
            temp=temp->next;
        }
        Node *del=temp->next;
        temp->next=getfirst();
        getfirst()->prev=temp;
        delete(del);
    }
    
}
void DCLL::deletePos(int position)
{
    if(position == 0)
    deleteB();
    else
    {
        Node *temp=head;
        for(int i=0;i<position-1;i++)
        {
            temp=temp->next;
        }
        Node *agla=temp->next->next;
        Node *del=temp->next;
        temp->next=agla;
        agla->prev=temp;
        delete(del);
    }
    
}
void DCLL::update(int data,int position)
{
    if(position == 0)
    {
        Node *temp=getfirst();
        temp->data=data;
    }
    else if(position < getsize())
    {
        Node *temp=head;
        for(int i=0;i<position;i++)
        {
            temp=temp->next;
        }
        temp->data=data;
    }
    else
    {
        Node *temp=getlast();
        temp->data=data;
    }
    
}
void DCLL::display()
{
    if(head == NULL)
    cout<<"Underflow the list is empty"<<endl;
    else
    {
        Node *temp=head;
        do
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        } while (temp != head);
        cout<<endl;
        
    }
    
}
bool DCLL::search(int value)
{
   Node *temp=head;
   do
   {
       if(temp->data == value)
       {
           return true;
           break;
       }
       temp=temp->next;
   } while (temp->next != head);
   return false;
}
int main()
{  DCLL d1;
d1.insertB(21);
d1.display();
d1.insertB(45);
d1.display();
d1.insertB(69);
d1.display();
d1.insertL(101);
d1.display();
d1.insertL(36);
d1.display();
d1.insert(23,2);
d1.display();
d1.insert(67,0);
d1.display();
cout<<"the size of list is= "<<d1.getsize()<<endl;
d1.update(69,4);
d1.display();
Node *temp=d1.getfirst();
cout<<"The first Node is= "<<temp->data<<endl;
Node *temp1=d1.getlast();
cout<<"The last node is= "<<temp1->data<<endl;
d1.deleteB();
d1.display();
d1.deleteL();
d1.display();
d1.deletePos(3);
d1.display();
    return 0;
}