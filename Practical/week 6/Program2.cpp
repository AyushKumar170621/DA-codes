/*II. Given a graph, design an algorithm and implement it using a program to find if a graph is
bipartite or not. (Hint: use BFS)
*/
#include<iostream>
#include<vector>
#include<list>
#include<queue>

using namespace std;
class Graph
{
    public:
        int v;
        vector<list<int>>adj;
        vector <bool> visited;
        Graph(int v)
        {
            this->v=v;
            adj.resize(v);
            visited.resize(v,false);
        }
        void addEdge(int v,int w)
        {
            adj[v].push_back(w);
        }
        void BFS(int s)
        {
            visited[s]=true;
            queue <int> q;
            q.push(s);
            while (!q.empty())
            {
                int x=q.front();
                q.pop();
                cout<<x<<" ";
                for(auto it=adj[s].begin();it!=adj[s].end();++it)
                {
                    if(!visited[*it])
                    {
                        visited[*it]=true;
                        q.push(*it);
                    }
                }
            }
            
        }
        bool isBipartite()
        {
            vector<int> col(v, -1);
            queue<pair<int, int> > q;
            for(int i=0;i<v;i++)
            {
                if(col[i] == -1)
                {
                    q.push({i,0});
                    col[i]=0;
                    while(!q.empty())
                    {
                        pair<int,int> p=q.front();
                        q.pop();
                        int ve=p.first;
                        int c=p.second;
                         for(auto it=adj[ve].begin();it!=adj[ve].end();++it)
                        {
                            if(col[*it]==c)
                            {
                                return false;
                            }
                            if(col[*it]==-1)
                            {
                                col[*it]=(c)?0:1;
                                q.push({*it,col[*it]});
                            }
                        }
                    }
                }
            }
        }

};
int main()
{
    int n;
    cout<<"Enter no edge :";
    cin>>n;
    Graph g(n);
    for(int i=0;i<n ;i++)
    {
        int v,w;
        cout<<"Enter Start and end node of edge :";
        cin>>v>>w;
        g.addEdge(v,w);
    }
    int source ,destination;
    cout<<"Enter Source and destination node:";
    cin>>source>>destination;
    //g.BFS(source);
    if(g.isBipartite())
        cout<<"\nBipartite "<<endl;
    else
        cout<<"\nNot Bipartite "<<endl;
}
