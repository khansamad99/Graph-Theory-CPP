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
        int component=1;
        dfstrav(src,visited);
        cout<<endl;

        for(auto i:adjList)
        {
            T city = i.first;
            if(!visited[city])
            {
                dfstrav(city,visited);
                component++;
            }
        }

        cout<<"The current graph has "<<component<<" components\n";
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
    Graph <string> g;

    g.addEdge("Amritsar","Jaipur");
    g.addEdge("Amritsar","Delhi");
    g.addEdge("Delhi","Jaipur");
    g.addEdge("Mumbai","Jaipur");
    g.addEdge("Mumbai","Bhopal");
    g.addEdge("Delhi","Bhopal");
    g.addEdge("Mumbai","Banglore");
    g.addEdge("Agra","Delhi");
    g.addEdge("Andaman","Nicobar");
    g.dfs("Amritsar");
    return 0;
}
