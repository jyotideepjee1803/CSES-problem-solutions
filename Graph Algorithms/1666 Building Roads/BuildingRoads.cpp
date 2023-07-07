//https://cses.fi/problemset/task/1666/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first 
#define ss second 
#define all(v) v.begin(),v.end()
#define revall(v) v.rbegin(), v.rend()
#define srt(v,l,r) sort(v.begin()+l, v.begin()+r) 
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
const int mod = 1e9+7;
const int MAXN = 1e6+2;
const int INF = INT64_MAX;
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

//APPROACH : DFS to find components
 
int n,m, components;
vector<vector<int>> g;
vector<int> vis;
vector<int> dis;
void dfs(int u, int p=-1){
    vis[u] = 1;
 
    for(auto v : g[u]){
        if(v == p) continue;
 
        if(!vis[v]){
            dfs(v,u);
        }
    }
}
 
 
void solve()
{
    cin>>n>>m;
    components = 0;
    
    g.assign(n+1,{});
    vis.assign(n+1,0);
    dis.clear();
 
    while(m--)
    {
        int u,v; 
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
       
    }
 
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
            components++;
            dis.pb(i);
        }
    }
 
    cout<<components-1<<"\n";
    for(int i=0;i<components-1;i++){
        cout<<dis[i]<<" "<<dis[i+1]<<"\n";
    }
    
}
 
int32_t main()
{
    init();
    int t=1;
    
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
