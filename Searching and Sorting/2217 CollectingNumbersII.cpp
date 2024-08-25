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
    int n,m; cin>>n>>m;
    vi a(n), pos(n+2);
    for(int i=0;i<n;i++){
        cin>>a[i];
        pos[a[i]] = i+1;
    }
 
    //set pos for 0 and n+1 as well
    pos[0] = 0;
    pos[n+1] = n+1;
 
    int rounds = 1;
    for(int i=1;i<n;i++){
        if(pos[i] > pos[i+1]) rounds++;
    }
 
    //cout<<rounds<<"\n";
    set<pii> updates;
    while(m--){
        int i,j; cin>>i>>j;
 
        int pehla = a[i-1], dusra = a[j-1];
        //cout<<pehla<<" "<<dusra<<"\n\n";
 
        updates.insert({pehla, pehla+1});
        updates.insert({pehla-1, pehla});
 
        updates.insert({dusra, dusra+1});
        updates.insert({dusra-1, dusra});
 
        //smaller value appears later :
        //decrease rounds as after swapping these may get in correct order
        for(auto p : updates){
            if(pos[p.ff] > pos[p.ss]) rounds--; 
        }
 
        //update : 
        swap(a[i-1],a[j-1]);
        pos[a[i-1]] = i;
        pos[a[j-1]] = j;
 
 
        //smaller value appears later :
        //increase rounds as these require more rounds to be in correct order
        for(auto p : updates){
            if(pos[p.ff] > pos[p.ss]) rounds++; 
        }
      
        cout<<rounds<<"\n";
        updates.clear();
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
