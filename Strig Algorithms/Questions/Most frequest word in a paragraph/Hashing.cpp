#include<bits/stdc++.h>
using namespace std;
typedef long long L;

class Frequent
{
    public:
    int baseValue=10;
    string Paragraph;
    map<string,int>HashTable;//this is the string and frequency table
    vector<string>Words;
    void preprocessParagraph();
    void MostFrequentWord();
    L RabinKarpHash(string Text);
};
void Frequent::preprocessParagraph()
{  
    vector<string>Lines;
    string substr="";
    int last=0;
    for(int i=0;i<Paragraph.size();i++)
    {
        if(Paragraph[i] != '\n')
        {
            substr+=Paragraph[i];
        }
        else
        { 
             Lines.push_back(substr);
             last=i;
             substr="";
        }
    }
    Lines.push_back(Paragraph.substr(last+1,Paragraph.size()));
     //these are the preprocessed Lines;
     for(int i=0;i<Lines.size();i++)
     {
         cout<<"Line "<<i+1<<") "<<Lines[i]<<endl;
     }

     //in the second step will trim the lines to remove all the extra spaces
      for(int i=0;i<Lines.size();i++)
     {
        if(Lines[i][0]==' ')
        {
            Lines[i]=Lines[i].substr(1,Lines[i].size());
        }
        
     }
     cout<<"This is the second phase preprocessed lines: \n";
     for(int i=0;i<Lines.size();i++)
     {
         cout<<"Line "<<i+1<<") "<<Lines[i]<<endl;
     }
     //this is the second phase of the preprocessing where all the words will be extracted from all the lines
    for(int i=0;i<Lines.size();i++)
   {
       //extracting the words
       string temp="";
       for(int j=0;j<Lines[i].size();j++)
       {
          if(Lines[i][j]!=' ')
          {
               temp+=Lines[i][j];
        }
        else
        {
            Words.push_back(temp);
            temp="";
         }
       }
    }
  //this is the last phase of preprocessing where all the spaces will be remove from the word
  for(auto word:Words)
  {
      word.erase(remove(word.begin(), word.end(), ' '), word.end());
  }
  cout<<"These are the final words in our list: \n";
  for(int i=0;i<Words.size();i++)
  {
      cout<<Words[i]<<",";
      if(i%10==0)
      {
          cout<<endl;
      }
  }
}
L Frequent::RabinKarpHash(string text)
{
    int size = text.size();
   long long sum = 0; //since we will be using high power values therefore use long long
   for(int i=0;i<text.size();i++)
   {
       sum=sum+((int)text[i])*pow(baseValue,size-1);
       size = size-1; //since for next character the power value will be one less
       
   }
   return sum;
}
void Frequent::MostFrequentWord()
{
   //design thi code to find the most frequent word
   int maxFrequency=0;
   string frequent="";
   for(auto word:Words)
   {  //the word exists in the hash table
       if(HashTable.find(word) != HashTable.end())
       {
           HashTable[word]+=1;//will increase the frequency count by 1
           if(HashTable[word]>maxFrequency)
           {
               maxFrequency=HashTable[word];
               frequent=word;
           }
       }
       else//the word does not exists in the hash table
       {
           HashTable[word]=1;
       }
   }
   cout<<"The most frequent word in the paragraph: "<<frequent<<endl;
   cout<<"The frequency is: "<<maxFrequency<<endl;
}
int main()
{
    Frequent F;
    F.Paragraph="Teri maa ka bhosda \n Teri behen ka bhosda \n Teri beti ka bhosda \n Roopa ki maa ka bhosda \n Teri dadi ka bhosda ";
    cout<<"This is the paragraph: "<<F.Paragraph<<endl;
    F.preprocessParagraph();
    F.MostFrequentWord();
    return 0;
}