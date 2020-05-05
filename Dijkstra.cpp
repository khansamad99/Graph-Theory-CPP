#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    
    map<T,list<pair<T,int>>> adjList;
    map<T,int> Dist;
    typedef pair<int,T> pii;

    public:

    void addEdge(T u,T v,int w)
    {
      adjList[u].push_back({v,w});
      adjList[v].push_back({u,w});
    }
    void Dijkstra(T source, int N) {
        priority_queue<pii, vector<pii>, greater<pii> > Q;   // min heap
        for(auto f:adjList){
            Dist[f.first]=INT_MAX;
        }
        Dist[source] = 0;
        Q.push({0,source});
        while(!Q.empty()){
            T u = Q.top().second;
            Q.pop();
            for(auto &c : adjList[u]){
                T v = c.first;
                int w = c.second;
                if(Dist[v] > Dist[u]+w){
                    Dist[v] = Dist[u]+w;
                    Q.push({Dist[v],v});
                }
            }
        }
    }
    void print()
    {
        for(auto i:Dist)
        {
            cout<<i.first<<" is located at a distance of "<<i.second<<"\n";
        }
    }

};

int main()
{
    Graph <string> g;
    g.addEdge("Amritsar","Delhi",1);
    g.addEdge("Amritsar","Jaipur",4);
    g.addEdge("Delhi","Jaipur",2);
    g.addEdge("Jaipur","Mumbai",8);
    g.addEdge("Bhopal","Agra",2);
    g.addEdge("Mumbai","Bhopal",3);
    g.addEdge("Agra","Delhi",1);
    g.Dijkstra("Amritsar",6);
    g.print();
    return 0;
}
