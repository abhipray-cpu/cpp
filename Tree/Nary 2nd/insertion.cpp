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

void inorder(Node *root)
/* The inorder traversal of an N-ary tree is defined as visiting all
 the children except the last then the root and finally the last child recursively. 
*/
{
    if (root == NULL)
        return;
 
    // Total children count
    int total = root->children.size();
    if(total>0)
    {
           // All the children except the last
    for (int i = 0; i < total-1; i++)
    { 
       inorder(root->children[i]);
    }
        
 
    // Print the current node's data
    cout<< root->data << "\t";
 
    // Last child
    inorder(root->children[total-1]);
    }
    else
{
cout<<root->data<<"\t";
    return;
}
     
  
}
void Level_order_traversal(Node *root)
{
    if(root==NULL)
    return;
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        Node *temp=q.front();
        q.pop();
        cout<<temp->data<<"\t";
        int size=temp->children.size();
        for(int i=0;i<size;i++)
        {
             q.push(temp->children[i]);
        }
    }
    cout<<endl;
}
/*Preorder Traversal of an N-ary Tree is similar to the preorder traversal
 of Binary Search Tree or Binary Tree with the only difference that is
 , all the child nodes of a parent are traversed from left to right in a sequence.*/

void preOrderTraversal(struct Node* root){
   stack<Node*> tree;
   tree.push(root);
   while (!tree.empty()) {
      Node* curr = tree.top();
      tree.pop();
      cout<<curr->data<<"\t";
      vector<Node*>::iterator it = curr->children.end();
      while (it != curr->children.begin()) {
         it--;
         tree.push(*it);
      }
   }
}

 vector<int> postOrder_traversal(Node *root)
 {
      vector<int> ans;
    if(root==NULL)
    {
        return ans;
    }
    stack<Node*> st;
    st.push(root);
    while(st.size()!=0)
    {
        Node *ptr;
        ptr=st.top();
        vector<Node*> v=ptr->children;
        if(v.size()==0)
        {
            ans.push_back(ptr->data);
            st.pop();
        }
        int i=v.size()-1;
        while(i>-1)
        {
            st.push(v[i]);
            i--;
        }
        ptr->children={};
    }
    return ans;
}
int maxDepth(Node* root) 
{
     if(root==NULL)
     return 0;
     int max_depth=1;
     for(int i=0;i<root->children.size();i++)
     {
         max_depth=max(max_depth,1+maxDepth(root->children[i]));
         
     }

     return max_depth;


}
 
void mirrorTree(Node * root)
{
    // Base case: Nothing to do if root is NULL
    if (root==NULL)
        return;
  
    // Number of children of root
    int n = root->children.size();

    // If number of child is less than 2 i.e.
    // 0 or 1 we do not need to do anything
    if (n < 2)
        return;
  
    // Calling mirror function for each child
    for (int i=0; i<n; i++)
        mirrorTree(root->children[i]);
  
    // Reverse vector (variable sized array) of child
    // pointers
    reverse(root->children.begin(), root->children.end());
}

