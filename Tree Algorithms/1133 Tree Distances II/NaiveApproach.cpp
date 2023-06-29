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
//APPROACH run dfs for all node -> O(n^2) -> n for a loop and for each iteration dfs runs in O(n)
//for high constraints -> gives TLE
vector<int> g[MAXN];
int lvl[MAXN];
 
void dfs(int u, int p=-1, int d=0){
    lvl[u] += d;
 
    for(int v : g[u]){
        if(v == p) continue;
 
        dfs(v,u,d+1);
    }
}
 
void solve(){
    int n; cin>>n;
 
    for(int i=0;i<n-1;i++){
        int a,b; cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }    
 
    for(int i=1;i<=n;i++){
        dfs(i);
    }
 
    for(int i=1;i<=n;i++){
        cout<<lvl[i]<<" ";
    }
    cout<<"\n";
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
