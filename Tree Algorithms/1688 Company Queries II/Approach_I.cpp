#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int mod = 1e9+7;
const int MAXN = 2e5+5;
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
//APPROACH TAKEN FROM KARTIK ARORA'S EDITORIAL
//THIS APPROACH GIVES TLE for some strict cases in CSES 
 
vector<int> g[MAXN];
//n <= 2e5
//k <= 2e5 => log(k) <= 20
int dp[MAXN][20]; 
int lvl[MAXN];
int n,q;
 
void dfs(int u, int p=-1, int l=0){
    //mark levels : 
    lvl[u] = l;
 
    //2^0 = 1 
    dp[u][0] = p; //immediate par
 
    //for higher levels (2^i): 
    for(int i=1;i<20;i++){
        //if 2^(i-1) level is not reachable
        //then 2^i is also not reachable :
        if(dp[u][i-1] == -1){
            dp[u][i] = -1;
        }
 
        //else take 2^(i-1) jump to a level 'a'
        //then from 'a' take another 2^(i-1) jump
        //to reach 2^i level 
        //2^i level = 2^(i-1) + 2^(i-1) = 2 * 2^(i-1) = 2^i
        else{
            int firstJumpPar = dp[u][i-1];
            dp[u][i] = dp[firstJumpPar][i-1];
        }
    }
 
    for(auto v : g[u]){
        if(v == p) continue;
 
        dfs(v,u,l+1);
    }
}

//lift -> O(logn)
int lift(int u, int jumps){
    for(int i=19; i>=0; i--){
        if(jumps == 0 or u == -1) break;
 
        if(jumps >= (1<<i)){
            u = (dp[u][i]);
            jumps =  (jumps - (1<<i));
        }
    }
 
    return u;
}

//ans is calculated in TC : (logn * logn) i.e O((logn)^2) 
//since within binary search lift() function is called for calculation of LCA 
int ans(int a, int b){
    if(lvl[a] < lvl[b]) swap(a,b);
 
    //parent of a at same lvl with b : 
    int aa = lift(a, lvl[a] - lvl[b]);
 
    int l=0, r=lvl[aa];
    while(l < r){
        int mid = (l+r)/2;
 
        int j1 = lift(aa, mid);
        int j2 = lift(b, mid);
 
        //if found common node,
        //either at LCA or at node higher than LCA  
        //then we can make max jump of mid : 
        if(j1 == j2){
            r = mid;
        }
 
        //make greater jump : 
        else{
            l = mid+1;
        }
    }
 
    return lift(aa, r);
}
 
void solve()
{
    int n,q;
    cin>>n>>q;
 
    for(int i=2;i<=n;i++){
        int e; cin>>e;
        g[i].pb(e);
        g[e].pb(i);
    }
    
    dfs(1);
 
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<ans(a,b)<<"\n";
    }
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
