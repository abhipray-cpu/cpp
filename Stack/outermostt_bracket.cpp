//we will pop top element
//and empty the stack till size ==1
//and compare whether brackets are balanced or not

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class outer_bracket
{
    public:
    bool is_balance(string str);
};

bool outer_bracket::is_balance(string str)
{
    stack<char>S;
    int len=str.length();
    for(int i=0;i<len;i++)
    {
        S.push(str[i]);
    }

    char a=S.top();
    S.pop();
    while(S.size() != 1)
    {
        S.pop();
    }
    char b=S.top();
    S.pop();
    if((a==')' && b=='(') || (a=='}' && b=='{') || (a==']' && b=='['))
    return true;
    else
    {
        return false;
    }
    
}

int main()
{
    string str="({[]})";
    outer_bracket Ob;
    bool state=Ob.is_balance(str);
    cout<<state<<endl;

    string str1="({[]})}";
    bool state1=Ob.is_balance(str1);
    cout<<state1<<endl;

    return 0;
}