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
    int search(int low, int high);
};

int binarySearch::search(int low, int high)
{
    if (low == high)
    {
        if (elements[low] == key)
        {
            return low;
            cout << "The elements was found at " << low << endl;
        }
        else
        {
            return 0;
            cout << "The key is not present in the given list of elements \n";
        }
    }
    else
    {
        int mid = (low + high) / 2;
        if (key == elements[mid])
        {
            cout << "the element was found at " << mid;
            return mid;
        }
        else if (key < elements[mid])
        {
            return search(low, mid - 1);
        }
        else
            return search(mid + 1, high);
    }
}
int main()
{
    binarySearch B;
    vector<int> elements = {45, 23, 67, 21, 89, 12, 90, 12, 67, 12, 78, 23, 89, 23, 12, 56, 34};
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
    auto val = B.search(B.low, B.high);
}