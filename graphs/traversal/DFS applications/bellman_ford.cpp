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
    int get_cost(Node *Start,int child);
    vector<int>get_neighbour_data(Node *start);
    void bellmanFord(Node *start);

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
int Adjacency_list::get_cost(Node *Start,int child)
{
    
    while(Start->next->data != child)
    {
        Start=Start->next;
    }
  return Start->weight;
}

void Adjacency_list::bellmanFord(Node *start)
{
    int count = Edges.size();
    map<Node*,int>Weight;
    for(int i=0;i<Edges.size();i++)
    {
        Node *temp = Edges[i];
        Weight[temp] = INT_MAX;
    }
    Weight[start]=0;
    for(int i=0;i<count;i++)
    {   map<Node*,bool>Visited;
        for(int i=0;i<Edges.size();i++)
        {
            Visited[Edges[i]]=false;
        }
        Visited[start] = true;
        
        queue<Node*>Q;
        Q.push(start);
        while(! Q.empty())
        {
            Node *front = Q.front();
            Q.pop();
            auto neighbours = get_neighbour_data(front);
            for(int j=0;j<neighbours.size();j++)
            {
                Node *temp = find_vertice(neighbours[j]);
                if(Visited[temp] == false)
                {
                   Visited[temp] = true;
                   int cost = get_cost(front,temp->data);
                   int curr_weight = Weight[temp];
                   int parentWeight = Weight[front];
                   int newWeight = parentWeight+cost;
                   if(newWeight<curr_weight)
                   {
                       Weight[temp]=newWeight;
                       Q.push(temp);
                   }
                   else
                   {
                       Q.push(temp);
                   }

                }
            }

        }
    }
    cout<<"Edge"<<"\t \t"<<"Distance \n";
    for(int i=0;i<Edges.size();i++)
    {
        cout<<start->data<<"-->"<<Edges[i]->data<<"\t \t"<<Weight[Edges[i]]<<endl;
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
    
    List.add_edge(1,2,6);
    List.add_edge(1,4,5);
    List.add_edge(1,3,5);
    List.add_edge(2,5,-1);
    List.add_edge(3,5,1);
    List.add_edge(3,2,-2);
    List.add_edge(4,3,-2);
    List.add_edge(4,6,-1);
    List.add_edge(5,7,3);
    List.add_edge(6,7,3);
    
    //List.display();
    List.bellmanFord(List.find_vertice(1));
    
    return 0;
}