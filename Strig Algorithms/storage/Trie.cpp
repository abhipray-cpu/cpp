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
    Node *root=NULL;
    void insert(string text);//this function will insert the text
    Node *insertChar(char ch,Node *root,bool Isend); //this function will be util function that will insert the character
    Node *getNewNode(char ch);// this function will give a new node to work with
    void search(string text,Node *root,int counter);//this function will search for the string in the BST
    void TraverseTrie(Node *root);
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
//this function will simply traverse the tree
void Trie::TraverseTrie(Node *root)
{  vector<char>characters={'a', 'b', 'c', 'd', 'e','f','g', 
'h', 'i', 'j', 'k', 'l', 'm', 'n','o',
'p', 'q', 'r', 's', 't', 'u','v','w','x','y','z',' '};
      for(char ch:characters)
      {
        if(root->Children[ch] != NULL)
        {
          if(root->Children[ch]->isEndOfString == false)
          {
            cout<<ch<<"-->";
          }
          else
          {
            cout<<ch<<endl;
          }
          TraverseTrie(root->Children[ch]);
        }
      }
}
//this function will search for a word in the string
void Trie::search(string text,Node *root,int counter)
{
  char ch = text[counter];
  if(root->Children[ch]!=NULL)
  {
    if(counter == text.size()-1)
    cout<<"The string is present is the trie"<<endl;
    else
    search(text,root->Children[ch],++counter);
  }
  else
  cout<<"The string is not present in the trie"<<endl;

}

int main()
{
  Trie T;
   vector<string>Store={"roopa","ki","maa","ka","bhosda","tum","sabki","bhi","maa","ka","bhosda","tum","sabki",
    "baba","ram dev","ki","rakhel","ka","bhosda"};
    T.root=T.getNewNode('*');
    for(int i=0;i<Store.size();i++)
    {
      T.insert(Store[i]);
    }
    T.TraverseTrie(T.root); 
      //while searching we need to skip this root as well
    //this algo works for only lower case letters so first convert the string to lower case first
    //check for them
    T.search("baba",T.root,0);
    return 0;
}