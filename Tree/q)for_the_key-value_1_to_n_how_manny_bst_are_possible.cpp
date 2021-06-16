/*consider each number can be tree and recursivley finf the possible
left and right tree size*/
#include<bits/stdc++.h>
using namespace std;
int countTree(int n)
{
    if(n<=1)
    return 1;
    else
    {
        int sum=0;
        int left,right,root;
        for(root=1;root<=n;root++)
        {
            left=countTree(root-1);
            right=countTree(n-root);
            sum+=left*right;
        }
        return sum;
    }
}

int main()
{
    cout<<"Number of trees with 44 "<<"distinct values is "<<countTree(44)<<endl;
    return 0;
}