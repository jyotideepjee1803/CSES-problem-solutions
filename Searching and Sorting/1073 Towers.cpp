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
    int n; cin>>n;
    vector<int> a;
    // vector<pii> v;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        // v.pb({x,i});
        a.pb(x);
    }

    vector<int> tow;
    tow.pb(a[0]);

    for(int i=1;i<n;i++){
        auto id = upper_bound(all(tow), a[i]);

        if(id == tow.end()) tow.pb(a[i]);
        else{
            int idx = (id-tow.begin());
            tow[idx] = a[i];
        }
    }

    cout<<tow.size()<<"\n";
    
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
