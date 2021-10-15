//THis is the minimum number of unique colors with which a graph/map can be colored;
//we can also find whether a graph can be colored with a given number of colors or not
// if the given number of colors > chromatic number then yes the graph can be colored
#include<iostream>
using namespace std;
int ChromaticIndex(int ed[][3], int e) {
   int i, c, j, max = -1;
   //to assign a valid color to every edge 'i'.
   for(i = 0; i < e; i++) {
      c = 1;
      flag:
         //assign color to current edge
         ed[i][2] = c;
         for(j = 0; j < e; j++) {
            if(j == i)
               continue;
               //Check the colors of the edges adjacent to the edge i.
               if(ed[j][0] == ed[i][0] || ed[j][0] == ed[i][1] || ed[j][1] == ed[i][0] || ed[j][1] == ed[i][1]) {
                  if(ed[j][2] == ed[i][2]) {
                     c++;
                     goto flag;
                  }
               }
         }
   }
   // Find the coloring index and return it
   for(i = 0; i < e; i++) {
      if(max < ed[i][2])
         max = ed[i][2];
   }
   return max;
}
int main() {
   int i, v, e, j, max = -1;
   cout<<"Enter the number of vertices of the graph: ";
   cin>>v;
   cout<<"Enter the number of edges of the graph: ";
   cin>>e;
   int ed[e][3];
   for(i = 0; i < e; i++) {
      cout<<"\nEnter the vertex pair for edge "<<i+1;
      cout<<"\nV(1): ";
      cin>>ed[i][0];
      cout<<"V(2): ";
      cin>>ed[i][1];
      ed[i][2] = -1;
   }
   cout<<"\n\nThe chromatic index of the given graph is: "<<ChromaticIndex(ed , e);
   for(i = 0; i < e; i++)
      cout<<"\nThe color of the edge between vertex n(1):"<<ed[i][0]<<" and n(2):"<<ed[i][1]<<" is: color"<<ed[i][2]<<".";
      return 0;
}