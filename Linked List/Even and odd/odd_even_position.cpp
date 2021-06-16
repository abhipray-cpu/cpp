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
       Node *rearrangeEBOPos(Node *head);//Maa ki chut iski
       Node *rearrangeOBEPos(Node *head);//odd position nodes before even positioned nodes.
       Node *gethead();
       void print(Node *temp);
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
Node* SingleLinkedList::rearrangeOBEPos(Node *head)
{ 
    if(head == NULL)
   return NULL;
   Node *odd=head;
   Node *even=head->next;
   Node *evenfirst=even;//since it is the first even node of list
   while (1)
   {
       // if no more nodes are left
       if(!odd || !even || !(even->next))
       {
           odd->next=evenfirst;
           break;
       }
       //connecting  odd nodes
       odd->next=even->next;
       odd=even->next;
       //if no more odd nodes after curr odd node
       if(odd->next == NULL)
       {
            even->next=NULL;
            odd->next=evenfirst;
            break;
       }
       //connecting even nodes
       even->next=odd->next;
       even=odd->next;
          }
          /* if you want to reverse even list
           Node* current = evenFirst; 
          Node* prev = NULL; 
         Node* front = NULL; 
  
    // Iterate in the complete linked list 
    while (current != NULL) { 
        front = current->next; 
        current->next = prev; 
        prev = current; 
        current = front; 
    } 
  
    evenFirst = prev; 
  
    // Attach the reversed even linked 
    // list to odd linked list 
    odd->next = evenFirst; 
    return head;*/
    //similarly you can reverse odd list too
          print(head);
   return head; 
}
Node* SingleLinkedList::gethead()
{
    return head;
}
void SingleLinkedList::print(Node *temp)
{
    Node *tempjr=temp;
    while (tempjr != NULL)
    {
        cout<<tempjr->data<<" ";
        tempjr=tempjr->next;
    }
    cout<<endl;
}



int main()
{
    SingleLinkedList l1;
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
    l1.insertB(22);
    l1.insertB(23);
    l1.insertB(24);
    l1.insertB(25);
    l1.insertB(27);
    l1.insertB(26);
    l1.insertB(28);
    l1.insertB(29);
    l1.insertB(69);
    //l1.display();
    //l1.rearrangeOBEPos(l1.gethead());
    l1.rearrangeEBOPos(l1.gethead());


    return 0;
}