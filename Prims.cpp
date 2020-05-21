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

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>

using namespace std;
const int MAX = 1e4 + 5;
typedef pair<long long, int> PII;
bool marked[MAX];
vector <PII> adj[MAX];

long long prim(int x)
{
    priority_queue<PII, vector<PII>, greater<PII> > Q;
    int y;
    long long minimumCost = 0;
    PII p;
    Q.push(make_pair(0, x));
    while(!Q.empty())
    {
        // Select the edge with minimum weight
        p = Q.top();
        Q.pop();
        x = p.second;
        // Checking for cycle
        if(marked[x] == true)
            continue;
        minimumCost += p.first;
        marked[x] = true;
        for(int i = 0;i < adj[x].size();++i)
        {
            y = adj[x][i].second;
            if(marked[y] == false)
                Q.push(adj[x][i]);
        }
    }
    return minimumCost;
}

int main()
{
    int nodes, edges, x, y;
    long long weight, minimumCost;
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        adj[x].push_back(make_pair(weight, y));
        adj[y].push_back(make_pair(weight, x));
    }
    // Selecting 1 as the starting node
    minimumCost = prim(1);
    cout << minimumCost << endl;
    return 0;
}
