#include<iostream>// see original implementation in copy
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
       int getsize(Node *head);
       Node *findIntersection(Node *head1,Node *head2);
       Node *getHead();
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
int SingleLinkedList::getsize(Node *head)
{
    Node *temp=head;
    if(head == NULL)
    return 0;
    else
    {
        int size=0;
        while(temp != NULL)
        {
            temp=temp->next;
            ++size;
        }
        return size;
    }
    
}
Node* SingleLinkedList::findIntersection(Node *head1,Node *head2)
{
         Node *temp1;
         Node *temp2;
         int diff;
         int size1=getsize(head1);
         int size2=getsize(head2);
         if(size1 > size2)
         {
                temp1=head1;
                temp2=head2;
                diff=size1-size2;
         }
         else if(size1 < size2)
         {
              temp1=head2;
              temp2=head1;
              diff=size2-size1;
         }
         else
         {
               temp1=head2;
              temp2=head1;
              diff=size2-size1;
         }

         for(int i=0;i<diff;i++)
         {
             temp1=temp1->next;
         }
         while(temp1 != NULL && temp2 != NULL)
         {
             if(temp1->data == temp2->data)
             return temp1;
             temp1=temp1->next;
             temp2=temp2->next;
         }
         return NULL;
         
         
}
Node* SingleLinkedList::getHead()
{
    return head;
}
int main()
{
    SingleLinkedList l1;
    SingleLinkedList l2;
    l1.insertB(1);
    l1.insertB(2);
    l1.insertB(3);
    l1.insertB(4);
    l1.display();
    l1.insertL(69);
    l1.insertL(70);
    l1.insertL(71);
    l1.insertL(72);
    l1.display();
    l2.insertB(11);
    l2.insertB(12);
    l2.insertB(13);
    l2.insertB(14);
    l2.display();
    l2.insertB(15);
    l2.insertB(16);
    l2.insertB(17);
    l2.display();
    l2.insertL(69);
    l2.insertL(70);
    l2.insertL(71);
    l2.insertL(72);
    l2.display();
    Node *head1=l1.getHead();
    Node *head2=l2.getHead();
    cout<<head1->data<<endl;
    cout<<head2->data<<endl;
    Node *intersection=l1.findIntersection(head1,head2);
    cout<<"The point of intersection of given 2 lists is = "<<intersection->data<<endl;

    return 0;
}