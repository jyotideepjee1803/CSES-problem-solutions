// https://cses.fi/problemset/task/1671
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
const int INF = 1e17;
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
 
//APPROACH : Apply djikstra algorithm
int n,m;
vector<vector<pair<int,int>>> g;
vector<int> vis;
vector<int> dis;
 
void djikstra(){
    dis.assign(n+1,INF);
 
    //{dist, node}
    set<pair<int,int>> s;
    s.insert({0,1});
 
    while(!s.empty()){
        auto node = *s.begin();
        int u = node.ss; 
        //cout<<u<<" ";
        dis[u] = node.ff;
 
        s.erase(s.begin());
 
        for(auto ch : g[u]){
            int v = ch.ff, wt = ch.ss;
 
            if(dis[u] + wt < dis[v]){
                //if smaller distance found update : 
                s.erase({dis[v],v});
                dis[v] = wt + dis[u];
                s.insert({dis[v],v});
            }
        }
    }
}
 
void solve() {
    cin>>n>>m;
    g.assign(n+1,{});
  
    while(m--){
        int u,v,x; cin>>u>>v>>x;
        g[u].pb({v,x});
    } 
 
    djikstra();
 
    for(int i=1;i<=n;++i){
        cout<<dis[i]<<" ";
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
