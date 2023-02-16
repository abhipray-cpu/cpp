#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    int stage;
    vector<pair<Node *, int>> connections; // this will be a vector of Node and cost edge connection
};
class multiStage

{
public:
    int maxStage = 0;
    Node *source = NULL;
    Node *destination = NULL;
    map<Node *, pair<Node *, int>> path; // will use this map to find the min cost path
    map<int, vector<Node *>> stageNodes; // this will contain all the info about the stage and nodes belonging to that stage
    void generateTree();                 // this function will generate the tree
    Node *getNewNode(int data, int stage);
    void findMinPath(); // this function will find the min path
    void showMinPath(); // this funnction will give tha actual min path
};
void multiStage::showMinPath()
{
    auto start = source;
    auto end = destination;
    cout << "This is the total cost of the path: " << path[source].second << endl;
    while (start != end)
    {
        cout << start->data << "-->";
        start = path[start].first;
    }
}
// is function ki maa ka bhosda
void multiStage::findMinPath()
{
    for (int i = maxStage; i >= 1; i--)
    {
        auto nodes = stageNodes[i];
        for (auto node : nodes)
        {
            if (node->connections.size() == 0)
            {
                path[node] = make_pair(node, 0);
            }
            // this is the main part of the code
            else
            {
                pair<Node *, int> minConnection;
                Node *minNode = NULL;
                int cost = 0;
                for (auto connection : node->connections)
                {
                    int iter = maxStage - i;
                    int minCost = INT_MAX;
                    int sum = connection.second;
                    auto vertex2 = connection.first;
                    for (int j = 0; j < iter; j++)
                    {
                        sum += path[vertex2].second;
                        vertex2 = path[vertex2].first;
                    }
                    if (sum < minCost)
                    {
                        minCost = sum;
                        minConnection = make_pair(connection.first, sum);
                        minNode = connection.first;
                        cost = minCost;
                    }

                    cout << connection.first->data << "-->" << sum << endl;
                }
                path[node] = make_pair(minNode, cost);
            }
        }
    }
    cout << "This is the result that we got \n";
    for (auto el : path)
    {
        cout << el.first->data << "-->" << el.second.first->data << "," << el.second.second << endl;
    }
}

Node *multiStage::getNewNode(int data, int stage)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->stage = stage;
    // push the new node to the stage and the nodes mapping
    stageNodes[stage].push_back(newNode);
    return newNode;
}
void multiStage::generateTree()
{
    Node *a = getNewNode(2, 2);
    Node *b = getNewNode(3, 2);
    Node *c = getNewNode(4, 2);
    Node *d = getNewNode(5, 2);
    Node *e = getNewNode(6, 3);
    Node *f = getNewNode(7, 3);
    Node *g = getNewNode(8, 3);
    Node *h = getNewNode(9, 4);
    Node *i = getNewNode(10, 4);
    Node *j = getNewNode(11, 4);
    cout << "These are all the nodes we got with their respective stage \n";
    cout << "Stage \t \t Nodes" << endl;
    for (auto it : stageNodes)
    {
        cout << it.first << "\t \t";
        for (auto it1 : it.second)
        {
            cout << it1->data << " ";
        }
        cout << endl;
    }
    cout << "Making the connections.... \n";
    source->connections.push_back(make_pair(a, 9));
    source->connections.push_back(make_pair(b, 7));
    source->connections.push_back(make_pair(c, 3));
    source->connections.push_back(make_pair(d, 2));
    a->connections.push_back(make_pair(e, 4));
    a->connections.push_back(make_pair(f, 2));
    a->connections.push_back(make_pair(g, 1));
    b->connections.push_back(make_pair(e, 2));
    b->connections.push_back(make_pair(f, 7));
    c->connections.push_back(make_pair(g, 11));
    d->connections.push_back(make_pair(f, 11));
    d->connections.push_back(make_pair(g, 8));
    e->connections.push_back(make_pair(h, 6));
    e->connections.push_back(make_pair(i, 5));
    f->connections.push_back(make_pair(h, 4));
    f->connections.push_back(make_pair(i, 3));
    g->connections.push_back(make_pair(j, 6));
    g->connections.push_back(make_pair(i, 5));
    h->connections.push_back(make_pair(destination, 4));
    i->connections.push_back(make_pair(destination, 2));
    j->connections.push_back(make_pair(destination, 5));
    cout << "These are the nodes after making the connnections \n";
    for (auto it : stageNodes)
    {
        cout << it.first << "\t \t";
        for (auto it1 : it.second)
        {
            for (auto it2 : it1->connections)
            {
                cout << it1->data << "->" << it2.first->data << "=" << it2.second << "\n";
            }
        }
    }
}

int main()
{
    multiStage M;
    M.maxStage = 5;
    auto source = M.getNewNode(1, 1);
    auto destination = M.getNewNode(12, 5);
    M.source = source;
    M.destination = destination;
    M.generateTree();
    M.findMinPath();
    cout << "This is the min path that we got \n";
    M.showMinPath();
    return 0;
}