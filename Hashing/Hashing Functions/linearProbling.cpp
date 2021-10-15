#include<bits/stdc++.h>
using namespace std;

class LinearProbing
{   public:
    int TableSize=1000;
     map<int,int>HashTable;
    float loadFactor = HashTable.size()/TableSize;
    void InsertValue(int value);
    void deleteValue(int value);
    void hashSearch(int value);
    int hashFunction(int data,int ProbingFactor);
    void RehashRequired();//this function will check whether rehash is required or not after every insertion
    void RehashTable(); //this function will implement the rehashing of the hashtable
};

void LinearProbing::InsertValue(int value)
{
    int hashValue = hashFunction(value,0);//this will most probably give a unique value for every element
    HashTable[hashValue] = value;
    loadFactor=(float)HashTable.size()/TableSize;
    RehashRequired();
    //since we are resolving the collisons therefore we should get a unique value in which we will be soring the value
}
void LinearProbing::RehashRequired()
{  //we will rehash the hash table in case the load factor is greater than 80%
    if(loadFactor >= 0.80)
    RehashTable();
}
//this function will rehash the hash table
void LinearProbing::RehashTable()
{  
   
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
void LinearProbing::deleteValue(int value)
 {  bool found = false;
    for(int i=0;i<1000;i++) //will be adding the probing factor until 1) value is found size limit is reached
   {
      int hashValue=(((((value*value)/1000)+10)*23)/6)+i;
       if(HashTable[hashValue] == value)
       {
           cout<<"Value found and will now be deleted \n";
           HashTable.erase(hashValue);
           found = true;
           break;
       }
   }
if(found==false)
{
    cout<<"The hash value was not found \n";
}
}

void LinearProbing::hashSearch(int value)
{
    bool found = false;
    for(int i=0;i<1000;i++) //will be adding the probing factor until 1) value is found size limit is reached
   {
      int hashValue=(((((value*value)/1000)+10)*23)/6)+i;
       if(HashTable[hashValue] == value)
       {
           cout<<"Value found  \n";
           found = true;
           break;
       }
   }
if(found==false)
{
    cout<<"The hash value was not found \n";
}
}

int LinearProbing::hashFunction(int value,int ProbingFactor)
{
    int hashValue = (((((value*value)/1000)+10)*23)/6)+ProbingFactor;
    if(HashTable[hashValue])
    {
        return hashFunction(value,ProbingFactor+1);
    }
    else
    {
        return hashValue;
    }
}
int main()
{
    LinearProbing L;
    for(int i=1;i<1000;i++)
    {
        L.InsertValue(i);
    }
    cout<<"This is the size of the Hash Table "<<endl;
    cout<<L.HashTable.size()<<endl;
    cout<<"Searching for a value that should be present let's say 69 \n";
   L.hashSearch(69);
   cout<<"Searching for a value that should not be present let's say 1169 \n";
   L.hashSearch(1169);
    return 0;
}