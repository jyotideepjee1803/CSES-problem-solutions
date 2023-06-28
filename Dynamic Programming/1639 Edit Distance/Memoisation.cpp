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

int dp[5002][5002];

int f(int i, int j, string &s1, string &s2){
    //both exhausted :
    if(i<0 and j<0) return 0;
  
    //if s1 exhausts, but s2 remaining
    //then add those many characters 
    if(i < 0) return (j+1); //idx+1 no. of chars remaining : 

    //if s2 exhausts, but s1 remaining
    //then add those many characters 
    else if(j < 0) return (i+1); //idx+1 no. of chars remaining : 

    if(dp[i][j] != -1) return dp[i][j];

    //chars matched no op move to next in both : 
    if(s1[i] == s2[j]){
        return dp[i][j] = f(i-1,j-1,s1,s2);
    }

    else{
        //remove non-match / add-match char in s1 : 
        int remadd1 = f(i-1,j,s1,s2);

        //remove non-match / add-match char in s2 : 
        int remadd2 = f(i,j-1,s1,s2);

        //replace non-match char in either and move to next in both :
        int rep = f(i-1,j-1,s1,s2);

        //perform 1 op among these :
        return dp[i][j] = 1 + min({remadd1, remadd2, rep});
    }
}

void solve(){
    string s1, s2;
    cin>>s1>>s2;

    int n = s1.size(), m = s2.size();

    memset(dp,-1,sizeof dp);
    cout<<f(n-1,m-1,s1,s2);
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
