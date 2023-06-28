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
    string s1, s2;
    cin>>s1>>s2;
    int n = s1.size(), m = s2.size();
 
    //dp[i][j] -> min ops till i length of s1 and j length of s2 : 
    int dp[n+1][m+1];
 
    for(int i=0;i<=n;i++)
    {
        for(int j=0; j<=m; j++){
            //shifted states : 
 
            //if s1 exhausts, but s2 remaining
            //then add those many characters 
            if(i == 0) dp[i][j] = j;
 
            //if s2 exhausts, but s1 remaining
            //then add those many characters 
            else if(j == 0) dp[i][j] = i; 
 
            //chars matched no op move to next in both : 
            else if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
 
            else{
                //remove non-match / add-match char in s1 : 
                int remadd1 = dp[i-1][j];
 
                //remove non-match / add-match char in s2 : 
                int remadd2 = dp[i][j-1];
 
                //replace non-match char in either and move to next in both :
                int rep = dp[i-1][j-1];
 
                //perform 1 op among these :
                dp[i][j] = 1 + min({remadd1, remadd2, rep});
            }
        }
    }
    cout<<dp[n][m];
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
