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
void inOrder(Node *root)//left->root->right
{
    if(root==NULL)
    return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
void delete_tree(Node *root)//this is the main function used for deleting the tree
{
    //we will be following bottom to top appraoch in this method
    /*child node should be deleted first before deleting the root/parent node
    therefore we will be following(postorder left->right->root) appraoch for this*/
    if(root==NULL)
    return;
    delete_tree(root->left);
    delete_tree(root->right);
    cout<<"The node that is deleted :"<<root->data<<endl;
    free(root);
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
           cout<<"The inorder traversal of the given tree is :"<<endl;
           inOrder(root);
           cout<<endl;
           cout<<"deleting the tree"<<endl;
           delete_tree(root);
           inOrder(root);
           return 0;
}