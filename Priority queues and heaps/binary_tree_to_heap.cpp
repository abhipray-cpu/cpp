#include<bits/stdc++.h>
using namespace std;
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
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
void store_inorder(Node *root,vector<int>&v)
{
    if(root==NULL)
    return;
    store_inorder(root->left,v);
    v.push_back(root->data);
    store_inorder(root->right,v);
}
void MaxHeapify(vector<int>&harr,int i,int heap_size)
{
    int l = 2*i+1;
	int r = 2*i+2;
	int largest = i;
	if (l < heap_size && harr[l] > harr[i])
		largest = l;
	if (r < heap_size && harr[r] > harr[largest])
		largest = r;
	if (largest != i)
	{
		swap(&harr[i], &harr[largest]);
		MaxHeapify(harr,largest,heap_size);
	}
}
void MinHeapify(vector<int>&harr,int i,int heap_size)
{
  int l = 2*i+1;
	int r = 2*i+2;
	int smallest = i;
	if (l < heap_size && harr[l] < harr[i])
		smallest = l;
	if (r < heap_size && harr[r] < harr[smallest])
		smallest = r;
	if (smallest != i)
	{
		swap(&harr[i], &harr[smallest]);
		MinHeapify(harr,smallest,heap_size);
	}
}

void create_max_heap(vector<int>&harr,int index,int heap_size)
{
     int left=2*index+1;
     int right=2*index+2;
     MaxHeapify(harr,left,heap_size);
     MaxHeapify(harr,right,heap_size);
     MaxHeapify(harr,index,heap_size);
}
void create_min_heap(vector<int>&harr,int index,int heap_size)
{
     int left=2*index+1;
     int right=2*index+2;
     MinHeapify(harr,left,heap_size);
     MinHeapify(harr,right,heap_size);
     MinHeapify(harr,index,heap_size);
}

int main()
{
    Node *root=NULL;
    root=insert(root,50000);
    vector<int>lesser,greater;
    for(int i=0;i<50000;i++)
    {
        lesser.push_back(i);
    }
    for(int i=50001;i<100000;i++)
    {
        greater.push_back(i);
    }
    auto rang=default_random_engine{};
    shuffle(lesser.begin(),lesser.end(),rang);
    shuffle(greater.begin(),greater.end(),rang);
    for(int i=0;i<lesser.size();i++)
    {
        insert(root,lesser[i]);
    }
    for(int i=0;i<greater.size();i++)
    {
        insert(root,greater[i]);
    }
    lesser.clear();
    greater.clear();
    //inorder(root);
    vector<int>min_vec,max_vec;
    min_vec={3 ,5 ,9 ,6 ,8 ,20 ,10 ,12 ,18 ,9};
    max_vec={20 ,18 ,10 ,12 ,9 ,9 ,3 ,5 ,6 ,8};
    // store_inorder(root,min_vec);
    // store_inorder(root,max_vec);
    // cout<<";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
    //       ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
    //       ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
    //       ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
    //       ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
    //       ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
    //       ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
    //       ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
    //       ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
    //       ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
    //       ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
    //       ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
    //       ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
    //       ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
    //       ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
    //       ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
    //       ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
    //       ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
    //       ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;";
    // for(int i=0;i<min_vec.size();i++)
    // {
    //     cout<<min_vec[i]<<"\t";
    // }
    //  cout<<";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
    //       ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
    //       ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
    //       ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
    //       ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
    //       ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
    //       ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
    //       ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
    //       ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
    //       ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
    //       ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
    //       ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
    //       ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
    //       ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
    //       ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
    //       ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
    //       ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
    //       ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
    //       ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;";
    // for(int i=0;i<max_vec.size();i++)
    // {
    //     cout<<max_vec[i]<<"\t";
    // }
    create_max_heap(max_vec,0,max_vec.size());
    create_min_heap(min_vec,0,min_vec.size());
    cout<<max_vec[0]<<endl;
    cout<<min_vec[0];
    
    return 0;
}
//bst to max heap
// C++ implementation to convert a given
// BST to Max Heap
// #include <bits/stdc++.h>
// using namespace std;

// struct Node {
// 	int data;
// 	Node *left, *right;
// };

// /* Helper function that allocates a new node
// with the given data and NULL left and right
// pointers. */
// struct Node* getNode(int data)
// {
// 	struct Node* newNode = new Node;
// 	newNode->data = data;
// 	newNode->left = newNode->right = NULL;
// 	return newNode;
// }

// // Function prototype for postorder traversal
// // of the given tree
// void postorderTraversal(Node*);

// // Function for the inorder traversal of the tree
// // so as to store the node values in 'arr' in
// // sorted order
// void inorderTraversal(Node* root, vector<int>& arr)
// {
// 	if (root == NULL)
// 		return;

// 	// first recur on left subtree
// 	inorderTraversal(root->left, arr);

