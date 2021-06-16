#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/* We will create 2 stacks one to store the min and other to store all other elements*/
class stack_custom
{
  public:
  stack<int>st;
  stack<int>min;//gives us the min element
  stack<int>max;//gives us the max element
  void pop();
  void push(int data);
  int get_min();
  int get_max();
  void min_stack();
  void max_stack();
};
/*Top element of min and max will give us the min and max element respectively
in O(1) time*/

void stack_custom::push(int data)
{
    st.push(data);
    if(min.empty() || min.top() >= data)
    {
        min.push(data);//we will push the min element into min element only if it is empty or min.top() >= curr data
        // if we want only the min element we can empty the stack first and then add the element
    }
    if(max.empty() || max.top() <= data)
    {
        max.push(data);
        //we will push the min element into min element only if it is empty or max.top() <= curr data
        // if we want only the max element we can empty the stack first and then add the element
    }
}
void stack_custom::pop()
{
       cout<<"This is the pop function"<<endl;
       st.pop();
       cout<<"The pop operation is performed"<<endl;
}
int stack_custom::get_min()
{
    return min.top();
}
int stack_custom::get_max()
{
    return max.top();
}

void stack_custom::max_stack()
{
    while(!max.empty())
    {
        cout<<max.top()<<" ";
        max.pop();
    }
    cout<<endl;
}

void stack_custom::min_stack()
{
    while (! min.empty())
    {
        cout<<min.top()<<" ";
        min.pop();
    }
    cout<<endl;
    
}

int main()
{
    stack_custom S1;
    //push the elements
    S1.push(12);
    S1.push(7);
    S1.push(56);
    S1.push(32);
    S1.push(23);
    S1.push(6);
    S1.push(665);
    S1.push(8);
    S1.push(68);
    S1.push(465);
    S1.push(3);
    S1.push(45);
    S1.push(2);

   cout<<"The min element is :"<<endl;
   cout<<S1.min.top()<<endl;
   cout<<"The max elment is :"<<S1.max.top()<<endl;

   S1.max_stack();
   cout<<endl;
   S1.min_stack();
   
}
