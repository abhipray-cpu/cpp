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
Node *get_preorderSuccessor(Node *root,Node *n)
{
    //this is the algorithm we will be using
    /*
    1)If left child of given node exists, then the left child is preorder successor.
     
     2)If left child does not exist and given node is left child of its parent, then its 
       sibling is its preorder successor.

     3)If none of above conditions are satisfied (left child does not exist and given 
       node is not left child of its parent), then we move up using parent pointers until one of the following happens.
       
       a)We reach root. In this case, preorder successor does not exist.
       
       b)Current node (one of the ancestors of given node) is left child of its parent, 
       in this case preorder successor is sibling of current node.*/

       if(n->left)//case 1
       return n->left;
       //else cases
       Node *curr=n;
       Node *parent=n->parent;
       while(parent!=NULL && parent->right==curr)
       {
           curr=curr->parent;
           parent=parent->parent;
       }
        if (parent == NULL)
        return NULL;
  
    return parent->right;
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
    Node *successor=get_preorderSuccessor(root,ancestor);
    cout<<"The preordersuccessor of "<<ancestor->data<<" is "<<successor->data<<endl;

  return 0;
}