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
 
void solve(){
    int n; cin>>n;
    vector<pii> mov;
    for(int i=0;i<n;i++){
        int a,b; cin>>a>>b;
        mov.pb({b,a});
    }
 
    sort(all(mov));
    int last_end = 0, done = 0;
    for(int i=0;i<n;i++){
        //if new movie starts after the end of last movie then we can watch the last movie completely
        if(mov[i].ss >= last_end){
            done++;
            last_end = mov[i].ff;
        }
    }
 
    cout<<done<<"\n";
 
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
