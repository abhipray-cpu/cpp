/*For each node there can be four ways that the max path goes through the node: 
1. Node only 
2. Max path through Left Child + Node 
3. Max path through Right Child + Node 
4. Max path through Left Child + Node + Max path through Right Child
The idea is to keep trace of four paths and pick up the max one in the end.
 An important thing to note is, root of every subtree need to return 
 maximum path sum such that at most one child of root is involved. 
This is needed for parent function call. In below code,
 this sum is stored in ‘max_single’ and returned by the recursive function.
*/
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
void inOrder(Node *root)//left->root->right
{
    if(root==NULL)
    return;
    inOrder(root->left);
    cout<<root->data<<"\t \t";
    inOrder(root->right);
}

int findMaxUtil(Node* root, int &res)
{
    //Base Case
    if (root == NULL)
        return 0;
 
    // l and r store maximum path sum going through left and
    // right child of root respectively
    int l = findMaxUtil(root->left,res);
    int r = findMaxUtil(root->right,res);
 
    // Max path for parent call of root. This path must
    // include at-most one child of root
    int max_single = max(max(l, r) + root->data, root->data);
 
    // Max Top represents the sum when the Node under
    // consideration is the root of the maxsum path and no
    // ancestors of root are there in max sum path
    int max_top = max(max_single, l + r + root->data);
 
    res = max(res, max_top); // Store the Maximum Result.
 
    return max_single;
}
int findMaxSum(Node *root)
{
    // Initialize result
    int res = INT_MIN;
 
    // Compute and return result
    findMaxUtil(root, res);
    return res;
}
int main()
{
    Node *root=NULL;
    root=insert(root,50000);
    vector<int> less,greater;
    for(int i=0;i<50000;i++)
    {
        less.push_back(i);
    }
    for(int j=50001;j<100000;j++)
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
  
    //inOrder(root);
    cout<<";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; \n";
    cout<<search(root,1618)<<endl;
    cout<<findMaxSum(root);
    return 0;

}



//incase the tree contains node with negative values as well
// class solution{
//     int max_path_sum;
//     public int maxPathSum(Node *root)
// {
//     max_path_sum=INT_MIN;
//     pathsum(root);
//     return max_path_sum;
//     }
// public int pathsum(Node *root)
// {
//     if(root==NULL)
//     return 0;
//     int left=max(0,pathsum(root->left));
//     int right=max(0,pathsum(root->right);
//     max_path_sum=max(max_path_sum,left+right+root->data);
//     return max(left,right)+root->data;
// }
// }