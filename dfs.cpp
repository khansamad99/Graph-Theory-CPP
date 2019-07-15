#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    
    map<T,list<T>> adjList;

    public:

    void addEdge(T u,T v,bool bidir=true)
    {
      adjList[u].push_back(v);
      if(bidir)
      {
          adjList[v].push_back(u);
      }
    }
    
    void dfstrav(T node,map<T,bool> &visited)
    {
        visited[node]=true;
        cout<<node<<" ";
        //find out node which is neighbour of current not not visited
        for(T n:adjList[node])
        {
            if(!visited[n])
            {
                dfstrav(n,visited);
            }
        }
    }
    void dfs(T src)
    {
        map<T,bool>visited;
        dfstrav(src,visited);
    }
    void print()
    {
        for(auto i:adjList)
        {
            cout<<i.first<<"->";
            for(auto j:i.second)
            {
                cout<<j<<"-";
            }
            cout<<"\n";
        }
    }

    
};

int main()
{
    Graph <int> g;

    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(4,3);
    g.addEdge(1,4);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.dfs(0);
    return 0;
}
