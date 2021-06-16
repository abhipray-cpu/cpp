#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class balance_bracket
{
    public:
    bool matching(char a,char b);
    bool balanced(string str);
};

bool balance_bracket::matching(char a, char b)
{
    if((a=='(' && b==')')||(a=='{' && b=='}')||(a=='[' && b==']'))
    return true;
    else
    {
        return false;
    }
    
}

bool balance_bracket::balanced(string str)
{
  stack <char>s;
  for(int i=0;i<str.length();i++)
  {
      char a=str[i];
      if(a=='(' || a=='{' || a=='[')
      s.push(a);
      if(a=='}' || a== ')' || a==']')
      {
          if(s.empty()){
          return false;
          break;
          }
          else if(!matching(s.top(),a))
          {   
              return false;
              break;
          }
          else
          {
              s.pop();
          }
          
      }
  }
  if(s.empty())
  return true;
  else
  {
      return false;
  }
  
}

int main()
{
    balance_bracket B1;
    string str1="({[]})";
    string str2="{([)}";
    cout<<B1.balanced(str1)<<endl;
    cout<<B1.balanced(str2)<<endl;
    return 0;
}