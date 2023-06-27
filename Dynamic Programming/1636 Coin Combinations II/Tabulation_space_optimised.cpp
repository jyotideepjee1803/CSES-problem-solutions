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


void solve(){
    int n,x;
    cin>>n>>x;

    vector<int> c(n);
    for(auto &e : c) cin>>e;

    int dp[x + 1];
 
    memset(dp, 0, sizeof(dp));
 
    // for sum 0 -> always 1 way(no selection) :
    dp[0] = 1;

    for (int i = 0; i < n; i++)
        for (int j = c[i]; j <= x; j++)
            dp[j] = (dp[j] +  dp[j - c[i]])%mod;

    cout<<dp[x];
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
