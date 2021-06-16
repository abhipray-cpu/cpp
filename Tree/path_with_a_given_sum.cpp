//same code just check the sum first while printingn the arrat if satisfies than print else don' print
//all paths from root to leafs
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

void printPathsRecur(Node* node, int path[], int pathLen,int sum); 
void printArray(int ints[], int len,int sum); 

void printPaths(Node *root,int sum)
{
    int path[1000]; 
    printPathsRecur(root, path, 0,sum); 
}
void printPathsRecur(Node* node, int path[], int pathLen,int sum)
{
      if(node ==NULL)
      return;
      path[pathLen++]=node->data;//we will append the node to path;
      //if this node is a leaf print the path
      if(node->left==NULL && node->right==NULL)
      {
          printArray(path,pathLen,sum);
      }
      //else traverse both the subtrees
      else
      {
          printPathsRecur(node->left,path,pathLen,sum);
          printPathsRecur(node->right,path,pathLen,sum);
      }
}
void printArray(int ints[], int len,int sum) 
{
    int sum_elements=0;
    for(int i=0;i<len;i++)
    {
        sum_elements+=ints[i];
    }
    if(sum_elements==sum)
    {
        cout<<"The total path length at this point of time is :"<<len<<endl;
     for (int i = 0; i < len; i++) 
    { 
        cout << ints[i] << "-->"; 
        
    } 

    cout<<"NULL";
    cout<<"the position indexes of theses values are :"<<endl;
    for(int i=0;i<len;i++)
    {
        cout<<i<<"-->";
    }
    cout<<endl;
    }
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
           cout<<"Here are all the possible paths from root to leaf :"<<endl;
           printPaths(root,42);
    return 0;
}