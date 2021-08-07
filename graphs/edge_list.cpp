#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct Directed_unweighted_edge
{
    int  startVertex;
    int endVertex;
};
struct Directed_weighted_edge
{
      int startVertex;
      int endVertex;
      int weight;
};
struct Undirected_unweighted_edge
{
      int *startIndex;
      int *endIndex;
};
struct Undirected_weighted_edge
{
     int startIndex;
     int endIndex;
     int weight;
};

void create_Directed_weighted_graph()
{
  vector<int>Vertex;
  for(int i=0;i<12;i++)
  {
      Vertex.push_back(i);
  }

  vector<Directed_weighted_edge*>Edge;
  Directed_weighted_edge *newEdge1=new Directed_weighted_edge;
  Directed_weighted_edge *newEdge2=new Directed_weighted_edge;
  Directed_weighted_edge *newEdge3=new Directed_weighted_edge;
  Directed_weighted_edge *newEdge4=new Directed_weighted_edge;
  Directed_weighted_edge *newEdge5=new Directed_weighted_edge;
  Directed_weighted_edge *newEdge6=new Directed_weighted_edge;
  Directed_weighted_edge *newEdge7=new Directed_weighted_edge;
  newEdge1->startVertex=0;
  newEdge1->endVertex=1;
  newEdge1->weight=2;
  Edge.push_back(newEdge1);
  newEdge2->startVertex=1;
  newEdge2->endVertex=2;
  newEdge2->weight=3;
  Edge.push_back(newEdge2);
  newEdge3->startVertex=2;
  newEdge3->endVertex=3;
  newEdge3->weight=4;
  Edge.push_back(newEdge3);
  newEdge4->startVertex=3;
  newEdge4->endVertex=4;
  newEdge4->weight=5;
  Edge.push_back(newEdge4);
  newEdge5->startVertex=4;
  newEdge5->endVertex=5;
  newEdge5->weight=6;
  Edge.push_back(newEdge5);
  newEdge6->startVertex=5;
  newEdge6->endVertex=6;
  newEdge6->weight=7;
  Edge.push_back(newEdge6);
  newEdge7->startVertex=6;
  newEdge7->endVertex=7;
  newEdge7->weight=8;
  Edge.push_back(newEdge7);

  cout<<"These are all the vertexes present in our graph"<<endl;
  for(int i=0;i<12;i++)
  {
      cout<<Vertex[i]<<"\t";
  }
  cout<<endl;
  cout<<"These are the edges present in our graph \n";
  for(int i=0;i<7;i++)
  {
    cout<<Edge[i]->startVertex<<"\t"<<Edge[i]->endVertex<<"\t"<<Edge[i]->weight<<endl;
}


}

int main()
{
   create_Directed_weighted_graph();
   return 0;

}
