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
    int n,x;
    cin >> n >> x;
 
    vector<int> a(n);
    for (int i = 0; i < n; ++i) 
    cin >> a[i];
 
    sort(all(a));
 
    //each gondola can <= 2 children:
    //pair light + heavy
    vector<int> taken(n,0);
 
    int i = 0, j = n - 1, cnt=0;
    while (i < j) {
        if (a[i] + a[j] <= x) {
            ++cnt; 
            taken[i++] = taken[j--] = true;
        }
        else {   
            --j;
        }
    }
 
    //unpaired children can have their individual gondolas : 
    for (int i = 0; i < n; ++i)
        if(!taken[i]) cnt++;
 
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
