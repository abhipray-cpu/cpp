#include<iostream>
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
    //bde node 2 pointer leke ghoomte hai
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
    //both the refrence pointer will be pointed towards the head pointer
    head=newnode;
}
void DLL::insertL(int data)
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

int main()
{
    DLL d1;
    d1.insertB(1);
    d1.insertB(2);
    d1.insertL(3);
    d1.insertL(4);
    d1.display();
    d1.insert(69,3);
    d1.insert(34,3);
    d1.display();
    return 0;
}