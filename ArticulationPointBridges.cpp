#include<bits/stdc++.h>
using namespace std;

const int N=100005,M=22;

vector<int>gr[N];
int disc[N],low[N],tme;
vector <int> art_p;
vector <pair<int,int>> bridge;

void dfs(int cur,int par)
{
    disc[cur]=low[cur]=tme++;
    int no_child=0;
    for(auto child:gr[cur]){
        if(disc[child]==0){
            dfs(child,cur);
            no_child++;
            low[cur]=min(low[cur],low[child]);
            //art point
            if(par!=0 && low[child]>=disc[cur]){
                art_p.push_back(cur);
            }
            
            //Bridge
            if(low[child]>disc[cur]){
                bridge.push_back({cur,child});
            }
        }
        else if(child!=par){
            //Backedge found
            low[cur]=min(low[cur],disc[child]);
        }
    }
    
    if(par==0&&no_child>=2){
        art_p.push_back(cur);
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
        gr[y].push_back(x);
    }
    tme=1;
    dfs(1,0);
    for(auto x:art_p) cout<<x<<" ";
}
int main(){
    solve();
}
