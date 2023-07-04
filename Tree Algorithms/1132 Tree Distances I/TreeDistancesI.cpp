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

//APPROACH :
//Get the diameter ends mxnode and mxnode2 and compute distances of each node from mxnode and mxnode2
//ultimately dis[i] = max(distFrom_mxnode[i], distFrom_mxnode2[i])

vector<vector<int>> g;
vector<int> lvl;
 
void dfs(int u, int p=-1, int d=0){
    lvl[u] = d;
    for(auto v : g[u]){
        if(v==p) continue;
        dfs(v,u,d+1);
    }
}

void solve(){
    int n; cin>>n;
    g.assign(n+1,{});
    lvl.assign(n+1,0);
 
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
  
    //call dfs for root -> get mxnode
    dfs(1);
    int mxnode = max_element(all(lvl)) - begin(lvl);
 
    //call dfs for mxnode -> get mxnode2
    dfs(mxnode);
     int mxnode2 = max_element(all(lvl)) - begin(lvl);
 
    //store mx-distances from mxnode2
    vector<int> oldLvl = lvl;
 
    lvl.assign(n+1,0); //reset
    dfs(mxnode2);
 
    for(int i=1;i<=n;i++){
        cout<<max(lvl[i], oldLvl[i])<<" ";
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
