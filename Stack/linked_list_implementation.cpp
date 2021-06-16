#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *link;
};
   Node *top=NULL;
Node *get_new_Node(int data)
{
    Node *newNode=new Node;
    newNode->data=data;
    newNode->link=NULL;
    return newNode;
}

void push(int data)
{
    Node *newNode=get_new_Node(data);
    newNode->link=top;
    top=newNode;
}
void pop()
{
    Node *temp=top;
    top=top->link;
    temp->link=NULL;
    delete(temp);
}
bool is_empty()
{
    if(top== NULL)
    return true;
    else
    {
        false;
    }
    
}

void show()
{
    Node *temp=top;
    while (temp != NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->link;
    }
    cout<<endl;
}

int get_top()
{
    if(top)
    return top->data;
    else
    {
        return 0;
    }
    

}
int get_size()
{
    int counter=0;
    Node *temp=top;
    while (temp != NULL)
    {
        ++counter;
        temp=temp->link;
    }
        return counter;   
}

int main()
{
    for(int i=0;i<=100;i++)
    push(i);
    show();
    cout<<"The size of stack is = "<<get_size()<<endl;
    cout<<"The top element of stack is = "<<get_top()<<endl;

    for(int i=200;i<10000;i=i+100)
    {
        push(i);
    }
    cout<<"The size of stack is ="<<get_size()<<endl;
    show();

}