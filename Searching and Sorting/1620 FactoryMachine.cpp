#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define ff first 
#define ss second 
#define all(v) v.begin(),v.end()
#define revall(v) v.rbegin(), v.rend()
#define srt(v,l,r) sort(v.begin()+l, v.begin()+r) 
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
const int mod = 1e9+7;
const int MAXN = 2e5+3;
const int INF = 1e12;
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
 
//Binary power**************************************************************************
int binexp(int a, int b)
{
    if(a==0) return 0;
 
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res * a)%mod;
        }
        a = (a*a)%mod;
        b = b>>1;
    }
 
    return res;
}
//**************************************************************************************
 
// PRIME SIEVE **********************************************************************
vector<bool> isPrime;
void sieve(int n){
    isPrime.assign(n+1,1);
    isPrime[0] = isPrime[1] = 0;
 
    for(int i=2;i<=n;i++){
        if(isPrime[i]){
            for(int r=i*i; r<=n; r+=i){
                isPrime[r] = 0;
            }
        }
    }
}

int check(int m, vi &v, int t){
 
    //products formed 
    int cnt = 0;
 
    for(auto e : v){
        cnt += m/e;
        if(cnt >= t) return 1;
    }
 
    return cnt >= t;
}
 
void solve(){
    int n,t; cin>>n>>t;
 
    vi v(n);
    for(auto &e : v) cin>>e;
 
    //bs on time reqd : 
    int l=0,r=1e18;
    int ans;
    while(l<=r){
        int mid = l + (r-l)/2;
 
        if(check(mid, v, t)){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout<<ans<<"\n";
}
 
int32_t main()
{
    init();
 
    int t=1;
    //cin >> t;
    int i=1;
    while (t--)
    {
        //cout<<"Case "<<i<<": ";
        solve();
        //i++;
    }
}
