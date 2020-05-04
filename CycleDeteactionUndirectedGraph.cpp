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
    bool cycle_helper(int src,bool *visited,int parent)
    {
        visited[src]=true;
        for(auto nbr:adjList[src]){
            if(!visited[nbr]){
                bool cycle_mila=cycle_helper(nbr,visited,src);
                if(cycle_mila){
                    return true;
                }
            }   
            else if(nbr!=parent){
                return true;
            }
        }
    }
    bool contains_cycle(T n)
    {
        bool visited[n+1];
        for(int i=0;i<=n;i++){
            visited[i]=false;
        }
        return cycle_helper(0,visited,-1);
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
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    //g.addEdge(4,0);
    //g.addEdge(4,2);
    //g.addEdge(1,5);
    if(g.contains_cycle(5)){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    return 0;
}
