#include <bits/stdc++.h>
using namespace std;

class KnapSack
{
public:
    map<int, pair<int, int>> Input;
    vector<pair<int, float>> ratio;
    map<int, float> results;
    float weight = 15;
    void getRatio();
    void sort();
    void calculate();
    void generateData();
    float giveProfit();
    float giveWeight();
    void showResults();
};

void KnapSack::generateData()
{
    Input[1] = make_pair(10, 2);
    Input[2] = make_pair(5, 3);
    Input[3] = make_pair(15, 5);
    Input[4] = make_pair(7, 7);
    Input[5] = make_pair(6, 1);
    Input[6] = make_pair(18, 4);
    Input[7] = make_pair(3, 1);
}

void KnapSack::getRatio()
{
    for (auto i : Input)
    {
        ratio.push_back(make_pair(i.first, i.second.first / i.second.second));
    }
}

void KnapSack::sort()
{
    for (int i = 0; i < ratio.size(); i++)
    {
        for (int j = i + 1; j < ratio.size(); j++)
        {
            if (ratio[j].second > ratio[i].second)
            {
                swap(ratio[i], ratio[j]);
            }
        }
    }
    cout << "This is the sorted list on which we would be working now: \n";
    for (int i = 0; i < ratio.size(); i++)
    {
        cout << ratio[i].first << " " << ratio[i].second << endl;
    }
}
void KnapSack::calculate()
{
    int count = 0;
    while (weight >= 0)
    {
        auto newWeight = weight - Input[ratio[count].first].second;
        if (newWeight >= 0)
        {
            weight = newWeight;
            results[ratio[count].first] = 1;
        }
        else
        {
            results[ratio[count].first] = (weight / Input[ratio[count].first].second);
            break;
        }
        count = count + 1;
    }
    cout << "This is the genrated result based on the knapSack greedy algo \n";
    for (auto i : results)
    {
        cout << i.first << " " << i.second << endl;
    }
}
// in next two function you just need to give the summation in order to vetify the results
int main()
{
    KnapSack ks;
    ks.generateData();
    ks.getRatio();
    ks.sort();
    ks.calculate();
    return 0;
}