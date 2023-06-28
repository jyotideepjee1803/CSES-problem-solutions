#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
const int MAXN = 1e6+2;
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
    vector<int> a(n);
    for(int i=0;i<n;i++) 
        cin>>a[i];
 
    //dp[i][term] -> no. of ways to fill array 
        //till i indeterm if term = term
    vector<vector<int>> dp(n+1, vector<int>(m+1,0));
 
    //base cases : 
    // if 0th idx occupied then only that term can be assigned in 1 way : 
    if(a[0]){
        dp[0][a[0]] = 1;
    }
 
    //if 0th idx vacant then any term can be assigned :
    else{
        for(int i=1;i<=m;i++){
            dp[0][i] = 1;
        }
    }
 
    for(int i=1;i<n;++i){
    
        //present :
        if(a[i])
        {
            //add the no. of ways : 
            int term = a[i];
            int same = dp[i-1][term];
            int less = (term-1 >= 1 ? dp[i-1][term-1] : 0);
            int more = (term+1 <=m ? dp[i-1][term+1] : 0);
            
            dp[i][term] = (same + less + more)%mod;
        }
 
        //missing :
        else
        {
            //check among 1->m :
            for(int term = 1; term<= m; term++)
            {
                //same no. in prev idx :
                int same = dp[i-1][term];
 
                //one less in prev idx :
                int less = (term-1 >= 1 ? dp[i-1][term-1] : 0);
                
                //one more in prev idx : 
                int more = (term+1 <=m ? dp[i-1][term+1] : 0);
 
                dp[i][term] = (same + less + more)%mod;
            }
        }
    }
 
    int res = 0;
    for(int i=1;i<=m;i++){
        res = (res + dp[n-1][i])%mod;
    }
 
    cout<<res<<"\n";
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
