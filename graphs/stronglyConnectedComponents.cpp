#include<bits/stdc++.h>
using namespace std;
void addedge(vector<int>adj[],int a,int b)
{
    adj[a].push_back(b);
}
void topo(int node,vector<int>adj[],stack<int>&st,vector<int>&visit)
{
    visit[node]=1;
    for(auto i:adj[node])
    {
        if(!visit[i])
        {
            topo(i,adj,st,visit);
        }
    }
    st.push(node);
}
void revdfs(int node,vector<int>&visit,vector<int>transp[])
{
    cout<<node<<" ";
    visit[node]=1;
    for(auto it:transp[node])
    {
        if(!visit[it])
        {
            revdfs(it,visit,transp);
        }
    }
}
int main()
{
    int vertex,edges;
    cout<<"ENTER THE NUMBER OF VERTEX AND EDGES:"<<endl;
    cin>>vertex>>edges;
    vector<int>adj[vertex];
    int a,b;
    cout<<"ENTER THE LINKS:"<<endl;
    for(int i=0;i<edges;i++)
    {
        cin>>a>>b;
        addedge(adj,a,b);
    }
    stack<int>st;
    vector<int>visit(vertex,0);
    for(int i=0;i<vertex;i++)
    {
        if(!visit[i])
        {
            topo(i,adj,st,visit);
        }
    }
    vector<int>transp[vertex];
    for(int i=0;i<vertex;i++)
    {
        visit[i]=0;
        for(auto it:adj[i])
        {
            transp[it].push_back(i);
        }
    }
    while(!st.empty())
    {
        int node =st.top();
        st.pop();
        if(!visit[node])
        {
            cout<<"SCC";
            revdfs(node,visit,transp);
            cout<<endl;
        }
    }
    return 0;
}
