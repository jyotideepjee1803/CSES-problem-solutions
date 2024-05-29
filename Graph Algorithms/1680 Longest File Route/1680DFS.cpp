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
const int MAXN = 2e5+3;
const int INF = 0x3f3f3f3f;
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
 
int n,m;
vector<vector<int>> g;
vector<int> order;
vector<int> vis;
 
void dfs(int u){
    if(vis[u]) return;
 
    vis[u] = 1;
    for(auto v : g[u]){
        if(!vis[v]) dfs(v);
    }
 
    order.pb(u);
}
 
void solve(){
    cin>>n>>m;
    g.assign(n+1,{});
    vis.resize(n+1);
 
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        g[a].pb(b);
    }
 
    // dfs(1);
    // cout<<"\n";
    
    vector<int> dis(n+1,-1e9), par(n+1,0);
 
    //toposort : 
    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(i);
    }
    // for(auto e : order){
    //     cout<<e<<" ";
    // }
 
 
    if(order.size() != n){
        cout<<"IMPOSSIBLE\n";
        return;
    }
 
    //traverse the topo order and 
    //update the dist of nodes to a greater distance if found
    dis[1] = 0;
    while(!order.empty()){
        int u = order.back(); order.pop_back();
        for(auto v : g[u]){
            if(dis[u] != -1e9 and dis[v] < 1 + dis[u]){
                dis[v] = 1 + dis[u];
                par[v] = u;
            }
        }
    }
 
    if(dis[n] == -1e9){
        cout<<"IMPOSSIBLE\n";
        return;
    }
 
    vector<int> path;
 
    int u = n;
    path.push_back(u);
    while(u != 1){
        u = par[u];
        path.push_back(u);
    }
 
    cout<<path.size()<<"\n";
    reverse(all(path));
    for(auto e : path){
        cout<<e<<" ";
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
