//this code will return mirror of a binary tree
//mirror of  a tree is also known as inverted tree
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

int main()
{
    Node *root=NULL;
    root=insert(root,20);//as root node is null initially therefore we need to assign value for further progress
    insert(root,10);
    insert(root,25);
    insert(root,8);
     insert(root,12);
      insert(root,24);
       insert(root,27);
        insert(root,4);
         insert(root,9);
          insert(root,11);
           insert(root,14);
           cout<<"This is the inorder traversal of the original tree: "<<endl;
           inorder_traversal(root);
           mirror(root);
           cout<<"this is the inorder traversal of the mirror of the tree: "<<endl;
           inorder_traversal(root);
           return 0;
}