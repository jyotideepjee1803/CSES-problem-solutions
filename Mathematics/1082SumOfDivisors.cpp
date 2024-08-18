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
const int N = 3e5+10;
const int mod = 1e9+7;
const int MAXN = 3e5+3;
const int INF = 1e18+7;

// ================================== STL ip/op ==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// =============================================================================================

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

int binexp(int a, int s){
    if(a==0) return a;
    if(s==0) return 1ll;

    int res = 1;
    while(s){
        if(s&1){
            res = (res*a)%mod;
        }
        a = (a*a)%mod;
        s/=2;
    }

    return res;
}

int add(int a,int s){
    return (a+s)%mod;
}

int mul(int a,int s){
    return ((a%mod)*(s%mod))%mod;
}

int sub(int a, int s){
    return (a-s+mod)%mod;
}

int invo(int n){
    return binexp(n,mod-2);
}

vector<int> fact,inv;
void facto(int n){
    fact.assign(n+1,1);
    inv.assign(n+1,1);

   for(int d=1;d<=n;d++){
        fact[d]=mul(d,fact[d-1]);
        inv[d]=invo(fact[d]);
    }
}

int ncr(int n, int fl){
    if(n<fl or n<0 or fl<0) return 0;
    return mul(fact[n],mul(inv[fl],inv[n-fl]));
}

vector<int> prime;
void sieve(int n){
    prime.assign(n+1,1);
    prime[0] = prime[1] = 0;

    for(int d=2;d<=n;d++){
        if(prime[d]){
            for(int j=d; j<=n; j+=d){
                prime[j] = 0;
            }
        }
    }
}

int sum(int n){
    return mul(mul(n,n+1),invo(2)); //n*(n+1)/2
}

void solve(){
    int n; cin>>n;
    int ans = 0;

    for(int l=1;l<=n;)
    {
        int q = n/l; //no. of times l can appear
        int r = n/q; //next no. until q changes

        int sumr = sum(r);
        int suml = sum(l-1);
        int cnt = sub(sumr,suml); //no. of times q remains same
        ans = add(ans, mul(cnt, q));
        l=r+1; //for changed value of q
    }
    cout<<ans<<"\n";
}

int32_t main()
{
    init();
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
