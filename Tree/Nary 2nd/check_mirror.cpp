#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    vector<Node*> children;
};
Node *get_newNode(int data)
{
    Node *newNode=new Node;
    newNode->data=data;
    return newNode;
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
void areMirrors(Node *root1,Node *root2)
{
 /*in this function we have 2 choices
 1)Stack of 1st tree level order left to right adn queue of 2nd tree from right to left
 2)Stack of 1st tree level order right to left and queue of 2nd tree from left to right
 upon comparing the reversed stack and queue we will find that the elements if mirror trees are
 in same order and therfore can find a mirror tree or not
 */
stack<Node*>S;
queue<Node*>Q;
queue<Node*>q1,q2;//one for level order of 1st tree and second for level order of another
q1.push(root1);
q2.push(root2);
while(!q1.empty())//stack left to right
{
   Node *temp1=q1.front();
   S.push(temp1);
   q1.pop();
   int size1=temp1->children.size();
   for(int i=0;i<size1;i++)
   {
       q1.push(temp1->children[i]);
   }
}
while(!q2.empty())//queue right to left
{
Node *temp2=q2.front();
Q.push(temp2);
q2.pop();
int size2=temp2->children.size();
for(int i=size2-1;i>=0;i--)
{
    q2.push(temp2->children[i]);
}
}
//now we will simplt reverse the stack and then check the elements of both containers one by one if they mathch we will return true else false
stack<Node*>Stack_rev;
while(!S.empty())
{
    Node *dummy=S.top();
    S.pop();
    Stack_rev.push(dummy);
}
//now we will simply compare the nodes
cout<<"This is the values of first tree"<<endl;
while(!Stack_rev.empty())
{
    cout<<Stack_rev.top()->data<<" ";
    Stack_rev.pop();
}
cout<<"\n These are the values of second tree"<<endl;
while(!Q.empty())
{
    cout<<Q.front()->data<<" ";
    Q.pop();
}
//run a simple for loop and check for values one by one and return value accordinlgy
}
int leaf_count(Node *root)
{
    queue<Node*>q;
    q.push(root);
    int leaf_count=0;
    while(!q.empty())
{
    Node *temp=q.front();
    q.pop();
    if(temp->children.size()==0)
    leaf_count++;
    for(int i=0;i<temp->children.size();i++)
    {
        q.push(temp->children[i]);
    }
    }
    return leaf_count;
}
int main()
{
    Node *root1=get_newNode(1);
    Node *root2=get_newNode(1);
    root1->children.push_back(get_newNode(2));
    root1->children.push_back(get_newNode(3));
    root1->children.push_back(get_newNode(4));
    root1->children[0]->children.push_back(get_newNode(5));
    root1->children[0]->children.push_back(get_newNode(6));
    root1->children[0]->children.push_back(get_newNode(7));
    root1->children[0]->children.push_back(get_newNode(8));
    root1->children[1]->children.push_back(get_newNode(9));
    root1->children[1]->children.push_back(get_newNode(10));
    root1->children[1]->children.push_back(get_newNode(11));
    root1->children[1]->children.push_back(get_newNode(12));
    root1->children[2]->children.push_back(get_newNode(13));
    root1->children[2]->children.push_back(get_newNode(14));
    root1->children[2]->children.push_back(get_newNode(15));
    root1->children[2]->children.push_back(get_newNode(16));
    root2->children.push_back(get_newNode(4));
    root2->children.push_back(get_newNode(3));
    root2->children.push_back(get_newNode(2));
    root2->children[0]->children.push_back(get_newNode(16));
    root2->children[0]->children.push_back(get_newNode(15));
    root2->children[0]->children.push_back(get_newNode(14));
    root2->children[0]->children.push_back(get_newNode(13));
    root2->children[1]->children.push_back(get_newNode(12));
    root2->children[1]->children.push_back(get_newNode(11));
    root2->children[1]->children.push_back(get_newNode(10));
    root2->children[1]->children.push_back(get_newNode(9));
    root2->children[2]->children.push_back(get_newNode(8));
    root2->children[2]->children.push_back(get_newNode(7));
    root2->children[2]->children.push_back(get_newNode(6));
    root2->children[2]->children.push_back(get_newNode(5));
    cout<<"This is our first tree: "<<endl;
    print_level_wise(root1);
    cout<<endl;
    cout<<"This is our second tree: "<<endl;
    print_level_wise(root2);
    cout<<"\n The Number of leaf nodes in given nary tree is: "<<leaf_count(root1)<<endl;
    cout<<"\n The Number of leaf nodes in given nary tree is: "<<leaf_count(root2)<<endl;
    areMirrors(root1,root2);
    return 0;
}