int main()
{
    Node *root=get_newNode(1);
    root->children.push_back(get_newNode(2));
    root->children.push_back(get_newNode(3));
    root->children.push_back(get_newNode(4));
    Node *first_child=root->children[0];
    Node *second_child=root->children[1];
    Node *third_child=root->children[2];
    first_child->children.push_back(get_newNode(5));
    first_child->children.push_back(get_newNode(6));
    first_child->children.push_back(get_newNode(7));
    first_child->children.push_back(get_newNode(8));
    second_child->children.push_back(get_newNode(9));
    second_child->children.push_back(get_newNode(10));
    second_child->children.push_back(get_newNode(11));
    second_child->children.push_back(get_newNode(12));
    third_child->children.push_back(get_newNode(13));
     third_child->children.push_back(get_newNode(14));
      third_child->children.push_back(get_newNode(15));
       third_child->children.push_back(get_newNode(16));
       Node *first_1=first_child->children[0];
       Node *first_2=first_child->children[1];
       Node *first_3=first_child->children[2];
       Node *first_4=first_child->children[3];
       Node *second_1=second_child->children[0];
       Node *second_2=second_child->children[1];
       Node *second_3=second_child->children[2];
       Node *second_4=second_child->children[3];
       Node *third_1=third_child->children[0];
       Node *third_2=third_child->children[1];
       Node *third_3=third_child->children[2];
       Node *third_4=third_child->children[3];
       first_1->children.push_back(get_newNode(17));
        first_1->children.push_back(get_newNode(18));
         first_1->children.push_back(get_newNode(19));
          first_1->children.push_back(get_newNode(20));
           first_1->children.push_back(get_newNode(21));
        first_2->children.push_back(get_newNode(22));
        first_2->children.push_back(get_newNode(23));
        first_2->children.push_back(get_newNode(24));
        first_2->children.push_back(get_newNode(25));
        first_2->children.push_back(get_newNode(26));
        first_3->children.push_back(get_newNode(27));
        first_3->children.push_back(get_newNode(28));
        first_3->children.push_back(get_newNode(29));
        first_3->children.push_back(get_newNode(30));
        first_3->children.push_back(get_newNode(31));
        second_1->children.push_back(get_newNode(32));
        second_1->children.push_back(get_newNode(33));
        second_1->children.push_back(get_newNode(34));
        second_1->children.push_back(get_newNode(35));
        second_1->children.push_back(get_newNode(36));
        second_2->children.push_back(get_newNode(37));
        second_2->children.push_back(get_newNode(38));
        second_2->children.push_back(get_newNode(39));
        second_2->children.push_back(get_newNode(40));
        second_2->children.push_back(get_newNode(41));
        second_3->children.push_back(get_newNode(42));
        second_3->children.push_back(get_newNode(43));
        second_3->children.push_back(get_newNode(44));
        second_3->children.push_back(get_newNode(45));
        second_3->children.push_back(get_newNode(46));
        second_4->children.push_back(get_newNode(47));
        second_4->children.push_back(get_newNode(48));
        second_4->children.push_back(get_newNode(49));
        second_4->children.push_back(get_newNode(50));
        second_4->children.push_back(get_newNode(51));
        first_4->children.push_back(get_newNode(52));
        first_4->children.push_back(get_newNode(53));
        first_4->children.push_back(get_newNode(54));
        first_4->children.push_back(get_newNode(55));
        first_4->children.push_back(get_newNode(56));
        third_1->children.push_back(get_newNode(57));
        third_1->children.push_back(get_newNode(58));
        third_1->children.push_back(get_newNode(59));
        third_1->children.push_back(get_newNode(60));
        third_1->children.push_back(get_newNode(61));
        third_2->children.push_back(get_newNode(62));
        third_2->children.push_back(get_newNode(63));
        third_2->children.push_back(get_newNode(64));
        third_2->children.push_back(get_newNode(65));
        third_2->children.push_back(get_newNode(66));
        third_3->children.push_back(get_newNode(67));
        third_3->children.push_back(get_newNode(68));
        third_3->children.push_back(get_newNode(69));
        third_3->children.push_back(get_newNode(70));
        third_3->children.push_back(get_newNode(71));
        third_4->children.push_back(get_newNode(72));
        third_4->children.push_back(get_newNode(73));
        third_4->children.push_back(get_newNode(74));
        third_4->children.push_back(get_newNode(75));
        third_4->children.push_back(get_newNode(76));
        third_4->children.push_back(get_newNode(77));
        third_4->children.push_back(get_newNode(78));
        third_4->children.push_back(get_newNode(79));
        third_4->children.push_back(get_newNode(80));
        cout<<root->data<<endl;
        cout<<first_child->data<<endl;
        cout<<second_child->data<<endl;
        cout<<third_child->data<<endl;
        cout<<first_1->data<<endl;
        cout<<first_2->data<<endl;
        cout<<first_3->data<<endl;
        cout<<first_4->data<<endl;
        cout<<second_1->data<<endl;
        cout<<second_2->data<<endl;
        cout<<second_3->data<<endl;
        cout<<second_4->data<<endl;
        cout<<third_1->data<<endl;
        cout<<third_2->data<<endl;
        cout<<third_3->data<<endl;
        cout<<third_4->data<<endl;

        cout<<"This is the level order traversal of the given nary tree"<<endl;
        Level_order_traversal(root);
        cout<<" \n This is the inorder traversal of the fiven nary tree "<<endl;
        inorder(root);
        cout<<"\n This is the pre order taversal of the given nry tree"<<endl;
        preOrderTraversal(root);
        vector<int> ans;
        ans=postOrder_traversal(root);
        cout<<"\n This is the postorder traversal of the given nary tree "<<endl;
        for(int j=0;j<ans.size();j++)
        {
            cout<<ans[j]<<"\t";
        }

        cout<<endl<<maxDepth(root)<<endl;
        
        return 0;




        
   


}