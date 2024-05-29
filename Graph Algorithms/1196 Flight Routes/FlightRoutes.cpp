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
    int k; cin>>n>>m>>k;
    vector<vector<pii>> g(n+1);
 
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        g[u].pb({v,w});
    }    
 
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0,1});
 
    vector<int> cnt(n+1);
    while(!pq.empty() and cnt[n]<k){
        auto t = pq.top();
        pq.pop(); 
 
        int a = t.ss,d = t.ff;
        
        cnt[a]++;
        
        if (a==n) cout<<(d)<<" ";
        
        if (cnt[a] > k) continue;
        
        for (auto ch : g[a]){
            int w = ch.ss, b = ch.ff;
            pq.push({d+w,b});
        }
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
