#include<bits/stdc++.h>
using namespace std;

class MultiHash{
    public:
    map<int,int>HashTable;
    int TableSize=1000;
    float LoadFactor=(float)HashTable.size()/TableSize;
    void InsertValue(int value);
    void DeleteValue(int value);
    void HashSearch(int value);
    void RehashRequired();
    void Rehash();
    int hashFunction(int value);//in this case either I can use a chain of different hash functions or I can use same hash function recursively
    int hashUtil(int value);//this function will return the actual hash value
};
void MultiHash::InsertValue(int value)
{
     int Hashvalue = hashFunction(value);
     HashTable[Hashvalue] = value;
     LoadFactor = (float)HashTable.size()/TableSize;
     RehashRequired();     
}
void MultiHash::RehashRequired()
{
    if(LoadFactor>=0.8)
    {   cout<<"Since the load factor threshold is reached therefore rehashing the hash table \n";
        Rehash();//this will rehash the hash table
    }
}
void MultiHash::DeleteValue(int value)
{
  int hashValue = hashFunction(value);
  HashTable.erase(hashValue);//this will remove the entry from hash table
}
void MultiHash::HashSearch(int value)
{ 
   int hashValue = hashFunction(value);//this should most probaly be consistent in nature therefore same value is expected
   if(HashTable[hashValue])
   { 
         cout<<"Value found in the hash table \n";
         }
         else
         {
             cout<<"Value was not found in the hash table \n";
         }
}

void MultiHash::Rehash()
{
       //these are the steps
       //extract all the value
       //delete all the values
       //double the table size
       //hash and inseert all the values again
       cout<<"Rehashing the table \n";
    vector<int>container,keys;
    auto it = HashTable.begin();
    // Iterate over the map using Iterator till end.
    while (it != HashTable.end())
    {
        // Accessing KEY from element pointed by it.
        auto key = it->first;
        // Accessing VALUE from element pointed by it.
        auto value = it->second;
        //adding the value to the container
        container.push_back(value);
        keys.push_back(key);
        it++;
        
    }
    for(int i=0;i<keys.size();i++)
    {
        HashTable.erase(i);
    }
    //step2
    TableSize=TableSize*2;
    
    //step3 hashing values using the new hash table size
    for(int i=0;i<container.size();i++)
    { 
        InsertValue(i);
    }
}
//in this approach I am using same function recursively
int MultiHash::hashFunction(int value)
{      int hashVal=hashUtil(value);
         for(int i=1;i<100;i++)
         {
             hashVal = hashUtil(hashVal);
         }
}

int MultiHash::hashUtil(int value)
{
    return (value*value)/TableSize;
}

int main()
{       
       MultiHash M;
 }