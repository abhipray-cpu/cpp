#include <bits/stdc++.h>
using namespace std;

class FixedSizeEncoding
{
public:
    string str;
    int uniqueChars;
    int bitSize;
    map<int, vector<int>> Binary;
    map<char, int> Characters;
    map<char, vector<int>> EncodingTable;
    void generateData();
    void getBitSize();
    void generateMappingTable();
    void generateBinaryMapping();
    map<char, vector<int>> getMapping();
    vector<int> EncodeTheString();
    void DecodeData(vector<int> encode);
};

void FixedSizeEncoding::generateData()
{
    int count = 0;
    for (auto i : str)
    {
        if (Characters.find(i) == Characters.end())
        {
            Characters[i] = count++;
            uniqueChars++;
        }
    }

    uniqueChars = Characters.size();
    cout << "The strig has " << uniqueChars << " number of unique characters" << endl;
    for (auto i : Characters)
    {
        cout << i.first << " " << i.second << endl;
    }
    cout << "Calculating the base power of 2 that should be used in the binary system....." << endl;
}
void FixedSizeEncoding::getBitSize()
{
    bitSize = (uniqueChars / 2) - 1;
    cout << "The bit size is " << bitSize << endl;
}

void FixedSizeEncoding::generateBinaryMapping()
{
    // in this function need to generate the binary mapping with base = bit size
    // in here defining some preDefined tables but need to use one which is dynamic and is calcualated on the go
    map<int, vector<int>> Mapping1; // this is for base 3
    map<int, vector<int>> Mapping2; // this is for base 4
    map<int, vector<int>> Mapping3; // this is for base 5
    map<int, vector<int>> Mapping4; // this is for base 6
    map<int, vector<int>> Mapping5; // this is for base 7
    map<int, vector<int>> Mapping6; // this is for base 8
    map<int, vector<int>> Mapping7; // this is for base 9
    map<int, vector<int>> Mapping8; // this is for base 10

    // this is for base3
    Mapping1[0] = {0, 0, 0};
    Mapping1[1] = {0, 0, 1};
    Mapping1[2] = {0, 1, 0};
    Mapping1[3] = {0, 1, 1};
    Mapping1[4] = {1, 0, 0};
    Mapping1[5] = {1, 0, 1};
    Mapping1[6] = {1, 1, 0};
    Mapping1[7] = {1, 1, 1};

    // this is for base4
    Mapping2[0] = {0, 0, 0, 0};
    Mapping2[1] = {0, 0, 0, 1};
    Mapping2[2] = {0, 0, 1, 0};
    Mapping2[3] = {0, 0, 1, 1};
    Mapping2[4] = {0, 1, 0, 0};
    Mapping2[5] = {0, 1, 0, 1};
    Mapping2[6] = {0, 1, 1, 0};
    Mapping2[7] = {0, 1, 1, 1};
    Mapping2[8] = {1, 0, 0, 0};
    Mapping2[9] = {1, 0, 0, 1};
    Mapping2[10] = {1, 0, 1, 0};
    Mapping2[11] = {1, 0, 1, 1};
    Mapping2[12] = {1, 1, 0, 0};
    Mapping2[13] = {1, 1, 0, 1};
    Mapping2[14] = {1, 1, 1, 0};
    Mapping2[15] = {1, 1, 1, 1};

    if (bitSize == 3)
        Binary = Mapping1;
    // this will be true in our case
    else if (bitSize == 4)
        Binary = Mapping2;
}

void FixedSizeEncoding::generateMappingTable()
{
    for (auto i : Characters)
    { // character is being mapped to the binary array
        EncodingTable[i.first] = Binary[i.second];
    }
    cout << "This is our mapping table: \n";
    for (auto i : EncodingTable)
    {
        cout << i.first;
        for (auto j : i.second)
        {
            cout << j;
        }
        cout << endl;
    }
}
vector<int> FixedSizeEncoding::EncodeTheString()
{
    vector<int> Encoded;
    for (auto i : str)
    {
        for (auto j : EncodingTable[i])
            Encoded.push_back(j);
    }
    return Encoded;
}

void FixedSizeEncoding::DecodeData(vector<int> encode)
{
    // this will need a 3rd map for bitstream to character mapping which I forgot to create
}

int main()
{
    FixedSizeEncoding obj;
    obj.str = "abcdwadsadweadsbfasnfiwfawbdwbdfuwfbasawdf";
    obj.generateData();
    obj.getBitSize();
    obj.generateBinaryMapping();
    obj.generateMappingTable();
    auto Encode = obj.EncodeTheString();
    cout << "This is the original string: " << obj.str << endl;
    cout << "This is the encoded string: \n";
    for (auto i : Encode)
    {
        cout << i;
    }
    cout << endl;
    obj.DecodeData(Encode);
    return 0;
}