#include<bits/stdc++.h>
using namespace std;

class Repeated
{
    public:
    map<int,char>Hashtable;
    string Test;
    int hashFunction(int value,int ProbingFactor);
    void insertValue(int value);
    void checkStringRepeated(string str);//this funcition will check for the first repeated char in the string
    void checkStrigNonRepeated(string str); // this function will check for the first non repeated char in the string
};
int Repeated::hashFunction(int value,int ProbingFactor)
{
    int hashValue = ((value*value)/1000)+ProbingFactor;
    if(Hashtable[hashValue])
    {
        return hashFunction(value,ProbingFactor+1);
    }
    else
    return hashValue;
}
void Repeated::insertValue(int value)
{

}
void Repeated::checkStringRepeated(string str)
{

}
void Repeated::checkStrigNonRepeated(string str)
{

}
int main()
{
    return 0;
}