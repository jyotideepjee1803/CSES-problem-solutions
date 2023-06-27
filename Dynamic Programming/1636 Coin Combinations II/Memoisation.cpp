#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
const int MAXN = 1e6+2;
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

vector<vector<int>> dp;
int f(int i, int t, vector<int> &c){
    if (t == 0)
        return 1;

    if (i < 0)
        return 0;

    if (dp[i][t] != -1)
        return dp[i][t];

    if (c[i] <= t) {
        // Pick this coin or not
        return dp[i][t] = (f(i, t - c[i], c) + f(i-1, t, c))%mod;
    }
    else // We leave this coin
        return dp[i][t] =  f(i-1, t, c)%mod;
}

void solve(){
    int n,x;
    cin>>n>>x;

    vector<int> c(n);
    for(auto &e : c) cin>>e;

    dp.assign(n, vector<int>(x+1,-1));
    cout<<f(n-1,x,c);
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
