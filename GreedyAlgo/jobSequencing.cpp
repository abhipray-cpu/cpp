#include <bits/stdc++.h>
using namespace std;

class JobSequencing
{
public:
    map<string, pair<int, int>> Input; // this is the input
    vector<pair<string, int>> Sort;    // this will be sorted as per profit from each job
    map<int, string> Sequence;         // this will be the output containing job and their sequence
    int totalProfit = 0;
    int maxTime;
    int giveMaxTime();
    void sort();
    void generateData();
    void findSequence();
    void displaySequence();
};
void JobSequencing::generateData()
{
    Input["J1"] = make_pair(20, 2);
    Input["J2"] = make_pair(15, 2);
    Input["J3"] = make_pair(10, 1);
    Input["J4"] = make_pair(5, 3);
    Input["J5"] = make_pair(1, 3);
}
void JobSequencing::sort()
{
    // generating the vector for sorting
    for (auto i : Input)
    {
        Sort.push_back(make_pair(i.first, i.second.first));
    }
    // sorting the vector in order of profit
    for (int i = 0; i < Sort.size(); i++)
    {
        for (int j = i + 1; j < Sort.size(); j++)
        { // will sort the vector in the descnding order of profit
            if (Sort[i].second < Sort[j].second)
            {
                swap(Sort[i], Sort[j]);
            }
        }
    }
    cout << "This is the jobs aftet being sorted on basis of profit: \n";
    for (int i = 0; i < Sort.size(); i++)
    {
        cout << Sort[i].first << "-->" << Sort[i].second << endl;
    }
}
// I love copilot for this autoCompletion #true lobh
int JobSequencing::giveMaxTime()
{
    int max = 0;
    for (auto i : Input)
    {
        if (i.second.second > max)
        {
            max = i.second.second;
        }
    }
    return max;
}
void JobSequencing::findSequence()
{
    maxTime = giveMaxTime();
    int JobCount = 1;
    for (int i = 0; i < Sort.size(); i++)
    {
        if (JobCount > maxTime)
        {
            break;
        }
        else
        {
            auto Job = Sort[i].first;
            if (Sequence.find(Input[Job].second) == Sequence.end())
            {
                Sequence[JobCount] = Job;
                totalProfit += Sort[i].second;
                JobCount++;
            }
        }
    }
    cout << "This is the jobSequenct that was generated: \n";
    for (auto i : Sequence)
    {
        cout << i.first << "-->" << i.second << endl;
    }
    cout << "This is the total profit: " << totalProfit << endl;
}
void JobSequencing::displaySequence()
{
    // in this profit you can display the output in a better way
    // but I am not going to do that shit here
}
int main()
{
    JobSequencing J;
    J.generateData();
    J.sort();
    J.findSequence();
    // J.displaySequence();
    return 0;
}