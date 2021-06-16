/*
There are n people standing in a circle waiting to be executed. 
The counting out begins at some point in the circle and proceeds 
around the circle in a fixed direction. In each step, a certain number 
of people are skipped and the next person is executed. The elimination
proceeds around the circle (which is becoming smaller and smaller as the
executed people are removed), until only the last person remains, who is 
given freedom. Given the total number of persons n and a number k which
indicates that k-1 persons are skipped and kth person is killed in circle.
The task is to choose the place in the initial circle so that you are the
last one remaining and so survive.

For example, if n = 5 and k = 2, then the safe position is 3.
Firstly, the person at position 2 is killed, then person at position 4 is killed,
then person at position 1 is killed. Finally, the person at position 5 is killed.
So the person at position 3 survives.
If n = 7 and k = 3, then the safe position is 4.
The persons at positions 3, 6, 2, 7, 5, 1 are killed in order, and person at position 4 survives.*/

/*
The problem has following recursive structure.

  josephus(n, k) = (josephus(n - 1, k) + k-1) % n + 1
  josephus(1, k) = 1*/

  
/*  a simple problem

    #include <iostream> 
using namespace std; 
  
int josephus(int n, int k) 
{ 
    if (n == 1) 
        return 1; 
    else
        /* The position returned by josephus(n - 1, k) 
        is adjusted because the recursive call  
        josephus(n - 1, k) considers the  
        original position k % n + 1 as position 1 
        return (josephus(n - 1, k) + k-1) % n + 1; 
} 
  
int main() 
{ 
    int n = 14; 
    int k = 2; 
    cout << "The chosen place is " << josephus(n, k); 
    return 0; 
}
 */

// using circular Linked List
#include <iostream>
using namespace std;
struct Node {
   int data;
   struct Node *next;
};
struct Node* head = NULL;
void insert(int newdata) {
   struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
   struct Node *ptr = head;
   newnode->data = newdata;
   newnode->next = head;
   if (head!= NULL) {
      while (ptr->next != head)
      ptr = ptr->next;
      ptr->next = newnode;
   } else
   newnode->next = newnode;
   head = newnode;
}
void display() {
   struct Node* ptr;
   ptr = head;
   do {
      cout<<ptr->data <<" ";
      ptr = ptr->next;
   } while(ptr != head);
}
void findJosephusPosition(int n,int m)
{ Node *temp=head;
for(int count=m;count > 1;--count)
{
    for(int i=0;i<n-1;i++)
    {
          temp=temp->next;
          temp->next=temp->next->next;
    }
}
cout<<temp->data<<endl;
}

int main() {
   insert(3);
   insert(1);
   insert(7);
   insert(2);
   insert(9);
   insert(21);
   insert(47);
   insert(67);
   insert(51);
   insert(32);
   cout<<"The circular linked list is: ";
   display();
   int n;
   cout<<"enter the number of persons you want to skip"<<endl;
   cin>>n;
   findJosephusPosition(n,10);

   return 0;
}