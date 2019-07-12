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
};

int main()
{
    Graph <string> g;
    g.addEdge("Putlin","Trump",false);
    g.addEdge("Putlin","Modi",false);
    g.addEdge("Putlin","Pomp",false);
    g.addEdge("Modi","Trump",true);
    g.addEdge("Modi","Yogi",true);
    g.addEdge("Yogi","Prabhu",false);
    g.addEdge("Prabhu","Modi",false);
    g.print();
}