/*Problem Statement 
pair nodes such that diff of their squares is max*/

/* Algo
1)Create a deque and insert all nodes value in the deque.
2)Sort the deque to get the largest node value and smallest node value in constant time.
3)Create another linked list having value difference of square’s of the largest and the s
mallest value from the back and the front of the deque respectively.
4)After each iteration pop both the smallest and largest value from the deque.
5)After the above steps, print the nodes of the new Linked List formed.
*/

 
#include <bits/stdc++.h>

using namespace std;
 
// Linked list node

struct Node {

    int data;

    struct Node* next;
};
 
// Function to push into Linked List

void push(struct Node** head_ref,

          int new_data)
{

    // Allocate node

    struct Node* new_node

        = (struct Node*)malloc(

            sizeof(struct Node));
 

    // Put in the data

    new_node->data = new_data;

    new_node->next = (*head_ref);
 

    // Move the head to point

    // to the new node

    (*head_ref) = new_node;
}
 
// Function to print the Linked List

void print(struct Node* head)
{

    Node* curr = head;
 

    // Iterate until curr is NULL

    while (curr) {
 

        // Print the data

        cout << curr->data << " ";
 

        // Move to next

        curr = curr->next;

    }
}
 
// Function to create a new Node of
// the Linked List

struct Node* newNode(int x)
{

    struct Node* temp

        = (struct Node*)malloc(

            sizeof(struct Node));
 

    temp->data = x;

    temp->next = NULL;
 

    // Return the node created

    return temp;
}
 
// Function used to re-order list

struct Node* reorder(Node* head)
{

    // Stores the node of LL

    deque<int> v;

    Node* curr = head;
 

    // Traverse the LL

    while (curr) {

        v.push_back(curr->data);

        curr = curr->next;

    }
 

    // Sort the deque

    sort(v.begin(), v.end());
 

    // Node head1 stores the

    // head of the new Linked List

    Node* head1 = NULL;

    Node* prev = NULL;
 

    // Size of new LL

    int x = v.size() / 2;
 

    // Loop to make new LL

    while (x--) {

        int a = v.front();

        int b = v.back();
 

        // Difference of squares of

        // largest and smallest value

        int ans = pow(b, 2) - pow(a, 2);
 

        // Create node with value ans

        struct Node* temp = newNode(ans);

        if (head1 == NULL) {

            head1 = temp;

            prev = temp;

        }
 

        // Otherwsie, update prev

        else {

            prev->next = temp;

            prev = temp;

        }
 

        // Pop the front and back node

        v.pop_back();

        v.pop_front();

    }
 

    // Return head of the new LL

    return head1;
}
 
// Driver Code

int main()
{

    struct Node* head = NULL;
 

    // Given Linked ist

    push(&head, 6);

    push(&head, 5);

    push(&head, 4);

    push(&head, 3);

    push(&head, 2);

    push(&head, 1);
 

    // Function Call

    Node* temp = reorder(head);
 

    // Print the new LL formed

    print(temp);
 

    return 0;
}