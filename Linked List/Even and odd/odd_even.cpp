/*Rearrange a linked list such that all even positioned node comes before odd positioned ones
or vice versa*/
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *fast,*slow;
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
       void formcycle();
       bool findcycle();
       int cyclelength();
       Node *startingNode();
       void RearrangeOBE();//i.e odd before even values
       /*spliting in two different list and than merging the odd and even list
       keeping track of starting and ending pointers for both the list
       */
       void RearrangeEBO();//i.e even before odd
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
void SingleLinkedList::formcycle()
{
    Node *start=head->next;
    Node *temp=head;
    while(temp->next != NULL)
    {
        temp=temp->next;
    }
    
    cout<<start->data<<endl;
    cout<<temp->data<<endl;
    temp->next=start;

}
bool SingleLinkedList::findcycle()
{
    slow=fast=head;
    int state=0;
    while(slow != NULL && fast != NULL && fast->next != NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow == fast)
        {
            state =1;
           break;
        }

    }
    if(state ==1)
    return true;
    else
    {
        return false;
    }
    
}
void SingleLinkedList::RearrangeEBO()
{
    Node *evenstart=NULL;
    Node *evenend=NULL;
    Node *oddstart=NULL;
    Node *oddend=NULL;
    Node *curr=head;
    while(curr != NULL)
    {
        int val=curr->data;
        if(val %2==0)
        {
            if(evenstart == NULL)
            {
                evenstart=curr;
                evenend=evenstart;
            }
            else
            {
                evenend->next=curr;
                evenend=curr;
            }
            
        }
        else
        {
            if(oddstart == NULL)
            {
                oddstart=curr;
                oddend=oddstart;
            }
            else
            {
                oddend->next=curr;
                oddend=curr;
            }
        }
        curr=curr->next;
        
    }
    if(oddstart == NULL || evenstart==NULL)
        return;
        else
        {
            evenend->next=oddstart;
            oddend->next=NULL;
            head=evenstart;
        }
        
}
void SingleLinkedList::RearrangeOBE()
{

    Node *evenstart=NULL;
    Node *evenend=NULL;
    Node *oddstart=NULL;
    Node *oddend=NULL;
    Node *curr=head;
    while(curr != NULL)
    {
        int val=curr->data;
        if(val %2==0)
        {
            if(evenstart == NULL)
            {
                evenstart=curr;
                evenend=evenstart;
            }
            else
            {
                evenend->next=curr;
                evenend=curr;
            }
            
        }
        else
        {
            if(oddstart == NULL)
            {
                oddstart=curr;
                oddend=oddstart;
            }
            else
            {
                oddend->next=curr;
                oddend=curr;
            }
        }
        curr=curr->next;
        
    }
    if(oddstart == NULL || evenstart==NULL)
        return;
        else
        {
            oddend->next=evenstart;
            evenend->next=NULL;
            head=oddstart;
        }
}
int main()
{
    SingleLinkedList l1;
    /*l1.insertB(1);
    l1.insertL(3);
    l1.insert(23,1);
    l1.formcycle();
    l1.deleteB();
    l1.deletel();
    if(l1.findcycle() == true)
    cout<<"The cycle is present"<<endl;
    if(l1.findcycle()== false)
    cout<<"The cycle is not present"<<endl;*/
    l1.insertB(1);
     l1.insertB(2);
      l1.insertB(3);
       l1.insertB(4);
        l1.insertB(5);
         l1.insertB(6);
          l1.insertB(7);
           l1.insertB(8);
            l1.insertB(9);


    l1.RearrangeEBO();
    l1.display();
    return 0;
}
