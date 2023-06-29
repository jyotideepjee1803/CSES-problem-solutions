#include <bits/stdc++.h>
using namespace std;
#define int long long
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
    int n;
    cin>>n;
 
    vector<int> v(n);
    vector<vector<int>> dp(n, vector<int>(n)); //dp[i][j] = max diff for [i,j] 
 
    int total = 0;
 
    for(int i=0;i<n;i++){
        cin>>v[i];
        dp[i][i] = v[i]; //for one element or segment of len 1, max diff remains the element itself 
        total += v[i];
    }
 
    for(int l=n-1; l>=0; l--)
    {
        for(int r=l+1; r<n; r++){
            //subtracting next diff as :
            //in next state, player2 chooses -> |S2 - S1|
            //currChoice + (S1 - S2) => currChoice - (S2 - S1)
            int left = v[l] - dp[l+1][r];
            int right = v[r] - dp[l][r-1];
 
            dp[l][r] = max(left, right);
        }
    }
 
    //S1 + S2 = total
    //S1 - S2 = maxdiff(0,n-1)
    //S1 = (total + maxdiff(0,n-1))/2
    cout<<(total + dp[0][n-1])/2<<"\n";
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
