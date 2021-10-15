#include<bits/stdc++.h>
using namespace std;

class CleanString
{  //numeric hashing based on ASCII value of the characters
    public:
    string toClean;
    string cleanFrom;
    map<int,char>Hashtable;
    int hashFunction(int value,int ProbingFactor);
    void insertValue(int value);
    void CheckString(string str);
    void hashValues(string str);
    bool check(int value,int ProbingFactor);

};
bool CleanString::check(int value,int ProbingFactor)
{
      int hashValue = ((value*value)/1000) + ProbingFactor;
      if(Hashtable[hashValue])
      {
          if(Hashtable[hashValue] == value)
          {
              return true;
          }
          else
          return check(value,ProbingFactor+1);
      }
      else
      return false;
}
int CleanString::hashFunction(int value,int ProbingFactor)
{
    int hashValue = ((value*value)/1000)+ProbingFactor;
    if(Hashtable[hashValue])
    {
        return hashFunction(value,ProbingFactor+1);
    }
    else
    return hashValue;
}
//in this function pass the string that needs to be cleaned
void CleanString::CheckString(string str)
{
    for(int i=0;i<str.length();i++)
    {
        int ascii = (int)str[i];
        bool result = check(ascii,0);
        if(result == true)
        {
            //remove the char from the string
            // a good way of doing this is concatinating the string while using slicing
            auto first = str.substr(0,i);
            auto second = str.substr(i+1,str.length());
            str = first+second;
        }
    }
}
void CleanString::insertValue(int value)
{
    int hashValue = hashFunction(value,0);//hopefully this should return unique hash value
    Hashtable[hashValue] = value;
}
void CleanString::hashValues(string str)//this is the string from which we will be extracting characters
{
    for(int i=0;i<str.length();i++)
    {
        int ascii = (int)str[i];//hashing the charcter based on it's ascii value
        int hashValue = hashFunction(ascii,0);//hopefully this should return unique hash value
        Hashtable[hashValue] = str[i];
    }
}
int main()
{
    // in this function declare two strings
    // one to be cleaned and other to be cleaned from
    //then run the functions to clean the string
   return 0;
} 