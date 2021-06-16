/*code to verify whethere a bt is a bst or not*/
//Appraoch 1

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
//this is approach 1 for verifying the bst
Node *get_max(Node *root)//rightmost node
{
Node *temp=root;
while(temp->right!=NULL)
{
         temp=temp->right;
}
return temp;
}
Node *get_min(Node *root)//leftmost node
{
Node *temp=root;
while(temp->left!=NULL)
{
         temp=temp->left;
}
return temp;
}
 bool approach1(Node *root)
 {
       Node *max=get_max(root->right);
       Node *min=get_min(root->left);
if(min->data<=root->data&&max->data>root->data)//general approach 
{
    return true;
}
else
return false;
 }
//this is the approch 2 for verfying the bst
bool isSubtreeLesser(Node *root,int value)
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
bool isSubtreeGreater(Node *root,int value)
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
bool isBST(Node *root)
{
    if(root==NULL)
    return true;
    if(isSubtreeGreater(root->right,root->data)&&isSubtreeLesser(root->left,root->data)&&isBST(root->left)&&isBST(root->right))
    {
        return true;
    }
    else
    return false;
}
/* Returns true if the given
tree is a BST and its values
are >= min and <= max. */
int isBSTUtil(Node* node, int min, int max)
{
    /* an empty tree is BST */
    if (node==NULL)
        return 1;
             
    /* false if this node violates
    the min/max constraint */
    if (node->data < min || node->data > max)
        return 0;
     
    /* otherwise check the subtrees recursively,
    tightening the min or max constraint */
    return
        isBSTUtil(node->left, min, node->data-1) && // Allow only distinct values
        isBSTUtil(node->right, node->data+1, max); // Allow only distinct values
}
int approach3(Node* node)
{
    return(isBSTUtil(node, INT_MIN, INT_MAX));
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
           cout<<approach1(root)<<endl;
           cout<<isBST(root)<<endl;
           cout<<approach3(root)<<endl;
           return 0;

}