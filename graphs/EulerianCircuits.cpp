/*
A path which visits all the nodes this is a primary condition
if the number of vertces with odd degress in the above satisfied condition is:
a)>2 than the graph is neither eulerian cycle not eulerian path
b)=2 than the graph is eulerian path/semi eulerian
c)=0 than the graph is eulerian cycle/eulerian

the degree can never be 1 in this case

*/
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
    vector<int>get_neighbour_data(Node *start);
    void findEulerian();
    bool isConnected();


};
void Adjacency_list::findEulerian(){
    if(!isConnected())
    {
        cout<<"The graph is not connected manjhe ther is not path that vists all the nodes"<<endl;
    }
    else
    {
        int odd = 0;
    for(int  i=0;i<Edges.size();i++)
    {
        if(get_neighbour_number(Edges[i]) > 0)
        {
            odd++;
        }
    }
    if(odd >2)
    {
        cout<<"The graph is connected but it is not eulerian since it has "<<odd<<" number of vertices with non zero degree"<<endl;

    }
    else if(odd == 2)
    {
        cout<<"This grpah contains an euleran path "<<endl;
    }
    else if(odd == 0)
    {
        cout<<"This graph contains an eulerian cycle"<<endl;
    }
    }
}

bool Adjacency_list::isConnected(){
    map<int,bool>Visited;
    for(int i=0;i<Edges.size();i++)
    { 
       Visited[i]=false ; 
    }
    int i=0;
    Node *start;
    for(int i=0;i<Edges.size();i++)
    {
        if(get_neighbour_number(Edges[i])>0)
        {

           start = Edges[i];
            break;
        }
    }
    if(i == Edges.size()-1)
    return true;
    queue<Node*>Q;
    Q.push(start);
    start->visited=true;
    while(!Q.empty())
    {
        Node *front = Q.front();
        Q.pop();
        auto neighbours = get_neighbour_data(front);
        for(int i=0;i<neighbours.size();i++)
        {
            Node *temp = find_vertice(neighbours[i]);
            if(temp->visited == false)
            {
                temp->visited=true;
                Q.push(temp);
            }
        }
    }

    // Checking the visited status of all the nodes
    for(int i=0;i<Edges.size();i++)
    if(Edges[i]->visited == false && get_neighbour_number(Edges[i]) == 0)
      return false;

    return true;
    
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
    List.findEulerian();
 
    
    return 0;
}