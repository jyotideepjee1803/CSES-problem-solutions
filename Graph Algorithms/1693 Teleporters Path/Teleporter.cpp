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

//APPROACH
//Condition for EULERIAN PATH in Directed Graph
//At most one node has outDeg - inDeg = 1
// and at most one node has inDeg - outDeg = 1

vector<vector<int>> g;
vector<int> ans;
void dfs(int u){
    auto &edges = g[u];
    while(edges.size()){
        int  v = edges.back();
        edges.pop_back();

        dfs(v);
    }
    ans.pb(u);
}

void solve(){
    int n,m; cin>>n>>m;
    g.resize(n+1);

    vector<int> in(n+1), out(n+1);
    int i=0;
    while(i<m){
        int u,v; cin>>u>>v;
        g[u].pb(v);
        in[v]++; out[u]++;
        i++;
    }

    int fl = 1;
    for (int node = 2; node <n; node++) {
        if (in[node] != out[node]) { 
            fl = 0; 
            break;
        }
    }

    //for 1 : outDeg - inDeg == 1
    //for n : inDeg - outDeg == 1
    if (out[1] - in[1] != 1 || in[n] - out[n] != 1 || fl==0) {
        cout << "IMPOSSIBLE";
        return;
    }

    dfs(1);
    if(ans[0] == n and ans.size() == m+1){
        for(int i=ans.size()-1; i>=0; i--){
            cout<<ans[i]<<" ";
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
