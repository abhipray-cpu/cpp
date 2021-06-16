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
    root->right=insert(root->right,data);
    else if(root->data>data)
    root->left=insert(root->left,data);
    return root;
}
void inorder(Node *root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->data<<"\t";
    inorder(root->right);
    }

void right_view_recurr(Node *root,int level ,int *max_level)
{
   if(root==NULL)
   return;
   if(*max_level<level)
   {
       cout<<root->data<<"-->";
       *max_level=level;
   }
   right_view_recurr(root->right,level+1,max_level);
   right_view_recurr(root->left,level+1,max_level);
}
void right_view(Node *root)
{
    int max_level=0;
    right_view_recurr(root,1,&max_level);
}
int main()
{
    Node *root=NULL;
    root=insert(root,50000);
    vector<int>v1,v2;
    for(int i=0;i<50000;i++)
{
    v1.push_back(i);
}
for(int i=50001;i<100000;i++)
{
    v2.push_back(i);
}
    auto rng=default_random_engine{};
    shuffle(v1.begin(),v1.end(),rng);
    shuffle(v2.begin(),v2.end(),rng);
    while(!v1.empty())
    {
        insert(root,v1.back());
        v1.pop_back();
    }
    while(!v2.empty())
    {
        insert(root,v2.back());
        v2.pop_back();
    }
    inorder(root);

cout<<";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
      ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
      ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; \n";
cout<<"This is the right view of the given binary tree \n";
right_view(root);
return 0;
}