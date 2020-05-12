#include<bits/stdc++.h>
using namespace std;

const int N=100005,M=22;

vector<int>gr[N];
int vis[N];
bool odd_cycle=0;


void dfs(int cur,int par,int col)
{
    vis[cur]=col;
    for(auto child:gr[cur]){
        if(!vis[child]){
            dfs(child,cur,3-cur);
        }
        else if(child!=par && col == vis[child]){
            odd_cycle=1;
        }
    }
    return ;
}
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    dfs(1,0,1);
    if(odd_cycle){
        cout<<"No it's not a Bipartite Graph\n";
    }
    else{
        cout<<"Yes it is\n";
    }
}
int main(){
    solve();
}
