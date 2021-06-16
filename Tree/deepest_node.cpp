//deepest node this can be found as the last node during the level order traversal
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
{
    root=get_newNode(data);
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
Node *deepest_node(Node *root)
{
    //we will be returning the last node of queue while level order traversal
    queue<Node*>q;
    q.push(root);
    Node *temp;
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        if(temp->left!=NULL)
        q.push(temp->left);
        if(temp->right!=NULL)
        q.push(temp->right);
}
return temp;
    
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
           Node *deepest=deepest_node(root);
           cout<<"The deepest node of the given tree is:"<<deepest->data<<endl;
           insert(root,28);
           Node *deepeset_2=deepest_node(root);
            cout<<"The deepest node of the given tree is:"<<deepeset_2->data<<endl;

    return 0;
}