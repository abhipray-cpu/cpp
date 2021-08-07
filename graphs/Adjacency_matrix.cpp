//this is for a unweighted graph
// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// int matrix[100][100];
// vector<pair<int,int>>Edges;
// // we are taking example for a non weighted graph
// void adjacency_matrix()
// {
//  for(int i=0;i<100;i++)
//    {
//        for(int j=0;j<100;j++)
//        {
//            matrix[i][j]=-1;
//        }
//    }
// }

// void display_matrix()
// {
//     cout<<"These is your initialzed matrix \n";
//     for(int i=0;i<100;i++)
//     {
//         for(int j=0;j<100;j++)
//         {
//             cout<<matrix[i][j]<<"\t";
//         }
//         cout<<endl;
//     }
// }

// void insert_edges()
// {
//     //first item in pair contains the statr vertex and 2nd item contains end vertex
//     for(int i=0;i<30;i++)
//     {
//         auto edge=Edges[i];
//         int start_index=edge.first;
//         int end_index=edge.second;
//         matrix[start_index][end_index]=1;

//     }
// }

// int main()
// {
// adjacency_matrix();
// display_matrix();

// auto edge1=make_pair(1,23);
// auto edge2=make_pair(1,67);
// auto edge3=make_pair(2,21);
// auto edge4=make_pair(2,73);
// auto edge5=make_pair(3,43);
// auto edge6=make_pair(3,63);
// auto edge7=make_pair(4,13);
// auto edge8=make_pair(4,43);
// auto edge9=make_pair(5,93);
// auto edge10=make_pair(5,3);
// auto edge11=make_pair(6,19);
// auto edge12=make_pair(6,35);
// auto edge13=make_pair(7,83);
// auto edge14=make_pair(7,31);
// auto edge15=make_pair(8,23);
// auto edge16=make_pair(8,23);
// auto edge17=make_pair(9,53);
// auto edge18=make_pair(9,23);
// auto edge19=make_pair(10,3);
// auto edge20=make_pair(10,10);
// auto edge21=make_pair(1,1);
// auto edge22=make_pair(2,2);
// auto edge23=make_pair(3,3);
// auto edge24=make_pair(4,4);
// auto edge25=make_pair(5,5);
// auto edge26=make_pair(6,6);
// auto edge27=make_pair(7,7);
// auto edge28=make_pair(8,8);
// auto edge29=make_pair(9,9);
// auto edge30=make_pair(10,10);
// Edges.push_back(edge1);
// Edges.push_back(edge2);
// Edges.push_back(edge3);
// Edges.push_back(edge4);
// Edges.push_back(edge5);
// Edges.push_back(edge6);
// Edges.push_back(edge7);
// Edges.push_back(edge8);
// Edges.push_back(edge9);
// Edges.push_back(edge10);
// Edges.push_back(edge11);
// Edges.push_back(edge12);
// Edges.push_back(edge13);
// Edges.push_back(edge14);
// Edges.push_back(edge15);
// Edges.push_back(edge16);
// Edges.push_back(edge17);
// Edges.push_back(edge18);
// Edges.push_back(edge19);
// Edges.push_back(edge20);
// Edges.push_back(edge21);
// Edges.push_back(edge22);
// Edges.push_back(edge23);
// Edges.push_back(edge24);
// Edges.push_back(edge25);
// Edges.push_back(edge26);
// Edges.push_back(edge27);
// Edges.push_back(edge28);
// Edges.push_back(edge29);
// Edges.push_back(edge30);
// insert_edges();
// display_matrix();
// /*
//   for weighted graph use this pair of edges
//   vector<pair<pair<int,int>,int> > edges;
//   first item of pair contains the start and end index and the second item contains the weight of edge
// */
// return 0;

// }

//this for a weighted graph

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int matrix[100][100];
vector<pair<pair<int,int>,int>>Edges;
// we are taking example for a non weighted graph
void adjacency_matrix()
{
 for(int i=0;i<100;i++)
   {
       for(int j=0;j<100;j++)
       {
           matrix[i][j]=-1;
       }
   }
}

