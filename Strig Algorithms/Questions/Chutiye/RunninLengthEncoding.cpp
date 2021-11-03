//simply compress the string by removing the duplicates and using the number of dulpicates in place
/*
ROOPAKIMAAKABHOSDA
1R3O1P4A2K1I1M1B1H1S1D
and if the lenght of new compressed string is same return the original string
*/

#include<bits/stdc++.h>
using namespace std;

class RunningLenghtEncoding
{
    public:
    string Text;
    map<char,int>Hash; //this will map the char to a frequency
    string runningLenghtEncoding();//this will return a string
};
string RunningLenghtEncoding::runningLenghtEncoding()
{
    string ans="";
    for(int i=0;i<Text.size();i++)
    {
        if(Hash[Text[i]])
        {
        Hash[Text[i]]+=1;
    }
    else
    {
        Hash[Text[i]]=1;
    }
    }
//forming the new string
  for(auto val:Hash)
  {     
      ans+=to_string(val.second);
        ans+=val.first;
        
  }
  if(ans.size()==Text.size())
  {
      return Text;
  }
  else
  {
      return ans;
  }
}
int main()
{
    RunningLenghtEncoding obj;
    obj.Text="ROOPAKIMAAKABHOSDA";
    cout<<"This is the compressed string obtained by running lenght encoding \n";
    cout<<obj.runningLenghtEncoding();
    return 0;
}