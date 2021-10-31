//using a bst and Rabin karp hash as value to decide the node in which the string should go

#include<bits/stdc++.h>
using namespace std;
typedef long long L;


struct Node
{
  string text;
  L hashValue;
  Node *left;
  Node *right;
};
class BSTAndStore
{
   public:
   Node *root=NULL; //this is the root node that will be overwritten once strings are added
   int baseValue = 10;
   vector<pair<string,L>>Pairs; //this is a pair containing the string and it's coressponfing hash value that 
   //will decide the position of node the string will be stored in the BST
   Node *getNewNode(string text,L hashValue);
   Node* insert(string text,L hashvalue,Node *root);//will insert in node based on the hash value of the string
   void search(string text,L hashValue,Node *root);
   void displayBST(Node *root);
   L RabinKarpHash(string text);
   bool stringMathches(string str1,string str2);
};

Node* BSTAndStore::getNewNode(string text,L hashValue=10000)//assigning 10000 t0 maintain some sort of uniform distribution in the tree
{
       Node *newNode = new Node;
       newNode->text = text;
       newNode->hashValue=hashValue;
       newNode->left = newNode->right=NULL;
       return newNode;
}
L BSTAndStore::RabinKarpHash(string text)
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
Node* BSTAndStore::insert(string text,L hashValue,Node *root)
{
          //if root is empty 
          if(root == NULL)
          {
              root=getNewNode(text);
          }
          else if(hashValue <= root->hashValue)
          {
              root->left= insert(text,hashValue,root->left);
          }
          else if (hashValue > root->hashValue)
          {
              root->right= insert(text,hashValue,root->right);
          }
          return root;
}

void BSTAndStore::search(string text,L hashValue,Node *root)
{
  //in this function do a binary search and if the hash matches then check for string
  if(root->hashValue == hashValue)
  { 
      if(stringMathches(text,root->text) == 1)
    cout<<"The string is found in the BST \n";
    else
    cout <<"No match found for the string \n";
  }
  //search in the left subtree
  else if(root->hashValue<hashValue)
  {
   search(text,hashValue,root->left);
  }
  //search in the right subtree
  else if(root->hashValue>hashValue)
  { 
     search(text,hashValue,root->right);
  }
}
bool BSTAndStore::stringMathches(string str1,string str2)
{
     if(str1.size()!= str2.size())
     {
         return false;
     }
     else
     {
         for(int i=0;i<str1.size();i++)
         {

             if(str1[i] == str2[i])
             {
                 continue;
             }
             else
             {
                 return false;
                 break;
             }
         }
         return true;
     }
}
//let's do the inorder traversal and display the strings
void BSTAndStore::displayBST(Node *root)
{
      if(root==NULL)
      return;
      displayBST(root->left);
      cout<<root->text<<endl;
      displayBST(root->right);
}
int main()
{
    BSTAndStore Bs;
    vector<string>Store={"Roopa","Ki","Maa","Ka","Bhosda","Tum","Sabki","Bhi","Maa","ka","bhosda","Tum","Sabki",
    "Baba","Ram dev","Ki","Rakhel","Ka","Bhosda"};
    //creating the string and coresponding Hash value
    for(int i=0;i<Store.size();i++)
    {
        L hashValue = Bs.RabinKarpHash(Store[i]);
        Bs.Pairs.push_back(make_pair(Store[i],hashValue));
    }
    cout<<"These are all the key values pairs that we got \n";
    for(int i=0;i<Bs.Pairs.size();i++)
    {
        cout<<"String: "<<Bs.Pairs[i].first<<"\t"<<"Hash value: "<<Bs.Pairs[i].second<<endl;
    }
    cout<<"**************** INSERTING THE VALUES IN THE BST ************************************* \n";
     //if you don't want a skewed tree you can also sort the pairs based on the hash values
     //first and then start building the tree recursivley starting from the middle element
     for(int i=0;i<Bs.Pairs.size();i++)
    {     
         //inserting the values
         if(i==0)
        Bs.root= Bs.insert(Bs.Pairs[i].first,Bs.Pairs[i].second,Bs.root); //ye bs q karna hota hai muhje?
        else
         Bs.insert(Bs.Pairs[i].first,Bs.Pairs[i].second,Bs.root);

    }
    cout<<"These are all the string in the BST displaying using BST \n";
    Bs.displayBST(Bs.root);
    Bs.search("Roopa",943316,Bs.root);
    return 0;
}