#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node *get_newNode(int data)
{
    Node *newNode=new Node;
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    return newNode;
}

Node *insert(Node *root,int data)
{
    if(root==NULL)
    root=get_newNode(data);
    else if(root->data<data)
    root->right=get_newNode(data);
    else if(root->data>data)
    root->left=get_newNode(data);
    return root;
}

int get_max_width(Node *root)
{
int max_Width=0;
int width;
int height=get_height(root);
int i;
   for (i = 1; i <= height; i++) {
        width = get_width(root, i);
        if (width > max_Width)
            max_Width = width;
    }
  
    return max_Width;
}
int get_width(Node *root,int level)
{
if(root==NULL)
return 0;
if(level==1)
return 1;
else if(level>1)
{
    return get_width(root->left,level-1)+
    get_width(root->right,level-1);
}
}
int get_height(Node *root)
{
    if(root==NULL)
    return 0;
    int ldepth=get_height(root->left);
    int rdepth=get_height(root->right);
    return(max(ldepth,rdepth)+1);
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
           insert(root,14); return 0;
}