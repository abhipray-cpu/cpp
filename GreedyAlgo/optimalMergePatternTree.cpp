
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    vector<int> lst;
    int size;
    Node *left, *right;
};
class OptimalSearchPattern
{
public:
    // using a priority queue to manage the list based on their size
    // this will create a priority queue of the list in the descending order of size
    Node *root;
    Node *getNewnode(vector<int> lst);
    void initializeNode();
    map<Node *, string> weights;
    priority_queue<Node *> nodeQueue;
    priority_queue<pair<vector<int>, int>> pq;
    void generateData();
    void optimalMerge();
    vector<int> merge(vector<int> lst1, vector<int> lst2); // this function will merge two lists and will return the merged list
    void construct_tree();                                 // this function will construct the optimal merge pattern tree
    void displayTree(Node *root);
    void getNumberOfMerges();
    void giveWeights(Node *root); // this function will asssign weights to the node connections based on the p
    void getPath(Node *root, Node *leaf);
    void getWeights(); // this function will give weight to the node
};
void OptimalSearchPattern::getWeights()
{
    // bc dekhlo baki how to generate the  tree mei nhi kar rha hu ab
}
void OptimalSearchPattern::getPath(Node *root, Node *leaf)
{
}
void OptimalSearchPattern::giveWeights(Node *root)
{
    // doing an inorder traversal and then assigning weights to the node connections
    if (root == NULL)
        return;
    // this will be an inorder traversal of the tree
    giveWeights(root->left);
    // in case of Huffman coding this will be 0 and 1 for left and right

    giveWeights(root->right);
}
void OptimalSearchPattern::generateData()
{
    auto P1 = make_pair(vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10);
    auto P2 = make_pair(vector<int>{11, 12, 13, 14, 15, 16, 17, 18, 19}, 9);
    auto P3 = make_pair(vector<int>{21, 22, 23, 24, 25, 26, 27, 28}, 8);
    auto P4 = make_pair(vector<int>{31, 32, 33, 34, 35, 36, 37}, 7);
    auto P5 = make_pair(vector<int>{41, 42, 43, 44, 45, 46}, 6);
    auto P6 = make_pair(vector<int>{51, 52, 53, 54, 55}, 5);
    auto P7 = make_pair(vector<int>{61, 62, 63, 64}, 4);
    auto P8 = make_pair(vector<int>{71, 72, 73}, 3);
    auto P9 = make_pair(vector<int>{81, 82}, 2);
    auto P10 = make_pair(vector<int>{91}, 1);
    pq.push(P1);
    pq.push(P2);
    pq.push(P3);
    pq.push(P4);
    pq.push(P5);
    pq.push(P6);
    pq.push(P7);
    pq.push(P8);
    pq.push(P9);
    pq.push(P10);
}
vector<int> OptimalSearchPattern::merge(vector<int> lst1, vector<int> lst2)
{
    vector<int> lst;
    int i = 0, j = 0;
    while (i < lst1.size() && j < lst2.size())
    {
        if (lst1[i] < lst2[j])
        {
            lst.push_back(lst1[i]);
            i++;
        }
        else
        {
            lst.push_back(lst2[j]);
            j++;
        }
    }
    while (i < lst1.size())
    {
        lst.push_back(lst1[i]);
        i++;
    }
    while (j < lst2.size())
    {
        lst.push_back(lst2[j]);
        j++;
    }
    return lst;
}

void OptimalSearchPattern::optimalMerge()
{
    while (pq.size() > 1)
    {
        auto P1 = pq.top().first;
        pq.pop();
        auto P2 = pq.top().first;
        pq.pop();
        auto newLst = merge(P1, P2);
        pq.push(make_pair(newLst, newLst.size()));
    }
    cout << "This is the final merged list \n";
    auto finalLst = pq.top().first;
    int size = pq.top().second;
    cout << "This is the size of the fina list: " << size << endl;
    for (auto i : finalLst)
    {
        cout << i << "-->";
    }
}
Node *OptimalSearchPattern::getNewnode(vector<int> lst)
{
    Node *newNode = new Node;
    newNode->lst = lst;
    newNode->size = lst.size();
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void OptimalSearchPattern::initializeNode()
{
    auto P1 = make_pair(vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10);
    auto P2 = make_pair(vector<int>{11, 12, 13, 14, 15, 16, 17, 18, 19}, 9);
    auto P3 = make_pair(vector<int>{21, 22, 23, 24, 25, 26, 27, 28}, 8);
    auto P4 = make_pair(vector<int>{31, 32, 33, 34, 35, 36, 37}, 7);
    auto P5 = make_pair(vector<int>{41, 42, 43, 44, 45, 46}, 6);
    auto P6 = make_pair(vector<int>{51, 52, 53, 54, 55}, 5);
    auto P7 = make_pair(vector<int>{61, 62, 63, 64}, 4);
    auto P8 = make_pair(vector<int>{71, 72, 73}, 3);
    auto P9 = make_pair(vector<int>{81, 82}, 2);
    auto P10 = make_pair(vector<int>{91}, 1);

    auto Node1 = getNewnode(P1.first);
    auto Node2 = getNewnode(P2.first);
    auto Node3 = getNewnode(P3.first);
    auto Node4 = getNewnode(P4.first);
    auto Node5 = getNewnode(P5.first);
    auto Node6 = getNewnode(P6.first);
    auto Node7 = getNewnode(P7.first);
    auto Node8 = getNewnode(P8.first);
    auto Node9 = getNewnode(P9.first);
    auto Node10 = getNewnode(P10.first);
    nodeQueue.push(Node1);
    nodeQueue.push(Node2);
    nodeQueue.push(Node3);
    nodeQueue.push(Node4);
    nodeQueue.push(Node5);
    nodeQueue.push(Node6);
    nodeQueue.push(Node7);
    nodeQueue.push(Node8);
    nodeQueue.push(Node9);
    nodeQueue.push(Node10);
}
void OptimalSearchPattern::construct_tree()
{
    while (nodeQueue.size() > 1)
    {

        auto node1 = nodeQueue.top();
        nodeQueue.pop();
        auto node2 = nodeQueue.top();
        nodeQueue.pop();

        auto newLst = merge(node1->lst, node2->lst);
        auto newNode = getNewnode(newLst);
        newNode->left = node1;
        newNode->right = node2;
        root = newNode;
        nodeQueue.push(newNode);
    }
}

void OptimalSearchPattern::displayTree(Node *root)
{
    if (root == NULL)
        return;
    // this will be an inorder traversal of the tree
    displayTree(root->left);
    cout << root->size << "-->";
    displayTree(root->right);
}

int main()
{
    OptimalSearchPattern obj;
    // obj.generateData();
    obj.initializeNode();
    // obj.optimalMerge();
    obj.root = obj.nodeQueue.top();
    obj.construct_tree();
    cout << "This is the generated tree \n";
    obj.displayTree(obj.root);
    return 0;
}