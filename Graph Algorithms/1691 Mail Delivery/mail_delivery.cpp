#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define ff first 
#define ss second 
#define all(u) u.begin(),u.end()
#define revall(u) u.rbegin(), u.rend()
#define srt(u,lo,hi) sort(u.begin()+lo, u.begin()+hi) 
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define piii pair<pii,int>
const int N = 2e5+10;
const int mod = 998244353;
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
 
int binexp(int a, int b){
    if(a==0) return a;
    if(b==0) return 1ll;
 
    int res = 1;
    while(b){
        if(b&1){
            res = (res*a)%mod;
        }
        a = (a*a)%mod;
        b/=2;
    }
 
    return res;
}

//APPROACH
//Find EULERIAN CYCLE in Graph
//FOR EULER PATH exactly 2 nodes can have odd deg
//FOR EULER CYCLE all nodes should have even deg
 
vector<set<int>> g;
vector<int> ans;
void dfs(int u){
    auto &edges = g[u];
    while(edges.size()){
        auto v = *edges.begin();
 
        //remove u-v edge
        edges.erase(v);
        g[v].erase(u);
 
        dfs(v);
    }
    ans.pb(u);
}
 
void solve(){
    int n,m; cin>>n>>m;
    g.resize(n+1);
 
    int i=0;
    while(i<m){
        int u,v; cin>>u>>v;
        g[u].insert(v);
        g[v].insert(u);
        i++;
    }
 
    for(int i=1;i<=n;i++){
        if((g[i].size() % 2) == 1){
            cout<<"IMPOSSIBLE\n";
            return;
        }
    }
 
    dfs(1);
    if(ans.size() == m+1){
        for(auto &e : ans){
            cout<<e<<" ";
        }
    }
    else{
        cout<<"IMPOSSIBLE\n";
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
