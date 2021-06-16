#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    
};
//same as sll just an extra connection of tail and head is added in this case therfore forming  a cycle
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
   newnode->next=NULL;
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
  temp=temp->next;
  while (temp !=head)//this loop is used to  traverse to the last node
  {
      temp=temp->next;
  }
  return temp;
  
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
    }//implementing do while since our termination condition is for head therefore the loop must execute atleast once
    //in order to go to last loop
    
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
    }
    else
    {
        newnode->next=head;//assignin a position before the head
        Node *last=getlast();
        head=newnode;//updatig the head node
        last->next=newnode;//since cycle has to be maintined therfore updating the next of last node
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
        newnode->next=getfirst();
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
        head=head->next;//shifting the head
        Node *first=getfirst();
        Node *last=getlast();
        last->next=first;//since the cycle needs to be maintained for continuity
        delete(temp);//deleting the reference node for temp
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
        for(int i=0;i<position-1;i++)
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
        
    }//note do while is implemented here due to similar temination conditiona at head
    
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

    return 0;
}