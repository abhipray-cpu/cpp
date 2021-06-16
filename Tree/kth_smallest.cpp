// // A simple inorder traversal based C++ program
// // to find k-th smallest element in a BST.
// #include <iostream>
// using namespace std;

// // A BST node
// struct Node {
// 	int data;
// 	Node *left, *right;
// 	Node(int x)
// 	{
// 		data = x;
// 		left = right = NULL;
// 	}
// };

// // Recursive function to insert an key into BST
// Node* insert(Node* root, int x)
// {
// 	if (root == NULL)
// 		return new Node(x);
// 	if (x < root->data)
// 		root->left = insert(root->left, x);
// 	else if (x > root->data)
// 		root->right = insert(root->right, x);
// 	return root;
// }

// // Function to find k'th largest element in BST
// // Here count denotes the number of nodes processed so far
// Node* kthSmallest(Node* root, int& k)
// {
// 	// base case
// 	if (root == NULL)
// 		return NULL;

// 	// search in left subtree
// 	Node* left = kthSmallest(root->left, k);

// 	// if k'th smallest is found in left subtree, return it
// 	if (left != NULL)//this case is generally false
// 		return left;

// 	// if current element is k'th smallest, return it
// 	k--;
// 	if (k == 0)//and this case is generally executed when k hits 0
// 		return root;

// 	// else search in right subtree
// 	return kthSmallest(root->right, k);
// }

// // Function to find k'th largest element in BST
// void printKthSmallest(Node* root, int k)
// {
// 	// maintain index to count number of nodes processed so far
// 	int count = 0;
// 	Node* res = kthSmallest(root, k);
// 	if (res == NULL)
// 		cout << "There are less than k nodes in the BST";
// 	else
// 		cout << "K-th Smallest Element is " << res->data;
// }

// // main function
// int main()
// {
// 	Node* root = NULL;
// 	int keys[] = { 20, 8, 22, 4, 12, 10, 14 };

// 	for (int x : keys)
// 		root = insert(root, x);

// 	int k = 3;
// 	printKthSmallest(root, k);
// 	return 0;
// }


//second appraoch is to form an inorder array and find the element  at kth position

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
void InorderRecursive(Node *root, std::vector<Node*>& nodes)
{
    if (root == NULL)
        return;

    InorderRecursive(root->left, nodes); //visit left sub-tree

    std::cout << "Word: " << root->data << std::endl;
    nodes.push_back(root);

    InorderRecursive(root->right, nodes); //visit right sub-tree
}

std::vector<Node*> Inorder(Node *root)
{
    std::vector<Node*> nodes;    
    InorderRecursive(root, nodes);
    return nodes;
}
int main()
{
    Node *root=NULL;
    root=insert(root,10000);
    vector<int> less,greater;
    for(int i=0;i<10000;i++)
    {
        less.push_back(i);
    }
    for(int j=10001;j<20000;j++)
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
    cout<<";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;";
    vector<Node*>v=Inorder(root);
    int position;
    cout<<"Enter the kth position you want smallest number at :"<<endl;
    cin>>position;
    cout<<"The "<<position<<"th smallest element is: "<<v[position]->data<<endl;
    return 0;

}




