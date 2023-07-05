#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(),v.end()
#define pb push_back
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
 
    //get ends of diameter of the tree = (a,b);
    dfs(1);
    int a = max_element(all(lvl)) - begin(lvl);
 
    //get farthest distance from a -> to get b :
    dfs(a);
    int b = max_element(all(lvl)) - begin(lvl);
 
    int diameter_dis = *max_element(all(lvl));
    cout<<diameter_dis<<"\n";
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
