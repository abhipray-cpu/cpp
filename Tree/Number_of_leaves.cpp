//level order and check for nodes with no children and keep their count
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
int single_parent_count(Node *root)
{
  queue<Node*>q;
    q.push(root);
    int single_parent_count=0;
    while(!q.empty())
    {
        Node *temp=q.front();
        q.pop();
        if((temp->left==NULL && temp->right!=NULL)||temp->left!=NULL && temp->right==NULL)
        {cout<<"The given node is a single parent node:"<<temp->data<<endl;
            single_parent_count++;
        }
        if(temp->left!=NULL)
        {
            q.push(temp->left);
        }
        if(temp->right!=NULL)
        {
            q.push(temp->right);
        }
    }
    return single_parent_count;   
}
int leaf_node_count(Node *root)
{
    queue<Node*>q;
    q.push(root);
    int leaf_count=0;
    while(!q.empty())
    {
        Node *temp=q.front();
        q.pop();
        if(temp->left==NULL && temp->right==NULL)
        {cout<<"The given node is a leaf node:"<<temp->data<<endl;
            leaf_count++;
        }
        if(temp->left!=NULL)
        {
            q.push(temp->left);
        }
        if(temp->right!=NULL)
        {
            q.push(temp->right);
        }
    }
    return leaf_count;
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
           insert(root,28);
           cout<<"The number of leaf nodes in given tree is:"<<leaf_node_count(root)<<endl;
           cout<<"The number of single parent  nodes in given tree is:"<<single_parent_count(root)<<endl;

           return 0;
}