/*1. Assume that a project of road construction to connect some cities is given to your friend. Map of these cities and roads which will connect them (after construction)
is provided to him in the form of a graph. Certain amount of rupees is associated with construction of each road. Your friend has to calculate the minimum budget required
for this project. The budget should be designed in such a way that the cost of connecting the cities should be minimum and number of roads required to connect all the
cities should be minimum (if there are N cities then only N-1 roads need to be constructed). He asks you for help. Now, you have to help your friend by designing an 
algorithm which will find minimum cost required to connect these cities. (use Prim's algorithm)*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findMin(int v,bool *vis,int *dis)
{
    int index=-1;
    int min=INT_MAX;
    int i;
    for(i=0;i<v;i++)
    {
        if(!vis[i] && dis[i]<min)
        {
            min=dis[i];
            index=i;
        }
    }
    return index;
}

int prims(vector<int>  *g,int v)
{
    bool vis[v];
    int dis[v];
    int parent[v];
    int i,j;
    int cost=0;

    for(i=0;i<v;i++)
    {
        vis[i]=false;
        dis[i]=INT_MAX;
        parent[i]=-1;
    }

    dis[0]=0;

    for(i=0;i<v;i++)
    {
        int ind=findMin(v,vis,dis);
        vis[ind]=true;
        cost+=dis[ind];
        for(j=0;j<v;j++)
        {
            int x=g[ind][j];
            if(x && dis[j]>x)
            {
                dis[j]=x;
                parent[j]=ind;
            }
        }
    }
    return cost;
}

int main()
{
    int v;
    cin>>v;

    vector<int> g[v];
    int i,j;

    for(i=0;i<v;i++)
    for(j=0;j<v;j++)
    {
        int x;
        cin>>x;
        g[i].push_back(x);
    }

    int cost=0;
    cost=prims(g,v);

    cout<<"Minimum Spanning Weight : "<<cost;

    return 0;
}
