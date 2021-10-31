#include<bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    bool isEndOfString;
    bool visited=false;
    map<char,Node*>Children;
};
class Trie
{
    public:
    Node *root=NULL;
    void insert(string text);//this function will insert the text
    Node *insertChar(char ch,Node *root,bool Isend); //this function will be util function that will insert the character
    Node *getNewNode(char ch);// this function will give a new node to work with
    Node *search(string text,Node *root,int counter);
    void findNext(string word);
    void traverse(string word,Node *root,string search);//this function is the util function which will serve for the nexr word in the dictionary
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

Node* Trie::search(string text,Node *root,int counter)
{
  char ch = text[counter];
  if(root->Children[ch]!=NULL)
  {  root->Children[ch]->visited=true;
    if(counter == text.size()-1)
    {
    return root->Children[ch];
  }
    else
    return search(text,root->Children[ch],++counter);
  }
  else
  cout<<"The string is not present in the trie"<<endl;
  return root;
}
void Trie::findNext(string text)
{
   for(int i=text.size();i>=0;i--)
   {  //this will scan the word from right to left in the trie
       text=text.substr(0,i);
       Node *pointer = search(text,root,0);
       traverse(text,pointer,text);
   }
}
//this function will traverse the subtree till a node is encountered for which end of string is set to 1;
void Trie::traverse(string text,Node *root,string search)
{
   vector<char>characters={'a', 'b', 'c', 'd', 'e','f','g', 
'h', 'i', 'j', 'k', 'l', 'm', 'n','o',
'p', 'q', 'r', 's', 't', 'u','v','w','x','y','z',' '};
for(auto ch:characters)
{
    if(root->Children[ch]!=NULL &&root->Children[ch]->visited==false)
    {   text=text+ch;
        if(root->Children[ch]->isEndOfString == true)
        { 
          
            cout<<"The next word is found: "<<text<<endl;
            break;

        }
        
        else
        {
            traverse(text,root->Children[ch],search);
            break;
        }
        
    }
}
}
int main()
{
    Trie T;
    T.root=T.getNewNode('*');
    vector<string>Words={"the","at","there","some","my"
"of","be","use","her","than","and","this","an","would","first"
"a","have","each","make","water","to","from","which","like","been","in","or"
,"she","him","call","is","one","do","into","who","you","had","how","time","oil",
"that","by","their","has","its","it","word","if","look","now","he","but","will","two"
,"find","was","not","up","more","long","for","what","other","write","down","on","all",
"about","go","day","are","were","out","see","did","as","we","many","number","get",
"with","when","then","no","come","his","your","them","way","made",
"they","can","these","could","may","I","said","so","80" ,"people","part"};
for(auto word:Words)
{
    T.insert(word);
}
T.findNext("into");
return 0;
}