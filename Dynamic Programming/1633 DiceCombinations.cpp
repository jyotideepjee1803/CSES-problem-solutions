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
 
vector<int> dp;
 
int f(int n){
    if(n<0) return 0;
    if(n==0) return 1;
 
 
    if(dp[n] != -1) return dp[n];
 
    int total = 0;
    for(int i=1;i<=6;i++){
        total = (total+ f(n-i))%mod;
    }
 
    return dp[n] = total;
}
void solve(){
    int n; cin>>n;
    dp.assign(n+1,-1);
    cout<<f(n);
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
