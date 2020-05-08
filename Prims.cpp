#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
        int v;
        list <pair<int,int>> *adj;
        
        Graph(int v){
            this->v=v;
            adj = new list<pair<int,int>> [v];
        }
        
        void addEdge(int u,int v,int w){
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        int findminvertex(int *weight,bool *visited,int v)
        {
            int minvertex=-1;
            for(int i=0;i<v;i++){
                if(!visited[i]&&(minvertex==-1||weight[i]<weight[minvertex])){
                    minvertex=i;
                }
            }
            return minvertex;
        }
        void Prims()
        {
            bool *visited = new bool[v];
            int *parent = new int[v];
            int *weight = new int[v];
            for(int i=0;i<v;i++){
                visited[i]=false;
                weight[i]=INT_MAX;
            }
            parent[0]=-1;
            weight[0]=0;
            for(int i=0;i<v;i++){
                int minvertex = findminvertex(weight,visited,v);
                visited[minvertex]=true;
                for(auto nbr:adj[minvertex]){
                    if(!visited[nbr.first]){
                        if(weight[nbr.first]>nbr.second){
                            parent[nbr.first]=minvertex;
                            weight[nbr.first]=nbr.second;
                        }
                    }
                }
            }
            
            for(int i=0;i<v;i++){
                cout<<i<<"--"<<parent[i]<<" with weight "<<weight[i]<<"\n";
            }
            
        }
};
