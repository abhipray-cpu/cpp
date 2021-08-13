// we will use queue for the purpose of traversal in this case
#include<bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  int weight;
  Node *next;
  bool visited;
};

class Adjacency_list
{ 
    public:
    vector<Node*>Edges;
    vector<int>Preorder_traversal; //this will be used in the bfs
    Node *get_newNode(int data);
    void add_edge(int start_index,int end_index,int weight);
    Node *find_vertice(int index);
    void insert_At_end(Node *start,Node *end,int weight);
    void display();
    int get_neighbour_number(Node *root);
    vector<int> performDFS_traversal(int start_index,int end_index);
    void construct_tree(vector<int>traversed_list);
    vector<int>get_neighbour_data(Node *start);

};
vector<int> Adjacency_list::get_neighbour_data(Node *start)
{
    vector<int>data;
    start=start->next;
    while(start != NULL)
    {
        data.push_back(start->data);
        start=start->next;
    }
    return data;

}
vector<int> Adjacency_list::performDFS_traversal(int start_index,int end_index)
{
   Node *start= find_vertice(start_index);
   Node *end= find_vertice(end_index);
   stack<Node*>S;
   start->visited=true;
   S.push(start);
   while(!S.empty())
   {
       Node *front=S.top();
       S.pop();
       cout<<front->data<<"\t"<<front->visited<<endl;
       Preorder_traversal.push_back(front->data);
       if(front->data == end->data) // we will return the found traveled path and will resete all the variables and containers as well
       {  
           cout<<"The end statement is reached \n";
           for(int i=0;i<Preorder_traversal.size();i++)
           {
               Node *found = find_vertice(Preorder_traversal[i]);
               found->visited=false;
               vector<int>found_list=Preorder_traversal;
               Preorder_traversal.clear();
               return found_list;

           }
           break;
           
       }
       else
       {
           vector<int>neighbours = get_neighbour_data(front);
           for(int i=0;i<neighbours.size();i++)
           {
               Node *vertice = find_vertice(neighbours[i]);
               if(vertice->visited == false)
               {
                   vertice->visited = true;
                   S.push(vertice);
               }
           }
       }
       
      
   }
}

void Adjacency_list::construct_tree(vector<int>traversed_list)
{
    cout<<"This is the path the algorithm traversed to go from starting node to the end node \n";
    for(int i=0;i<traversed_list.size();i++)
    {
        cout<<traversed_list[i]<<"-->";
    }

}
Node *Adjacency_list::get_newNode(int data)
{
    Node *newNode=new Node;
    newNode->data=data;
    newNode->visited=false;
    newNode->next=NULL;
    newNode->weight=0;
    return newNode;
}
Node *Adjacency_list::find_vertice(int index)
{
    if(index >0 && index < Edges.size())
    {
        return Edges[index-1];
    }
    else
    return NULL;
}
void Adjacency_list::insert_At_end(Node *start,Node *end,int weight)
{
    Node *temp=start;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next=end;
    temp->weight=weight;
}
void Adjacency_list::add_edge(int start_index,int end_index,int weight)
{
       Node *start=find_vertice(start_index);
       Node* end=get_newNode(end_index);
       insert_At_end(start,end,weight);
       
}
int Adjacency_list::get_neighbour_number(Node *root)
{
    int count =0;
    Node *temp=root;
    while(temp->next != NULL)
    {
       count=count+1;
       temp=temp->next;
    }
    return count;
}
void Adjacency_list::display()
{
    cout<<"Your graph contains "<<Edges.size()<<" number of vertices \n";
    int edge_count=0;
    for(int i=0;i<Edges.size();i++)
    {
        Node *root=Edges[i];
        int neighbour=get_neighbour_number(root);
        edge_count+=neighbour;
    }
    cout<<"There are "<<edge_count<<" number of edges in your graph \n";
    cout<<";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; \n";
          
    cout<<"Edge"<<"\t \t"<<"Weight \n";
    for(int i=0;i<Edges.size();i++)
    {
        Node *temp=Edges[i];
        if(get_neighbour_number(temp)>0)
        {
            while(temp->next != NULL)
            {
                cout<<Edges[i]->data<<"-->"<<temp->next->data<<"\t \t"<<temp->weight<<endl;
                temp=temp->next;
            }
        }
    }

}
int main()
{
    Adjacency_list List;
    for(int i=1;i<=100;i++)
    {
        auto Vertice=List.get_newNode(i);
        List.Edges.push_back(Vertice);    
    }
    
    List.add_edge(1,2,2);
    List.add_edge(2,3,2);
    List.add_edge(3,4,2);
    List.add_edge(4,5,2);
    List.add_edge(5,6,2);
    List.add_edge(6,7,2);
    List.add_edge(7,8,2);
    List.add_edge(5,7,2);
    List.add_edge(5,47,2);
    List.add_edge(5,37,2);
    List.add_edge(5,17,2);
    List.add_edge(5,27,2);
    List.add_edge(5,77,2);
    List.add_edge(5,67,2);
    List.add_edge(5,79,2);
    List.display();
    vector<int> traversed_list=List.performDFS_traversal(1,8);
    List.construct_tree(traversed_list);
    
    return 0;
}