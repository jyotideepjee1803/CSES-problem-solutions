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
#define pii pair<int,int>
const int mod = 1e9+7;
const int MAXN = 1e6+2;
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
 
void solve(){
    int n; cin>>n;
    vector<pii> times;
 
    for(int i=0;i<n;i++){
        int a,b; cin>>a>>b;
        times.pb({a,1});
        times.pb({b,-1});
    }
 
    sort(all(times), [&](pii a, pii b){
        return a.ff < b.ff;
    });
  
    int mx = 0, cnt = 0;
    for(int i=0;i<times.size();i++){
        if(times[i].ss == 1){
            cnt++;
        }
        else cnt--;
 
        mx = max(mx, cnt);
    }
 
    cout<<mx<<"\n";
    
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
