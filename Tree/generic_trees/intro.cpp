//efficient approach is to use the first child and next sibling approach
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *first_child;
    Node *next_sibling;
};

/*advantages of this node structure

Memory efficient – No extra links are required, hence a lot of memory is saved.

Treated as binary trees – Since we are able to convert any generic tree to binary representation, we can treat all generic trees with a first child/next sibling representation as binary trees. Instead of left and right pointers, we just use firstChild and nextSibling.

Many algorithms can be expressed more easily because it is just a binary tree.

Each node is of fixed size no auxiliary array or vector is required.*/