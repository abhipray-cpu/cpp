//drop all chars in a stack and then pop them all out till the stack is empty

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class string_reverse
{
   public:
   stack<char>rev;
   string reverse(string str);
};
string string_reverse::reverse(string str)
{
    int len=str.length();
    rev.push(' ');
    for(int i=0;i<len;i++)
    {
        rev.push(str[i]);
    }

    string reverse;
    while (! rev.empty())
    {
        reverse+=rev.top();
        rev.pop();
    }
    return reverse;
    
}

int main()
{
    string str="Maa Ka Bhosda";
    cout<<"The original string is :"<<str<<endl;
    string_reverse R;
    cout<<"The reversed string is :"<<R.reverse(str)<<endl;
}