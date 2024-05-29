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
vector<vector<int>> g;
void solve(){
    cin>>n>>m;
    g.assign(n+1,{});
    vector<int> deg(n+1,0);
 
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        g[a].pb(b);
        deg[b]++;
    }
    vector<int> dis(n+1,-INF), par(n+1,-1);
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(deg[i] == 0) q.push(i);
    }

    vector<int> ord;
    while(q.size()){
        auto f = q.front(); q.pop();
        ord.pb(f);

        for(auto v : g[f]){
            if(deg[v]){
                deg[v]--;
                if(deg[v] == 0) q.push(v);
            }
        }
    }

    if(ord.size() != n){
        cout<<"IMPOSSIBLE\n";
        return;
    }

    dis[1] = 0;
    for(auto &u : ord){
        for(auto v : g[u]){
            if(dis[u] != -INF and dis[v] < 1+dis[u]){ //to find the longest route, compare opposite to find the shortest route
                dis[v] = 1+dis[u];
                par[v] = u;
            }
        }
    }

    if(dis[n] == -INF){
        cout<<"IMPOSSIBLE\n";
        return;
    }

    vector<int> path;
    int curr = n;
    while(curr != 1){
        path.pb(curr);
        curr = par[curr];
    }

    path.pb(1);
    reverse(all(path));
    cout<<path.size()<<"\n";
    for(auto &e : path){
        cout<<e<<" ";
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
