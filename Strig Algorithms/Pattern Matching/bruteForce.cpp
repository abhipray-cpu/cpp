// in this approach we will simply search the parent string character by character for finding the sub pattern
#include<bits/stdc++.h>
using namespace std;

class PatternMatch
{
    public:
    string Parent; //this is the string in which we will be searching the pattern
    string child; //this is the pattern which we will be searching for in the main string
    vector<pair<int,int>>Matches; //in this vector we will be storing the matched sub string index so that it can be retrieved later on
    void findPatterns();//this function will find all the patterns in the substring
    void showPatterns(); //this function will show all the found patterns in the parent string
};
void PatternMatch::findPatterns()
{
  int m = Parent.size();
  int n = child.size();
  for(int i=0;i<m;i++)
  {
      if(Parent[i] == child[0])
      {
          int start = i;
          int found =1;
          i++;
          for(int j=1;j<n;j++)
          {
              if(Parent[i] == child[j])
              {  i++;
                  continue;
              }
              else
              {
                  i = start;
                  found=0; //than we will not add any indexes
                  break;
              }
          }
          if(found == 1)
          {
              Matches.push_back(make_pair(start,start+n-1));
          }
      }
  }
}
void PatternMatch::showPatterns()
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
    PatternMatch P;
    P.Parent = "Roopa ki maa ka bhosda";
    P.child = "maa ka bhosda";
    cout<<"Searching for patterns in the two string"<<endl;
    P.findPatterns();
    cout<<"These are all the mathced patterns found in the string:"<<endl;
    P.showPatterns();
    return 0;
}