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
    int n,m,k; cin>>n>>m>>k;
    vector<int> a(n), b(m);
 
    for(auto &e : a) cin>>e;
    for(auto &e : b) cin>>e;
 
    sort(all(a));
    sort(all(b));
 
    int i=0,j=0,cnt=0;
    while(i<n and j<m){
        if(abs(a[i] - b[j]) <= k){
            i++; j++; cnt++;
        }
 
        else{
            if(a[i] - b[j] > k){
                j++; //if more desire then check larger apartments 
            }
            else{
                //if less desire than current, move to next appl
                i++;
            }
        }
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
