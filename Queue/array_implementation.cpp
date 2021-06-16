#include<iostream>
using namespace std;
#define Max 100
class Queue
{  public:
     int arr[Max];
     int front=0;
     int rear=0;
     void enqueue(int data);
     void dequeue();
     int front_element();
     int back();
     int get_size();
     void display();
};

void Queue::enqueue(int data)
{
       if(rear<Max)
       arr[rear++]=data;
       else if(rear == Max)
       {
           cout<<"The queue has reached it's full size therefore an overflow error is thrown"<<endl;
       }
       
}

void Queue::dequeue()
{
        if(front == rear)
        {
            cout<<"The queue is empty"<<endl;
        }
        else
        {
            for(int i=0;i<rear;i++)
            {
                arr[i]=arr[i+1];//shifting all the elements to plus one position
            }
            rear --;
        }
        
}

int Queue::front_element()
{
 if(rear == front){
      cout<<"The queue is empty"<<endl;
      return -1;}
      else
      {
          return arr[0];
      }
      

      
}

int Queue::back()
{
   if(rear !=0 && rear != Max)
   {
       return arr[rear];
   }
   else if(rear == 0)
   {
       cout<<"The queue is empty"<<endl;
       return -1;
   }
   else if(rear == Max)
   {
       cout<<"Overflow"<<endl;
       return -1;
   }
}

void Queue::display()
{
    for(int i=0;i<rear;i++)
    {
        cout<<arr[i]<<endl;
    }
}

int Queue::get_size()
{
      return rear+1;
}
 int main()
 {   

     Queue Q;
     for(int i=0;i<50;i++)
     {
         Q.enqueue(i);
     }

     cout<<"The original queue is"<<endl;
     Q.display();
     
     cout<<"Dequing the first ten elements"<<endl;
     Q.dequeue();
     Q.display();

     cout<<"The fron elements is :"<<Q.front_element()<<endl;
     cout<<"The last element is :"<<Q.back()<<endl;
     cout<<"The size of array is:"<<Q.get_size();
     return 0;

 }
