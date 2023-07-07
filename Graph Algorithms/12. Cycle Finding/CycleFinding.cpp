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
const int INF = 1LL<<62;
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

//APPLY BELLMANFORD's algorithm to detect -ve cycle
//keep track of the latest element which becomes part of -ve cycle
//that latest element may be integral part of -ve cycle 
//or may lead to the exit of cycle through other neighbours
//in worst case (n-1) retraces would take us to a node which is an integral part of -ve cycle

void solve()
{
    int n,m;
    cin>>n>>m;
  
    vector<vi> edges;
    for(int i=0;i<m;i++){
       int u,v,x; cin>>u>>v>>x;
       edges.pb({u,v,x});
    }
    vector<int> dis(n+1, INF);
    vector<int> par(n+1, -1e7);
  
    int fl = 0, st;
  
    //BELLMAN FORD : 
    for(int i=0; i<n; i++){
        fl = 0;
        for(auto e : edges){
            int u = e[0], v = e[1], wt = e[2];
            if(dis[v] > dis[u] + wt){
                dis[v] = dis[u] + wt;
                par[v] = u;
                st = v;
                fl = 1;
            }
        }
    }
    if(!fl){
        cout<<"NO\n"; return;
    }
  
    cout<<"YES\n";
  
    //trace back n-1 times to get the node
    //which is part of -ve cycle
    //st now currently maybe a node that's
    //leading to a exit node i.e. 
    //one of the neighbour may lead to exit cycle
  
    for(int i=1;i<n;i++){
        st = par[st];
    }
  
    vector<int> path;
    path.pb(st);
  
    int curr = par[st];
    while(curr != st){
        path.pb(curr);
        curr = par[curr];
    }
  
    path.pb(st);
  
    reverse(all(path));
    for(auto e : path) cout<<e<<" ";
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
