// creating a table of values first and then deriving the LCS from it.This will be a top to bottom approach
#include <bits/stdc++.h>
using namespace std;
class LCS
{
public:
    string seq1, seq2, seq = "";
    int rowCount, columnCount;
    // usin a map for a dynamic 2d table
    map<pair<int, int>, int> table;
    void initializeTable();
    void getLCS(); // this function will derive the LCS from the generated Table
};
void LCS::initializeTable()
{
    // fillig in the 0th column and row with 0 value
    rowCount = seq1.length();
    columnCount = seq2.length();
    for (int i = 0; i <= rowCount; i++)
    {
        table[make_pair(i, 0)] = 0;
    }
    for (int i = 0; i < columnCount; i++)
    {
        table[make_pair(0, i)] = 0;
    }
    // filling in the rest of the columns
    for (int i = 1; i <= rowCount; i++)
    {
        for (int j = 1; j <= columnCount; j++)
        {
            if (seq1[i - 1] == seq2[j - 1])
            {
                table[make_pair(i, j)] = table[make_pair(i - 1, j - 1)] + 1;
            }
            else
            {
                table[make_pair(i, j)] = max(table[make_pair(i - 1, j)], table[make_pair(i, j - 1)]);
            }
        }
    }
}
void LCS::getLCS()
{
    // note the characters here will be derived from the column coresspondin string which is the longer of the two
    int val = table[make_pair(rowCount, columnCount)];
    string str = "";
    int r = rowCount;    // this will keep track of the rows
    int c = columnCount; // this will keep track of the columns
    while (val != 0 && r >= 0 && c >= 0)
    {

        // we can only move in two directions that is left and diagonally left based on the condition we encounter
        if (table[make_pair(r, c - 1)] == val)
        {
            cout << "if condirion /n";
            cout << "( " << r << "," << c << ")" << endl;
            c = c - 1;
        }
        else
        {
            cout << "Else condition \n";
            cout << "( " << r << "," << c << ")" << endl;
            str += seq2[c - 1];
            r = r - 1;
            c = c - 1;
        }
        val = table[make_pair(r, c)];
    }
    // the string we get will be reversed order therefore we need to reverse it in order to get the correct matrix
    reverse(str.begin(), str.end());
    cout << "This is the LCS od the given two strings =>" << str << endl;
}
int main()
{
    LCS L;
    cout << "Enter sequence 1: \n";
    cin >> L.seq1;
    cout << "Enter sequence 2: \n";
    cin >> L.seq2;
    L.initializeTable();
    // cout << "This is the tabular table that we got \n";
    // for (auto val : L.table)
    // {
    //     cout << val.first.first << "," << val.first.second << "=>" << val.second << endl;
    // }
    L.getLCS();
    ;
    return 0;
}
