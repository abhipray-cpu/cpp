//reversing the words in a sentence
#include<bits/stdc++.h>
using namespace std;

class ReverseWords
{
    public:
    string sentence;
    vector<string>Words;
    void preProcess();
    void reverseSentence();
};
void ReverseWords::preProcess()
{  //removing the string from the front and back
   if(sentence[0] == ' ')
   {
       sentence=sentence.substr(1,sentence.size());
   }
   if(sentence[sentence.size()-1] == ' ')
   {
       sentence=sentence.substr(0,sentence.size()-1);
   }
}
void ReverseWords::reverseSentence()
{        string temp="";
       for(int j=0;j<sentence.size();j++)
       {
          if(sentence[j]!=' ')
          {
               temp+=sentence[j];
        }
        else
        {
            Words.push_back(temp);
            temp="";
         }
       }
    cout<<"These are all the words:"<<endl;
    for(auto word:Words)
    {
        cout<<word<<"\t";
    }
    string reverse="";
    for(int i=Words.size()-1;i>=0;i--)
    {
        reverse=reverse+Words[i];
        reverse+=" ";
    }
    cout<<"This is the reversed string:\n ";
    cout<<reverse<<endl;
}
int main()
{
    ReverseWords R;
    R.sentence = " Roopa ki maa ka bhosda Remya ki bhi maa ka bhosda Nie ki bhi maa ka bhosda VTU ki bhi maa ka bhosda ";
    cout<<"This is the original sentence: \n";
    cout<<R.sentence<<endl;
    R.reverseSentence();
    return 0;
}