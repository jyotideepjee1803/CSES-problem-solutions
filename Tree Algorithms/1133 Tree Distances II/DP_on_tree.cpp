#include <bits/stdc++.h>
using namespace std;
#define int long long
void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
#ifndef ONLINE_JUDGE
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
#endif
}
 
vector<int> g[MAXN];
int lvl[MAXN];
int dp[MAXN]; //dp[i] = the no. of nodes under subtree rooted at i
int n;
 
//compute answer for 1 so that other can be computed using this : 
void dfsfor1(int u, int p=-1, int d=0){
    dp[u] = 1; //entry dfs
    lvl[1] += d;
 
    for(int v : g[u]){
        if(v == p) continue;
        dfsfor1(v,u,d+1);
 
        dp[u] += dp[v];//update cnt
    }
}
 
void dfsAns(int u=1, int p=-1){
    for(int v : g[u]){
        if(v == p) continue;
 
        //1. the depth of nodes outside subtree of v (++)increase (n-dp[v])
        //2. the depth of nodes inside substree of v (--)decrease 
        // the decrease can be done by decreasing from lvl[u]
        lvl[v] = lvl[u] - dp[v] + (n-dp[v]);
        //next nodes : 
        dfsAns(v,u);
    }
}
void solve(){
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b; cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }    
    dfsfor1(1);
 
    //compute ans : 
    dfsAns();
    for(int i=1;i<=n;i++){
        cout<<lvl[i]<<" ";
    }
}
 
int32_t main()
{
    init();
    int t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}
