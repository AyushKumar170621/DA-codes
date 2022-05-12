/*I. Given a (directed/undirected) graph, design an algorithm and implement it using a program to
find if a path exists between two given vertices or not. (Hint: use DFS)
*/
#include<iostream>
#include<list>
#include<map>
using namespace std;
class Graph
{
    public:
        map <int , bool> visited;
        map <int ,list<int>> adjnode;
        void addEdge(int v,int w)
        {
            adjnode[v].push_back(w);
        }
        void DFS(int s)
        {
            visited[s]=true;
            cout<<s<<" ";
            list<int>::iterator it;
            for(it=adjnode[s].begin();it != adjnode[s].end();++it)
            {
                if(!visited[*it])
                    DFS(*it);
            }
        }
};

int main()
{
    Graph g;
    int n;
    cout<<"Enter no edge :";
    cin>>n;
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
    g.DFS(source);
    if(g.visited[destination])
        cout<<"\nYes Path Exist "<<endl;
    else
        cout<<"\nNo such Path does not exist "<<endl;
}
