#include<bits/stdc++.h>
using namespace std;

class RecursiveRemove
{
    public:
    string text;
    string recursiveRemoval(string text);
};
string RecursiveRemove::recursiveRemoval(string text)
{
    for(int i=0;i<text.size();i++)
    {
        if(text[i] == text[i+1])//adajacent characters matches
        {
              string left = text.substr(0,i);
              string right = text.substr(i+2,text.size());
              string newString = left + right;
              text = recursiveRemoval(newString); 
        }
      cout<<"This is the current text: "<<text<<endl;
    }
    return text;
}
int main()
{
    RecursiveRemove R;
    R.text="ABCCBCBA";
    cout<<"This is the original string: "<<R.text<<endl;
    R.recursiveRemoval(R.text);
    cout<<"This is the string after removing the adjacent duplicate characters: "<<endl;
}