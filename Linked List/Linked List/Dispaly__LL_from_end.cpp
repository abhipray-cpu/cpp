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
       void display();
       void insertB(int data);
       void insertL(int data);
       void insert(int data,int position);
       void deletel();
       void deleteB();
       void deletepos(int position);
       void Print_from_end(Node *head);//this function prints LL from end
       Node *gethead();
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
void SingleLinkedList::Print_from_end(Node *head)
{
            
    if(head == NULL)
       return;
       Print_from_end(head->next);
       cout<<head->data<<" ";
    

}
Node *SingleLinkedList::gethead()
{
       return head;
}
int main()
{
    SingleLinkedList l1;
    l1.insertB(69);
    l1.insertB(12);
    l1.insertL(23);
    l1.insertL(45);
    l1.insertL(48);
    l1.insertB(6969);
    l1.insertB(21);
    l1.display();
    Node *head=l1.gethead();
    l1.Print_from_end(head);

    return 0;
}