// 	// then copy the data of the node
// 	arr.push_back(root->data);

// 	// now recur for right subtree
// 	inorderTraversal(root->right, arr);
// }

// void BSTToMaxHeap(Node* root, vector<int> arr, int* i)
// {
// 	if (root == NULL)
// 		return;

// 	// recur on left subtree
// 	BSTToMaxHeap(root->left, arr, i);

// 	// recur on right subtree
// 	BSTToMaxHeap(root->right, arr, i);

// 	// copy data at index 'i' of 'arr' to
// 	// the node
// 	root->data = arr[++*i];
// }

// // Utility function to convert the given BST to
// // MAX HEAP
// void convertToMaxHeapUtil(Node* root)
// {
// 	// vector to store the data of all the
// 	// nodes of the BST
// 	vector<int> arr;
// 	int i = -1;

// 	// inorder traversal to populate 'arr'
// 	inorderTraversal(root, arr);

// 	// BST to MAX HEAP conversion
// 	BSTToMaxHeap(root, arr, &i);
// }

// // Function to Print Postorder Traversal of the tree
// void postorderTraversal(Node* root)
// {
// 	if (!root)
// 		return;

// 	// recur on left subtree
// 	postorderTraversal(root->left);

// 	// then recur on right subtree
// 	postorderTraversal(root->right);

// 	// print the root's data
// 	cout << root->data << " ";
// }

// // Driver Code
// int main()
// {
// 	// BST formation
// 	struct Node* root = getNode(4);
// 	root->left = getNode(2);
// 	root->right = getNode(6);
// 	root->left->left = getNode(1);
// 	root->left->right = getNode(3);
// 	root->right->left = getNode(5);
// 	root->right->right = getNode(7);

// 	convertToMaxHeapUtil(root);
// 	cout << "Postorder Traversal of Tree:" << endl;
// 	postorderTraversal(root);

// 	return 0;
// }

//BST to min heap
// C++ implementation to convert the given
// BST to Min Heap
// #include <bits/stdc++.h>
// using namespace std;

// // structure of a node of BST
// struct Node
// {
// 	int data;
// 	Node *left, *right;
// };

// /* Helper function that allocates a new node
// with the given data and NULL left and right
// pointers. */
// struct Node* getNode(int data)
// {
// 	struct Node *newNode = new Node;
// 	newNode->data = data;
// 	newNode->left = newNode->right = NULL;
// 	return newNode;
// }

// // function prototype for preorder traversal
// // of the given tree
// void preorderTraversal(Node*);

// // function for the inorder traversal of the tree
// // so as to store the node values in 'arr' in
// // sorted order
// void inorderTraversal(Node *root, vector<int>& arr)
// {
// 	if (root == NULL)
// 		return;

// 	// first recur on left subtree
// 	inorderTraversal(root->left, arr);

// 	// then copy the data of the node
// 	arr.push_back(root->data);

// 	// now recur for right subtree
// 	inorderTraversal(root->right, arr);
// }

// // function to convert the given BST to MIN HEAP
// // performs preorder traversal of the tree
// void BSTToMinHeap(Node *root, vector<int> arr, int *i)
// {
// 	if (root == NULL)
// 		return;

// 	// first copy data at index 'i' of 'arr' to
// 	// the node
// 	root->data = arr[++*i];

// 	// then recur on left subtree
// 	BSTToMinHeap(root->left, arr, i);

// 	// now recur on right subtree
// 	BSTToMinHeap(root->right, arr, i);
// }

// // utility function to convert the given BST to
// // MIN HEAP
// void convertToMinHeapUtil(Node *root)
// {
// 	// vector to store the data of all the
// 	// nodes of the BST
// 	vector<int> arr;
// 	int i = -1;

// 	// inorder traversal to populate 'arr'
// 	inorderTraversal(root, arr);

// 	// BST to MIN HEAP conversion
// 	BSTToMinHeap(root, arr, &i);
// }

// // function for the preorder traversal of the tree
// void preorderTraversal(Node *root)
// {
// 	if (!root)
// 		return;

// 	// first print the root's data
// 	cout << root->data << " ";

// 	// then recur on left subtree
// 	preorderTraversal(root->left);

// 	// now recur on right subtree
// 	preorderTraversal(root->right);
// }

// // Driver program to test above
// int main()
// {
// 	// BST formation
// 	struct Node *root = getNode(4);
// 	root->left = getNode(2);
// 	root->right = getNode(6);
// 	root->left->left = getNode(1);
// 	root->left->right = getNode(3);
// 	root->right->left = getNode(5);
// 	root->right->right = getNode(7);

// 	convertToMinHeapUtil(root);
// 	cout << "Preorder Traversal:" << endl;
// 	preorderTraversal(root);

// 	return 0;
// }
