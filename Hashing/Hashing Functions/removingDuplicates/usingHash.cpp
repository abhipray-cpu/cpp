#include<bits/stdc++.h>
using namespace std;
class RemoveDuplictes{
    public:
    int TableSize=1000; 
    map<int,int>HashTable;
    int arr[1000];
    void InsertValue();
    void InitializeArray();
    void newArray();
    int HashFunction(int value);
};
void RemoveDuplictes::InsertValue()
{
        //after the hash check do one more check for value equality since hash might be same for some values 
        for(int i=0;i<TableSize;i++)
        {
            int hashVal = HashFunction(arr[i]);
            if(HashTable[hashVal] && i == HashTable[hashVal])//this confirms a duplicate
            {
                cout<<"Duplicate found and therefore not inserting it in the hash table \n";
                arr[i]=-1;
            }
            else
            HashTable[hashVal] = i;
        }  
        cout<<"This is the new array"<<endl;
        for(int i=0;i<TableSize;i++)
        {
            if(i!=-1)
            {
                cout<<i<<"\t";
            }
        }
}
void RemoveDuplictes::InitializeArray()
{
   for(int i=0;i<TableSize;i++)
   {
      arr[i] = rand(); 
   }
}

int RemoveDuplictes::HashFunction(int value)
{   
     return (value*value)/TableSize;
}
int main()
{
    RemoveDuplictes R;
    R.InitializeArray();
   R.InsertValue();
   return 0;
}