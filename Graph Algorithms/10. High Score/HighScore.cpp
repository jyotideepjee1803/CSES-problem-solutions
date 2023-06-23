// https://cses.fi/problemset/task/1673/
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

// Constraints
// 1≤n≤2500
// 1≤m≤5000
// 1≤a,b≤n
// −109≤x≤109
 
//APPROACH : For -ve edges, shortest/greatest path -> Apply Bellman Ford's Algo
//           negate all input edges, to find the path with most -ve magnitude
//           that most -ve magnitude would turn out to be the highest score magnitude
 
//Implementation : 
// By Bellman Ford find nodes that are included in the -ve cycle if any node 
// that is included in cycle is reachable by 1 and then further can reach 'n'
// then print -1 else print dis[n];
 
int n,m;
vector<vector<int>> edges, g1, g2;
vector<int> vis1, vis2, dis;
 
void dfs(int u){
    vis1[u] = 1;
    for(auto v : g1[u]){
        if(vis1[v]) continue;
        dfs(v);
    }
}
 
void dfs2(int u){
    vis2[u] = 1;
    for(auto v : g2[u]){
        if(vis2[v]) continue;
        dfs2(v);
    }
}
 
void solve()
{
    cin>>n>>m;
 
    edges.clear();
    dis.assign(n+1,1e13);
    vis1.assign(n+1,0), vis2.assign(n+1,0);
    g1.assign(n+1,{}), g2.assign(n+1,{});
 
    while(m--)
    {
        int u,v,x; 
        cin>>u>>v>>x;
 
        //u,v, score :
        edges.pb({u,v,-x});
 
        g1[u].pb(v); //u->v
        g2[v].pb(u); //v->u
    }
 
    dfs(1);
    dfs2(n);

    //BELLMAN FORD : 
    
    dis[1] = 0;
    //n-1 iterations : 
    for(int i=0; i<n-1; ++i){
        for(auto it : edges){
            int u = it[0], v = it[1], w = it[2];
 
            if(dis[u] != 1e13 and dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
            }
        }
    }
 
    //nth iteration :
    for(auto it : edges){
        int u = it[0], v = it[1], w = it[2];
 
        //if v can be relaxed then v is part of -ve cycle 
        //and 1->v->n then n also part of a cycle 
        if(dis[u] != 1e13 and dis[v] > dis[u] + w){
            dis[v] = dis[u] + w;
            if(vis1[v] and vis2[v]){
                cout<<"-1\n"; return;
            }
        }
    }
 
    //no -ve cylce : 
    cout<<-dis[n]<<"\n";
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
