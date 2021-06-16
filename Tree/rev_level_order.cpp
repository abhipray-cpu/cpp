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
    newNode->left=NULL;
    newNode->right=NULL;
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

void reverse_levelOrder(Node *root)
{
//we will use a queue for regular level order traversla and then store the elements in a stack so that they can be printed in revrese order
queue<Node*>q;
stack<Node*>s;
q.push(root);
while(!q.empty())
{
    Node *temp=q.front();
    q.pop();
    if(temp->right!=NULL)
    {
        q.push(temp->right);
    }
    if(temp->left!=NULL)
    {
        q.push(temp->left);
    }
    s.push(temp);
}
while(!s.empty())
{
    cout<<s.top()<<" ";//for sure this will give us the address as we are storing the address not value
    s.pop();
}
}
void rev_level_order_data(Node *root)
{
    queue<Node*>q;
    stack<int>s;
    q.push(root);
    while(!q.empty())
    {
        Node *temp=q.front();
        q.pop();
        if(temp->right!=NULL)
        {
            q.push(temp->right);
        }
        if(temp->left!=NULL)
        {
            q.push(temp->left);
        }
        s.push(temp->data);
    }
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
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
           cout<<"The reverse level order traversal for pointers only of the given binary tree is : "<<endl;
           reverse_levelOrder(root);
           cout<<endl;
           cout<<"The reverse level order traversal of the given tree is :"<<endl;
           rev_level_order_data(root);

    return 0;
}