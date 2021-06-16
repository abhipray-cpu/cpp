#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class pair_check
{
    public:
    stack<int> S;
    bool Pair_check(stack <int> S);
};

bool pair_check::Pair_check(stack<int> S)
{       bool state=true;
      while(!S.empty())
      {
          int a=S.top();
          S.pop();
          int b=S.top();
          if(b-a !=1)
          {
             break;
              state=false;
          }
      }
      return state;
}
int main()
{
    pair_check Pc1;
    pair_check Pc2;
    for(int i=0;i<1000;i++)
    {
       Pc1.S.push(i);

    }
    for(int i=0;i<1000;i=i+10)
    {
       Pc2.S.push(i);

    }

    cout<<"The first stack has consecutive elements "<<Pc1.Pair_check(Pc1.S)<<endl;
    cout<<"The second stack has consecutive elements "<<Pc2.Pair_check(Pc2.S)<<endl;

    return 0;
    

    


}
