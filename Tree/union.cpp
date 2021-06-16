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
void megred_list(vector<int>v1,vector<int>v2,vector<int>&megred_list)
{
  int m=v1.size();
  int n=v2.size();
  int i=0,j=0,k=0;
  cout<<megred_list.size()<<endl<<m<<endl<<n<<endl;
  while(i<m && j<n)
  {
      if(v1[i]<v2[j])
      {
          cout<<"The element stored at "<<k<<"th "<<"position is "<<v1[i]<<endl;
          megred_list.push_back(v1[i++]);
          cout<<megred_list[0];
      }
      else if(v1[i]>v2[j]){
          cout<<"The element stored at "<<k<<"th "<<"position is"<<v2[j]<<endl;
          megred_list.push_back(v2[j++]);
      }
      k++;
  }
  while(i<m)
  {
      megred_list.push_back(v1[i++]);
  }
  while(j<n)
  {
      megred_list.push_back(v2[j++]);
  }
  cout<<"\n this is the merged vector \n";
  for(auto it=megred_list.begin();it!=megred_list.end();it++)
  {
      cout<<*it<<"\t";
  }
  cout<<endl;
 }
Node *sorted_array_to_BST(vector<int>arr,int start,int end)
{
    if(start>end)
    return NULL;
    int mid=(start+end)/2;
    Node *root=get_newNode(arr[mid]);
    root->left=sorted_array_to_BST(arr,start,mid-1);
    root->right=sorted_array_to_BST(arr,mid+1,end);
    return root;
}

void store_inorder(Node *root,vector<int>&v)
{
    if(root==NULL)
    return;
    store_inorder(root->left,v);
    v.push_back(root->data);
    store_inorder(root->right,v);
}
void print_inorder(Node *root)
{
    if(root==NULL)
    return;
    print_inorder(root->left);
    cout<<root->data<<"\t";
    print_inorder(root->right);
}

Node *mergedTree(Node *root1,Node *root2)
{
     vector<int>v1;
     vector<int>v2;
     vector<int>merged_list;
     store_inorder(root1,v1);
     store_inorder(root2,v2);
     cout<<"\n this is the first sorted array \n";
     int m=v1.size();
     int n=v2.size();
     cout<<m<<endl;
     cout<<n<<endl;
     megred_list(v1,v2,merged_list);
    
     
     return sorted_array_to_BST(merged_list,0,m+n-1);

}
int main()
{
	/* Create following tree as first balanced BST
		100
		/ \
		50 300
	/ \
	20 70
	*/
	Node *root1 = get_newNode(100);
	root1->left	 = get_newNode(50);
	root1->right = get_newNode(300);
	root1->left->left = get_newNode(20);
	root1->left->right = get_newNode(70);

	/* Create following tree as second balanced BST
			80
		/ \
		40 120
	*/
	Node *root2 = get_newNode(80);
	root2->left	 = get_newNode(40);
	root2->right = get_newNode(120);

	Node *mergedTree_root = mergedTree(root1, root2);

	cout << "Following is Inorder traversal of the merged tree \n";
	print_inorder(mergedTree_root);

	return 0;
}
