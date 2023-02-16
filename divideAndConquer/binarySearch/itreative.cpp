#include <bits/stdc++.h>
using namespace std;

class binarySearch
{
public:
    int high;
    int low;
    int key;
    int mid;
    vector<int> elements;
    void search();
};

void binarySearch::search()
{
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (elements[mid] == key)
        {
            cout << "Element found at " << mid;
            break;
        }
        else if (key < mid)
        {
            high = mid - 1;
        }
        else if (key > mid)
        {
            low = mid + 1;
        }
    }
}
int main()
{
    binarySearch B;
    vector<int> elements = {45, 23, 67, 21, 89, 12, 90, 12, 67, 12, 78, 23, 89, 23, 12, 56, 34};
    B.elements = elements;
    B.low = 0;
    B.high = elements.size() - 1;
    B.key = 89;
    // sorting the array first
    for (int i = 0; i < elements.size(); i++)
    {
        for (int j = i + 1; j <= elements.size(); j++)
        {
            if (elements[i] > elements[j])
            {
                int temp = elements[i];
                elements[i] = elements[j];
                elements[j] = temp;
            }
        }
    }
    // proceeding with the sorted arrays
    B.search();
}