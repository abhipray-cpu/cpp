#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Tree
{
   public:
   Node *root;
   Node *getnewNode(int data);
   Node *insert(Node *root,int data);
   bool search(Node *root,int data);
   void inOrder(Node *root);
   void postOrder(Node *root);
   void preOrder(Node *root);
   Node *deleteNode(Node *temp,int data);
   int get_min(Node *root);
   int get_max(Node *root);
   int max_depth(Node *root);
   void levelOrder(Node *root);

};
Node* Tree::getnewNode(int data)
{
    Node *newNode=new Node;
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

Node *Tree::insert(Node *root,int data)
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
bool Tree::search(Node *root,int data)
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
void Tree::inOrder(Node *root)
{
 if(root==NULL)
    return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
void Tree::preOrder(Node *root)
{
if(root==NULL)
    return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void Tree::postOrder(Node *root)
{

    if(root==NULL)
    return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}


int Tree::get_min(Node *root)
{
Node *temp=root;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp->data;
}
int Tree::get_max(Node *root)
{
    Node *temp=root;
while(temp->right!=NULL)
{
    temp=temp->right;
}
return temp->data;
}

Node* Tree::deleteNode(Node *root,int data)
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


int Tree::max_depth(Node *root)
{
    if(root==NULL)
return 0;
int ldepth=max_depth(root->left);
int rdepth=max_depth(root->right);
return (max(ldepth,rdepth)+1);
}
void Tree::levelOrder(Node *root)
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
    Tree T;
    T.root=NULL;
    T.root=T.insert(T.root,20);
    T.insert(T.root,10);
    T.insert(T.root,25);
    T.insert(T.root,8);
    T.insert(T.root,12);
    T.insert(T.root,24);
    T.insert(T.root,27);
    T.insert(T.root,4);
    T.insert(T.root,9);
    T.insert(T.root,11);
    T.insert(T.root,14);
      cout<<"This is the inorder traversal of the given tree"<<endl;
           T.inOrder(T.root);
           cout<<endl;
           cout<<"This is the preorder traversal of the given tree"<<endl;
           T.preOrder(T.root);
           cout<<endl;
           cout<<"This is the postOrder traversal of the given tree"<<endl;
           T.postOrder(T.root);
           cout<<T.search(T.root,14)<<endl;
           cout<<T.search(T.root,69)<<endl;
           cout<<T.search(T.root,27)<<endl;
           cout<<"The min value in given tree is = "<<T.get_min(T.root)<<endl;
           cout<<"The max value in given tree is = "<<T.get_max(T.root)<<endl;
           cout<<"The max depth of treee or the depth of tree = "<<T.max_depth(T.root)<<endl;
          Node *del= T.deleteNode(T.root,14);
cout<<T.search(T.root,14)<<endl;
cout<<"The level order traversal of the given tree is :"<<endl;
T.levelOrder(T.root);

cout<<endl;
return 0;
}