void display_matrix()
{
    cout<<"These is your initialzed matrix \n";
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void insert_edges()
{
    //first item in pair contains the statr vertex and 2nd item contains end vertex
    for(int i=0;i<30;i++)
    {
        auto edge=Edges[i];
        auto indexes=edge.first;
        int start_index=indexes.first;
        int end_index=indexes.second;
        int weight=edge.second;
        matrix[start_index][end_index]=weight;

    }
}

int main()
{
adjacency_matrix();
display_matrix();

auto edge1=make_pair(1,23);
auto edge2=make_pair(1,67);
auto edge3=make_pair(2,21);
auto edge4=make_pair(2,73);
auto edge5=make_pair(3,43);
auto edge6=make_pair(3,63);
auto edge7=make_pair(4,13);
auto edge8=make_pair(4,43);
auto edge9=make_pair(5,93);
auto edge10=make_pair(5,3);
auto edge11=make_pair(6,19);
auto edge12=make_pair(6,35);
auto edge13=make_pair(7,83);
auto edge14=make_pair(7,31);
auto edge15=make_pair(8,23);
auto edge16=make_pair(8,23);
auto edge17=make_pair(9,53);
auto edge18=make_pair(9,23);
auto edge19=make_pair(10,3);
auto edge20=make_pair(10,10);
auto edge21=make_pair(1,1);
auto edge22=make_pair(2,2);
auto edge23=make_pair(3,3);
auto edge24=make_pair(4,4);
auto edge25=make_pair(5,5);
auto edge26=make_pair(6,6);
auto edge27=make_pair(7,7);
auto edge28=make_pair(8,8);
auto edge29=make_pair(9,9);
auto edge30=make_pair(10,10);
auto edge1_weight=make_pair(edge1,69);
auto edge2_weight=make_pair(edge2,69);
auto edge3_weight=make_pair(edge3,69);
auto edge4_weight=make_pair(edge4,69);
auto edge5_weight=make_pair(edge5,69);
auto edge6_weight=make_pair(edge6,69);
auto edge7_weight=make_pair(edge7,69);
auto edge8_weight=make_pair(edge8,69);
auto edge9_weight=make_pair(edge9,69);
auto edge10_weight=make_pair(edge10,69);
auto edge11_weight=make_pair(edge11,69);
auto edge12_weight=make_pair(edge12,69);
auto edge13_weight=make_pair(edge13,69);
auto edge14_weight=make_pair(edge14,69);
auto edge15_weight=make_pair(edge15,69);
auto edge16_weight=make_pair(edge16,69);
auto edge17_weight=make_pair(edge17,69);
auto edge18_weight=make_pair(edge18,69);
auto edge19_weight=make_pair(edge19,69);
auto edge20_weight=make_pair(edge20,69);
auto edge21_weight=make_pair(edge21,69);
auto edge22_weight=make_pair(edge22,69);
auto edge23_weight=make_pair(edge23,69);
auto edge24_weight=make_pair(edge24,69);
auto edge25_weight=make_pair(edge25,69);
auto edge26_weight=make_pair(edge26,69);
auto edge27_weight=make_pair(edge27,69);
auto edge28_weight=make_pair(edge28,69);
auto edge29_weight=make_pair(edge29,69);
auto edge30_weight=make_pair(edge30,69);
Edges.push_back(edge1_weight);
Edges.push_back(edge2_weight);
Edges.push_back(edge3_weight);
Edges.push_back(edge4_weight);
Edges.push_back(edge5_weight);
Edges.push_back(edge6_weight);
Edges.push_back(edge7_weight);
Edges.push_back(edge8_weight);
Edges.push_back(edge9_weight);
Edges.push_back(edge10_weight);
Edges.push_back(edge11_weight);
Edges.push_back(edge12_weight);
Edges.push_back(edge13_weight);
Edges.push_back(edge14_weight);
Edges.push_back(edge15_weight);
Edges.push_back(edge16_weight);
Edges.push_back(edge17_weight);
Edges.push_back(edge18_weight);
Edges.push_back(edge19_weight);
Edges.push_back(edge20_weight);
Edges.push_back(edge21_weight);
Edges.push_back(edge22_weight);
Edges.push_back(edge23_weight);
Edges.push_back(edge24_weight);
Edges.push_back(edge25_weight);
Edges.push_back(edge26_weight);
Edges.push_back(edge27_weight);
Edges.push_back(edge28_weight);
Edges.push_back(edge29_weight);
Edges.push_back(edge30_weight);
insert_edges();
display_matrix();
/*
  for weighted graph use this pair of edges
  vector<pair<pair<int,int>,int> > edges;
  first item of pair contains the start and end index and the second item contains the weight of edge
*/
return 0;

}