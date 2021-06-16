#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Tree
{
   public:
   Node *root;
   Node *getnewNode(int data);
   Node *insert(Node *root,int data);
   bool binary_identical_tree(Node *root1,Node *root2);

};
Node* Tree::getnewNode(int data)
{
    Node *newNode=new Node;
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

Node *Tree::insert(Node *root,int data)
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

bool Tree::binary_identical_tree(Node *root1,Node *root2)
{
    if(root1==NULL && root2==NULL)
    return true;
    if(root1==NULL||root2==NULL)
    return false;
    else if((root1->data==root2->data)&&(binary_identical_tree(root1->left,root2->left))&&(binary_identical_tree(root1->right,root2->right)))
    return true;
    else 
    return false;
}

int main()
{
    Tree T1;
    T1.root=NULL;
    T1.root=T1.insert(T1.root,20);
    T1.insert(T1.root,10);
    T1.insert(T1.root,25);
    T1.insert(T1.root,8);
    T1.insert(T1.root,12);
    T1.insert(T1.root,24);
    T1.insert(T1.root,27);
    T1.insert(T1.root,4);
    T1.insert(T1.root,9);
    T1.insert(T1.root,11);
    T1.insert(T1.root,14);
    Tree T2;
    T2.root=NULL;
    T2.root=T2.insert(T2.root,20);
    T2.insert(T2.root,10);
    T2.insert(T2.root,25);
    T2.insert(T2.root,8);
    T2.insert(T2.root,12);
    T2.insert(T2.root,24);
    T2.insert(T2.root,27);
    T2.insert(T2.root,4);
    T2.insert(T2.root,9);
    T2.insert(T2.root,11);
    T2.insert(T2.root,14);
    cout<<T1.binary_identical_tree(T1.root,T2.root)<<endl;
   
    return 0;
}