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
    int n,m; cin>>n>>m;
    vector<int> maxp(n);
    
    for(auto &e : maxp) cin>>e;
    multiset<int> ms(all(maxp));

    while(m--)
    {
        int cus; cin>>cus;
        auto it = ms.upper_bound(cus);
 
        if(it == ms.begin()){
            cout<<"-1\n";
        }
        else{
            cout<<*(--it)<<"\n";
            ms.erase(it);
        }
    }
    
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
