


// //second appraoch is to form an inorder array and find the element  at kth position

// #include<bits/stdc++.h>
// using namespace std;

// struct Node
// {
//     int data;
//     Node *left;
//     Node *right;
// };
// Node *getnewNode(int data)
// {
//     Node *newNode=new Node;
//     newNode->data=data;
//     newNode->left=NULL;
//     newNode->right=NULL;
//     return newNode;
// }

// Node *insert(Node *root,int data)
// {
// if(root==NULL)
// {
//     root=getnewNode(data);
// }
// else if(data <= root->data)
// {
//     root->left=insert(root->left,data);
// }
// else if(data>root->data)
// {
//     root->right=insert(root->right,data);
// }
// return root;
// }
// bool search(Node *root,int data)
// {
//     if(root==NULL)
//     {
//         return false;
//     }
//     else if(root->data==data)
//     {
//         return true;
//     }
//     else if(root->data<data)
//     {
//         return search(root->right,data);
//     }
//     else if(root->data >= data)
//     {
//         return search(root->left,data);
//     }
// }
// void InorderRecursive(Node *root, std::vector<Node*>& nodes)
// {
//     if (root == NULL)
//         return;

//     InorderRecursive(root->left, nodes); //visit left sub-tree

//     std::cout << "Word: " << root->data << "\t";
//     nodes.push_back(root);

//     InorderRecursive(root->right, nodes); //visit right sub-tree
// }

// std::vector<Node*> Inorder(Node *root)
// {
//     std::vector<Node*> nodes;    
//     InorderRecursive(root, nodes);
//     return nodes;
// }
// int main()
// {
//     Node *root=NULL;
//     root=insert(root,10000);
//     vector<int> less,greater;
//     for(int i=0;i<10000;i++)
//     {
//         less.push_back(i);
//     }
//     for(int j=10001;j<20000;j++)
//     {
//         greater.push_back(j);
//     }
//     auto rng = default_random_engine{};
//     shuffle(less.begin(),less.end(), rng);
//     shuffle(greater.begin(),greater.end(), rng);
//     while(!less.empty())
//     {
//         insert(root,less.back());
//         less.pop_back();
//     }
//     while(!greater.empty())
//     {
//         insert(root,greater.back());
//         greater.pop_back();
//     }
//     cout<<";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;";
//     vector<Node*>v=Inorder(root);
//     int position;
//     cout<<"Enter the kth position you want smallest number at :"<<endl;
//     cin>>position;
//     cout<<"The "<<position<<"th smallest element is: "<<v[20000-position]->data<<endl;
//     return 0;

// }

/*;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
INverted inorder*/
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
    InorderRecursive(root->right, nodes); //visit right sub-tree
    std::cout << "Word: " << root->data << "\t";
    nodes.push_back(root);
    InorderRecursive(root->left, nodes); //visit left sub-tree

   
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




