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
const int mod = 1e9+7;
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

//APPLY BINARYLIFT TO FIND THE Kth NODE
int n,m;
int dp[N][31];

int jump(int u, int k){
    for(int i=30; i>=0; i--){
        if(u == -1 or k == 0) break;
        if(k >= (1<<i)){
            u = dp[u][i];
            k -= (1<<i);
        }
    }
 
    return u;
}

void solve(){
    cin>>n>>m;
    vector<int> t(n+1);
    for(int i=1;i<=n;i++){
        cin>>t[i];
    }

    //immediate parents:
    for(int i=1;i<=n;i++){
        dp[i][0] = t[i];
    }

    for(int i=1;i<=30;i++){
        for(int u=1;u<=n;u++){
            int prev = dp[u][i-1];
            dp[u][i] = dp[prev][i-1]; 
        }
    }

    while(m--){
        int u,k; //k ~ 1e9
        cin>>u>>k; 

        cout<<jump(u,k)<<"\n";
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
