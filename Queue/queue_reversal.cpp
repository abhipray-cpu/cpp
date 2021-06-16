// // CPP program to reverse a Queue 
// #include <bits/stdc++.h> 
// using namespace std; 

// // Utility function to print the queue 
// void Print(queue<int>& Queue) 
// { 
// 	while (!Queue.empty()) { 
// 		cout << Queue.front() << " "; 
// 		Queue.pop(); 
// 	} 
// } 

// // Function to reverse the queue 
// void reverseQueue(queue<int>& Queue) 
// { 
// 	stack<int> Stack; 
// 	while (!Queue.empty()) { 
// 		Stack.push(Queue.front()); 
// 		Queue.pop(); 
// 	} 
// 	while (!Stack.empty()) { 
// 		Queue.push(Stack.top()); 
// 		Stack.pop(); 
// 	} 
// } 

// // Driver code 
// int main() 
// { 
// 	queue<int> Queue; 
// 	Queue.push(10); 
// 	Queue.push(20); 
// 	Queue.push(30); 
// 	Queue.push(40); 
// 	Queue.push(50); 
// 	Queue.push(60); 
// 	Queue.push(70); 
// 	Queue.push(80); 
// 	Queue.push(90); 
// 	Queue.push(100); 

// 	reverseQueue(Queue); 
// 	Print(Queue); 
// } 


//second approach i.e using recurssion

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class getting_reversed
{
    public:
    queue<int>Q;
    void reverse_it(queue<int>&q);
    void display();
};
void getting_reversed::reverse_it(queue<int>&q)
{     
      if(q.empty())
      return;
      else
      {
          int data = q.front();
           q.pop();
            reverse_it(q);
           q.push(data);
      }
      

}
void getting_reversed:: display()
{      queue<int>Q1=Q;
        while(!Q1.empty())
        {
            cout<<Q1.front()<<" ";
            Q1.pop();
        }
}
int main()
{
    getting_reversed R;
    for(int i=0;i<1000;i++)
    {
        R.Q.push(i);
    }

    cout<<"The original queue is:"<<endl;
    R.display();

    R.reverse_it(R.Q);
    for(int i=0;i<13;i++)
    {
        cout<<endl;
    }
    cout<<endl<<endl<<endl<<"The reversed queue is :" <<endl;
    R.display();
    
    return 0;


}