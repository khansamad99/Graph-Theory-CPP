#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    
    map<T,list<T>> adjList;

    public:

    void addEdge(T u,T v)
    {
      adjList[u].push_back(v);
      adjList[v].push_back(u);
    }
    
    bool is_tree(T n)
    {
        queue <T> q;
        map <T,bool> visited;
        map <T,T> parent;
        T src=0;
        q.push(src);
        visited[src] = true;
        for(int i=0;i<=n;i++){
            parent[i]=i;
            visited[i]=false;
        }
        while(!q.empty())
        {
            T node = q.front();
            q.pop();
            for(auto neighbour:adjList[node])
            {
                if(visited[neighbour]==true and parent[node]!=neighbour){
                    return false;
                }
                else if(!visited[neighbour]){
                    visited[neighbour]=true;
                    parent[neighbour]=node;
                    q.push(neighbour);
                }
            }
        }
        return true;
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
    g.addEdge(3,2);
    g.addEdge(1,2);
    //g.addEdge(1,4);
    if(g.is_tree(4)){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    return 0;
}
