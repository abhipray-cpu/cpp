//this code will return mirror of a binary tree
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node *getnewNode(int data)
{
    Node *newNode=new Node;
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
Node *insert(Node *root,int data)
{
if(root==NULL)
{
    root=getnewNode(data);
}
else if(data <= root->data)
{
    root->left=insert(root->left,data);
}
else if(data>root->data)
{
    root->right=insert(root->right,data);
}
return root;
}

   void mirror(Node*root) 
{
    if (root == NULL) 
        return; 
    else
    {
        Node *temp;
          
        /* do the subtrees */
        mirror(root->left);
        mirror(root->right);
      
        /* swap the pointers in this node */
        temp     = root->left;
        root->left = root->right;
        root->right = temp;
    }
} 

void inorder_traversal(Node *root)
{
    if(root==NULL)
    return;
    inorder_traversal(root->left);
    cout<<root->data<<" ";
    inorder_traversal(root->right);
}

int areMirror(Node* a, Node* b)
{
    /* Base case : Both empty */
    if (a==NULL && b==NULL)
        return true;
  
    // If only one is empty
    if (a==NULL || b == NULL)
        return false;
  
    /* Both non-empty, compare them recursively
     Note that in recursive calls, we pass left
     of one tree and right of other tree */
    return  a->data == b->data &&
            areMirror(a->left, b->right) &&
            areMirror(a->right, b->left);
}

int main()
{
    Node *root1=NULL;
    root1=insert(root1,20);//as root node is null initially therefore we need to assign value for further progress
    insert(root1,10);
    insert(root1,25);
    insert(root1,8);
     insert(root1,12);
      insert(root1,24);
       insert(root1,27);
        insert(root1,4);
         insert(root1,9);
          insert(root1,11);
           insert(root1,14);
           Node *root2=NULL;
    root2=insert(root2,20);//as root node is null initially therefore we need to assign value for further progress
    insert(root2,10);
    insert(root2,25);
    insert(root2,8);
     insert(root2,12);
      insert(root2,24);
       insert(root2,27);
        insert(root2,4);
         insert(root2,9);
          insert(root2,11);
           insert(root2,14);
           cout<<"This is the inorder traversal of the original tree: "<<endl;
           inorder_traversal(root1);
           mirror(root1);
           cout<<"this is the inorder traversal of the mirror of the tree: "<<endl;
           inorder_traversal(root1);
           cout<<endl;
           //we are producing two identical trees and is mirroring one of them here root1 and root2 is unaltered
           cout<<areMirror(root1,root2)?true:false;
           return 0;
}

//first a  seprate mirror tree will be produced than these two trees will be checked with  each other