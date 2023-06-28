#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
const int MAXN = 2e5+2;
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
//APPROACH : DP Bottom Up approach but gives TLE for high constraints : 
int dp[MAXN], a[MAXN];
void solve(){
    int n; 
    cin>>n;
 
    for(int i=0;i<n;i++) 
        cin>>a[i];
 
    //dp[i] -> length of LIS till ith index :
    for(int i=0;i<n;i++){
        dp[i] = 1;
    }
 
    for(int i=0;i<n;i++){
        for(int prev=0; prev<i; prev++){
            if(a[prev] < a[i]){
                dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }
    }
 
    int mx = 0;
    for(int i=0; i<n; i++){
        mx = max(mx, dp[i]);
    }
 
    cout<<mx<<"\n";
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
