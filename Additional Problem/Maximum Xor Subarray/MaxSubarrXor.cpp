#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first 
#define ss second 
#define all(v) v.begin(),v.end()
#define revall(v) v.rbegin(), v.rend()
#define srt(v,l,r) sort(v.begin()+l, v.begin()+r) 
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
const int mod = 1e9+7;
const int MAXN = 1e5+5;
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

//Trie Node : 
struct Node{
    Node *a[2];
};

Node *root;
void insert(int n){
    Node *curr = root;
    for(int i=31; i>=0; i--){
        int b = (n & (1<<i));
        int bit = (b>0) ? 1 : 0;

        if(!curr->a[bit]){
            curr->a[bit] = new Node();
        }

        curr = curr->a[bit];
    }
}

int maxXor(int n){
    Node *curr = root;
    int res = 0;

    for(int i=31; i>=0; i--){
        int b = (n&(1<<i));
        int bit = (b>0) ? 1 : 0;

        if(curr->a[bit^1]){
            res |= (1<<i);
            curr = curr->a[bit^1];
        }
        else{
            curr = curr->a[bit];
        }
    }

    return res;
}

void solve()
{
    int n; cin>>n;
    vector<int> a(n);
    for(auto &e : a) cin>>e;
 
    root = new Node();
    insert(0);
    int preXor = 0, ans = 0;
    for(auto e : a){
        preXor ^= e;
        insert(preXor);

        ans = max(ans, maxXor(preXor));
    }

    cout<<ans<<"\n";
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
