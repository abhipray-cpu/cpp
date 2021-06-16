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
        search(root->right,data);
    }
    else if(root->data >= data)
    {
        search(root->left,data);
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
void preOrder(Node *root)//root->left->right
{
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(Node *root)//left->right->root
{
    if(root==NULL)
    return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int get_min(Node *root)//since the leftmost node is the min value
{
    Node *temp=root;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp->data;
}

int get_max(Node *root)//right most node contains the max value
{ Node *temp=root;
while(temp->right!=NULL)
{
    temp=temp->right;
}
return temp->data;
}

//this one is a recurssive approach
Node* deleteNode(Node*root,int data)
//deleting a node from a binary tree
{
//we have three scenarios here
/*leaf node:just delete it
parent with one child node:swapt the nodes and than delete the child/leaf node
parent with more than one child?
swap with the min value from right tree or
max value from left subtree and simply delte the swapped value than
which will be a leaf node ultimately*/

/*
     * If the node becomes NULL, it will return NULL
     * Two possible ways which can trigger this case
     * 1. If we send the empty tree. i.e root == NULL
     * 2. If the given node is not present in the tree.
     */
    if(root == NULL)
        return NULL;
    /*
     * If root->key < val. val must be present in the right subtree
     * So, call the above remove function with root->right
     */
    if(root->data < data)
        root->right = deleteNode(root->right,data);
    /*
     * if root->key > val. val must be present in the left subtree
     * So, call the above function with root->left
     */
    else if(root->data > data)
        root->left = deleteNode(root->left,data);
    /*
     * This part will be executed only if the root->key == val
     * The actual removal starts from here
     */
    else
    {
        /*
         * Case 1: Leaf node. Both left and right reference is NULL
         * replace the node with NULL by returning NULL to the calling pointer.
         * free the node
         */
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        /*
         * Case 2: Node has right child.
         * replace the root node with root->right and free the right node
         */
        else if(root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        /*
         * Case 3: Node has left child.
         * replace the node with root->left and free the left node
         */
        else if(root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        /*
         * Case 4: Node has both left and right children.
         * Find the min value in the right subtree
         * replace node value with min.
         * And again call the remove function to delete the node which has the min value.
         * Since we find the min value from the right subtree call the remove function with root->right.
         */
        else
        {
            int rightMin = get_min(root->right);
            root->data = rightMin;
            root->right = deleteNode(root->right,rightMin);
            /*we can also follow an alternative approach of using the max value from left subtree here
            int leftMax = get_maxa(root->left);
            root->data = leftMax;
            root->left = deleteNode(root->left,leftMax);*/
        }

    }

    //return the actual root's address
    return root;
}


// Node *get_minNode(Node *root)
// {
//  Node *temp=root;
//     while(temp->left!=NULL)
//     {
//         temp=temp->left;
//     }
//     return temp;
// }
// Node *get_maxNode(Node *root)
// {
// Node *temp=root;
// while(temp->right!=NULL)
// {
//     temp=temp->right;
// }
// return temp;
// }


int max_depth(Node *root)//max depth is same as the depth of the tree
{
if(root==NULL)
return 0;
int ldepth=max_depth(root->left);
int rdepth=max_depth(root->right);
return (max(ldepth,rdepth)+1);
}
void levelOrder(Node *root)
{
// Base Case
    if (root == NULL)  return;
 
    // Create an empty queue for level order traversal
    queue<Node *> q;
 
    // Enqueue Root and initialize height
    q.push(root);
 
    while (q.empty() == false)
    {
        // Print front of queue and remove it from queue
        Node *node = q.front();
        cout << node->data << " ";
        q.pop();
 
        /* Enqueue left child */
        if (node->left != NULL)
            q.push(node->left);
 
        /*Enqueue right child */
        if (node->right != NULL)
            q.push(node->right);
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
           cout<<"This is the inorder traversal of the given tree"<<endl;
           inOrder(root);
           cout<<endl;
           cout<<"This is the preorder traversal of the given tree"<<endl;
           preOrder(root);
           cout<<endl;
           cout<<"This is the postOrder traversal of the given tree"<<endl;
           postOrder(root);
           cout<<endl;
           cout<<search(root,14)<<endl;
           cout<<search(root,69)<<endl;
           cout<<search(root,27)<<endl;
           cout<<"The min value in given tree is = "<<get_min(root)<<endl;
           cout<<"The max value in given tree is = "<<get_max(root)<<endl;
           cout<<"The max depth of treee or the depth of tree = "<<max_depth(root)<<endl;
cout<<"The level order traversal of the given tree is :"<<endl;
levelOrder(root);
cout<<endl;
Node *del=deleteNode(root,14);
cout<<search(root,14)<<endl;
    return 0;
}