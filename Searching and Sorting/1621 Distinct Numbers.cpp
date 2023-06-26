#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(),v.end()
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
    vector<int> a(n);
 
    for(auto &e : a) cin>>e;
    sort(all(a));
    int cnt = 0;
    for(int i=0;i<n-1;i++){
        if(a[i] != a[i+1]) cnt ++;
    }
 
    cout<<cnt+1<<"\n";
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
