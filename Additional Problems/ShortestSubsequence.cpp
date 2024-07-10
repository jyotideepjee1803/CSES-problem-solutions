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

// int dp[N];
// int f(int x, vector<int> &d){
//     if(x == 0){
//         return 0;
//     }

//     if(dp[x] != -1) return dp[x];

//     int ans = INT_MAX;
//     for(auto &e : d){
//         if(x == e) return 0;
//         if(x > e){
//             ans = min(ans, x + f(x-e,d));
//         }
//     }

//     return dp[x] = ans;
// }

void solve(){
    string s; cin>>s;

    string r = "ACGT";
    map<int,int> mp;
    for(int i=0;i<4;i++){
        mp[r[i]]=i;
    }
    vector<int> vis(4);
    vector<int> sub;
    int cnt = 0;
    for(int i=0;i<s.size();i++){
        if(!vis[mp[s[i]]]){
            cnt++;
            vis[mp[s[i]]]++;

            //found all 
            if(cnt == 4){
                sub.pb(i);
                //reset
                cnt = 0;
                vis.assign(4,0);
            }
        }
    }

    for(auto &i : sub) cout<<s[i];
    //from the last vis seq get the not vis
    for(auto ch : r){
        if(!vis[mp[ch]]){
            cout<<ch;
            break;
        }
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
        // cout<<"Set "<<i<<": ";
        solve();
        // i++;
    }
}
