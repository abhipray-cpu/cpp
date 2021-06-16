#include<iostream>// by changing condition this can also be applied for odd frequency
using namespace std;
struct Node
{
    int data;
    Node *next;
};
class SingleLinkedList
{
       private:
       Node *head;
       public:
       SingleLinkedList()
       {
           head=NULL;
       }
       Node *getnewnode(int data);
       void display();
       void insertB(int data);
       void insertL(int data);
       void insert(int data,int position);
       void deletel();
       void deleteB();
       void deletepos(int position);
       int getfrequency(int value);
       void deleteOddFrequency();
       void deleteEvenFrequency();
       int getsize();
       ~SingleLinkedList()
       {
           cout<<"Mam ne kha isliye destructor call kiya"<<endl;
           while(head !=NULL)
           {
               deletel();
           }
           cout<<endl;
       }
};
Node* SingleLinkedList::getnewnode(int data)
{
    Node *newnode=new Node;
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
void SingleLinkedList::display()
{
    Node *temp=head;
    if(head == NULL)
    {
        cout<<"error liist is empty"<<endl;
    }
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void SingleLinkedList::insertB(int data)
{
    Node *newnode=getnewnode(data);
    newnode->next=head;
    head=newnode;
}
void SingleLinkedList::insertL(int data)
{
    Node *newnode=getnewnode(data);
    if(head == NULL)
    {
        cout<<"The list was empty therefore inseerting in front"<<endl;
        insertB(data);
    }
    Node *temp=head;
    while(temp->next != NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=NULL;
}
void SingleLinkedList::insert(int data,int position)
{
    if(position == 0)
    {
        insertB(data);
    }
    else
    {
        Node *newnode=getnewnode(data);
        Node *temp=head;
        for(int i=0;i<position-1;i++)
        {
            temp=temp->next;
        }
        Node *agla=temp->next;
        temp->next=newnode;
        newnode->next=agla;
    }
    
}
void SingleLinkedList::deleteB()
{
    Node*temp=head;
    head=head->next;
    delete(temp);
}
void SingleLinkedList::deletel()
{
    if(head == NULL)
    {
        cout<<"underflow"<<endl;
    }
    Node *temp=head;
    while(temp->next->next != NULL)
    {
        temp=temp->next;
        }
        Node *del=temp->next;
        temp->next=NULL;
        delete(del);
}
void SingleLinkedList::deletepos(int position)
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
    
int SingleLinkedList::getfrequency(int value)
{
    Node *temp=head;
    int freq=0;
    while (temp != NULL)
    {
        if(temp->data == value)
        {
            ++freq;
        }
        temp=temp->next;
    }
    return freq;
}
    
void SingleLinkedList::deleteOddFrequency()
{
    Node *temp=head;
    while(temp != NULL)
    {
        int freq=getfrequency(temp->data);
        if(freq%2 == 0)
        {   cout<<temp->data<<" ";
             Node *temp1=head;
             int count=0;
             while (temp1 != NULL)
             {
                 if(temp1->data == !temp->data)
                 {
                    deletepos(count);
                 }
                 temp1=temp1->next;
                 count=count+1;
             }
             
        }
        temp=temp->next;
    }
}

void SingleLinkedList::deleteEvenFrequency()
{
    Node *temp=head;
    while(temp != NULL)
    {
        int freq=getfrequency(temp->data);
        if(freq%2 != 0)
        {   cout<<temp->data<<" ";
             Node *temp1=head;
             int count=0;
             while (temp1 != NULL)
             {
                 if(temp1->data == !temp->data)
                 {
                    deletepos(count);
                 }
                 temp1=temp1->next;
                 count=count+1;
             }
             
        }
        temp=temp->next;
    }
}
      

int SingleLinkedList::getsize()
{
    int count=0;
    Node *temp=head;
    while (temp != NULL)
    {
        ++count;
        temp=temp->next;
    }
    return count;
}
int main()
{
    SingleLinkedList l1;
    l1.insertB(1);
    l1.insertB(1);
    l1.insertB(1);
    l1.insertB(1);
    l1.insertB(1);
    l1.insertB(2);
    l1.insertB(2);
    l1.insertB(2);
    l1.insertB(2);
    l1.insertB(3);
    l1.insertB(3);
    l1.insertB(3);
    l1.insertB(4);
    l1.insertB(4);
    l1.insertB(5);
    l1.insertB(5);
    l1.insertB(5);
    l1.display();
    l1.deleteOddFrequency();
    l1.deleteEvenFrequency();


    return 0;
}