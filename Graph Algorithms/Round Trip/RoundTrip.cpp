// https://cses.fi/problemset/task/1669
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

//APPROACH : To check for cycle in UDG

vector<vector<int>> g;
vector<int> vis;
vector<int> par;
int st,en;

bool dfs(int u, int p=-1){
    vis[u] = 1;
    for(auto v : g[u]){
        if(v == p) continue;
        
        if(vis[v]){
            st = v;
            en = u;
            return true;
        }

        par[v] = u;
        if(dfs(v,u)) return true;
    }

    return false;
}

void solve() {
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    vis.assign(n+1,0);
    par.assign(n+1,-1);
    while(m--){
        int u,v; cin>>u>>v;
        g[u].pb(v); g[v].pb(u);
    }

    st = -1, en = -1;

    for(int i=1;i<=n;i++){
        if(vis[i] == 0 ){
           if(dfs(i)) break; //detected cycle 
        }
    }

    if(st == -1){
        cout<<"IMPOSSIBLE\n"; return; //no cycle
    }

    vector<int> path;
    path.pb(st);
    int node = en;
    while(node != st){
        path.pb(node);
        node = par[node];
    }
    path.pb(st);

    cout<<path.size()<<"\n";
    for(auto e : path){
        cout<<e<<" ";
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
