/* a better aproach would be to sort both the lists in order to reduce the execution time
but I hadn't studied Insertion sort again therefore going with this approach
for sorted lists search with a threshold that value of 2nd list that is being searched should be less
than that of current value of first list that is beiing searched in second list this will reduce the execution time for code*/
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
       void commonElements(Node *head1,Node *head2);
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
Node* SingleLinkedList::gethead()
{
    return head;
}
void SingleLinkedList::commonElements(Node *head1,Node *head2)
{
    Node *temp1=head1;
    Node *temp2=head2;
    while (temp1 != NULL)
    { 
        Node *iter=temp2;
        while (iter != NULL)
        {
            if(iter->data == temp1->data)
            {
                cout<<iter->data<<" ";
            }
            iter=iter->next;
        }
        cout<<endl;
        temp1=temp1->next;
        
    }
    
}
int main()
{
    SingleLinkedList l1;
    SingleLinkedList l2;
    l1.insertB(12);
    l1.insertB(13);
    l1.insertB(14);
    l1.insertB(15);
    l1.insertB(16);
    l1.insertB(17);
    l1.insertB(18);
    l1.insertB(19);
    l1.insertB(20);
    l1.insertB(21);
    l1.display();
    l2.insertB(25);
    l2.insertB(24);
    l2.insertB(23);
    l2.insertB(22);
    l2.insertB(21);
    l2.insertB(20);
    l2.insertB(19);
    l2.display();
    Node *head1=l1.gethead();
    Node *head2=l2.gethead();
    l1.commonElements(head1,head2);


    return 0;
}