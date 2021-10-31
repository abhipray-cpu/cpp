/*
Problem statement ot find minimum window in a given string such that it contains all the
characters present in a given pattern
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long L;
class MinWindow
{
    public:
    int baseValue=10;
    string INPUT;
    string Characters;
    vector<string>MinWindow;
    L charHash;
    L Hash(string text);
    bool stringsMatch(string str1,string str2);
    void findMinWindow();
};

L MinWindow::Hash(string text)//using this rabin karp hash since it will minimize 
{
   int size = text.size();
   long long sum = 0; //since we will be using high power values therefore use long long
   for(int i=0;i<text.size();i++)
   {
       sum=sum+((int)text[i]);
       size = size-1; 
       
   }
   return sum;
}
bool MinWindow::stringsMatch(string str1,string str2)
{
    map<char,int>Map1;//this is for string 1
    map<char,int>Map2;//this is for string 2
    //mapping the frequency to the characters
    for(int i=0;i<str1.size();i++)
    {
        if(Map1[str1[i]])
        {
            Map1[str1[i]]+=1;
        }
        else
        {
            Map1[str1[i]]=1;
        }
        if(Map2[str2[i]])
        {
            Map2[str2[i]]+=1;
        }
        else
        {
            Map2[str2[i]]=1;
        }
    }
    //comparing the charaters in both of the maps
    for(int i=0;i<str1.size();i++)
    {   
        if(Map1[str1[i]] != Map2[str2[i]])
        {
             return false;
             break;
        }
    }
    return true;
}
//this window will find the min window using the rolling window
void MinWindow::findMinWindow()
{
   int start=0;
   int end = Characters.size();
   while(start<=INPUT.size()-Characters.size())
   {
       string substr = INPUT.substr(start,end);
       auto sum = Hash(substr);//or can also use rolling hash kind a thing for O(1) time complexity
       if(sum == charHash)
       {    cout<<"Found a sum match of the given string \n";
             cout<<substr<<endl;
           if(stringsMatch(substr,Characters))
           {   
              MinWindow.push_back(substr);
              start=start+1;
              end=end+1;
           }
           else
           {
             start=start+1;
              end=end+1;
           }
       }
       else
       {
           start=start+1;
              end=end+1;
       }

   }
}
int main()
{
   MinWindow M;
   cout<<"testing some matching words for the hash function \n";
   vector<string>test={"test","best","lest","nest","rest","west","zest","fest"};
   for(auto word:test)
   {
       cout<<"Word: "<<word<<"\t hash: "<<M.Hash(word)<<endl;
   }
   M.Characters="bhosda";
   M.INPUT="maakashodba";
   M.charHash=M.Hash(M.Characters);
   M.findMinWindow();
   return 0;
}