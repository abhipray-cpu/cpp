#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class verify{
    public:
    Node *root;
    Node *getnewNode(int data);
    Node *insert(Node *root,int data);
    Node *get_min(Node *root);
    Node *get_max(Node *root);
    bool approach1(Node *root);//correct but not efficient
    bool isSubtreeLesser(Node *root,int value);
    bool isSubtreeGreater(Node *root,int value);
    bool approach2(Node *root);
    int isBSTUtil(Node* root, int min, int max);
    int approach3(Node* root);//efficient approach
    };


Node* verify::getnewNode(int data)
{
  Node *newNode=new Node;
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
Node* verify::insert(Node *root,int data)
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
Node* verify::get_min(Node *root)
{
Node *temp=root;
while(temp->left!=NULL)
{
         temp=temp->left;
}
return temp;
}
Node* verify::get_max(Node *root)
{
Node *temp=root;
while(temp->right!=NULL)
{
         temp=temp->right;
}
return temp;
}
bool verify::approach1(Node *root)
{
   Node *max=get_max(root->right);
       Node *min=get_min(root->left);
if(min->data<=root->data&&max->data>root->data)
{
    return true;
}
else
return false;
}

bool verify::isSubtreeLesser(Node *root,int value)
{
if(root==NULL)
   return true;
   if((root->data<=value)&&isSubtreeLesser(root->left,value)&&isSubtreeLesser(root->right,value))
{
        return true;
   }
   else
   return false;
}
bool verify::isSubtreeGreater(Node *root,int value)
{
    if(root==NULL)
   return true;
   if((root->data>value)&&isSubtreeGreater(root->left,value)&&isSubtreeGreater(root->right,value))
{
        return true;
   }
   else
   return false;
}
bool verify::approach2(Node *root)
{
if(root==NULL)
    return true;
    if(isSubtreeGreater(root->right,root->data)&&isSubtreeLesser(root->left,root->data)&&approach2(root->left)&&approach2(root->right))
    {
        return true;
    }
    else
    return false;
}
int verify::isBSTUtil(Node *root,int min,int max)
{
 /* an empty tree is BST */
    if (root==NULL)
        return 1;
             
    /* false if this node violates
    the min/max constraint */
    if (root->data < min || root->data > max)
        return 0;
     
    /* otherwise check the subtrees recursively,
    tightening the min or max constraint */
    return
        isBSTUtil(root->left, min, root->data-1) && // Allow only distinct values
        isBSTUtil(root->right, root->data+1, max); // Allow only distinct values
}
int verify::approach3(Node *root)
{
return(isBSTUtil(root, INT_MIN, INT_MAX));
}
int min()
{
    verify T;
    T.root=NULL;
    T.root=T.insert(T.root,20);
    T.insert(T.root,10);
    T.insert(T.root,25);
    T.insert(T.root,8);
    T.insert(T.root,12);
    T.insert(T.root,24);
    T.insert(T.root,27);
    T.insert(T.root,4);
    T.insert(T.root,9);
    T.insert(T.root,11);
    T.insert(T.root,14);
    cout<<T.approach1(T.root)<<endl;
           cout<<T.approach2(T.root)<<endl;
           cout<<T.approach3(T.root)<<endl;
           return 0;
}