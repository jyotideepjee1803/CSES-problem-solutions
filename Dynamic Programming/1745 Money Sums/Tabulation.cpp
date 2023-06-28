#include <bits/stdc++.h>
using namespace std;
#define int long long
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
    int n; cin>>n;
  
    vector<int> x(n);
    for(auto &c : x) cin>>c;

    int total = accumulate(all(x), 0ll);
    vector<vector<int>> dp(n+1, vector<int>(total+1, 0));
 
    //dp[i][sum] = possibility to obtain 'sum' using first 'i' x :

    dp[0][0] = 1; //0 elements -> 0 sum => true

    for(int i=1;i<=n;i++){
        for(int s=0;s<=total;++s){
            //notTake : 
            //if till (i-1)th we've got s then we will get it till ith also:
            int notTake = dp[i-1][s];

            //if prev sum possible till (i-1)th 
            //then we can take the curr element to get sum s at ith: 
            int take = 0;
            if(s - x[i-1] >=0){
                take = dp[i-1][s - x[i-1]];
            }
            dp[i][s] = notTake | take;
        }
    }

    vector<int> res;
    for(int i=1;i<=total; i++){
        if(dp[n][i]) res.pb(i);
    }

    cout<<res.size()<<"\n";
    for(auto e : res) cout<<e<<" ";
    cout<<"\n";
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
