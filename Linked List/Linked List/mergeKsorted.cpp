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
       Node *mergeKsortedList(int k,Node* arr[]);
       Node *gethead();
       Node *merge(Node *head1,Node *head2);
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
Node* SingleLinkedList::mergeKsortedList(int k,Node* arr[])
{   
    for(int i=1;i<k;i++)

{
    arr[0]=merge(arr[0],arr[i]);
}

return arr[0];
}
Node* SingleLinkedList::merge(Node *head1,Node *head2)
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
        result->next=merge(head1->next,head2);
    }
    else if(head1->data > head2->data)
    {
        result=head2;
        result->next=merge(head1,head2->next);

    }
    return result;
}

Node* SingleLinkedList::gethead()
{
    return head;
}
int main()
{
    SingleLinkedList l1;
    SingleLinkedList l2;
    SingleLinkedList l3;
    SingleLinkedList l4;
    SingleLinkedList l5;
    SingleLinkedList l6;
    SingleLinkedList l7;
    SingleLinkedList l8;
    SingleLinkedList l9;
    for(int i=0;i<100;i++)
    {
        l1.insertL(i);
    }
    for(int i=100;i<200;i++)
    {
        l2.insertL(i);
    }
    for(int i=200;i<300;i++)
    {
        l3.insertL(i);
    }
    for(int i=300;i<400;i++)
    {
        l4.insertL(i);
    }
    for(int i=400;i<500;i++)
    {
        l5.insertL(i);
    }
    for(int i=500;i<600;i++)
    {
        l6.insertL(i);
    }
    for(int i=600;i<700;i++)
    {
        l7.insertL(i);
    }
    for(int i=700;i<800;i++)
    {
        l8.insertL(i);
    }
    for(int i=800;i<900;i++)
    {
        l9.insertL(i);
    }
     Node *arr[9]={l1.gethead(),l2.gethead(),l3.gethead(),
     l4.gethead(),l5.gethead(),l6.gethead(),l7.gethead(),l8.gethead(),l9.gethead()};

    l1.display(l1.gethead());
    cout<<endl<<endl<<endl;
     l2.display(l2.gethead());
    cout<<endl<<endl<<endl;
     l3.display(l3.gethead());
    cout<<endl<<endl<<endl;
     l4.display(l4.gethead());
    cout<<endl<<endl<<endl;
     l5.display(l5.gethead());
    cout<<endl<<endl<<endl;
     l6.display(l6.gethead());
    cout<<endl<<endl<<endl;
     l7.display(l7.gethead());
    cout<<endl<<endl<<endl;
     l8.display(l8.gethead());
    cout<<endl<<endl<<endl;
     l9.display(l9.gethead());
    cout<<endl<<endl<<endl;
    Node *merge=l1.mergeKsortedList(9,arr);
    l1.display(merge);

    return 0;
}