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
#define vii vector<vector<int>>
#define pii pair<int,int>
const int mod = 1e9+7;
const int MAXN = 2e5+5;
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

//APPROACH : store the numbers and their indices, in sorted order of value. If the adjacent element have different comparison of indices then need a round
void solve(){
    int n; cin>>n;
    vector<pii> a;
    for(int i=0; i<n; i++){
        int x; cin>>x;
        a.pb({x,i});
    }
    sort(all(a));
    int cnt = 1;
    for(int i=0; i<n-1;i++){
        if(a[i+1].ss < a[i].ss) cnt++;
    }
 
    cout<<cnt<<"\n";
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
