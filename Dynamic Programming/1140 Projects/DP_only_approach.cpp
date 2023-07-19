#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first 
#define ss second 
#define all(a) a.begin(),a.end()
#define revall(a) a.rbegin(), a.rend()
#define srt(a,l,r) sort(a.begin()+l, a.begin()+r) 
#define pb push_back
#define ai vector<int>
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

//Passes all test cases except 1
//acceptable solution for n <= pow(10,5)
int dp[MAXN];
int n;
int f(int idx, int prev, vector<vector<int>> &p){
 
    if(idx >= n) return 0;
    //this task to be overlooked
    //this case dealt earlier, as when we memoise it, 
    //this state would have some value assigned to it and won't let us skip it
    if(p[idx][0] <= prev) return f(idx+1,prev,p);
 
    if(dp[idx] != -1) return dp[idx];
 
    int take=0, notTake = 0;
    if(p[idx][0] > prev){
        take = p[idx][2] + f(idx+1,p[idx][1],p);
    }
 
    notTake = f(idx+1,prev,p);
 
    return dp[idx] = max(take, notTake);
}
 
void solve()
{   
    cin>>n;
    vector<vector<int>> p;
    for(int i=0;i<n;i++){
        int s,e,m;
        cin>>s>>e>>m;
        p.pb({s,e,m});
    }
    //sorted according to start time : 
    sort(all(p));
 
    memset(dp,-1,sizeof dp);
    cout<<f(0,0,p);
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
