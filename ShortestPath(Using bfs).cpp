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

    void Singlesourceshortestpath(T src)
    {
        queue <T> q;
        map <T,int> dist;
        for(auto d:adjList)
        {
            dist[d.first]=INT_MAX;
        }
        q.push(src);
        dist[src] = 0;
        cout<<"The Shortest Path is ";
        int k=0;
        while(!q.empty())
        {
            if(k==1)
            {
                cout<<" -> ";
            }
            k=1;
            T node = q.front();
            q.pop();
            cout<<node;
            for(auto neighbour:adjList[node])
            {
                if(dist[neighbour]==INT_MAX)
                {
                    q.push(neighbour);
                    dist[neighbour] = dist[node] + 1;
                }
            }
        }
        cout<<endl;
        for(auto i:adjList)
        {
            T node = i.first;
            cout<<"Distance of "<<node<<" from "<<src<<" is "<<dist[node]<<"\n";
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
    g.Singlesourceshortestpath(0);
    return 0;
}