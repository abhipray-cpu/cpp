// problem statement we are given a set of keys assocaited to a node for which we ar
// are given probablity of sucess and of failure now we need to find the optimal binary search
// tree for the given set of keys

#include <bits/stdc++.h>
using namespace std;
typedef vector<pair<int, int>> pairs;
struct Node
{
    int data;
    Node *left, *right;
};
struct cell
{
    int weight;
    int cost;
    int key;
};
class optimalBinarySearchTree
{
public:
    int cost;
    int nodeCount;
    map<int, Node *> keys;
    vector<int> success;
    vector<int> fail;
    int total; // this will be equal to success+fail to make the probab 1 we will divide the final cost with this value
    vector<int> OptimalSequence;
    map<pair<int, int>, cell> data; // this will be our tabular data
    Node *getNewNode(int data);
    cell *getNewCell(int weight);
    void generateData();
    void fillWeights();                               // this will fil the weight for all the cells
    void fillTable();                                 // this will fill the weight and selected root for the cell
    void getOptimalSequence(int i, int j, int count); // this will find the optimal sequence based on the generated data
    void generateTree();                              // this function will generate the tree
    pairs getPairs(int diff);                         // this function will return the cell numbers based on the required difference we are currently in
    int getWeight(int i, int j);
    pair<int, int> returnData(int i, int j); // this function will return the data and root belonging to the cell.
};
Node *optimalBinarySearchTree::getNewNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
cell *optimalBinarySearchTree::getNewCell(int weight)
{
    cell *newCell = new cell;
    newCell->weight = weight;
    newCell->cost = 0;
    newCell->key = 0;
    return newCell;
}
void optimalBinarySearchTree::generateData()
{
    // generating random data or you can take in user input as well
    nodeCount = 4;
    Node *first = getNewNode(10);
    Node *second = getNewNode(20);
    Node *third = getNewNode(30);
    Node *fourth = getNewNode(40);
    keys[1] = first;
    keys[2] = second;
    keys[3] = third;
    keys[4] = fourth;
    success = {0, 3, 3, 1, 1}; // 0 is added for balancing both the arrays
    fail = {2, 3, 1, 1, 1};
    total = success.size() + fail.size();
}
pairs optimalBinarySearchTree::getPairs(int diff)
{
    pairs result;
    for (int i = 0; i <= nodeCount; i++)
    {
        if (i <= nodeCount && i + diff <= nodeCount)
        {
            auto el = make_pair(i, i + diff);
            result.push_back(el);
        }
    }
    return result;
}
void optimalBinarySearchTree::fillWeights()
{
    // will be filling data in increasing order of difference
    for (int i = 0; i <= nodeCount; i++)
    {
        auto res = getPairs(i); // this will return the cell locations based on the diff
        // need to fill weight for these pairs
        for (auto el : res)
        {
            int weight = getWeight(el.first, el.second);
            cell *newCell = getNewCell(weight);
            auto key = make_pair(el.first, el.second);
            data[key] = *newCell;
        }
    }
    // cout << "This is the data \n";
    // for (auto el : data)
    // {
    //     cout << el.first.first << "," << el.first.second << "=>" << el.second.weight << "\n";
    // }
}

int optimalBinarySearchTree::getWeight(int i, int j)
{

    // if(i==j) we will simply return the failure associated with the value of i
    if (i == j)
        return fail[i];
    else
    {
        auto key = make_pair(i, j - 1);
        if (i == 1 && j == 2)
        {
            cout << data[key].weight << "\n";
            cout << success[i] << "\n";
            cout << fail[i] << "\n";
        }
        return data[key].weight + (success[j] + fail[j]);
    }
}
void optimalBinarySearchTree::fillTable()
{
    for (int i = 0; i <= nodeCount; i++)
    {
        auto res = getPairs(i);
        for (auto val : res)
        {
            auto key = make_pair(val.first, val.second);
            auto value = returnData(val.first, val.second);
            // first value of value will be cost and second will be root key
            data[key].cost = value.first;
            data[key].key = value.second;
        }
    }
    cout << "This is the data \n";
    for (auto el : data)
    {
        cout << el.first.first << "," << el.first.second << "=>" << el.second.weight << "," << el.second.cost << "," << el.second.key << "\n";
    }
}

pair<int, int> optimalBinarySearchTree::returnData(int i, int j)
{
    if (i == j)
    {
        return make_pair(0, 0); // first value is the cost and second is the root key
    }
    else
    {
        int minCost = INT_MAX;
        int minKey;

        for (int k = i + 1; k <= j; k++)
        {
            auto key1 = make_pair(i, k - 1);
            auto key2 = make_pair(k, j);
            int cost = data[key1].cost + data[key2].cost;
            if (cost < minCost)
            {
                minCost = cost;
                minKey = k;
            }
        }
        minCost += data[make_pair(i, j)].weight;
        return make_pair(minCost, minKey);
    }
}
void optimalBinarySearchTree::getOptimalSequence(int i, int j, int count)
{

    if (count <= nodeCount)
    {
        auto start = make_pair(i, j);
        int key = data[start].key;
        cout << "This is the value of k:" << key << "\n";
        if (keys.find(key) != keys.end())
        {
            OptimalSequence.push_back(data[start].key);
            count++;
            getOptimalSequence(i, key - 1, count);
            getOptimalSequence(key, j, count);
        }
        else
            return;
    }
    else
        return;
}

void optimalBinarySearchTree::generateTree()
{
    // the above obtaine sequence is correct now you can
    // form a tree using the keys mapping or simply fuck yourself.
}
int main()
{
    optimalBinarySearchTree Bs;
    Bs.generateData();
    Bs.fillWeights();
    Bs.fillTable();
    Bs.getOptimalSequence(0, Bs.nodeCount, 0);
    cout << "This is the size of optimal sequence " << Bs.OptimalSequence.size();
    cout << "This is the optimal sequence \n";
    for (auto el : Bs.OptimalSequence)
    {
        cout << el << "\t";
    }
    cout << endl;
    // Bs.generateTree();
    return 0;
}
