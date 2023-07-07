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
const int MAXN = 1e5+2;
const int INF = 1LL<<62;
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
//APPROACH : Toposort + Cycle detection using toposort
 
int n,m;
vector<vector<int>> g;
vector<int> vis;
 
void dfs(int u, stack<int> &st){
    vis[u] = 1;
 
    for(auto v : g[u]){
        if(!vis[v]) dfs(v,st);
    }
 
    st.push(u);
}
void solve()
{
    cin>>n>>m;
    g.assign(n+1,{});
    vis.assign(n+1,0);
 
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
 
        g[u].pb(v);
    }
    stack<int> st;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,st);
        }
    }
 
    //check cycle : 
    map<int,int> occ; vi order;
    int i = 0;
    while(!st.empty()){
        int t = st.top(); st.pop();
        occ[t] = i;
        order.pb(t);
        i++;
    }
    
    for(int i=1; i<=n;i++){
        for(auto v : g[i]){
            //child appears earlier
            if(occ[v] < occ[i]) {
                cout<<"IMPOSSIBLE\n"; return;
            }
        }
    }
 
    for(auto e : order){
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
