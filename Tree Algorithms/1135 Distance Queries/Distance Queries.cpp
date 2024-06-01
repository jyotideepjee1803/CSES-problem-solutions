#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define ff first 
#define ss second 
#define all(u) u.begin(),u.end()
#define revall(u) u.rbegin(), u.rend()
#define srt(u,l,r) sort(u.begin()+l, u.begin()+r) 
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define piii pair<pii,int>
const int N = 2e5+10;
const int mod = 1e9+7;
const int MAXN = 3e5+3;
const int INF = 1e18+7;
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
vector<int> lvl;
vector<vector<int>> g;
int dp[N][20];

int jump(int u, int k){
    for(int i=0;i<20;i++){
        int mask = k&(1ll<<i);
        if(mask){
            u = dp[u][i];
        }
    }
    return u;
}

void dfs(int u, int p=-1, int l=0){
    lvl[u] = l;

    dp[u][0] = p;
    for(int i=1;i<19;i++){
        if(dp[u][i-1] == -1) dp[u][i] = -1;
        else{
            dp[u][i] = dp[dp[u][i-1]][i-1];
        }
    }

    for(auto v: g[u]){
        if(v == p) continue;
        dfs(v,u,l+1);
    }
}

int lca(int u, int v){
    if(lvl[u] < lvl[v]) swap(u,v); //keeping u at a greater depth

    u = jump(u, lvl[u] - lvl[v]); //bring u and v at same depths

    int i;
    for(i=19; i>=0; i--){
        if(dp[u][i] != dp[v][i]){
            u = dp[u][i];
            v = dp[v][i];   
        }
    }

    if(u == v) return u;

    return jump(u,1);
}

void solve(){
    cin>>n>>m;
    g.assign(n+1,{});
    lvl.assign(n+1,0);
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(1);
    while(m--){
        int a,b; cin>>a>>b;
        int c = lca(a,b);
        cout<<lvl[a]+lvl[b]-2*lvl[c]<<"\n";
    }
}

int32_t main()
{
    init();
    int t=1;
    // cin >> t;
    // int i=1;
    while (t--)
    {
        //cout<<"Case "<<i<<": ";
        solve();
        //i++;
    }
}
