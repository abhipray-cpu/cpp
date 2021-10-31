//using the hash table to store the string:

#include<bits/stdc++.h>
using namespace std;
typedef long long L;

//using the RabinKarpHash hash here but one can also use Mur Mur3 hash for this rate as it has less coliision rated 
//compared to RabinKarpHash hash function
class HashAndStore
{
    public:
    int baseValue=10;
    map<L,string>HashTable;
    void insert(string Str);
    void search(string Str);
    void display();
    L RabinKarpHash(string Str);
};
//this function will return a RabinKarpHash hash for a given string
L HashAndStore::RabinKarpHash(string text)
{
    int size = text.size();
   long long sum = 0; //since we will be using high power values therefore use long long
   for(int i=0;i<text.size();i++)
   {
       sum=sum+((int)text[i])*pow(baseValue,size-1);
       size = size-1; //since for next character the power value will be one less
       
   }
   return sum;
}
//this function will insert the string into hash table
void HashAndStore::insert(string Str)
{
   //do we need some sort of collision technique?
   //will simply be overwritten since we are not using any collision technique
   L hashValue = RabinKarpHash(Str);
   HashTable[hashValue]=Str;
}
//this function will search the hashtable
void HashAndStore::search(string Str)
{
        L hashValue = RabinKarpHash(Str);
        string str = ""; 
        str=HashTable[hashValue];
        if(str != "")
        {
           cout<<"string is present in the hashtable \n";
        }
}
int main()
{
   HashAndStore Hs;
   //these are some strings for which we are checking the hash function
   vector<string>Test;
   Test.push_back("Roopa");
   Test.push_back("Ki");
   Test.push_back("Maa");
   Test.push_back("Ka");
   Test.push_back("Bhosda");
   Test.push_back("Teri");
   Test.push_back("Bhi");
   for(int i=0;i<Test.size();i++)
   {
       cout<<Test[i]<<"\t"<<Hs.RabinKarpHash(Test[i])<<endl;
   }
   cout<<"Insrting some test values \n";
   Hs.insert("Roopa");
   Hs.insert("Ki");
    Hs.insert("Maa");
    Hs.insert("Ka");
    Hs.insert("Bhosda");
    Hs.insert("Teri");
    Hs.insert("Bhi");
    cout<<"Checking whether the strings are present are not \n";
    Hs.search("Roopa");
   return 0;
}