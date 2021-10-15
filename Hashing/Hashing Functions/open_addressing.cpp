#include<bits/stdc++.h>
using namespace std;

//this is the list node
struct ListNode
{
   int data;
   ListNode *next;
};
//in this code our hashTable consits of a map which will map a hashed value to a linked

class OpenAddressing
{   
    public:
    int tableSize  = 1000;//defining a table size
    map<int,ListNode*>HashTable;
    int hashFunction(int value);//this function will return a hashed value
    void Insert(int value);//this function will be used to insert a value to the hash function 
    void hashSearch(int value); //this function will search for the value in the hash table 
    bool listSearch(ListNode*head,int value); //this will search for the value in the linked list
    void deleteValue(ListNode *head,int value); //this will delete the value from the list;
    void deletehash(int value); //this function will delete the entire linked list coressponding to the hash value
    void emptyList(ListNode *head); //this function will empty the list 
    //to rehash the table we need to implement a hash table of fixed size
    //when the load factor crosses a certain threshold we will simply double the size and then redistriubute the elements
    //these functions will give the new nodes
    ListNode *getNewListNode(int data);
    void listInsert(ListNode *head,int value);//this function will insert the value in the list
    void deleteHashedValue(int value);
    //ismei nhi kar rha rehash mei bc nayi sari list ki values nikalo phir unhe dubara hash apne se na ho paega
     bool RehashRequired();//this function will check whether rehash is required or not after every insertion
    void Rehash(); //this function will implement the rehashing of the hashtable

};

void OpenAddressing::Insert(int value)
{
    int hashVal = hashFunction(value);
    if(HashTable[hashVal])
    {   cout<<"The hash value already existst therefore inserting the value to the coressponding list \n";
        ListNode* List = HashTable[hashVal];//this will give the coressponding list to the hash value
        listInsert(List,value); //this function will add the new value with same hash to the end of the coressponding list
    }
    else
    {   cout<<"This is a new hash value and therefore creating a new list for the hash value \n";
        auto newList = getNewListNode(value);//creating a new list
        HashTable[hashVal] = newList;//inserting the newly created list to the hastable with the coressponding hash value 
    }
}
int OpenAddressing::hashFunction(int value)
{
    return (value*value)/1000;
}
ListNode* OpenAddressing::getNewListNode(int value) {
    ListNode *newNode = new ListNode;
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void OpenAddressing::listInsert(ListNode *head,int data)
{
    auto temp = head;
    ListNode *newNode = new ListNode;
    newNode->data = data;
    newNode->next=NULL;
    while(temp->next != NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
}
void OpenAddressing::hashSearch(int value)
{
    int hashVal = hashFunction(value);
    if(HashTable[hashVal])
    {  
        cout<<"The hash val exists and then searching it in the coresspondig list \n";
       ListNode *List = HashTable[hashVal];
       if(listSearch(List,value)) //this function will return a bool value based on whether the value was found in the list or not
       {
           cout<<"The value exists in the hashtable \n";
       } 
       else
       {   
           cout<<"The value was not found in the list \n";
       
       }
    }
    else
    {  
         cout<<"The value does not exists in the hash table and therefore not searchinh in the list \n";
    }
}
bool OpenAddressing::listSearch(ListNode *head,int value)
{
          ListNode *temp = head;
          while(temp != NULL)
          {
              if(temp->data == value)
              {
                  return true;
                  break;
              }
              temp = temp->next;
          }
          return false;
}
void OpenAddressing::deleteHashedValue(int value)
{
    int hashedValue = hashFunction(value);
    ListNode* List = HashTable[hashedValue];
    if(List)
    {
       cout<<"The list exists for the given hash function \n";
       deleteValue(List,value);
    }
    else{
        cout<<"The list doesn't exists for the given hash function \n";
    }
}
void OpenAddressing::deleteValue(ListNode *head,int value)
{
      //this function will delte the node ;
      ListNode *temp = head;
      while(temp->next->data != value)
      {
          temp = temp->next;
      }//this loop will stop at a point before the value to be deleted;
      auto del = temp->next;
      auto next = temp->next->next;
      temp->next = next;//joining new connection
      delete(del);//deleting the node from the memmory
      cout<<"The value is deleted from the list \n";
}
//this function will delete all the nodes from the list of nodes 
void OpenAddressing::emptyList(ListNode *head)
{
    ListNode *temp = head;
    while(temp != NULL)
    {
        auto del = temp;
        temp=temp->next;
        delete(del);
    }
}
void OpenAddressing::deletehash(int hashValue)
{
    ListNode * list = HashTable[hashValue];
    if(list)
    {
        cout<<"The list exists now clearing the coressponding list\n";
        emptyList(list);
        HashTable.erase(hashValue);//this will remove the entry
    }
    else
    {
        cout<<"The hash value does not existst \n";
    }
}
int main()
{
   OpenAddressing O;
   for(int i=1;i<1000;i++)
   {
       O.Insert(i);
   }
   cout<<"The size of the hashtable after insertion is "<<O.HashTable.size()<<endl;
   cout<<"Searching for a value that should be present let's say 69 \n";
   O.hashSearch(69);
   cout<<"Searching for a value that should not be present let's say 1169 \n";
   O.hashSearch(1169);
   O.deleteHashedValue(67);
    return 0;
}