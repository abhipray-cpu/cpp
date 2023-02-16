#include <bits/stdc++.h>
using namespace std;

class ASCIIEncoding
{
public:
    map<char, vector<int>> Maping; // this will be character to the binary bit stream mapping
    void setMapping();
    vector<int> encodeData();
    void decodeData(vector<int> Data);
};
void ASCIIEncoding::setMapping()
{
    // do this map each character to the binary bit stream of size 10 cooressponding to the ASCII table
}
vector<int> ASCIIEncoding::encodeData()
{
    // take the character and map it to the binary bit stream
    // then add this bit stream to a vector
    // do this for all the characters in the string
    // return the final resulting vector
}
void ASCIIEncoding::decodeData(vector<int> Data)
{
    // divide the vector into 10 bit chunks
    // now decode each chunk based on the mapping table
    // need to create two maps one for char to bit stream mapping
    // and one for bit stream to char mapping
    // add the decoded character to your string and get the decoded output string
}
int main()
{
    ASCIIEncoding A;
    A.setMapping();
    vector<int> Data = A.encodeData();
    cout << "THis is the encoded bit stream:" << endl;
    for (auto i : Data)
        cout << i;
    A.decodeData(Data);
    return 0;
}