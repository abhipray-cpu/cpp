//this is also a string matching algorithm

/*
it has two steps
1)preprocessing generating the bad match table O(n)
2)Scanning the text O(m)
*/

#include<bits/stdc++.h>
using namespace std;

class BoyreMoore
{
   public:
         map<char,int>BadMatchTable;//this is the bad match table that will contain the value of the bad match
          vector<pair<int,int>>Matches;//this will store the start and end index of the matched pattern
         string Parent;
         string Child;
         void generateBadMatch();//this function will generate the bad match table from the pattern
         void scanText();//this will scan the text
         void showPatterns();//this will show the found patterns in the string
};

void BoyreMoore::generateBadMatch()
{
   char lastChar = Child[Child.size() - 1]; //we are storing the last char to assign it a value = size in the badmatch table
   BadMatchTable[lastChar] = Child.size(); 
   BadMatchTable['*'] = Child.size();//this is for handling any character that is not there in the bad match table
   for(int i = 0; i < Child.size()-1; i++)//-1 since the value for last char is already assigned
   {
     if(Child[i] != lastChar)//since the value of last char will not be updated we are checking for it
     {  
       BadMatchTable[Child[i]] = Child.size()-i-1;
     }
   }  
}
void BoyreMoore::scanText()
{
  int start = 0;
  int end = Child.size();
  while(start<=Parent.size()-Child.size())
  {   
      string SubString = Parent.substr(start, end);
      cout<<"Start: "<<start<<endl;
      cout<<"End: "<<end<<endl;
      cout<<"This is the substring we will be scanning: "<<SubString<<endl;
      int k=end-1;
      int foundStart = start;
      int foundEnd = end;
      int j=Child.size()-1;
      for(j;j>=0;j--)
      {
          if(Parent[k] == Child[j])
          {
              k--;
              continue;
          }
          else
          {
              start = start+BadMatchTable[Parent[k]];
              end = end+BadMatchTable[Parent[k]];
            break;
          }
      }
      cout<<"This the value of j: "<< j<<endl;
     if(j==-1)
     {
         cout<<"A patter is matched in the main string \n";
         Matches.push_back(make_pair(foundStart,foundEnd));
         start=start+1;
         end=end=1;
     }
}}
void BoyreMoore::showPatterns()
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
BoyreMoore BM;
BM.Parent="Roopa ki maa ka bhosda";
BM.Child="maa ka bhosda";
BM.generateBadMatch(); //this function will generate the bad match table
cout<<"This is the generated bad matchh table \n";
for (auto i : BM.BadMatchTable)
        cout << i.first << "   " << i.second
             << endl;

cout<<"Scanning the text for the pattern .... \n";
BM.scanText();
cout<<"The text is scanned and here are the results \n";
BM.showPatterns();
return 0;
}

