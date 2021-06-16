//similar to stack either make dequeue expensive or make enqueue expensive


//Approach1 making enequeue expensive


//algorithm
/*enQueue(q, x):



While stack1 is not empty, push everything from stack1 to stack2.
Push x to stack1 (assuming size of stacks is unlimited).
Push everything back to stack1.
Here time complexity will be O(n)

deQueue(q):

If stack1 is empty then error
Pop an item from stack1 and return it
Here time complexity will be O(1)*/
// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// class queue_ki_maa_ka_bhosda
// {
//   public:
//   stack<int>S1,S2;
//   void enqueue(int data);
//   void dequeue();
//   int get_front();
//   int get_last();
//   void display();
// };

// void queue_ki_maa_ka_bhosda::enqueue(int data)
// {
//      while(!S1.empty())
//      {
//          S2.push(S1.top());
//          S1.pop();
//      }//step1

//      S1.push(data);//step2
//      while (!S2.empty())
//      {
//          S1.push(S2.top());
//          S2.pop();
//      }//step3
     

// }

// void queue_ki_maa_ka_bhosda::dequeue()
// {
//        if(S1.empty())
//        {
//            cout<<"Error the queue is empty"<<endl;
//        }
//        else
//        {
//            S1.pop();
//        }
       
// }

// int queue_ki_maa_ka_bhosda::get_front()
// {
//            return S1.top();
// }

// int queue_ki_maa_ka_bhosda::get_last()
// {
//         stack<int>temp=S1;
//         while(temp.size()!=1)
//         {
//             temp.pop();
//         }

//         return temp.top();
// }

// void queue_ki_maa_ka_bhosda::display()
// {
//     stack<int>temp = S1;
//     while(!temp.empty())
//     {
//         cout<<temp.top()<<" ";
//         temp.pop();
//     }
//     cout<<endl;
// }
// int main()
// {
//       queue_ki_maa_ka_bhosda Q;
//       for(int i=0;i<100;i++)
//       {
//           Q.enqueue(i);
//       }

//     Q.display();

//     Q.dequeue();
//     Q.dequeue();
//     Q.dequeue();
//     Q.display();
//     cout<<Q.get_front()<<endl<<Q.get_last();




// }


//second approach includes making dequeue operation expensive

//algorithm

/*enQueue(q,  x)
  1) Push x to stack1 (assuming size of stacks is unlimited).
Here time complexity will be O(1)

deQueue(q)
  1) If both stacks are empty then error.
  2) If stack2 is empty
       While stack1 is not empty, push everything from stack1 to stack2.
  3) Pop the element from stack2 and return it.
Here time complexity will be O(n)
*/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class queue_ki_maa_ka_bhosda
{
  public:
  stack<int>S1,S2;
  void enqueue(int data);
  void dequeue();
  int get_front();
  int get_last();
  void display();
};

void queue_ki_maa_ka_bhosda::enqueue(int data)
{
   S1.push(data);
}

void queue_ki_maa_ka_bhosda::dequeue()
{
        if(S1.empty() && S2.empty())
        cout<<"The queue is empty #underflow"<<endl;
        while(!S1.empty())
        {
            S2.push(S1.top());
            S1.pop();
 }
 S2.pop();
 while (!S2.empty())
 {
     S1.push(S2.top());
     S2.pop();
 }
 

}

int queue_ki_maa_ka_bhosda::get_front()
{
        return S1.top();
}

int queue_ki_maa_ka_bhosda::get_last()
{
stack<int>temp=S1;
        while(temp.size()!=1)
        {
            temp.pop();
        }

        return temp.top();
}

void queue_ki_maa_ka_bhosda::display()
{
    stack<int>temp = S1;
    while(!temp.empty())
    {
        cout<<temp.top()<<" ";
        temp.pop();
    }
    cout<<endl;

}
int main()
{
      queue_ki_maa_ka_bhosda Q;
      for(int i=0;i<100;i++)
      {
          Q.enqueue(i);
      }

    Q.display();

    Q.dequeue();
    Q.dequeue();
    Q.dequeue();
    Q.display();
    cout<<Q.get_front()<<endl<<Q.get_last();
    return 0;
}


