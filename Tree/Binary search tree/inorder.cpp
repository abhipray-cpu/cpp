/*
Inorder successor:Minimum value in right subtree
Inorder Predecessor:Max value in left subtree


*/


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
bool search(Node *root,int data)
{
    if(root==NULL)
    {
        return false;
    }
    else if(root->data==data)
    {
        return true;
    }
    else if(root->data<data)
    {
        return search(root->right,data);
    }
    else if(root->data >= data)
    {
        return search(root->left,data);
    }
}
Node *findMin(Node *root)
{
if(root==NULL)
return NULL;
else if(root->left==NULL)
return root;
else 
return findMin(root->left);
}
Node *findMax(Node *root)
{
    if(root==NULL)
return NULL;
else if(root->right==NULL)
return root;
else 
return findMax(root->right);
}
Node *inorder_successor(Node *root)
{
return findMin(root->right);
}
Node *inorder_predecssor(Node *root)
{
return findMax(root->left);
}
Node *returnNode(Node *root,int data)
{
if(root==NULL)
return NULL;
if(root->data==data)
{
    return root;
}
else if(root->data<data)
{
    return returnNode(root->right,data);
}
else if(root->data>data)
{
    return returnNode(root->left,data);
}
}
void inOrder(Node *root)//left->root->right
{
    if(root==NULL)
    return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
int main()
{
    Node *root=NULL;
    root=insert(root,1000);
    vector<int> less,greater;
    for(int i=0;i<1000;i++)
    {
        less.push_back(i);
    }
    for(int j=1001;j<2000;j++)
    {
        greater.push_back(j);
    }
    auto rng = default_random_engine{};
    shuffle(less.begin(),less.end(), rng);
    shuffle(greater.begin(),greater.end(), rng);
    while(!less.empty())
    {
        insert(root,less.back());
        less.pop_back();
    }
    while(!greater.empty())
    {
        insert(root,greater.back());
        greater.pop_back();
    }
    inOrder(root);
    cout<<";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; \n";
    cout<<search(root,1618)<<endl;
    Node *temp=returnNode(root,1957);
    cout<<temp->data<<endl;
    Node *inorderSuccessor=findMin(temp->right);
    Node *inorderPredecssor=findMax(temp->left);
    cout<<inorderSuccessor->data<<endl;//this approach is not that good follow the bt one
    cout<<";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;";
    inOrder(temp->left);
    return 0;

}
