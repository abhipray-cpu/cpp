#include<bits/stdc++.h>
using namespace std;

static vector<Node*>mkb;
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

Node *get_Node(Node*root,int data)
{
     if(root==NULL)
     return NULL;
     if(root->data==data)
     return root;
     if(root->data<data)
     return get_Node(root->right,data);
     if(root->data>data)
     return get_Node(root->left,data);
     else
     return NULL;
}



bool all_ancestors(Node *root,int data)
{
    if(root==NULL)
    return false;
    if(root->data==data)
    return true;
    if(all_ancestors(root->left,data)||all_ancestors(root->right,data))
    {
     cout<<root->data<<" ";
     return true;
    }
    return false;
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

           Node *a1=get_Node(root,20);
           Node *a2=get_Node(root,10);
           Node *a3=get_Node(root,25);
           Node *a4=get_Node(root,8);
           Node *a5=get_Node(root,12);
           Node *a6=get_Node(root,24);
           Node *a7=get_Node(root,27);
           Node *a8=get_Node(root,4);
           Node *a9=get_Node(root,9);
           Node *a10=get_Node(root,11);
           Node *a11=get_Node(root,14);

           cout<<a1->data<<endl;
            cout<<a2->data<<endl;
             cout<<a3->data<<endl;
              cout<<a4->data<<endl;
               cout<<a5->data<<endl;
                cout<<a6->data<<endl;
                 cout<<a7->data<<endl;
                  cout<<a8->data<<endl;
                   cout<<a9->data<<endl;
                    cout<<a10->data<<endl;
                     cout<<a11->data<<endl;

        queue<Node*>ancestors;
        bool val=all_ancestors(root,14);
        cout<<endl;
        cout<<val<<endl;
       

        
        
      
        return 0;
        

}