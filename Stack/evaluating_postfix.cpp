#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Evaluate_Postfix
{
    public:
    int evaluation(string str);
    bool is_unary(char ch);
    bool is_binary(char ch);
    int evaluate_binary(int ch1,int ch2,char operand);
    int evaluate_unary(int ch,char operand);
};
int Evaluate_Postfix::evaluation(string str)
{
    int length=str.length();
    stack<int>st;
    for(int i=0;i<length;i++)
    {
        char ch=str[i];
        if(ch >=0 && ch<=9)
        st.push(ch);
    else if(is_unary(str[i]))
    {
         int ch=st.top();
         st.pop();
         int ans=evaluate_unary(ch,str[i]);
         st.push(ans);
    }
    else if(is_binary(str[i]))
    {
        int ch1=st.top();
        st.pop();
        int ch2=st.top();
        st.pop();
        int ans=evaluate_binary(ch1,ch2,str[i]);
        st.push(ans);
    }
}
return st.top();
}

bool Evaluate_Postfix::is_unary(char ch)
{
    if(ch=='++'||ch=='--')
    return true;
    else
    {
        return false;
    }
    
}
bool Evaluate_Postfix::is_binary(char ch)
{
    if(ch=='+' || ch=='-'  || ch=='*' || ch=='/' || ch=='%')
    return true;
    else
    return false;
}

int Evaluate_Postfix::evaluate_unary(int a,char operand)
{
    if(operand =='++')
    a=++a;
    else if(operand =='--')
    a=--a;

    return a;
}

int Evaluate_Postfix::evaluate_binary(int a,int b,char operand)
{
    if(operand == '+')
    {
        return a+b;
    }
    else if(operand == '-')
    {
        return a-b;
    }
    else if(operand == '*')
    {
        return a*b;
    }
    else if(operand == '/')
    {
        return a/b;
    }
    else if(operand == '^')
    {
        return a^b;
    }
}

int main()
{
    Evaluate_Postfix Ep;
    string str="";//enter your postfix expression to be evaluated
    cout<<Ep.evaluation(str)<<endl;
    return 0;
}
