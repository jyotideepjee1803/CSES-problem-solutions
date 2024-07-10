#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define ff first 
#define ss second 
#define all(u) u.begin(),u.end()
#define revall(u) u.rbegin(), u.rend()
#define srt(u,lo,hi) sort(u.begin()+lo, u.begin()+hi) 
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define piii pair<pii,int>
const int N = 1e4+10;
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

int binexp(int a, int b){
    if(a==0) return a;
    if(b==0) return 1ll;

    int res = 1;
    while(b){
        if(b&1){
            res = (res*a)%mod;
        }
        a = (a*a)%mod;
        b/=2;
    }

    return res;
}

int add(int a,int b){
    return (a+b)%mod;
}

int mul(int a,int b){
    return (a*b)%mod;
}

int sub(int a, int b){
    return (a-b+mod)%mod;
}

int invo(int n){
    return binexp(n,mod-2);
}

// vector<int> fact,inv;
// void facto(int n){
//     fact.assign(n+1,1);
//     inv.assign(n+1,1);

//    for(int i=1;i<=n;i++){
//         fact[i]=mul(i,fact[i-1]);
//         inv[i]=invo(fact[i]);
//     }
// }

// int ncr(int n, int hi){
//     if(n<hi or n<0 or hi<0) return 0;
//     return mul(fact[n],mul(inv[hi],inv[n-hi]));
// }

vector<int> prime;
void sieve(int n){
    prime.assign(n+1,1);
    prime[0] = prime[1] = 0;

    for(int i=2;i<=n;i++){
        if(prime[i]){
            for(int j=i; j<=n; j+=i){
                prime[j] = 0;
            }
        }
    }
}

map<int,int> dp;
int f(int n){
    if(n == 0) return 0;
  
    if(dp[n]) return dp[n];
 
    int p = log2(n);
    // cout<<n<<" "<<p<<"\n";
    // p columns have 2^(p-1) ones in each
 
    int ones = (1ll<<(p-1))*p;
    ones += (n - (1ll<<p) + 1);
    return dp[n] = ones + f(n - (1ll<<p));
}
void solve(){
    int n; 
    cin>>n;
    cout<<f(n)<<"\n";
}

int32_t main()
{
    init();
    int t=1;
    // cin >> t;
    // int i=1;
    while (t--)
    {
        // cout<<"Set "<<i<<": ";
        solve();
        // i++;
    }
}
