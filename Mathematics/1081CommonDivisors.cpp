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
const int N = 3e5+10;
const int mod = 998244353;
const int MAXN = 1e6+3;
const int INF = 1e18+7;

// ================================== STL ip/op ==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// =============================================================================================

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
int mp[MAXN];
void solve(){
    int n=1,m=0;
    string s;
    cin>>n;
    vi v(n);
    for(auto &e : v){
        cin>>e;
        mp[e]++;
    }
    //O(N*sqrt(mx))
    // int mx = *max_element(all(v))
    // vi dp(mx+1); //dp[i] - freq of i as divisors of a no.
    // for(auto &e : v){
    //     for(int j=1; j<=(int)sqrt(e); j++){
    //         if(e%j == 0){
    //             dp[j]++;
    //             if(j != e/j){
    //                 dp[e/j]++;
    //             }
    //         }
    //     }
    // }
    // for(int i=mx; i>=1; i--){
    //     if(dp[i] > 1){
    //         cout<<i<<"\n";
    //         return;
    //     }
    // }

    //Approach: Iterate across all possible GCDs
    //find the count of multple of GCDs in the array
    //O(mx*log(mx))
    for(int g=MAXN;g>=1;g--){
        int cnt = 0;
        for(int j=g;j<=MAXN;j+=g){
            cnt += mp[j];
        }
        if(cnt >= 2){
            cout<<g<<"\n";
            return;
        }
    }
}

int32_t main()
{
    init();
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
