#include<bits/stdc++.h>
using namespace std;

string reverseString(string text)
{
  for(int i= text.size()-1; i>=text.size()/2; i--)
  {
      char temp = text[text.size() - 1-i];
      text[text.size() - 1-i]=text[i];
      text[i]=temp;
  }
  return text;
}
int main()
{
    string test = "Roopa ki maa ka bhosda";
    cout<<"This is the original string: \n";
    cout<<test<<endl;
   string reversed = reverseString(test);
    cout<<"This is the reverses string \n";
    cout<<reversed;
    return 0;
}