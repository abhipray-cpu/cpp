/*
 * bst.cpp
 *
 *  Created on: 07-Apr-2017
 *      Author: sharmila
 */

# include <iostream>
# include <cstdlib>

using namespace std;
/*
 * Node Declaration
 */
struct node
{
    int info; //data
    node *left; // left link
    node *right;
}*root;

/*
 * Class Declaration
 */

class BST
{
    public:
        void insert(node *, node *);
        void inorder(node *);
        void display(node *, int);
        BST()
        {
            root = NULL;
        }
};
/*
 * Main Contains Menu
 */
int main()
{
    int choice, num;
    BST bst;
    node *temp;
    while (1)
    {
        cout<<"-----------------"<<endl;
        cout<<"Operations on BST"<<endl;
        cout<<"-----------------"<<endl;
        cout<<"1.Insert Element "<<endl;
        cout<<"2.Inorder Traversal"<<endl;
        cout<<"3.Display"<<endl;
        cout<<"4.Quit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            temp = new node;
            cout<<"Enter the number to be inserted : ";
            cin>>temp->info;
            bst.insert(root, temp);
            break;
        case 2:
            cout<<"Inorder Traversal of BST:"<<endl;
            bst.inorder(root);
            cout<<endl;
            break;
        case 3:
            cout<<"Display BST:"<<endl;
            bst.display(root,1);
            cout<<endl;
            break;
        case 4:
            exit(1);
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
}

/*
 * Inserting Element into the Tree
 */
void BST::insert(node *tree, node *newnode)//0x56 , 0x72
											//0x106, 0x72
{
    if (root == NULL) //New Tree
    {
        root = new node;
        root->info = newnode->info;
        root->left = NULL;
        root->right = NULL;
        cout<<"Root Node is Added"<<endl;
        return;
    }
    if (tree->info == newnode->info)
    {
        cout<<"Element already in the tree"<<endl;
        return;
    }
    if (tree->info > newnode->info)// True go for Left side7 >3
    													//5 > 3
    {
        if (tree->left != NULL)
        {
            insert(tree->left, newnode);//Pause and call its own
        }
        else // Go for left side if address is NULL
        {
            tree->left = newnode;
            (tree->left)->left = NULL;
            (tree->left)->right = NULL;
            cout<<"Node Added To Left"<<endl;
            return;
        }
    }
    else //Right Side of Tree
    {
        if (tree->right != NULL)
        {
            insert(tree->right, newnode);
        }
        else // Go to right if address is NULL
        {
            tree->right = newnode;
            (tree->right)->left = NULL;
            (tree->right)->right = NULL;
            cout<<"Node Added To Right"<<endl;
            return;
        }
    }
}
/*
 * In Order Traversal
 */
void BST::inorder(node *ptr)
{
    if (root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    if (ptr != NULL)
    {
        inorder(ptr->left);
        cout<<ptr->info<<"  ";
        inorder(ptr->right);
    }
}
/*
 * Display Tree Structure
 */
void BST::display(node *ptr, int level)// 7   // 1
{
    int i;
    if (ptr != NULL)
    {
        display(ptr->right, level+1);
        cout<<endl;
        if (ptr == root)
            cout<<"Root->:  ";
        else
        {
            for (i = 0;i < level;i++)
                cout<<"       ";
        }
        cout<<ptr->info;
        display(ptr->left, level+1);
    }
}

          //8, 6, 10, 5, 12,7, 11