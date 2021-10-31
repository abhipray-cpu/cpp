#include<bits/stdc++.h>
using namespace std;

string reverseString(string text){
    vector<char>Store;
 for(auto ch: text)
 {
     Store.push_back(ch);
 }
 string rev="";
 for(int i=Store.size()-1; i>=0;i--)
 {
     rev+=Store[i];
 }
 return rev;
}
int main()
{
    string test = "Roopa ki maa ka bhosad";
    cout<<"This is the original string \n";
    cout<<test<<endl;
    string rev = reverseString(test);
    cout<<"This is the reverses string \n";
    cout<<rev;
    return 0;

}