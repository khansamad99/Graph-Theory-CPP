#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    
    map<T,list<T>> adjList;

    public:

    void addEdge(T u,T v)
    {
      adjList[u].push_back(v);
    }
    
    void dfstrav(T node,map<T,bool> &visited,list<T> &S)
    {
        visited[node]=true;
        //find out node which is neighbour of current not not visited
        for(T n:adjList[node])
        {
            if(!visited[n])
            {
                dfstrav(n,visited,S);
            }
        }
        S.push_front(node);
        return;
    }
    void dfs()
    {
        map<T,bool>visited;
        list<T> S;
        for(auto p:adjList){
            T node=p.first;
            visited[node]=false;
        }
        for(auto p:adjList){
            T node = p.first;
            if(!visited[node]){
                dfstrav(node,visited,S);
            }
        }
       for(auto f:S){
           cout<<f<<" ";
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
    Graph <int> g;

    g.addEdge(5,0);
    g.addEdge(5,2);
    g.addEdge(4,0);
    g.addEdge(4,1);
    g.addEdge(3,1);
    g.addEdge(2,3);
    g.addEdge(0,0);
    g.addEdge(1,1);
    g.dfs();
    return 0;
}
