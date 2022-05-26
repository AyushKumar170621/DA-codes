#include <bits/stdc++.h>

using namespace std;
int mindistance(int d[],bool sptset[],int v)
{
    ind,mini=INT_MAX;
    for(int i=0;i<v;i++)
    {
        if(mini > d[i])
        {
            mini=d[i];
            ind=i;
        }
    }
    return ind;
}
void printpath(int parent[],int ind)
{
    if(parent[ind]==-1)
        return;
    printpath(parent,parent[j])
        cout<<j<<" ";
}
void printsol(parent[],int j,int v)
{
    for(int i=1;i<v;i++)
    {
        printpath(parent,j);
        cout<<" : "<<dist[i]<<end;
    }
}
void dikshtra(int graph[][],int src,int v)
{
    int dist[v]={INT_MAX};
    parent[v]={-1};
    bool sptset[v]={true};
    dist[src]=0;
    for(int c=0;c<v-1;c++)
    {
        int u=mindistance(dist,sptset,v);
        sptset[u]=true;
        for(int i=0;i<v;i++)
        {
            for(v1=0;v1<v;v1++)
            {
                if(!sptset[v1] && graph[u][v1] && dist[u]+graph[u][v1]<dist[v1])
                {
                    parent[v1]=u;
                    dist[v1]=dist[u]+graph[u][v1];
                }
            }
        }
    }
}
int main()
{
    int v;
    cout<<"Enter vetices of graph :";
    cin>>v;
    int graph[v][v];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>graph[i][j];
        }
    }
    dikshtra(graph,0,v);
    return 0;
}
