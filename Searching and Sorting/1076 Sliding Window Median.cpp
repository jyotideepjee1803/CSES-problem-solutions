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


int k;
multiset<int> lef,ri;
 
void add(int v){
    int med = *lef.rbegin();

    //smaller element -> left
    //greater element -> right
    if(med < v){
        ri.insert(v);
        if(ri.size() > k/2){
            lef.insert(*ri.begin());
            ri.erase(ri.find(*ri.begin()));
        }
    }else{
        lef.insert(v);
        if(lef.size() > (k+1)/2){
            ri.insert(*lef.rbegin());
            lef.erase(lef.find(*lef.rbegin()));
        }
    }
}
 
void remove(int val){
    if(lef.find(val) != lef.end()) lef.erase(lef.find(val));
    else ri.erase(ri.find(val));
 
    if(lef.empty()){
        lef.insert(*ri.begin());
        ri.erase(ri.find(*ri.begin()));
    }
}

int getMedian(){
    return *lef.rbegin();
}

void solve()
{
    int n; cin>>n>>k;
    vi v(n);
    for(auto &e : v) cin>>e;
 
    if(k==1){
        for(auto e : v)cout<<e<<" ";
        return;
    }
 
    lef.insert(v[0]);
    for(int i=1;i<k;i++){
        add(v[i]);
    }

    for(int i=k;i<=n;i++){
        cout<<getMedian()<<" ";
        
        if(i>=n) break;
        remove(v[i-k]);
        add(v[i]);
    }

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
