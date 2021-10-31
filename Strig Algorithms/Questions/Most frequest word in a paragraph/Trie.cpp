//this code file will implement trie that is time efficient but is not memmory efficient

#include<bits/stdc++.h>
using namespace std;
//this is the trie node that will be implemented in this code
struct Node
{
   char data;
   bool isEndOfString;
   map<char,Node*>Children;//since we require 26 nodes to reperent the 26 alphabets
};
class Trie
{
    public:
    map<string,int>Record;//this will keep the record of frequenct coressponding to a given word
    Node *root=NULL;
    string Paragraph="";
    vector<string>Words;
      void insert(string text);//this function will insert the text
    Node *insertChar(char ch,Node *root,bool Isend); //this function will be util function that will insert the character
    Node *getNewNode(char ch);// this function will give a new node to work with
    void preprocessParagraph();
    void MostFrequentWord();
    bool search(string text,Node *root,int counter);
};

Node *Trie::getNewNode(char ch)
{
  Node *newNode = new Node;
  newNode->data = ch;
  newNode->isEndOfString =false;
  //assigninh null values to all the children
  newNode->Children[' ']=NULL;
  newNode->Children['a']=NULL;
  newNode->Children['b']=NULL;
  newNode->Children['c']=NULL;
  newNode->Children['d']=NULL;
  newNode->Children['e']=NULL;
  newNode->Children['f']=NULL;
  newNode->Children['g']=NULL;
  newNode->Children['h']=NULL;
  newNode->Children['i']=NULL;
  newNode->Children['j']=NULL;
  newNode->Children['k']=NULL;
  newNode->Children['l']=NULL;
  newNode->Children['m']=NULL;
  newNode->Children['n']=NULL;
  newNode->Children['o']=NULL;
  newNode->Children['p']=NULL;
  newNode->Children['q']=NULL;
  newNode->Children['r']=NULL;
  newNode->Children['s']=NULL;
  newNode->Children['t']=NULL;
  newNode->Children['u']=NULL;
  newNode->Children['v']=NULL;
  newNode->Children['w']=NULL;
  newNode->Children['x']=NULL;
  newNode->Children['y']=NULL;
  newNode->Children['z']=NULL;
  return newNode;
  }

    
bool Trie::search(string text,Node *root,int counter)
{
  char ch = text[counter];
  if(root->Children[ch]!=NULL)
  {
    if(counter == text.size()-1)
    {cout<<"The word exists \n";
    return true;}
    else
     return search(text,root->Children[ch],++counter);
  }
  else
cout<<"The word does not exists \n";
  return false;
}
void Trie::insert(string text)
{  Node *temp  = root;
  for(int i=0;i<text.size();i++)
  {
     //this will save time since we will already be in the last
      //node where the last word was placed and need not to traverse again
      if(i == text.size()-1)
       temp=insertChar(text[i],temp,1); //if this the last character we will end the string by assigning 1
       else
        temp=insertChar(text[i],temp,0);//else we will be assigning 0 to all the nodes
  }
}

Node* Trie::insertChar(char ch,Node *root,bool Isend)
{                           
        //the character does not exists yet 
        if(root->Children[ch] == NULL) 
        {
             Node *newNode = getNewNode(ch);
             if(Isend == 1)
             newNode->isEndOfString = true;
             root->Children[ch] = newNode;
             return newNode;
        }   
        // we will iterate through the trie to find the next empty spot  
        else
        {
            return root->Children[ch];
            //this will simpy point to the node in succession
        }  

}
void Trie::MostFrequentWord()
{
    //in this code if the word exists increase it's frequency and update the record
    // if the word does not exists simply insrt it and then co
}
void Trie::preprocessParagraph()
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
int main()
{
    Trie T;
    T.Paragraph="Teri maa ka bhosda \n Teri behen ka bhosda \n Teri beti ka bhosda \n Roopa ki maa ka bhosda \n Teri dadi ka bhosda ";
    cout<<"This is the paragraph: "<<T.Paragraph<<endl;
    T.preprocessParagraph();
    T.MostFrequentWord();


    return 0;
}