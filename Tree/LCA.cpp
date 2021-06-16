//LCA is the shortest path between 2 nodes as well
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

Node *lca(Node *root1,int n1,int n2)
{
if(root1==NULL)
return NULL;
if(root1->data>n1&&root1->data>n2)
{
    return lca(root1->left,n1,n2);
}
if(root1->data<n1&&root1->data<n2)
{
    return lca(root1->right,n1,n2);
    }
return root1;    
}
void Inorder(Node *root)
{
    if(root==NULL)
    return;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}


Node *LCA(Node *root1,Node *n1,Node *n2)
{
    if(root1==NULL)
return NULL;
if(root1->data>n1->data&&root1->data>n2->data)
{
    return LCA(root1->left,n1,n2);
}
if(root1->data<n1->data&&root1->data<n2->data)
{
    return LCA(root1->right,n1,n2);
    }
return root1; 
}

Node *get_Node(Node*root,int data)
{
     if(root==NULL)
     return NULL;
     if(root->data==data)
     return root;
     if(root->data<data)
     return get_Node(root->right,data);
     if(root->data>data)
     return get_Node(root->left,data);
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
           cout<<"The inorder traversal of the given node is:"<<endl;
           Inorder(root);
           cout<<endl;
           cout<<lca(root,4,9)->data<<endl;
           cout<<lca(root,4,11)->data<<endl;
           cout<<lca(root,8,12)->data<<endl;
           cout<<lca(root,12,24)->data<<endl;
           cout<<lca(root,24,27)->data<<endl;
           cout<<lca(root,10,25)->data<<endl;
           cout<<lca(root,8,27)->data<<endl;

           Node *node_14=get_Node(root,14);
           Node *node_9=get_Node(root,9);
           cout<<"The node is "<<node_14->data<<endl;
           cout<<"The node is "<<node_9->data<<endl;

           Node  *LCA_Node=LCA(root,node_14,node_9);
           cout<<"The lca of nodes 14 and 9 is "<<LCA_Node->data<<endl;

           return 0;
}