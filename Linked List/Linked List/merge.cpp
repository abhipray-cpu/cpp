#include<iostream>
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
       void display(Node *head);
       void insertB(int data);
       void insertL(int data);
       void insert(int data,int position);
       void deletel();
       void deleteB();
       void deletepos(int position);
       Node *sortedMerge(Node *head1,Node *head2);
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
void SingleLinkedList::display(Node *head)
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
Node* SingleLinkedList::sortedMerge(Node *head1,Node *head2)
{
    Node *result=NULL;
    if(head1 == NULL)
    return(head2);
    else if(head2 == NULL)
    return(head1);
    else if(head1 == NULL && head2 == NULL)
    return NULL;
    else if(head1->data<=head2->data)
    {
        result=head1;
        result->next=sortedMerge(head1->next,head2);
    }
    else if(head1->data > head2->data)
    {
        result=head2;
        result->next=sortedMerge(head1,head2->next);

    }
    return result;
}
Node* SingleLinkedList::getHead()
{
    return head;
}
int main()
{
    SingleLinkedList l1;
    SingleLinkedList l2;
    for(int i=0;i<500;i++)
    {
        l1.insertL(i);
    }
    for(int i=500;i<1000;i++)
    {
        l2.insertL(i);
    }
    cout<<"This is first list"<<endl;
    l1.display(l1.getHead());
    cout<<"This is second list"<<endl;
    l2.display(l2.getHead());
    Node *merge=l1.sortedMerge(l1.getHead(),l2.getHead());
    l1.display(merge);

    return 0;
}