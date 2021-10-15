//in this case we will hash the address of the nodes and if two hashes are same we will check for address equality to be sure and thus confirm the presence of loop
//using the inbuilt hash function of c++

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};
//baki hash the address and check whether the hash is same for some value if yes than thre is a loop 
//mei nhi kar rha code ab bc
class LinkedList{
    public:
    Node *head=NULL;//this will be the head od our linked list
    Node *getnewNode(int value);
    void Insert(int value);
    void DetectCycle();
};

int main()
{
    LinkedList L;

}