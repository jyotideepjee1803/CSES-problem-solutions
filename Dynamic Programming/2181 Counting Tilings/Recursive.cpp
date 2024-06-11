#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define ff first 
#define ss second 
#define all(u) u.begin(),u.end()
#define revall(u) u.rbegin(), u.rend()
#define srt(u,l,r) sort(u.begin()+l, u.begin()+r) 
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define piii pair<pii,int>
const int N = 2e5+10;
const int mod = 1e9+7;
const int INF = 1e18+7;
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
 
int n,m;
int dp[1002][1<<11];
 
void placeTiles(int mask, int r, int nmask, vector<int>& newMasks){
    if(r == n + 1){
        newMasks.push_back(nmask);
        return;
    }
      
    //already filled
    if((mask & (1 << r)) != 0) placeTiles(mask, r + 1, nmask, newMasks);
      
    //vertical tile : no impact on next col 
    if(r < n and (mask & (1 << r)) == 0 && (mask & (1 << (r+1))) == 0)
        placeTiles(mask, r + 2, nmask, newMasks);      
     
    //horizontal tile : rth row in next col will also get filled -> include in nmask 
    if((mask & (1 << r)) == 0) placeTiles(mask, r + 1, nmask + (1 << r), newMasks);    
}
 
int f(int j, int mask){
    //by the end of grid, col outside grid shouldn't have any tile
    if(j == m + 1){
        return mask == 0;
    }
 
    if(dp[j][mask] != -1) return dp[j][mask];
 
     //place tiles at the ith colm and determine 
     // all possible masks for next colm
    int cnt = 0;
    vector<int> newMasks;
    placeTiles(mask, 1, 0, newMasks);
 
    for(int nmask: newMasks){
        cnt = (cnt + f(j+1, nmask)) % mod;
    }
 
    return dp[j][mask] = cnt;
}
 
 
void solve()
{
    cin>>n>>m;
    memset(dp,-1,sizeof dp);
    // cout<<n<<m<<"\n";
    cout<<f(1,0);
}
 
int32_t main()
{
    init();
    int t=1;
    // cin >> t;
    // int r=1;
    while (t--)
    {
        //cout<<"Case "<<r<<": ";
        solve();
        //r++;
    }
}
