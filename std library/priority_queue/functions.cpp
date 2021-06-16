/*priority_queue::empty() in C++ STL– empty() function returns whether the queue is empty.
priority_queue::size() in C++ STL– size() function returns the size of the queue.
priority_queue::top() in C++ STL– Returns a reference to the top most element of the queue
priority_queue::push() in C++ STL– push(g) function adds the element ‘g’ at the end of the queue.
priority_queue::pop() in C++ STL– pop() function deletes the first element of the queue.
priority_queue::swap() in C++ STL– This function is used to swap the contents of one priority queue with another priority
 queue of same type and size.
priority_queue::emplace() in C++ STL – This function is used to insert a new element into the priority queue container
, the new element is added to the top of the priority queue.
priority_queue value_type in C++ STL– Represents the type of object stored as an element in a priority_queue.
 It acts as a synonym for the template parameter.*/

 #include<iostream>
 #include<bits/stdc++.h>
 #define MAX 45454
 using namespace std;

 int main()
 {
     char alphabet[MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 
                          'h', 'i', 'j', 'k', 'l', 'm', 'n',  
                          'o', 'p', 'q', 'r', 's', 't', 'u', 
                          'v', 'w', 'x', 'y', 'z' }; //container to create the random character
     priority_queue<char,vector<char>,greater<char>>ch;
     for(int i=0;i<69;i++)
     {
         ch.push(rand() % MAX); //formulae defined to insert the randomized element into the container
     }
     while(!ch.empty())
     {
         cout<<ch.top()<<endl;
         ch.pop();
     }
     return 0;
 }