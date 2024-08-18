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
const int MAXN = 3e5+3;
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

void solve(){
    int n,k; cin>>n>>k;
    vi v(k);
    cin>>v;

    vi freq(k+1,0);
    for(int i=0; i<(1<<k); i++){
        int divisors = 0;
        int cnt = n;
        for(int j=0;j<k;j++){
            if(i&(1<<j)){
                divisors++;
                cnt /= v[j];
            }
        }
        // cout<<divisors<<"\n";
        freq[divisors] += cnt;
    }

    int total = 0;
    for(int i=1;i<=k;i++){
        if(i%2 == 0){
            total -= freq[i];
        }
        else{
            total += freq[i];
        }
    }
    cout<<total<<"\n";
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
