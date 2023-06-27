#include<bits/stdc++.h>
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
 
//memoisation : fails some TCs
vector<vector<int>> dp;
int f(int i, int x, vector<int> &c){
    if(i==0){
        if(x%c[i] == 0){
            return x/c[i];
        }
        return 1e9;
    }
 
    if(dp[i][x] != -1) return dp[i][x];
 
    int take = 1e9;
    if(x - c[i] >= 0){
        take = 1 + f(i,x-c[i], c);
    }
 
    int notTake = f(i-1, x, c);
 
    return dp[i][x] = min(take, notTake);
}

void solve(){
    int n,x; 
    cin>>n>>x;
 
    vector<int> c(n);
    for(auto &e : c) cin>>e;
 
    dp.assign(n, vector<int>(x+1, -1));
 
    int res = f(n-1,x,c);
 
    if(res >= 1e9){
      cout<<"-1\n";
      return;
    }
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
