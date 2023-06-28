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
 
int a[MAXN];
void solve(){
    int n; cin>>n;
 
    for(int i=0;i<n;i++) 
        cin>>a[i];
 
    //Binary Search approach :
    vector<int> temp;
    //insert the first element in array : 
    temp.pb(a[0]);
            
    int len = 1;
 
    for(int i=1;i<n;i++){
 
        //if curr is greater than last then simply add it to the array : 
        if(a[i] > temp.back()){
            temp.pb(a[i]);
            len++;
        }
 
        //if smaller than find the correct pos to overwrite so to keep track of LIS : 
        else{
            int pos = lower_bound(all(temp), a[i]) - temp.begin();
 
            //replace the element at pos with curr :
            temp[pos] = a[i];
        }
    }
    cout<<len;
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
