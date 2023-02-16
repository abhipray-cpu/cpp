#include <bits/stdc++.h>
using namespace std;

class knapSack
{
public:
    vector<int> Profit;
    vector<int> Weight;
    int capacity;            // this is the max capaciy of the sack
    int n;                   // this is the number of elements
    map<int, bool> finalSet; // this will contain the info whether the item was selected or not
    vector<vector<int>> Mat; // this is the matric that we need to fill
    void getData();          // this will takje user ip as data
    void fillData();         // this will fill data after initial steps
    void getSelection();     // this will give the final selected values
};
void knapSack::getData()
{
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the capacity of the sack: ";
    cin >> capacity;
    cout << "Enter the profit and weight of the elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        int profit, weight;
        cin >> profit >> weight;
        Profit.push_back(profit);
        Weight.push_back(weight);
    }
    // resizing the vectors so that we can later allocate the values to the vectors using inidices
    Mat.resize(n + 1);
    for (int i = 0; i < n + 1; i++)
    {
        Mat[i].resize(capacity + 1);
    }
    // cout << "This is the data that you entered \n";
    // cout << "NUmber of elements: " << n << endl;
    // cout << "Capacity of the sack: " << capacity << endl;
    // cout << "Weights: \n";
    // for (auto w : Weight)
    //     cout << w << "\t";
    // cout << endl;
    // cout << "Profit: \n";
    // for (auto p : Profit)
    //     cout << p << "\t";
    // cout << endl;
    // cout << "The data is collected now filling the matrix.... \n";
}

void knapSack::fillData()
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            if (i == 0 || j == 0)
            {
                Mat[i][j] = 0;
            }
            else if (Weight[i] <= j)
            {
                Mat[i][j] = max(Profit[i] + Mat[i - 1][j - Weight[i]], Mat[i - 1][j]);
            }
            else
            {
                Mat[i][j] = Mat[i - 1][j];
            }
            cout << "i: " << i << " j: " << j << endl;
        }
    }

    cout << "Thi is the generated matrix \n";
    for (auto row : Mat)
    {
        for (auto col : row)
        {
            cout << col << "\t";
        }
        cout << endl;
    }
}

void knapSack::getSelection()
{
    cout << "This is the optimal cost fotr the given knap sack problem \n";
    cout << Mat[n][capacity] << endl;
    cout << "This is the optimal selction for the given knap sack pronlem \n";
    int i = n, j = capacity;
    while (i > 0 && j > 0)
    {
        if (Mat[i][j] == Mat[i - 1][j])
        {
            finalSet[i] = false;
            i--;
        }
        else
        {
            finalSet[i] = true;
            j = j - Weight[i];
            i--;
        }
    }
    // this is the map iterating through items
    for (auto val : finalSet)
    {
        cout << val.first << "=>" << val.second << endl;
    }
}
int main()
{
    knapSack K;
    K.getData();
    K.fillData();
    K.getSelection();
    return 0;
}