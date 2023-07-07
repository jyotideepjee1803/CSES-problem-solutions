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
const int MAXN = 1e5+2;
const int INF = 1e15;
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

//APPROACH : dijsktra to find shortest distance of ends of given edges from start and end
// for {a,b,w} : edges find (shortest dist of a from 1) and (shortest dist of b from n) and add w/2
// take min of above 

int n,m;
vi dis1, disN, vis;

void dijkstra(int s, vi &dis, vector<pii> g[]){    
    priority_queue<pii> q;
    
    dis.assign(n+1, INF);
    vis.assign(n+1, 0);
    dis[s]=0;
    
    q.push({0,s});

    while(!q.empty()){
        int u = q.top().ss; q.pop();

        if (vis[u]) continue;
        
        vis[u]=1;
        for (auto p: g[u]){
            int v = p.ff, w = p.ss; 

            if (dis[u]+ w < dis[v]){

                dis[v] = dis[u]+w;
                q.push({-dis[v], v});

            }
        }
    }
}


void solve()
{
   cin>>n>>m;
   vector<pii> g1[n+1], g2[n+1];
   vector<vi> edges;

   while(m--){
      int u,v,x; cin>>u>>v>>x;
      edges.pb({u,v,x});

      g1[u].pb({v,x});
      g2[v].pb({u,x});
   }

   dijkstra(1,dis1,g1);
   dijkstra(n,disN,g2);

   int mn = INF;
   for(auto e : edges){
       mn = min(mn, dis1[e[0]] + e[2]/2 + disN[e[1]]); 
   }

   cout<<mn<<"\n";
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
