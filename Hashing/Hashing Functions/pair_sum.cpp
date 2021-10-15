#include<bits/stdc++.h>
using namespace std;
typedef vector<pair<int,int>> List;
class findPairs{
    public:
    int Sum=34;
    map<int,int>HashTable;
    List pairs;
    vector<int>Set1,Set2;
    void FindPairs();
    int hashFunction(int value,int ProbingFactor);
    void HashArray(vector<int>Arr);
    void insert(int value); // since using linear probing hopefully this wil give a unique hash value
    void checkArr2();//this function will check for all the matching pairs
    bool check(int value,int ProbingFactor);
};
void findPairs::FindPairs()
{
   int size1 = Set1.size();
   int size2 = Set2.size();
   bool cond = size1<size2 ? true:false;
   if(cond == true)
   {
      HashArray(Set1);   }
   else
   HashArray(Set2);
}
void findPairs::checkArr2()
{
    for(int i=0;i<Set2.size();i++)
    {
        int testValue = Sum - Set2[i];
        bool result = check(testValue,0);
        if(result == true)
        {
            auto pair = make_pair(testValue,Set2[i]);
            pairs.insert(pair);
        }
    }
}
void findPairs::insert(int value)
{
    int hashValue = hashFunction(value,0);
    HashTable[hashValue] = value;
}

//this function will hash all the elements of the smaller sized set
void findPairs::HashArray(vector<int>Arr)
{
   for(int i=0;i<Arr.size();i++)
   {
       insert(Arr[i]);
   }
}

int findPairs::hashFunction(int value,int ProbingFactor)
{
      int hashValue = ((value*value)/1000) + ProbingFactor;
      if(HashTable[hashValue])
      {
          return hashFunction(value,ProbingFactor+1);
      }
      else
      return hashValue;
}

bool findPairs::check(int value,int ProbingFactor)
{
      int hashValue = ((value*value)/1000) + ProbingFactor;
      if(HashTable[hashValue])
      {
          if(HashTable[hashValue] == value)
          {
              return true;
          }
          else
          return check(value,ProbingFactor+1);
      }
      else
      return false;
}

int main()
{
    return 0;
}