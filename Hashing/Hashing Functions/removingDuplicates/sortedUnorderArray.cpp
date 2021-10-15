//sorted unordered array check for equality i.e they have same set of elements will be using frequency node in this

#include<bits/stdc++.h>
using namespace std;

class CheckArrays
{
   public:
   int tableSize = 10;
   int arr1[10];
   int arr2[10];
   vector<int,pair<int,int>>HashTable;//this is the node structure hashValue=<value,frequency>
   void InsertArr1();
   void CheckArr2();
   int HashFunction(int value);
};

void CheckArrays::InsertArr1()
{
 //in this function of hash same is same and the value is also same then only increase freq else implement probing quadratic probing
  for(int i=0;i<10;i++)
  {
      int hashValue = HashFunction(i);
      if(HashTable[hashValue] && arr1[i] == HashTable[hashValue])
      {
          //in this case will increase the frequency
          HashTable[hashValue].second+=1;//second field is the frequency
      }
      else if(HashTable[hashValue] && arr2[i] != HashTable[hashValue])//in this case we have same hash but it does not match the value therefore provbing
      {
           for(int i=0;i<tableSize;i++)
           {
                   hashValue=hashValue+i;//linear probing
                   if(HashTable[hashValue])
                   continue;
                   else
                   {
                       HashTable[hashValue]=make_pair(arr1[i],0);
                       break;
                   }
           }
      }
      else //in this case we have an entirely new hash value
      {
         
          HashTable[hashValue]=arr1[i];
      }
  }
}
void CheckArrays::CheckArr2()
{
    for(int i=0;i<10;i++)
    {
        int hashValue = HashFunction(arr2[i]);
        if(HashTable[hashValue] && arr2[i] == HashTable[hashValue])
      {
          //in this case will increase the frequency
          HashTable[hashValue].second-=1;//second field is the frequency
      }
      else if(HashTable[hashValue] && arr2[i] != HashTable[hashValue])//in this case we have same hash but it does not match the value therefore provbing
      {   bool found = 0;
           for(int i=0;i<tableSize;i++)
           {
                   hashValue=hashValue+i;//linear probing
                   if(HashTable[hashValue]&& arr2[i] == HashTable[hashValue])
                   {
                          HashTable[hashValue].second-=1;
                          found=1;
                   }
                 }
                 if(found == 0)
                {
                    cout<<"New element found in B which is not in A therefore a mismatch \n";
                }
      }
      else //in this case we have an entirely new hash value
      {
         
          cout<<"New element found in B which is not in A therefore a mismatch \n";
      }
    }
}
int CheckArrays::HashFunction(int value)
{ 
   return (value*value)/tableSize;
} 
 

int main()
{
    //initialize an array 1 and array2 and then  run the above mentioned function
    return 0;
}