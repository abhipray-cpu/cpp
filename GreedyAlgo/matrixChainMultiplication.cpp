// we need to find the optimal order of multiplication of matrices to get the maximum result with min number of multiplicaitons
#include <bits/stdc++.h>
using namespace std;
typedef map<pair<int, int>, int> Map;
class optimalMultiplication
{
public:
    int matrixCount;
    vector<pair<int, int>> dimensions; // this will store the dimensions of the matrix

    Map cost;
    Map order;
    map<int, Map> Matrices;
    int factorial(int num);
    int nCr(int n, int r);
    vector<pair<int, int>> getPairs(int diff); // this will give pairs based on the diff value we are currentyle working on
    void initializeMat();                      // this function will fill 0 for all the diagonal matrix
    void getData();                            // this will fill the remainig cells
    pair<int, int> getValues(int i, int j);    // this function will give value first being the cost and second being the order
    vector<int> getMultiplicationSequence();   // this function will generate a sequence from the data generated above
    void multiplyMats();                       // this function will perform an efficient matrix multiplication.
};
void optimalMultiplication::multiplyMats()
{
    // dekhlo koi logic ab bc mera dimaag kharab ho rha hai.
}
vector<int> optimalMultiplication::getMultiplicationSequence()
{
    // we only need row1 of the order matrix for this purpose.
    vector<int> sequence;
    for (int i = matrixCount; i > 1; i--)
    {
        sequence.push_back(order[make_pair(1, i)]);
    }
    // what we can do this multiply the mat with same order first and then for the new mats we can multiply them based on the ascending order
}
void optimalMultiplication::initializeMat()
{
    // fill all the diagonal elements as 0 for the cost matrix
    for (int i = 1; i <= matrixCount; i++)
    {
        cost[make_pair(i, i)] = 0;
    }
}
void optimalMultiplication::getData()
{
    for (int i = 1; i <= matrixCount; i++)
    {
        auto res = getPairs(i);
        // the table is filled in this fashion
        for (auto val : res)
        {
            auto result = getValues(val.first, val.second);
            cost[make_pair(val.first, val.second)] = result.first;
            order[make_pair(val.first, val.second)] = result.second;
        }
    }
}
pair<int, int> optimalMultiplication::getValues(int i, int j)
{
    int minCost = INT_MAX;
    int minOrder;
    for (int k = i; k < j; k++)
    {
        int currCost = cost[make_pair(i, k)] + cost[make_pair(k + 1, j)] + dimensions[i - 1].first * dimensions[k].first * dimensions[j].second;
        if (currCost < minCost)
        {
            minCost = currCost;
            minOrder = k;
        }
    }
    return make_pair(minCost, minOrder);
}
vector<pair<int, int>> optimalMultiplication::getPairs(int diff)
{
    vector<pair<int, int>> result;
    for (int i = 0; i <= matrixCount; i++)
    {
        if (i <= matrixCount && i + diff <= matrixCount)
        {
            auto el = make_pair(i, i + diff);
            result.push_back(el);
        }
    }
    return result;
}
int optimalMultiplication::factorial(int n)
{
    int factorial = 1;
    for (int i = 2; i <= n; i++)
        factorial = factorial * i;
    return factorial;
}

int optimalMultiplication::nCr(int n, int r)
{
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int main()
{
    optimalMultiplication obj;
    cout << "Enter the number of matrices:";
    cin >> obj.matrixCount;
    cout << endl;
    for (int i = 1; i <= obj.matrixCount; i++)
    {
        cout << "Enter the dimensions of matrix " << i << ":";
        int r, c;
        cin >> r >> c;
        obj.dimensions.push_back(make_pair(r, c));
        cout << endl;
        Map newMap;
        for (int j = 0; j < r; j++)
        {
            for (int k = 0; k < c; k++)
            {
                cout << "Enter the value of matrix " << j << " " << k << ":";
                int val;
                cin >> val;
                newMap[make_pair(j, k)] = val;
            }
        }
        obj.Matrices[i] = newMap;
    }
    cout << "These are the possible combinations that we can get \n"
         << obj.nCr(2 * (obj.matrixCount - 1), obj.matrixCount - 1) / obj.matrixCount << endl;
    return 0;
}