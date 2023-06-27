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

    //w.r.t previous tabulation approach we drop the index state
    //as we update the value of DP[] for each value of total <= x :
    vector<int> dp(x+1,0);
 
    for(int t=0; t<=x; t++){
        if(t%c[0] == 0){
            dp[t] = t/c[0];
        }
        else dp[t] = 1e9;   
    }
    
    for(int i=1;i<n;i++){
        for(int t=0; t<=x; t++){
            int take = 1e9;
            if(t - c[i] >= 0){
                take = 1 + dp[t-c[i]];
            }
            int notTake = dp[t];
          
            dp[t] = min(take, notTake);
        }
    }
    int ans = dp[x];
    cout<<(ans>=1e9 ? -1 : ans);
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
