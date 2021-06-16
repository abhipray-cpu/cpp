#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
Node *get_newNode(int data)
{
    Node *newNode=new Node;
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    newNode->height=1;
    return newNode;
}
int height(Node *root)
{
    if(root==NULL)
    return 0;
    else
    return root->height;
}
int max(int a,int b)
{
    return a>b?a:b;
}
int getBalance(Node *root)
{
    if(root==NULL)
    return 0;
    else
    return height(root->left)-height(root->right);
}
void preorder(Node *root)
{
    if(root==NULL)
    return;
    cout<<root->data<<"\t";
    preorder(root->left);
    preorder(root->right);
}

Node *rightRotate(Node *root)
{
    Node *x = root->left;
	Node *T2 = x->right;

	// Perform rotation
	x->right = root;
	root->left = T2;

	// Update heights
	root->height = max(height(root->left),
					height(root->right)) + 1;
	x->height = max(height(x->left),
					height(x->right)) + 1;

	// Return new root
	return x;
}
Node *leftRotate(Node *root)
{
    Node *y = root->right;
	Node *T2 = y->left;

	// Perform rotation
	y->left = root;
	root->right = T2;

	// Update heights
	root->height = max(height(root->left),
					height(root->right)) + 1;
	y->height = max(height(y->left),
					height(y->right)) + 1;

	// Return new root
	return y;

}
Node *insert(Node *root,int data)
{
    if(root==NULL)
    root=get_newNode(data);
    else if(root->data<data)
    root->right=insert(root->right,data);
    else if (root->data>data)
    root->left=insert(root->left,data);
    else
    return root;
    //updating heights and doing rotations
    /* 2. Update height of this ancestor node */
	root->height = 1 + max(height(root->left),
						height(root->right));

	/* 3. Get the balance factor of this ancestor
		node to check whether this node became
		unbalanced */
	int balance = getBalance(root);

	// If this node becomes unbalanced, then
	// there are 4 cases

	// Left Left Case
	if (balance > 1 && data < root->left->data)
		return rightRotate(root);

	// Right Right Case
	if (balance < -1 && data > root->right->data)
		return leftRotate(root);

	// Left Right Case
	if (balance > 1 && data > root->left->data)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	// Right Left Case
	if (balance < -1 && data < root->right->data)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	/* return the (unchanged) node pointer */
	return root;
}
//we will first merge by doing node sum
//1)recursive call
Node *merge_node_sum_recurr(Node *root1,Node *root2)
{
    if(root1==NULL)
    return root1;
    if(root2==NULL)
    return root1;
    root1->data=root1->data+root2->data;
    root1->left=merge_node_sum_recurr(root1->left,root2->left);
    root1->right=merge_node_sum_recurr(root1->right,root2->right);
    return root1;
}

int main()
{
	Node *root1 = NULL;
	
	/* Constructing tree given in
	the above figure */
	root1 = insert(root1, 10000);
    for(int i=0;i<10000;i++)
    {
        insert(root1,rand());
    }
	cout << "Preorder traversal of the "
			"constructed AVL tree1 is \n";
	preorder(root1);
    cout<<";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
          ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
          ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
          ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
          ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;";
        Node *root2 = NULL;
	
	/* Constructing tree given in
	the above figure */
	root2 = insert(root2, 10000);
    for(int i=0;i<10000;i++)
    {
        insert(root2,rand());
    }
	cout << "Preorder traversal of the "
			"constructed AVL tree1 is \n";
	preorder(root2);
    cout<<"The merged node sum of the two trees is : \n";
    Node *root_12=merge_node_sum_recurr(root1,root2);
    preorder(root_12);
	
	return 0;
}