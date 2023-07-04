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
const int MAXN = 2e5+5;
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
 
vector<int> g[MAXN];
vector<int> par[MAXN];
int n,q;

//APPROACH : Run dfs(1) to store and inherit parents of all nodes and the answer the queries :
//Problem : Excess memory usage 
void dfs(int u, int p=-1){
    if(p != -1){
        par[u] = par[p];
        par[u].pb(p);
    }
    for(auto v : g[u]){
        if(v == p) continue;
 
        dfs(v,u);
    }
}
 
void solve(){
    cin>>n>>q;
 
    for(int i=2;i<=n;i++){
        int e; cin>>e;
        //cout<<i<<"->"<<e<<"\n";
        g[e].pb(i);
        g[i].pb(e);
    }
  
    par[1].pb(-1);
    dfs(1);
 
    while(q--){
        int x,k;
        cin>>x>>k;
    
        int m = par[x].size();
        //cout<<m<<" ";
        if(m-k < 0) cout<<"-1\n";
        else cout<<par[x][m-k]<<"\n";
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
