#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node *parent;
};
Node *get_newNode(int data)
{
Node *newNode=new Node;
newNode->data=data;
newNode->left=NULL;
newNode->right=NULL;
newNode->parent=NULL;
return newNode;
}
Node *insert(Node *root,int data)
{
    if(root==NULL)
    return(get_newNode(data));
    else if(data<root->data)
    {
        Node *temp=insert(root->left,data);
        root->left=temp;
        temp->parent=root;
    }
    else if(data>root->data)
    {
        Node *temp=insert(root->right,data);
        root->right=temp;
        temp->parent=root;
    }
    return root;
}
Node *search(Node *root,int data)
{
    if(root==NULL)
    return root;
    else if(root->data==data)
    return root;
    else if(root->data<data)
    search(root->right,data);
    else if(root->data>data)
    search(root->left,data);
}
void inorderTraversal(Node *root)
{
    if(root==NULL)
    return;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}
void preorder(Node *root)
{
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node *root)
{
    if(root==NULL)
    return;
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
//finding inorder successor
Node *get_min(Node *root)
{
    Node *temp=root;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
}
Node *get_inorderSuccessor(Node *root,Node *n)
{
    //we will be usimg this algo
    /*If right subtree of node is not NULL, then succ lies in right subtree. Do the following. 
Go to right subtree and return the node with minimum key value in the right subtree.
If right sbtree of node is NULL, then succ is one of the ancestors. Do the following. 
Travel up using the parent pointer until you see a node which is left child of its parent.
 The parent of such a node is the succ.*/


 //firstly if the right subtree is not null we will return the min value node from it
 if(n->right!=NULL)
 {
     return get_min(n->right);
 }
 //this is the second case where the right subtree is null
 Node *p=n->parent;
 while(p!=NULL&n==p->right)
 {
     n=p;
     p=p->parent;
 }
 return p;
}
int main()
{
     Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    inorderTraversal(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    cout<<"The min value present in tree is = "<<get_min(root)->data<<endl;
    Node *ancestor=search(root,40);
    Node *successor=get_inorderSuccessor(root,ancestor);
    cout<<"The successor of "<<ancestor->data<<" is "<<successor->data<<endl;

  return 0;
}