#include <bits/stdc++.h>

using namespace std;

struct Edge
{
  int s;
  int d;
  int w;
};
struct Graph
{
    int V;
    int E;
    struct Edge* edge;
};
struct Graph* createGraph(int v,int e)
{
    struct Graph *graph = new Graph;
    graph->V=v;
    graph->E=e;
    graph->edge=new Edge[e];
    return graph;
}
void printDist(int par[],int dist[],int v)
{
    for(int i=0;i<v;i++)
    {
        cout<<i+1<<" ";
        int t=i;
        while(par[t] != -1)
        {
            cout<<par[t]+1<<" ";
            t=par[t];
        }
        cout<<" : "<<dist[i]<<endl;
    }
}
void bellmonFord(struct Graph * g,int src)
{
    int ver=g->V;
    int e=g->E;
    int dist[ver];
    for(int i=0;i<ver;i++)
        dist[i]=INT_MAX;
    int parent[ver]={-1};
    dist[src]=0;
    
    for(int i=1;i<ver;i++)
    {
        for(int j=0;j<e;j++)
        {
            int u=g->edge[j].s;
            int v=g->edge[j].d;
            int w=g->edge[j].w;
            if(dist[u] != INT_MAX && dist[u] + w < dist[v])
            {
                dist[v]=dist[u]+w;
                parent[v]=u;
            }
        }
    }
    for(int j=0;j<e;j++)
    {
        int u=g->edge[j].s;
        int v=g->edge[j].d;
        int w=g->edge[j].w;
        if(dist[u] != INT_MAX && dist[u] + w < dist[v])
        {
            cout<<"Graph contains -ve Cycle."<<endl;
            return;
        }
    }
    printDist(parent,dist,ver);
}
int main()
{
    int ver,e;
    cout<<"Enter vertices and edges number :";
    cin>>ver>>e;
    Graph *g=createGraph(ver,e);
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cout<<"Enter Source destination weight :";
        cin>>u>>v>>w;
        g->edge[i].s=u;
        g->edge[i].d=v;
        g->edge[i].w=w;
    }
    bellmonFord(g,0);
    return 0;
}
