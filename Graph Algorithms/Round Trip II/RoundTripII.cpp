// https://cses.fi/problemset/task/1678
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first 
#define ss second 
#define all(v) v.begin(),v.end()
#define revall(v) v.rbegin(), v.rend()
#define srt(v,l,r) sort(v.begin()+l, v.begin()+r) 
#define pb push_back
const int mod = 1e9+7;
const int N = 2e5+3;
const int MAXN = 1e6+2;
const int INF = INT64_MAX;
void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

// #ifndef ONLINE_JUDGE
//     freopen("inputf.txt", "r", stdin);
//     freopen("outputf.txt", "w", stdout);
// #endif
}

//APPROACH : To check for cycle in Directed Graph
int n,m;
vector<vector<int>> g;
vector<int> vis;
vector<int> par;
int st,en;

//initially all nodes unvisited vis[i] = 0
//entering dfs, vis[i] = 1 partly explored or fully explored and i is part of cycle 
//exit dfs, vis[i] = 2 -> fully explored not part of any cycle  
bool dfs(int u){
    vis[u] = 1;
    for(int v : g[u]){
        //reached an already visited node : -> cycle
        if(vis[v] == 1){
            st = v; en = u; return true;
        }
 
        else if(vis[v] == 0){
            par[v] = u;
            if(dfs(v)) return true;
        }
    }
 
    vis[u] = 2;
    return false;
}
 
bool seeAll(){
    for(int i=1;i<=n;i++){
        if(dfs(i)) return true;
    }
 
    return false;
}

void solve() {
   cin>>n>>m;
   g.resize(n+1);
   vis.assign(n+1,0);
   par.assign(n+1,-1);
 
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        g[u].pb(v);
    }
 
    if(!seeAll()){
        cout<<"IMPOSSIBLE\n"; return;
    }
 
    vector<int> path;
    path.pb(st);
    int i=en;
    while(i!=st){
        path.pb(i); i = par[i];
    }
    path.pb(st);
    reverse(all(path));

    cout<<path.size()<<"\n";
    for(auto e : path) cout<<e<<" ";
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
