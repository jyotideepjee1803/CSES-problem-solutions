#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first 
#define ss second 
#define all(v) v.begin(),v.end()
#define revall(v) v.rbegin(), v.rend()
#define srt(v,l,r) sort(v.begin()+l, v.begin()+r) 
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
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
//APPROACH : Classic knapsack : 
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
int f(int i, int t){
    if(t==0) return 1;

    if(i>n)
    {
        return t==0;
    }

    if(dp[i][t] != -1 ) return dp[i][t];

    int take = 0, notTake = 0;

    if(t - i >= 0){
        take = f(i+1,t-i)%mod;
    }
    notTake = f(i+1,t)%mod;

    return dp[i][t] = (notTake + take)%mod;
}
void solve()
{
    cin>>n;
    int total = n*(n+1)/2;
    //cout<<total<<"\n";
    if(total & 1){
        cout<<"0\n"; return;
    }
    dp.assign(n+1,vector<int>(total/2+1,-1));
    cout<<(f(1,total/2)%mod * binexp(2,mod-2))%mod<<"\n";
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
