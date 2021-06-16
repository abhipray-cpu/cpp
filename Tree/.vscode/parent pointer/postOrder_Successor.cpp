#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node *parent;
};
Node *get_newNode(int data)
{
Node *newNode=new Node;
newNode->data=data;
newNode->left=NULL;
newNode->right=NULL;
newNode->parent=NULL;
return newNode;
}
Node *insert(Node *root,int data)
{
    if(root==NULL)
    return(get_newNode(data));
    else if(data<root->data)
    {
        Node *temp=insert(root->left,data);
        root->left=temp;
        temp->parent=root;
    }
    else if(data>root->data)
    {
        Node *temp=insert(root->right,data);
        root->right=temp;
        temp->parent=root;
    }
    return root;
}
Node *search(Node *root,int data)
{
    if(root==NULL)
    return root;
    else if(root->data==data)
    return root;
    else if(root->data<data)
    search(root->right,data);
    else if(root->data>data)
    search(root->left,data);
}
void inorderTraversal(Node *root)
{
    if(root==NULL)
    return;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}
void preorder(Node *root)
{
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node *root)
{
    if(root==NULL)
    return;
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
//finding inorder successor
Node *get_min(Node *root)
{
    Node *temp=root;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
}
Node *get_postorderSuccessor(Node *root,Node *n)
{
    //this is the algorithm we will be following
    /*An efficient solution is based on below observations.

1)If given node is root then postorder successor is NULL, since root is the last
 node print in a postorder traversal

2)If given node is right child of parent or right child of parent is NULL, then parent is postorder successor.

3)If given node is left child of parent and right child of parent is not NULL, then postorder successor is the leftmost node of parent’s right subtree*/


//case1
if(n==root)
return NULL;
//if given node is right child of paretn or parent's rigtht is empty
Node *parent=n->parent;
 if (parent->right == NULL || parent->right == n)
        return parent;
//in all other cases find leftmost child in right subtree
    Node* curr = parent->right;
    while (curr->left != NULL)//here we are finding the min node in left subtree
        curr = curr->left;
   
    return curr;

}
int main()
{
     Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    inorderTraversal(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    cout<<"The min value present in tree is = "<<get_min(root)->data<<endl;
    Node *ancestor=search(root,40);
    Node *successor=get_postorderSuccessor(root,ancestor);
    cout<<"The postordersuccessor of "<<ancestor->data<<" is "<<successor->data<<endl;

  return 0;
}