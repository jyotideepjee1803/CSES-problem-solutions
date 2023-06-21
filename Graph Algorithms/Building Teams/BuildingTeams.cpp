// https://cses.fi/problemset/task/1668
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
const int INF = INT64_MAX;
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

//APPROACH : To segregate the friends into different groups, form a graph and check for bipartite
vector<vector<int>> g;
vector<int> color;

int isBipartite = 1;

void bfs(int u){
    queue<int> q;
    q.push(u);
    color[u] = 0;

    while(!q.empty()){
        int curr = q.front(); q.pop();

        for(auto v: g[curr]){
            if(color[v] == -1){
                color[v] = color[curr]^1;
                q.push(v);
            }
            else{
                isBipartite &= (color[curr] != color[v]);
            }
        }
    }
}

void dfs(int u, int c){
    color[u] = c;

    for(auto v : g[u]){
        if(color[v] == -1){
            dfs(v,c^1);
        }

        else{
            isBipartite &= (color[v] != color[u]);
        }
    }
}

void solve() {
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    color.assign(n+1,-1);
    while(m--){
        int u,v; cin>>u>>v;
        g[u].pb(v); g[v].pb(u);
    }

    for(int i=1;i<=n;i++){
        if(color[i] == -1){
            bfs(i);
            // dfs(i,0);
        }
    }
    if(isBipartite){
        for(int i=1;i<=n;i++){
            cout<<(color[i] ? 1 : 2)<<" ";
        }
        return;
    }
    cout<<"IMPOSSIBLE\n";
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
