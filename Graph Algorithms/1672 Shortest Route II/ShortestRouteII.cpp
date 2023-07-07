// https://cses.fi/problemset/task/1672
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
 
//APPROACH : Apply floyd warshall algorithm(constraints are comparatively low)
 
// 1≤n≤500
// 1≤m≤n2
// 1≤q≤105
// 1≤a,b≤n
// 1≤c≤109
 
int n,m,q;
vector<vector<int>> dis;
 
void solve() {
    cin>>n>>m>>q;
    dis.assign(n+1,vector<int>(n+1, INF));
 
    //self:
    for(int i=1;i<=n;i++){
        dis[i][i] = 0;
    }
 
    while(m--){
        int u,v,x; cin>>u>>v>>x;
        dis[u][v] = min(dis[u][v],x);
        dis[v][u] = min(dis[v][u],x);
    } 
 
    //warshall : 
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
 
    while(q--){
        int u,v; cin>>u>>v;
        if(dis[u][v]== INF){
            cout<<"-1\n";
        }
        else{
            cout<<dis[u][v]<<"\n";
        }
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
