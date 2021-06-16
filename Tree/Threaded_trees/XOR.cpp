/*An XOR tree is a tree whose parent node is the XOR of 
the left child and the right child node of the tree. 
Parent node = Left child node ^ Right child node
Approach: 
1)Since it’s a perfect binary tree, there are a total 
of 2^h-1 nodes, where h is the height of the XOR tree.

2)Since leaf nodes of a perfect binary tree are given,
the root node is built by first building the left and
right subtrees recursively.

3)Every node in the left and right subtrees is formed by
performing the XOR operation on their children.
*/
#include<bits/stdc++.h>
using namespace std;

int  maxsize=100005;//max number of nodes
vector<int>xor_tree(maxsize);//creating a tree with size=maxsize
// A recursive function that constructs xor tree
// for vector array[start.....end].
// x is index of current node in XOR tree
void construct_Xor_Tree_Util(vector<int>current,int start,int end,int x)
{
    //x is the index of the node to be inserted

    // If there is one element in vector array, store it
    // in current node of XOR tree
    if(start==end)
    {
        xor_tree[x]=current[start];
        return;
    }
    int left=x*2 +1;
    int right=x*2 +2;
    int mid=(start+end)/2;
    //building left and right subtree recursively
    construct_Xor_Tree_Util(current,start,mid,left);//left tree
    construct_Xor_Tree_Util(current,mid+1,end,right);//right subtree
    //merging left and right subtree
    xor_tree[x]=(xor_tree[left]^xor_tree[right]);

}
void contruct_Xor_tree(vector<int>arr,int n)
{
    construct_Xor_Tree_Util(arr,0,n-1,0);
}
int main()
{
    // leaf nodes  of Perfect Binary Tree
    vector<int> leaf_nodes = { 40, 32, 12, 1, 4, 3, 2, 7 };
 
    int n = leaf_nodes.size();
 
    // Build the xor tree
    contruct_Xor_tree(leaf_nodes, n);

    //1)height of xor tree
    int x=(int)ceil(log2(n));

    //2)Max size of xor tree
    int max_size = 2 * (int)pow(2, x) - 1;
    cout<<"The  height of the generated tree is: "<<x<<endl;
    cout<<"The max size of the generated tree is: "<<max_size<<endl;

    cout << "Nodes of the XOR Tree:\n";
    for (int i = 0; i < max_size; i++) {
        cout << xor_tree[i] << " ";
    }
 
    // Root node is at index 0 considering
    // 0-based indexing in XOR Tree
    int root = 0;
 
    // print value at root node
    cout << "\nRoot: " << xor_tree[root];
    return 0;
}
