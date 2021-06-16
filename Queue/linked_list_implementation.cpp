#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Queue
{
    private:
    Node *front,*rear;
    public:
    Queue()
    {
        front=NULL;
        rear=NULL;
    }
    Node *getNewNode(int data);
    void enqueue(int data);
    void dequeue();
    int get_front();
    int  get_last();
    void display();
};

Node* Queue::getNewNode(int data)
{
    Node *newNode=new Node;
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void Queue::enqueue(int data)
{      Node *temp=getNewNode(data);
      if(rear == NULL)//implies that queue is empty
    {
        front=temp;
        rear=temp;

    }
    //else
    rear->next=temp;
    rear=temp;
//we will be referencing with respect to rear and not front here
}
void Queue::dequeue()
{
    if(front == NULL)//queue is empty
    return ;
    Node *dummy=front;
    front=front->next;
    if(front == NULL)//if front is null it implies there was only one element in the list and by deleting taht element we reduced the size of list to 0
    rear=NULL;
    delete(dummy);
}

int Queue::get_front()
{
    Node *temp=front;
    return temp->data;
}


int Queue::get_last()
{
    Node *temp=rear;
    return temp->data;
}

void Queue::display()
{
    Node *temp=front;
    while(temp != rear)
    {
         cout<<temp->data<<" ";
         temp=temp->next;
    }
    cout<<endl;
}


int main()
{    Queue Q;
for(int i=0;i<50;i++)
{
    Q.enqueue(i);
}
Q.display();
Q.dequeue();
Q.display();
cout<<Q.get_front()<<endl;
cout<<Q.get_last()<<endl;
    return 0;
}