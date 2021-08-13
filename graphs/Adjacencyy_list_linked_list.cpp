#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    int weight;
    int edge_count;
};

class Adjacency_list
{
    public:
    vector<Node*>Edges;
    void insert_Neighbour(int head,int neighbour,int weight);
    void find_neighbours();
    void display();
    Node *get_newNode(int data);
};


void Adjacency_list::display()
{
   cout<<"Your graph contains "<<Edges.size()<<" number of verteices"<<endl;
   int Edge_count=0;
   for(int i=0;i<Edges.size();i++)
   {
       int number=Edges[i]->edge_count;
       Edge_count+=number;
   }
   cout<<"Your graph contains "<<Edge_count<<" number of edges"<<endl;
   cout<<"This is a summary of the edges in your graph \n";
    for(int i=0;i<Edges.size();i++)
    {
       cout<<"Edge: "<<Edges[i]->data<<endl;
       Node *curr=Edges[i];
       Node *temp=curr;
       cout<<"Edge:"<<"\t \t"<<"Associated Weight"<<endl;
       while(temp != NULL)
       {
           int end=0;
           if(temp->next !=NULL)
           {
               end=temp->next->data;
               cout<<curr->data<<"-->"<<end<<"\t \t"<<temp->weight<<endl;
           }
           temp=temp->next;
       
       }

       cout<<endl;
    }

}
Node* Adjacency_list::get_newNode(int data)
{
    Node * newNode= new Node;
    newNode->data = data;
    newNode->next = NULL;
    newNode->weight = 0;
    newNode->edge_count = 0;
    return newNode;

}
int main()
{
    Adjacency_list List;
    auto Edge1=List.get_newNode(1);
    auto Edge2=List.get_newNode(2);
    auto Edge3=List.get_newNode(3);
    auto Edge4=List.get_newNode(4);
    auto Edge5=List.get_newNode(5);
    auto Edge6=List.get_newNode(6);
    auto Edge7=List.get_newNode(7);
    auto Edge8=List.get_newNode(8);
    auto Edge9=List.get_newNode(9);
    auto Edge10=List.get_newNode(10);
    List.Edges.push_back(Edge1);
    List.Edges.push_back(Edge2);
    List.Edges.push_back(Edge3);
    List.Edges.push_back(Edge4);
    List.Edges.push_back(Edge5);
    List.Edges.push_back(Edge6);
    List.Edges.push_back(Edge7);
    List.Edges.push_back(Edge8);
    List.Edges.push_back(Edge9);
    List.Edges.push_back(Edge10);
    List.display();
    Node *newNode = new Node;
    newNode->data =2;
    newNode->weight =0;
    newNode->next=NULL;
    Edge1->next=newNode;
    Edge1->weight =3;
    Node *temp=Edge1;
    List.display();
    
}