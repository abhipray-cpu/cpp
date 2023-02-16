#include <bits/stdc++.h>
using namespace std;
struct Node
{
    char ch;
    int freq;
    Node *left, *right;
    int leftWeight, rightWeight;
    // this function is required to create  the priority queue
};

class huffmanCoding
{
public:
    string Pattern;
    // this will be used to construct the tree
    map<char, int> UniqueChars;
    vector<Node *> nodeList;
    map<char, string> codes; // this will be the final map that will be used for encoding the string
    void getUnique();        // this function will give all the unique characters in the string
    Node *getnewNode(char ch, int freq);
    void sort(); // will sort the map based on the frequency
                 // and will be using a priority queue for this purpose
    void sortList();
    void formTree();
    void inorderTraversal(Node *root); // this function will perform the inorder traversal of the given tree
    void assignWeights(Node *root);    // this function will assign the weihts to the node connections
    // performing a binary search and keeping the record of left and right paths for each left add 0 to string
    // and for each right encountered add a 1
    void assignCode(Node *root, char ch, string code);
    void getCodes(Node *root); // this will be an iterative function that will call the above function for all the characters
    string encodeString();     // this function will encode teh string based on the generated encouding string
};
string huffmanCoding::encodeString()
{
    string encode = "";
    for (char ch : Pattern)
    {
        encode += codes[ch];
    }
    return encode;
}
void huffmanCoding::getCodes(Node *root)
{
    for (auto i : UniqueChars)
    {

        assignCode(root, i.first, "");
    }
}
void huffmanCoding::assignCode(Node *root, char ch, string code)
{
    if (root != NULL)
    {
        if (root->ch == ch)
        {
            codes[ch] = code;
        }
        assignCode(root->right, ch, code + "1");

        assignCode(root->left, ch, code + "0");
    }
    else
        return;
}
void huffmanCoding::assignWeights(Node *root)
{
    if (root == NULL)
        return;
    assignWeights(root->left);
    root->leftWeight = 0;
    root->rightWeight = 1;
    assignWeights(root->right);
}
void huffmanCoding::inorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    cout << root->ch << "=>" << root->freq << "\t";
    inorderTraversal(root->right);
}
Node *huffmanCoding::getnewNode(char ch, int freq)
{
    Node *newNode = new Node;
    newNode->ch = ch;
    newNode->freq = freq;
    newNode->left = newNode->right = NULL;
    return newNode;
}
void huffmanCoding::getUnique()
{
    for (auto ch : Pattern)
    { // if the character is not present
        if (UniqueChars.find(ch) == UniqueChars.end())
        {
            UniqueChars[ch] = 1;
        }
        // if the character is present
        else
        {
            UniqueChars[ch]++;
        }
    }
    // cout << "This is the frequency of the characters in the string\n";
    // for (auto i : UniqueChars)
    // {
    //     cout << i.first << " " << i.second << endl;
    // }
}
void huffmanCoding::sort()
{
    // creating the nodes for all the key:value pairs
    for (auto i : UniqueChars)
    {
        Node *newNode = getnewNode(i.first, i.second);
        nodeList.push_back(newNode);
    }
    // sorting the list based on the frequenct
    for (int i = 0; i < nodeList.size(); i++)
    {
        for (int j = i + 1; j < nodeList.size(); j++)
        {
            if (nodeList[i]->freq > nodeList[j]->freq)
            {
                Node *temp = nodeList[i];
                nodeList[i] = nodeList[j];
                nodeList[j] = temp;
            }
        }
    }
    // cout << "This is the sorted list \n";
    // for (auto el : nodeList)
    // {
    //     cout << el->ch << " " << el->freq << endl;
    // }
}
void huffmanCoding::sortList()
{
    for (int i = 0; i < nodeList.size(); i++)
    {
        for (int j = i + 1; j < nodeList.size(); j++)
        {
            if (nodeList[i]->freq > nodeList[j]->freq)
            {
                Node *temp = nodeList[i];
                nodeList[i] = nodeList[j];
                nodeList[j] = temp;
            }
        }
    }
}
// this will be used to sort the list
// since priority queue is not working will be sorting Nodelist after every newNode foramtion
void huffmanCoding::formTree()
{
    while (nodeList.size() > 1)
    {
        // cout << "This is the curr state of list: \n";
        // for (auto i : nodeList)
        //     cout << i->freq << "\t";
        // cout << endl;

        auto node1 = nodeList[0];
        auto node2 = nodeList[1];
        auto newNode = getnewNode('\0', node1->freq + node2->freq);
        nodeList.erase(nodeList.begin() + 0);
        nodeList.erase(nodeList.begin() + 0);
        newNode->right = node1;
        newNode->left = node2;
        nodeList.push_back(newNode);
        sortList();
        // cout << "This is the list after removing the nodes \n";
        // for (auto j : nodeList)
        //     cout << j->freq << "\t";
        // cout << endl;
    }
}
int main()
{
    huffmanCoding hf;
    hf.Pattern = "abshdaabbsdwass";
    // cout << "This is the original string that needs to be encoded \n";
    // cout << hf.Pattern << endl;
    hf.getUnique();
    hf.sort();
    hf.formTree();
    // cout << "This is the inorder traversal of the tree \n";
    hf.inorderTraversal(hf.nodeList[0]);
    // cout << "Assiginh the weights to the node conncetions \n";
    hf.assignWeights(hf.nodeList[0]);
    // cout << "Getting the codes for each character \n";
    hf.getCodes(hf.nodeList[0]);
    cout << " \n This is the encoding table for this string: \n";
    for (auto i : hf.codes)
    {
        cout << i.first << "=>" << i.second << endl;
    }
    cout << "Generating the huffman encode string: ......\n";
    auto encode = hf.encodeString();
    cout << "This is the orginal string: \n";
    cout << hf.Pattern << endl;
    cout << "This is the hufman encoded string \n";
    cout << encode << endl;
    return 0;
}

/*mopdify this code to use a priority code while forming the optimal merge
tree*/