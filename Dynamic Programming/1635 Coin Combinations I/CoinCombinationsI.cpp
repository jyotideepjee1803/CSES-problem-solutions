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
//COIN COMBINATIONS I :
//Asks us to find the no. of distinct ways of getting a sum
//Whereas in part II we're asked about distinct orderings 

//For a sum 9 :
//2,2,5 and 5,2,2 and 2,5,2 will be considered distinct in part I
//but in part II our algo takes each denomination in the order of their occurence 
//so these will be considered same in part II
void solve(){
    int n,x;
    cin>>n>>x;

    vector<int> c;
    for(int i=0;i<n;i++){
        int e; cin>>e; 
        c.pb(e);
    }

    //dp[t] -> no. of ways to form sum = t:
    vector<int> dp(x+1,0);

    dp[0] = 1; //zero sum -> 1 way : no selection 

    //for every val of sum : 
    for(int t=1; t<=x; t++){

        //go across all denominations : 
        for(int i=0; i<n; i++){
            
            if(t - c[i] >= 0)
                dp[t] = (dp[t] + dp[t-c[i]])%mod;
        }
    }
    cout<<dp[x]<<"\n";
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
