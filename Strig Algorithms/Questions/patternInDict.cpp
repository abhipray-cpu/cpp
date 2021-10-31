//we need to confirm that pattern exists in the trie
//then traverse the entire subtree belonging to that pattern
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
    vector<string>pattern;//this vector will store all the matching pattern words
    void insert(string text);//this function will insert the text
    Node *insertChar(char ch,Node *root,bool Isend); //this function will be util function that will insert the character
    Node *getNewNode(char ch);// this function will give a new node to work with
    Node *search(string text,Node *root,int counter);
    void findPattern(string Pattern);//this function will return the pointer to the last character node of the pattern
    void traverse(string prefix,Node *root);
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

void Trie::findPattern(string Pattern)
{
    Node *temp=search(Pattern,root,0);//this will return the pointer pointing to the last character node of the pattern
    //next we need to travers the sub trie
    if(temp != NULL)
    {
        cout<<"The prefix pattern exists searching for all the coressponding patterns now: \n";
        if(temp->isEndOfString == true)
        {
            pattern.push_back(Pattern);
            traverse(Pattern,temp);
        }
        else
        traverse(Pattern,temp);
        
    }
    else
    cout<<"The prefix pattern does not exists in the trie \n";
}
void Trie::traverse(string Prefix,Node *root)
{
     vector<char>characters={'a', 'b', 'c', 'd', 'e','f','g', 
'h', 'i', 'j', 'k', 'l', 'm', 'n','o',
'p', 'q', 'r', 's', 't', 'u','v','w','x','y','z',' '};
   for(auto ch:characters)
   {
       if(root->Children[ch]!=NULL)
   {       string word = Prefix+ch;
       if(root->Children[ch]->isEndOfString==true)
       {
           pattern.push_back(word);
           cout<<"Entering the word: "<<word<<endl;
       }
       else
       {
           traverse(word,root->Children[ch]);
       }
   }
   }
}
int main()
{
    Trie T;
    T.root=T.getNewNode('*');
    vector<string>Words={"make","man","mammal","mac","mars","mass"};
for(auto word:Words)
{
    T.insert(word);
}
T.findPattern("ma");
return 0;
}