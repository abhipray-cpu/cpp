#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void Tower_of_hanoi(int n,char fromPeg,char toPeg,char auxPeg)
{
    if(n==1)
    {
        cout<<"Move disk 1 from "<<fromPeg<<" to "<<toPeg<<endl;
        return;
    }
    Tower_of_hanoi(n-1,fromPeg,auxPeg,toPeg);
    cout<<"Move disk "<<n<<" from "<<fromPeg<<" to "<<toPeg<<endl;
    Tower_of_hanoi(n-1,auxPeg,toPeg,fromPeg);
}
int main()
{
    int n=3;
    char fromPeg='A';
    char toPeg='C';
    char auxPeg='B';
    Tower_of_hanoi(n,fromPeg,toPeg,auxPeg);
    return 0;
}