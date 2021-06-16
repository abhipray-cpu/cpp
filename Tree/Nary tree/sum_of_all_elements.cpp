#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *first_child;
    Node *next_sibling;
};

Node *get_newNode(int data)
{
    Node *newNode=new Node;
    newNode->data=data;
    newNode->first_child=NULL;
    newNode->next_sibling=NULL;
    return newNode;
}
Node *insert(Node *root_first_child,int data)//this is the main insetion function we will use
/*Algorithm used in this 
first 2 nodes are filled before hand 
and than we use the seconf node as the refernce node for insertion
next sibling stores the greater element
and first child stores the smaller element
in this fashion we will be storing the elements
*/
{
    if(root_first_child==NULL)
    {
        root_first_child=get_newNode(data);
    }
    else if(root_first_child->data<data)
    {
        root_first_child->next_sibling=insert(root_first_child->next_sibling,data);
    }
    else if(root_first_child->data>data)
    {
        root_first_child->first_child=insert(root_first_child->first_child,data);
            }
            return root_first_child;
}
int sum_of_all_nodes(Node *root)
{
    if(root==NULL)
    return 0;
    return(root->data+sum_of_all_nodes(root->first_child)+sum_of_all_nodes(root->next_sibling));
}
int main()
{
    
    Node *root=NULL;
    root=get_newNode(100);
    Node *root_first_child=NULL;
    root_first_child=get_newNode(50);
    root->first_child=root_first_child;
    cout<<root->data<<endl;
    cout<<root->first_child->data<<endl;
    root_first_child=insert(root_first_child,60);
    insert(root_first_child,70);
    insert(root_first_child,80);
    insert(root_first_child,90);
    insert(root_first_child,99);
    insert(root_first_child,40);
    insert(root_first_child,42);
    insert(root_first_child,58);
    insert(root_first_child,59);
    insert(root_first_child,91);
    insert(root_first_child,92);
    insert(root_first_child,93);
    insert(root_first_child,94);
    cout<<"Sab bdia hogya kaam"<<endl;
    cout<<root_first_child->next_sibling->next_sibling->data<<endl;
    cout<<root_first_child->first_child->next_sibling->data<<endl;
    cout<<"The sum of all elements is: "<<sum_of_all_nodes(root)<<endl;
    return 0;
}