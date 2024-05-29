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
void solve(){
    cin>>n>>m;
    vector<vector<int>> edges(m);
    for(int i=0;i<m;i++){
        int u,v,x; cin>>u>>v>>x;
        edges[i] = {u,v,x};
    }

    vector<int> dis(n+1,INF), par(n+1,-1);

    for(int i=0;i<n-1;i++){
        for(auto &e: edges){
            int u=e[0], v=e[1], w=e[2];
            if(dis[v] > dis[u] + w){
                par[v] = u;
                dis[v] = dis[u] + w;
            }
        }
    }

    //cycle check : 
    int fl=0,st=-1;
    for(auto &e: edges){
        int u=e[0], v=e[1], w=e[2];
        if(dis[v] > dis[u] + w){
            par[v] = u;
            dis[v] = dis[u] + w;
            fl=1;
            st=v;
        }
    }

    if(!fl){
        cout<<"NO\n"; return;
    }
    cout<<"YES\n";

    // For ref : https://cs.stackexchange.com/a/50558/170471
    //n-1 retraces takes us to the start of this cycle
    //curr node may be an exit node i.e. connected to non cyclic node
    for(int i=0;i<n-1;i++){
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
    reverse(all(path)); //directed graph need to maintain order
    for(auto &e : path) cout<<e<<" ";
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
