#include<bits/stdc++.h>
using namespace std;

struct dsu{
    vector <int> par;
    int total_cmp=0;
    
    void init(int n)
    {
        par.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
        total_cmp=n;
    }
    
    int get_superparent(int x)
    {
        if(x==par[x]){
            return x;
        }
        else{
            return par[x]=get_superparent(par[x]);
        }
    }
    
    void unite(int x,int y)
    {
        int superparent_x=get_superparent(x);
        int superparent_y=get_superparent(y);
        if(superparent_x!=superparent_y){
            par[superparent_x]=superparent_y;
            total_cmp--;
        }
    }
}G;
int main()
{
    int n,m,ans=0;
    cin>>n>>m;
    vector <vector<int>>edges(m);
    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        x--;
        y--;
        edges[i]={w,x,y};
    }
    sort(edges.begin(),edges.end());
    dsu G;
    G.init(n);
    for(int i=0;i<m;i++){
        int x=edges[i][1];
        int y=edges[i][2];
        if(G.get_superparent(x)!=G.get_superparent(y)){
            G.unite(x,y);
            ans+=w;
        }
    }
    cout<<ans;
    return 0;
}
