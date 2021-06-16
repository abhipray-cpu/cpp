/*
strore inorder of both the tree in an array sorted ordder(inorder traversal)
compare the two array and keep a couter print the common elements when encountered
and if the counter==size of both trees(which should be equal) than the trees are identical as well


*/
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
void inorder_traversal(Node *root)
{
    if(root==NULL)
    return;
    inorder_traversal(root->left);
    cout<<root->data<<"\t";
    inorder_traversal(root->right);
}
void _store_inorder(Node *root,vector<Node*>&v)
{
    if(root==NULL)
    return;
    _store_inorder(root->left,v);
     v.push_back(root);
     _store_inorder(root->right,v);
}
int main()
{
    Node *root1=NULL,*root2=NULL;
    root1=insert(root1,10000);
    root2=insert(root2,10000);
    for(int i=0;i<100000;i++)
    {
        insert(root1,rand());
        insert(root2,rand());
    }
    // cout<<"INorder traversal of tree 1 is: "<<endl;
    // inorder_traversal(root1);
    // cout<<";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"<<endl;
    //  cout<<"INorder traversal of tree 2 is: "<<endl;
    // inorder_traversal(root2);
    vector<Node*>v1,v2;
    _store_inorder(root1,v1);
    _store_inorder(root2,v2);
    cout<<v1.size()<<endl<<v2.size();
    int size=min(v1.size(),v2.size());
    int counter=0;
    for(int i=0;i<size;i++)
    {
        if(v1[i]->data==v2[i]->data)
        {
            counter++;
            cout<<"Common element"<<counter<<" is "<<v1[i]->data<<endl;
        }
    }

    cout<<"\n there are "<<counter<<" number of common elements in toal in both the trees"<<endl;

    return 0;

}