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

Node *find(Node *root,int data)
{
if(root==NULL)
return NULL;
else if(root->data==data)
return root;
else if(root->data<data)
{
    return find(root->right,data);
}
else
return find(root->left,data);
}

Node *find_min(Node *root)
{
Node *temp=root;
if(temp==NULL)
return NULL;
while(temp->left!=NULL)
{
    temp=temp->left;
}
return temp;
}
Node *postOrder_successor(Node *root,int data)
{
    //cover this up in white board
}
int main()
{
    Node *root=NULL;
    root=insert(root,20);
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
         
           return 0;
}