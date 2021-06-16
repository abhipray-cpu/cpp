//Appraoch one making push operation expensive
/*#include <bits/stdc++.h> 

using namespace std; 

class Stack { 
	// Two inbuilt queues 
	queue<int> q1, q2; 

	// To maintain current number of 
	// elements 
	int curr_size; 

public: 
	Stack() 
	{ 
		curr_size = 0; 
	} 

	void push(int x) 
	{ 
		curr_size++; 

		// Push x first in empty q2 
		q2.push(x); 

		// Push all the remaining 
		// elements in q1 to q2. 
		while (!q1.empty()) { 
			q2.push(q1.front()); 
			q1.pop(); 
		} 

		// swap the names of two queues 
		queue<int> q = q1; 
		q1 = q2; 
		q2 = q; 
	} 

	void pop() 
	{ 

		// if no elements are there in q1 
		if (q1.empty()) 
			return; 
		q1.pop(); 
		curr_size--; 
	} 

	int top() 
	{ 
		if (q1.empty()) 
			return -1; 
		return q1.front(); 
	} 

	int size() 
	{ 
		return curr_size; 
	} 
}; 

// Driver code 
int main() 
{ 
	Stack s; 
	s.push(1); 
	s.push(2); 
	s.push(3); 

	cout << "current size: " << s.size() 
		<< endl; 
	cout << s.top() << endl; 
	s.pop(); 
	cout << s.top() << endl; 
	s.pop(); 
	cout << s.top() << endl; 

	cout << "current size: " << s.size() 
		<< endl; 
	return 0; 
} 
*/


//Approach 2 making POP operation expensive

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Stack
{
    queue<int> q1,q2;
    int curr_size;
    public:
    Stack()
    {
        curr_size=0;
    }
    void push(int data);//in q1 
    void pop();
    int top();//top element of stack
    int size();//get the size of stack
};

void Stack::push(int data)
{
    q1.push(data);
    curr_size++;
}

int Stack::size()
{
    return curr_size;
}

void Stack::pop()
{
    // empty the q1 leaving only the last element into q2
    //then pop the last element of q1 and change the name of two queues

    if(q1.empty())
    return;
    while (q1.size() != 1) 
    {
        q2.push(q1.front());
        q1.pop();
    }

    q1.pop();
    curr_size --;
    queue<int> q=q1;
    q1=q2;
    q2=q;
    
}

int Stack::top()
{
    //same as pop but instead of deleting the last element we will add in q2 later on
     if(q1.empty())
      return 0;
    while (q1.size() != 1) 
    {
        q2.push(q1.front());
        q1.pop();
    }
        int temp=q1.front();
        q1.pop();
        q2.push(temp);
    queue<int> q=q1;
    q1=q2;
    q2=q;
          return temp;
}

int main()
{
     Stack s; 
    s.push(1); 
    s.push(2); 
    s.push(3); 
    s.push(4); 
  
    cout << "current size: " << s.size() 
         << endl; 
    cout << s.top() << endl; 
    s.pop(); 
    cout << s.top() << endl; 
    s.pop(); 
    cout << s.top() << endl; 
    cout << "current size: " << s.size() 
         << endl; 
    return 0; 
}
