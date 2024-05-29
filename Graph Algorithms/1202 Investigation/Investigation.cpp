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
vector<vector<pair<int,int>>> g;
vector<int> vis;
vector<int> dis;
vector<int> dp,mx,mn;

void djikstra(){
    dis.assign(n+1,INF);
    dp.assign(n+1,0); //dp[i] = no. of shortest ways to reach i
    mx.assign(n+1,0); //mx[i] = max edges in the shortest ways to reach i
    mn.assign(n+1,n+1); //mn[i] = min edges in the shortest ways to reach i

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0,1});
    dis[1] = 0;
    dp[1] = 1; mn[1] = 0;

    while(pq.size()){
        auto t = pq.top(); pq.pop();
        int u = t.ss, d = t.ff;

        if(d > dis[u]) continue;

        for(auto ch : g[u]){
            int v = ch.ff, w = ch.ss;

            if(dis[v] == dis[u] + w){
                dp[v] = (dp[v] + dp[u])%mod;
                mx[v] = max(mx[v], 1+mx[u]);
                mn[v] = min(mn[v], 1+mn[u]);
            }
            
            else if(dis[v] > dis[u] + w){
                dp[v] = dp[u];
                mx[v] = 1+mx[u];
                mn[v] = 1+mn[u];

                dis[v] = dis[u]+w;
                pq.push({dis[v],v});
            }
        }
    }

    cout<<dis[n]<<" "<<dp[n]<<" "<<mn[n]<<" "<<mx[n]<<"\n";
}

void solve(){
    cin>>n>>m;
    g.assign(n+1,{});
  
    while(m--){
        int u,v,x; cin>>u>>v>>x;
        g[u].pb({v,x});
    } 
 
    djikstra();
 
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
