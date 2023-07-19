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
//APPROACH : DP + Binary Search 
vector<int> dp; 
int prevBest(vector<int>& e, int val)
{
    auto pos= lower_bound(all(e), val);
    if(pos == e.begin())
        return 0;
    
    pos--;
    return 1 + (int)(pos - e.begin()); //+1 for 1 based index    
}
 
int f(int i, vi &e, vector<vector<int>> &p){
    if(i<=0) return 0;
 
    if(dp[i] != -1) return dp[i];
 
    int notTake = f(i-1,e,p);
    int j = prevBest(e, p[i][0]);
    int take = p[i][2] + f(j,e,p);
 
    return dp[i] = max(take, notTake);
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
 
    vector<int> ends;
    for(int i=1;i<=n;i++){
        ends.pb(p[i][1]);
    }
 
    dp.assign(n+1,-1);
    cout<<f(n,ends,p);
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
