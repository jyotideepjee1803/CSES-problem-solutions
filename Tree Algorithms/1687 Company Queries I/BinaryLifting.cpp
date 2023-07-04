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
const int MAXN = 2e5+5;
const int INF = INT64_MAX;
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
 
vector<int> g[MAXN];
//n <= 2e5
//k <= 2e5 => log(k) <= 20
int dp[MAXN][20]; 
int n,q;

//Binary Lifting -> Memory Efficient technique to answer queries in shorter runtime :
//DFS -> O(n)
void binaryLift(int u, int p=-1){
    //2^0 = 1 
    dp[u][0] = p; //immediate par
 
    //for higher levels (2^i): 
    for(int i=1;i<20;i++){
        //if k^(i-1) level is not reachable
        //then k^i is also not reachable :
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
 
        binaryLift(v,u);
    }
}
 
int ans(int u, int jumps){
    if(u==-1 or jumps == 0) return u;
 
    //take the largest jump : 
    for(int i=19; i>=0; i--){
        if(jumps >= (1<<i)){
            return ans(dp[u][i], jumps - (1<<i));
        }
    }
}
 
void solve(){
    cin>>n>>q;
 
    for(int i=2;i<=n;i++){
        int e; cin>>e;
        //cout<<i<<"->"<<e<<"\n";
        g[e].pb(i);
        g[i].pb(e);
    }
 
    binaryLift(1);
 
    //q * logn :
    while(q--){
        int x,k;
        cin>>x>>k;
 
        cout<<ans(x,k)<<"\n";
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
