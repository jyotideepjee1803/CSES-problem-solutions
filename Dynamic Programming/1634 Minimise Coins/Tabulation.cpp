//Also check the space optimised approach related to tabulation

//Tabulation :
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
 
    vector<vector<int>> dp(n,vector<int>(x+1,0));
 
    for(int t=0; t<=x; t++){
 
        if(t%c[0] == 0){
            dp[0][t] = t/c[0];
        }
        else dp[0][t] = 1e9;
        
    }
    
    for(int i=1;i<n;i++){
        for(int t=0; t<=x; t++){
            int take = 1e9;
            if(t - c[i] >= 0){
                take = 1 + dp[i][t-c[i]];
            }
 
            int notTake = dp[i-1][t];
 
            dp[i][t] = min(take, notTake);
        }
    }
 
 
    int res = dp[n-1][x];
 
    if(res >= 1e9){ cout<<"-1\n"; return;}
    cout<<res<<"\n";
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
