#include<iostream>
using namespace std;
#define size 1000;

class Queue
{
   public:
  int front=-1;
  int rear=-1;
  int arr[1000];
   void enqueue(int data);
   void dequeue();
   int get_first_element();
   int get_last_element();
   bool is_empty();
   void display();
};

void Queue::enqueue(int data)
{   int value = (rear + 1)%size;
   if(value == front)
   cout<<"overflow queue is full"<<endl;
   else
   {
       if(front == -1)
       {
             front=0;
       }
       rear=(rear + 1)%size;
       arr[rear]=data;
   }
   
}
void Queue::dequeue()
{
 if(front == -1 && rear == -1)
 cout<<"The queue is empty"<<endl;
 else
 {
     if(front == rear)//only one element is present
     {
         front=rear=-1;
     }
     else
     {
         front=(front + 1)%size;
     }
     
 }
 
}
int Queue::get_first_element()
{
      return arr[front];
}
int Queue::get_last_element()
{
   return arr[rear];
}

bool Queue::is_empty()
{
    if(front == -1 && rear == -1)
    return true;
    else
    {
        return false;
    }
    
}

void Queue::display()
{
    for(int i=front;i<=rear;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{  
    Queue Q;
    for(int i=0;i<10000;i=i+10)
    {
        Q.enqueue(i);
    }
    Q.display();
        Q.dequeue();

Q.dequeue();
Q.dequeue();        
    
    Q.display();
    for(int i=0;i<23;i++)
    {
        cout<<endl;
    }
cout<<"The first element is:"<<Q.get_first_element()<<endl;
cout<<"The last element is:"<<Q.get_last_element()<<endl;

    return 0;
}