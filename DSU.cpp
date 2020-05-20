#include<bits/stdc++.h>
using namespace std;
class DSU{
    public:
     vector <int> par;
     vector <int> sz;
    void initialize(int n)
    {
        par.resize(n+1);
        sz.resize(n+1);
        for(int i=1;i<=n;i++){
            par[i]=i;
        }
    }
    int getparent(int x)
    {
        while(par[x] != x)
        {
            par[x] = par[par[x]];
            x = par[x];
        }
    return x;
    }
    void unite(int x,int y)
    {
        int px=getparent(x);
        int py=getparent(y);
        if(px!=py){
            par[px]=py;
        }
    }
    void friends(int n)
    {
        multiset<int>S;
        long long int ans=0;
        for(int i=1;i<=n;i++){
            sz[getparent(i)]++;
        }
        for(int i=1;i<=n;i++){
            if(sz[i]!=0){
               ans++;
            }
        }
        cout<<ans;
    }
};
int main()
{
    int n;
    cin>>n;
    DSU G;
    G.initialize(n);
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        G.unite(x,i);
    }
    G.friends(n);
}
