//this is also a string matching algorithm and it genderates a LPS for the patterns
//and then tracks the main text using the LPS of the pattern

#include<bits/stdc++.h>
using namespace std;

class KMPAlgo
{
  public:
    string Parent;
    string child;
    vector<pair<int,int>>Matches;//this will store the start and end index of the matched pattern
    map<int,int>LPS; //LPS is basically a frequency index taht helps us to find the prefix of the pattern that has already been scanned
    map<char,int>Counter;//this will tell us whether the character was encountere previously
    void GenerateLPS(); //this function will generate the LPS
    void scanText();//this function will scna the text
    void showPatterns();//this function will show the patterns if any found
};

void KMPAlgo::GenerateLPS()
{
    //this function will generate the LPS for the pattern 
    int currCount=0;
    for(int i=0;i<child.size();i++)
    {
        if(Counter[child[i]])
        {
           LPS[i]=++currCount;
           Counter[child[i]]=Counter[child[i]]+1;

        }
        else
        {
            currCount=0;
            Counter[child[i]]=1;
            LPS[i]=0;
        }
    }
}
void KMPAlgo::scanText()
{  
    int j=-1;
 for(int i=0;i<Parent.size();i++)
 {  
    if(Parent[i] == child[j+1]) //if the character matches we will jump to the next character by icnrementing j
    {
          j++;
    }
    else if(Parent[i] != child[j+1] ) //if the character does not match
    {     
        if(j==0 || j== -1)//these are basically the starting indexes for text scan
        {
            j=-1;
        }
        else
        {
            j=LPS[j-1]; // we go to index is the LPS[j-1] position
        }
    }
    if(j == child.size()-2) // -2 since we are starting the j counter from -1
    {
         cout<<"A match for the pattern is found in the text \n";
         Matches.push_back(make_pair(i-child.size(),i));
         // i will be the end count and we are decreasing the size of pattern to find the starting index
    } 
 }
}
void KMPAlgo::showPatterns()
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
    KMPAlgo K;
    K.Parent = "Roopa ki maa ka bhosda";
    K.child = "maa ka bhosda";
    K.GenerateLPS();//this will generate the LPS for the pattern
    cout<<"Scaning the text for the pattern .... \n";
    K.scanText();
    cout<<"The scanning is completed and this the result \n";
    K.showPatterns();
    return 0;
}