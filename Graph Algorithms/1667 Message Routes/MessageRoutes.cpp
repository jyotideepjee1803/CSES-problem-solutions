//https://cses.fi/problemset/task/1667/
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

int n,m, components;
vector<vector<int>> g;
vector<int> vis;
vector<int> par;
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
    par.assign(n+1,-1);

    while(m--)
    {
        int u,v; 
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
       
    }

    queue<int> q; 
    q.push(1);
    vis[1] = 1;
    int fl=0;
    while(!q.empty()){
        int sz = q.size();
        for(int i=0;i<sz;++i){

            int curr = q.front(); q.pop();

            if(curr == n){
                fl=1;
                break;
            }

            for(auto v : g[curr]){
                if(!vis[v]){
                    q.push(v);
                    vis[v] = 1;
                    par[v] = curr;
                }
            }
        }
    }

    if(!fl){
        cout<<"IMPOSSIBLE\n"; return;
    }
    vector<int> path;
    int curr = n;
    while(curr != -1){
        path.pb(curr);
        curr = par[curr];
    }

    reverse(all(path));
    cout<<path.size()<<"\n";
    for(auto e : path) cout<<e<<" ";
    
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
