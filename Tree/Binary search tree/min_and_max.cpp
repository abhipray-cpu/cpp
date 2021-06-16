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
void inOrder(Node *root)//left->root->right
{
    if(root==NULL)
    return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
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
    Node *min=findMin(root);
    Node *max=findMax(root);
    cout<<"The min element in given BST is :"<<min->data<<endl;
    cout<<"The max element in given BST is :"<<max->data<<endl;
    return 0;

}
