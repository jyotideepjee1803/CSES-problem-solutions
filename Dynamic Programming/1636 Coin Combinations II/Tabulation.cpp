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

void solve(){
    int n,x;
    cin>>n>>x;

    vector<int> c(n);
    for(auto &e : c) cin>>e;
    
    dp.assign(n, vector<int>(x+1,0));
    
    //base case : 
    for(int i=0;i<n;i++){
        dp[i][0] = 1; //x == 0
    }
    
    for (int j = 0; j < n; j++) {
        for (int i = 1; i <= x; i++) {
            int take = (i - c[j] >= 0) ? dp[j][i - c[j]] : 0;
            int notTake = (j >= 1) ? dp[j - 1][i] : 0;
            // total count
            dp[j][i] = (notTake + take)%mod;
        }
    }
    cout<<dp[n - 1][x];
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
