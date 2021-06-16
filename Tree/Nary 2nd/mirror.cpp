#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    vector<Node*>children;
};
Node *get_newNode(int data)
{
    Node *newNode=new Node;
    newNode->data=data;
    return newNode;
}

void mirror(Node *root)
{
    if(root==NULL)
    return;
    int n=root->children.size();
    if(n<2)//no need to mirror of the number of children<1
    return;
    for(int i=0;i<n;i++)
    mirror(root->children[i]);
    reverse(root->children.begin(),root->children.end());//we are basically reversing the vector storing the chiildren nodes
//we are reversing at the lowest level first

}
int max_depth(Node *root)
{
    if (root == NULL) {
      return 0;
   }
   int maxDepth = 1;
   for (vector<Node*>::iterator it = root->children.begin(); it != root->children.end(); it++) {
      maxDepth = max(maxDepth, max_depth(*it));
   }
   return maxDepth + 1;
}
void print_level_wise(Node *root)
{
      if(root==NULL)
      return;
      queue<Node*>q;
      q.push(root);
      while(!q.empty())
      {
          int n=q.size();
          while(n>0)
          {
               Node *temp=q.front();
               q.pop();
               cout<<temp->data<<" ";
               for(int i=0;i<temp->children.size();i++)
               {
                   q.push(temp->children[i]);
               }
               n--;
          }
          cout<<endl;
      }
}
int main()
{
    Node *root=get_newNode(1);
    root->children.push_back(get_newNode(2));
    root->children.push_back(get_newNode(3));
    root->children.push_back(get_newNode(4));
    root->children.push_back(get_newNode(5));
    root->children[0]->children.push_back(get_newNode(6));
    root->children[0]->children.push_back(get_newNode(7));
    root->children[0]->children.push_back(get_newNode(8));
    root->children[1]->children.push_back(get_newNode(9));
    root->children[1]->children.push_back(get_newNode(17));
    root->children[1]->children.push_back(get_newNode(18));
    root->children[2]->children.push_back(get_newNode(26));
    root->children[2]->children.push_back(get_newNode(27));
    root->children[2]->children.push_back(get_newNode(28));
    root->children[3]->children.push_back(get_newNode(36));
    root->children[3]->children.push_back(get_newNode(37));
    root->children[3]->children.push_back(get_newNode(48));
    root->children[3]->children.push_back(get_newNode(46));
    root->children[3]->children.push_back(get_newNode(17));
    root->children[3]->children.push_back(get_newNode(98));
    print_level_wise(root);
    mirror(root);
    print_level_wise(root);
    cout<<" \n The max depthh fo the given nary tree is "<<max_depth(root)<<endl;
    return 0;
}