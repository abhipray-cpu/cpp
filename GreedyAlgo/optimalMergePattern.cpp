#include <bits/stdc++.h>
using namespace std;

class OptimalSearchPattern
{
public:
    // using a priority queue to manage the list based on their size
    // this will create a priority queue of the list in the descending order of size
    priority_queue<pair<vector<int>, int>> pq;
    void generateData();
    void optimalMerge();
    vector<int> merge(vector<int> lst1, vector<int> lst2); // this function will merge two lists and will return the merged list
};

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
int main()
{
    OptimalSearchPattern obj;
    obj.generateData();
    obj.optimalMerge();
    return 0;
}