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

int f(vector<int> &v, int k, int m){
    int cnt = 1;
    int curr = 0;
    for(auto &e : v){
        if(curr+e > m){
            curr = e;
            cnt++;
        }
        else curr += e;
    }

    return cnt <= k;
}

void solve()
{
    int n,k; cin>>n>>k;
    vi v(n);
    for(auto &e : v) cin>>e;

    int l=0,r=0;
    for(auto &e : v)
    {
        l = max(l,e);
        r += e;
    }

    int ans = -1;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(f(v,k,mid)){
            ans = mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout<<ans<<"\n";
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
