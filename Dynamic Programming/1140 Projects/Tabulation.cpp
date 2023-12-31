#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first 
#define ss second 
#define all(a) a.begin(),a.end()
#define revall(a) a.rbegin(), a.rend()
#define srt(a,l,r) sort(a.begin()+l, a.begin()+r) 
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
const int mod = 1e9+7;
const int MAXN = 2e5+3;
const int INF = 0x3f3f3f3f;
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

//SIMILAR QUESTIONS : 
//LC : 1235. Maximum profit in job scheduling
//LC : 1751. Maximum number of events that can be attended II
int prevBest(vector<int>& e, int val)
{
    auto pos= lower_bound(all(e), val);
    if(pos == e.begin())
        return 0;
    
    pos--;
    return 1 + (int)(pos - e.begin()); //+1 for 1 based index    
}
 
void solve()
{
    int n;
    cin >> n;
    vector<vi> p(n+1, vi(3));
 
    for(int i=1;i<n+1;i++)
        cin>>p[i][0]>>p[i][1]>>p[i][2];
 
    sort(p.begin() + 1, p.end(), [](vi &a, vi &b){
        return a[1] < b[1];
    });
  
    int dp[n+1]; //dp[i] = max prize obtained till ith tasks
    dp[0] = 0;
 
    vector<int> ends;
    for(int i = 1; i < p.size(); i++)
            ends.pb(p[i][1]);
 
    for(int i = 1; i <= n; i++)
    {
        int notTake = dp[i-1], take = 0;
        // find largest j s.t. end point of j is less than start point of i.
        int j = prevBest(ends,p[i][0]);
        take = p[i][2] + dp[j];
        dp[i] = max(take,notTake);
    }
 
    cout<<dp[n];
}
 
int32_t main()
{
    init();
    int t=1;
    while (t--)
    {
       solve();
    }
}
