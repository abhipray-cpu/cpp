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
void inorder(Node *root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->data<<"\t";
    inorder(root->right);
    }

void printTop(Node* root, int dist, int level, map<int,pair<int,int>>&map)
{
    // base case: empty tree
    if (root == nullptr) {
        return;
    }
 
    // if the current level is less than the maximum level seen so far
    // for the same horizontal distance, or if the horizontal distance
    // is seen for the first time, update the map
    if (map.find(dist) == map.end() || level < map[dist].second)
    {
        // update value and level for current distance
        map[dist] = { root->data, level };
    }
 
    // recur for the left subtree by decreasing horizontal distance and
    // increasing level by 1
    printTop(root->left, dist - 1, level + 1, map);
 
    // recur for the right subtree by increasing both level and
    // horizontal distance by 1
    printTop(root->right, dist + 1, level + 1, map);
}
 
// Function to print the top view of a given binary tree
void printTop(Node* root)
{
    // create an empty map where
    // `key` —> relative horizontal distance of the node from the root node, and
    // `value` —> pair containing the node's value and its level
    map<int, pair<int, int>> map;
 
    // perform preorder traversal on the tree and fill the map
    printTop(root, 0, 0, map);
 
    // traverse the map and print the top view
    cout<<"Node \t Level \n";
    for (auto it: map) {
        cout << it.second.first << "\t"<<it.second.second<<endl;
    }
}
int main()
{
    Node *root=NULL;
    root=insert(root,50000);
    vector<int>v1,v2;
    for(int i=0;i<50000;i++)
{
    v1.push_back(i);
}
for(int i=50001;i<100000;i++)
{
    v2.push_back(i);
}
    auto rng=default_random_engine{};
    shuffle(v1.begin(),v1.end(),rng);
    shuffle(v2.begin(),v2.end(),rng);
    while(!v1.empty())
    {
        insert(root,v1.back());
        v1.pop_back();
    }
    while(!v2.empty())
    {
        insert(root,v2.back());
        v2.pop_back();
    }
    inorder(root);

cout<<";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
      ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;"
      ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; \n";
      cout<<"This is the top viewd of the given binary tree \n";
      printTop(root);
      return 0;

return 0;
}