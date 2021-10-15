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
    vector<int>Levelorder_traversal; //this will be used in the bfs
    Node *get_newNode(int data);
    void add_edge(int start_index,int end_index,int weight);
    Node *find_vertice(int index);
    void insert_At_end(Node *start,Node *end,int weight);
    void display();
    int get_neighbour_number(Node *root);
    vector<int> performBFS_traversal(int start_index,int end_index);
    void construct_tree(vector<int>traversed_list);
    vector<int>get_neighbour_data(Node *start);
    void shortest_path(Node *start);
    // since we have the same data as index in this case therefore no such issue
    // in case data and index is not same we can use an additional feature of index in the node structure

};
void Adjacency_list::shortest_path(Node *start)
{
    //pair is in order of distance and path
  map<int,pair<int,int>>Element;
  for(int i=0;i<Edges.size();i++)
  {
      auto data = make_pair(-1,-1);
      Element.insert(make_pair(i,data));
  }
  auto initial = make_pair(0,0);
  Element[start->data]=initial;
  queue<Node*>Q;
  start->visited = true;
  Q.push(start);

  while(!Q.empty())
   {
      Node *temp = Q.front();
      Q.pop();
      vector<int> neighbors = get_neighbour_data(temp);
      for(int i=0;i<neighbors.size();i++)
      {
          Node *curr = find_vertice(neighbors[i]);
          if(curr->visited == false)
          {
              curr->visited == true;
              Q.push(curr);
              if(Element[curr->data].first == -1)
              {
                  if(Element[temp->data].first == 0)
                  {
                            Element[curr->data].first = 1;
                            Element[curr->data].second = temp->data;
                  }
                  else
                  {
                      Element[curr->data].first = Element[temp->data].first+1;
                            Element[curr->data].second = temp->data;
                  }
              }

          }
      }
   }
   cout<<Element[3].first<<"\t"<<Element[3].second<<endl;

}


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
vector<int> Adjacency_list::performBFS_traversal(int start_index,int end_index)
{
   Node *start= find_vertice(start_index);
   Node *end= find_vertice(end_index);
   list<Node *>queue;
   start->visited=true;
   queue.push_back(start);
   while(!queue.empty())
   {
       Node *front=queue.front();
       queue.pop_front();
       cout<<front->data<<"\t"<<front->visited<<endl;
       Levelorder_traversal.push_back(front->data);
       if(front->data == end->data) // we will return the found traveled path and will resete all the variables and containers as well
       {  
           cout<<"The end statement is reached \n";
           for(int i=0;i<Levelorder_traversal.size();i++)
           {
               Node *found = find_vertice(Levelorder_traversal[i]);
               found->visited=false;
               vector<int>found_list=Levelorder_traversal;
               Levelorder_traversal.clear();
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
                   queue.push_back(vertice);
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
    
    List.add_edge(7,1,1);
    List.add_edge(7,4,1);
    List.add_edge(1,2,1);
    List.add_edge(1,3,1);
    List.add_edge(2,3,1);
    List.add_edge(2,6,1);
    List.add_edge(3,4,1);
    List.add_edge(3,5,1);
    List.add_edge(6,5,1);
    List.add_edge(5,4,1);
    List.display();
    List.shortest_path(List.find_vertice(7));
    
    return 0;
}