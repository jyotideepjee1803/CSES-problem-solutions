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

//APPROACH : space optimised tabulation :
void solve(){
    int n;
    cin>>n;

    vector<int> v(n);
    for(auto &e : v) cin>>e;

    int total = accumulate(v.begin(), v.end(), 0ll);
    vector<int> dp(total+1,0); //dp[sum] -> possibe if sum can be formed

    dp[0] = 1; //no sum possible
    for(int i=0;i<n;i++){
        for(int s=total; s>0; --s){
            //if prev sum exists then curr would also exist :
            if(s - v[i] >= 0)
                dp[s] |= dp[s - v[i]];
        }
    }

    vector<int> res;
    for(int i=1;i<=total; i++){
        if(dp[i]) res.pb(i);
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
