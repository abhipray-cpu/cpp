//this is hash based algo
/*
in this case we use a special hash function (Rabin karp hash function)
and compare the set of substrings of size = size of patterns for fnding the mathces based on the hash value 
of the substring
and we also use rolling hash function to get the hash value in constant time
we only compare the strings if the hash matches
we will also use a countet to keep the count of the substring we are in
*/

#include<bits/stdc++.h>
using namespace std;

class RabinKarp
{
    public:
    string Parent;
    string child;
    int baseValue;
    long long patternHash;
    vector<pair<int,int>>Matches;
    long long RabinKarpHash(string text); //this function will give back a hash value
    // we can assign custom code to the characters or we can simply use ascii codes which I will be using 
    void findPatterns(int find_patterns); //this function will fibd the indexes of the patterns
    void showPatterns(); //this function will show all the matched patterns indexes
    bool compareString(string subString);
};

long long RabinKarp::RabinKarpHash(string text)
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
//this is the main function that will be findig the patterns based on the hash value of the sub pattern

//rolling hash is implemented since it gives the hash of a string in constant time
void RabinKarp::findPatterns(int pattern_size)
{
   //for rolling hash what's the power of the base value that should be added and subtracted from the main hash function
   string subStr = Parent.substr(0,child.size());
   long long hash=RabinKarpHash(subStr);
   int count=0;
   int start=count+1;
   int end = start+pattern_size-1;
   auto match = compareString(subStr);
   if(match == true)
   {
       Matches.push_back(make_pair(0,child.size()-1));
       cout<<"A match is found /n";
   }
   while(end <= Parent.size()-1)
   {  
       hash=((hash-((int)Parent[count]*pow(baseValue,child.size()-1)))*baseValue)+(int)Parent[end];
       
       
    //    cout<<count<<") "<<"Pattern hash:"<<patternHash<<"\t"<<"Sub string hash:"<<hash<<endl;
       
       if(hash == patternHash)
       {
           subStr = Parent.substr(start,end+1);
        auto match = compareString(subStr);
        if(match == true)
        {
            cout<<"A pattern is found in the main string \n";
            Matches.push_back(make_pair(start,end));
        }

       }
       count++;
       start=count+1;
       end = start+pattern_size-1;
   }
}

bool RabinKarp::compareString(string subString)
{
   for(int i=0;i<subString.size();i++)
   {
       if(subString[i]!=child[i])
       {
           return false;
       }
   }
   return true;
}

void RabinKarp::showPatterns()
{
auto size = Matches.size();
    if(size == 0)
    {
        cout<<"No matches were found in the string \n";
    }
    else
    {
        cout<<size<<" patterns were found in the string \n";
        for(int i=0;i<size;i++)
        {
            auto index = Matches[i];
            cout<<"These are the indexes of the pattern found: "<<"start: "<<index.first<<" second: "<<index.second<<endl;
            cout<<endl;
        }
    }
}
int main()
{
    RabinKarp RK;
    RK.Parent = "Roopa ki maa ka bhosda";
    RK.child = " maa ka bhosda";
    RK.baseValue=4 ; //since I am accounting for all the characters in the ascii code table
    RK.patternHash=RK.RabinKarpHash(RK.child);
    cout<<"Finding the patterns in the parent string \n";
    RK.findPatterns(RK.child.size());
    cout<<"These are all the patterns in the parent string \n";
    RK.showPatterns();
    cout<<"This is a demo for rbin karp hash function \n";
    return 0;
}