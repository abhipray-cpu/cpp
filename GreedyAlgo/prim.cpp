#include <bits/stdc++.h>
using namespace std;

class Algorithm
{
public:
    vector<pair<pair<int, int>, int>> Edges;
    vector<pair<pair<int, int>, int>> MST;
    map<int, bool> Vertices;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> Q;
    void generateData();
};

void Algorithm::generateData()
{
    Edges[0] = make_pair(make_pair(1, 2), 28);
    Edges[1] = make_pair(make_pair(2, 3), 16);
    Edges[2] = make_pair(make_pair(3, 4), 12);
    Edges[3] = make_pair(make_pair(4, 5), 22);
    Edges[4] = make_pair(make_pair(5, 6), 25);
    Edges[5] = make_pair(make_pair(6, 7), 24);
    Edges[6] = make_pair(make_pair(7, 2), 14);
    Edges[7] = make_pair(make_pair(7, 4), 18);
    Edges[8] = make_pair(make_pair(1, 6), 10);

    cout << "This is the graph \n";
    for (pair<pair<int, int>, int> i : Edges)
    {
        cout << "(" << i.first.first << "->" << i.first.second << ")"
             << "\t" << i.second << "\n";
    }
}
int main()
{
    Algorithm A;
    A.generateData();
    return 0;
}