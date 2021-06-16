/*just like single linked list but instead of storing only a single element in a single node
this type of linked list stores an array of elements in a single node and a poniter to next node*/
/*
advantage: linear serach is much faster
less storage space for pointers as compared to simple linked list
operation are faster because linear search is faster
*/
/*disadvantage overhead per node is very high*/

#include<iostream>
# define maxelements 10
using namespace std;
struct Node
{
    int numElements;
    int key;
    int arr[maxelements];
    Node *next;
};
int key=0;
Node *head=NULL;
Node *getnewnode(int arr[],int num)
{
    Node *newnode=new Node;
    newnode->numElements=num;
    newnode->key=key;
    ++key;

    for(int i=0;i<num;i++)
    {
        newnode->arr[i]=arr[i];
    }
    newnode->next=NULL;
    return newnode;
}
void insertB(int arr[],int num)
{
      Node *newnode=getnewnode(arr,num);
      newnode->next=head;
      head=newnode;
}
void insertL(int arr[],int num)
{
    Node *newnode=getnewnode(arr,num);
    Node *last=getlast();
    last->next=newnode;
    newnode->next=NULL;
}
void insert(int arr[],int num,int position)
{
          if(position == 0)
          insertB(arr,num);
          else
          {
              Node *newnode=getnewnode(arr,num);
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
void deleteB()
{
       Node *temp=head;
       head=head->next;
       delete(temp);
}
void deleteL()
{
      Node *temp=head;
      while(temp->next != NULL)
      {
          temp=temp->next;
      }
      Node *del=temp->next;
      temp->next=NULL;
      delete(del);


}
void deletePos(int  position)
{
      if(position == 0)
      {
          deleteB();
      }
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
void update(int arr[],int num,int posittion)
{
       if(posittion == 0)
       {
           Node *temp=getfirst();
           for(int i=0;i<num;i++)
           {
               temp->arr[i]=arr[i];
           }
       }
       else if(posittion < getsize())
       {
          Node *temp=head;
          for(int i=0;i<posittion;i++)
          {
              temp=temp->next;
          }
          for(int i=0;i<num;i++)
          {
              temp->arr[i]=arr[i];
          }
          
       }
       else
       {
           Node *temp=getlast();
           for(int i=0;i<num;i++)
           {
               temp->arr[i]=arr[i];
           }
       }
       
}
void print(int key)
{
   Node *temp=head;
   while (temp != NULL)
   {
       for(int i=0;i<temp->numElements;i++)
       {
           cout<<temp->arr[i]<<" ";
       }
       cout<<"-->";
       temp=temp->next;
   }
   cout<<endl;
}
Node *search(int key)
{
    Node *temp=head;
    while(temp != NULL)
    {
        if(temp->key == key)
        {
            return temp;
            break;
        }
        temp=temp->next;
    }
}
Node *getlast()
{
     Node *temp=head;
     while(temp !=NULL)
     {
         temp=temp->next;
     }
     return temp;
}
Node *getfirst()
{
     Node *temp=head;
     return temp;
}
int getsize()
{
    return key+1;
}
int main()
{
    //dekhlo yaar mera mann nhi hai array input karne ke baarbar
}

