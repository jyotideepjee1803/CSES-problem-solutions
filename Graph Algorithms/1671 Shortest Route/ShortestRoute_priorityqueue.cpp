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


int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int lcm(int a, int b){
    return a/gcd(a,b)*b;
}

int n,m;
vector<vector<pair<int,int>>> g;
vector<int> vis;
vector<int> dis;

void djikstra(){
    dis.assign(n+1,INF);

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0,1});
    dis[1]=0;

    while(pq.size()){
        auto t = pq.top(); pq.pop();
        int u = t.ss, d = t.ff;

        if(d > dis[u]) continue;

        for(auto ch : g[u]){
            int v = ch.ff, w = ch.ss;
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u]+w;
                pq.push({dis[v],v});
            }
        }
    }
}

void solve(){
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
    // cin >> t;
    // int i=1;
    while (t--)
    {
        //cout<<"Case "<<i<<": ";
        solve();
        //i++;
    }
}
