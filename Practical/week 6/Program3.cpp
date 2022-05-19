/*3.Given a directed graph, design an algorithm and implement it using a program to find whether
cycle exists in the graph or not.
*/
//kahn's algorithm for topological sort
#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int ver;
    list<int> *adj;
    public :
    Graph(int v)
    {
        ver=v;
        adj=new list<int>[v];
    }
    void addedge(int s,int d)
    {
        adj[s].push_back(d);
    }
    bool isCycle()
    {
        vector<int> deg(ver,0);
        for(int u=0;u<ver;u++)
            for(auto j=adj[u].begin();j != adj[u].end();j++)
            {
                deg[*j]++;
            }
        queue<int> q;
        for(int u=0;u<ver;u++)
        {
            if(deg[u]==0)
                q.push(u);
        }
        vector<int> topological_or;
        int c=1;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            topological_or.push_back(u);
            for(auto it:adj[u])
            {
                if(--deg[it]==0)
                {
                    q.push(it);
                    c++;
                }
            }
        }
        if(c==ver)
            return true;
        
        return false;
    }
};

int main()
{
    int edge;
    cout<<"Enter number of edges "<<endl;
    cin>>edge;
    Graph g(edge);
    for(int i=0;i<edge;i++)
    {
        int s,d;
        cout<<"Enter source and destination :";
        cin>>s>>d;
        g.addedge(s,d);
    }
    if(g.isCycle())
        cout<<"Yes Cycle Exist"<<endl;
    else
        cout<<"No Cycle Exist"<<endl;

    return 0;
}
