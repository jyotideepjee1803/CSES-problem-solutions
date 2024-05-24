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
const int mod = 998244353;
const int MAXN = 3e5+3;
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

void solve()
{
    int n,k; cin>>n;
    vi v(n);
    for(auto &e : v) cin>>e;

    map<int,int> mp;
    mp[0] = 1;

    // vector<int> pre(n);
    // pre[0] = (v[0]+n)%n;
    // for(int i=1;i<n;i++){
    //     pre[i] = (pre[i-1] + v[i]%n + n)%n;
    // }
    
    int pj = 0;
    int cnt = 0;
    for(int j=0;j<n;j++){
        //key : (pj - pi-1)%n = 0
        pj = (pj + v[j]%n + n)%n;

        int pi = (pj+n)%n;
        // int pi = (pre[j]+n)%n;
        if(mp.count(pi)) cnt += mp[pi];

        mp[pj]++;
    }
    cout<<cnt<<"\n";
}

int32_t main()
{
    init();
    int t=1;
    // cin >> t;
    // int i=1;
    while (t--)
    {
        //cout<<"Case "<<i<<": ";
        solve();
        //i++;
    }
}
