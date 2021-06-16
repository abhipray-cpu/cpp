/*Problem Statement : we are given a case in which head points towards the Kth node
we are required to find all the nodes before this kth node
This is not possible incase of single Linked List and is only possible if we have some kind
of prev pointer like in Doubly Linked List so we requrie a doubly linked list for this problem statement */

/* karlo yaar easy approach hai kth node mei jao vo head se miljaega
phir using prev node traverse the list till you enocounter head*/

/*
use this method
node* p = head->ptr;
node* prev = NULL;
node* curr = head;
node* next = NULL;

while(curr!=p && p)
{
   next = xor(prev,curr->ptr);
   print(curr->data);
   prev = curr;
   curr = next;
}
  or you can use the memmory efficient linked list
*/