// this is longest common subsequence problem using recursion stack
#include <bits/stdc++.h>
using namespace std;

class LCS
{
public:
    string seq1;
    string seq2;
    string seq = "";
    int LongestCommonSequence(int i, int j);
};
int LCS::LongestCommonSequence(int i, int j)
{
    if (seq1[i] == '\0' || seq2[j] == '\0')
        return 0;
    else if (seq1[i] == seq2[j])
    {
        // this approach is not able to get the LCS string
        return 1 + LongestCommonSequence(i + 1, j + 1);
    }
    else
    {
        return max(LongestCommonSequence(i + 1, j), LongestCommonSequence(i, j + 1));
    }
}
int main()
{
    LCS L;
    cout << "Enter the first sequence: ";
    cin >> L.seq1;
    cout << "Enter the second sequence: ";
    cin >> L.seq2;
    int length = L.LongestCommonSequence(0, 0);
    cout << "The longest common subsequence is: " << L.seq << endl;
    cout << "Lenght of longest common subsequence is: " << length << endl;
    return 0;
}