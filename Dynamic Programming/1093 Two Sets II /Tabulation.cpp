#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
const int MAXN = 1e5+5;
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
//APPROACH : classic knapsack tabulation : 
int binexp(int a, int b)
{
    if(a==0) return 0;

    int  res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (1ll * res * a)%mod;
        }
        a = (1ll* a*a)%mod;
        b = b>>1;
    }

    return res%mod;
}

int n;
vector<vector<int>> dp;
void solve()
{
    cin>>n;
    int total = n*(n+1)/2;
    //cout<<total<<"\n";
    if(total & 1){
        cout<<"0\n"; return;
    }

    dp.assign(n+1,vector<int>(total/2+1,0));
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int t = 0; t<=total/2; t++){
            int notTake = dp[i-1][t];
            int take = 0;

            if(t - i >= 0) take = dp[i-1][t-i];

            dp[i][t] = (notTake + take)%mod;
        }
    }
    cout<<((dp[n][total/2])%mod * (binexp(2,mod-2)))%mod<<"\n";
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
