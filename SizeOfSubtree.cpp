#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define po          pop_back
#define pii         pair<ll,ll>
#define vi          vector<ll>
#define vii         vector<pii>
#define mi          map<int,int>
#define ms          map<string,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define pqb         priority_queue<int>
#define pqs         priority_queue<int,vi,greater<int> >
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
#define debug(x,y)  cout<<x<<" "<<y<<"\n";
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N=1e3+5;

vector <int> gr[N];
int vis[N],ans[N];

int dfs(int node)
{
    vis[node]=1;
    int curr_sz=1;
    for(auto f:gr[node]){
        if(!vis[f]){
            curr_sz+dfs(f);
        }
    }
    
    ans[node]=curr_sz;
    return curr_sz;
}
void solve()
{
    int n;
    cin>>n;
    rep(i,1,n){
        int x,y;
        cin>>x>>y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
}
int main()
{
    IOS
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}
