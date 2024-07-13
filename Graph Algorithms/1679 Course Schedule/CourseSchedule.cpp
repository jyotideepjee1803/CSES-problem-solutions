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

void solve(){
    int n,m; cin>>n>>m;
    vector<vector<int>> g(n+1);
    vector<int> deg(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v; cin>>u>>v;
        g[u].pb(v);
        deg[v]++;
    }

    vector<int> vis(n+1);
    vector<int> order;

    queue<int> q;
    for(int i=1;i<=n;i++){
        if(deg[i] == 0){
            q.push(i);
        }
    }

    while(q.size()){
        auto f = q.front(); q.pop();
        vis[f]=1;
        order.pb(f);

        for(auto u : g[f]){
            if(!vis[u]){
                deg[u]--;
                if(deg[u] == 0)
                    q.push(u);
            }
        }
    }

    if(order.size() != n){
        cout<<"IMPOSSIBLE\n";
        return;
    }

    for(int i=0;i<order.size();i++){
        cout<<order[i]<<" ";
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
