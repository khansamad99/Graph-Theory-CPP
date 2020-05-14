#include<bits/stdc++.h>
using namespace std;

const int N=100005,M=22;

vector<int>gr[N],grr[N];
int vis[N];
vector <int> order;
vector <int> in_comp[N];


void dfs(int cur)
{
    vis[cur]=1;
    for(auto nbr:gr[cur]){
        if(!vis[nbr]){
            dfs(nbr);
        }
    }
    order.push_back(cur);
}

void dfs_revese(int cur,int col)
{
    in_comp[cur].push_back(col);
    vis[cur]=1;
    for(auto nbr:grr[cur]){
        if(!vis[nbr]){
            dfs_revese(nbr,col);
        }
    }
}
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        gr[x].push_back(y);
        grr[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    memset(vis,0,sizeof(vis));
    int col=1;
    for(int i=n;i>=1;i--){
        if(!vis[order[i]]){
            dfs_revese(order[i],col);
            col++;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<i<<"->";
        for(auto f:in_comp[i]){
            cout<<f<<" ";
        }
        cout<<"\n";
    }
    
}
int main(){
    solve();
}
