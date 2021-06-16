#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class check
{
    public:
    string check_repeat(string str);
    string reverse(string str);
};

string check::check_repeat(string str)
{
    stack<char> S;
    S.push(' ');
    S.push(str[0]);
    for(int i=1;i<str.length();i++)
    {
        if(S.top() == str[i])
        {
           S.pop();
        }
        else
        {
            S.push(str[i]);
        }
        
    }
    string result;
    while(!S.empty())
    {
        result+=S.top();
        S.pop();
    }
    return result;
}

int main()
{
    string str="maa ka bhosda";
    check C1;
    string result=C1.check_repeat(str);
    cout<<"The ediited /formatted string is and reversed string is"<<endl;
    cout<<result<<endl;


}

