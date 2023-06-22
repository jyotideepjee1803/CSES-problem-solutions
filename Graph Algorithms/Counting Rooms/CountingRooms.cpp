//https://cses.fi/problemset/task/1192/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first 
#define ss second
#define all(v) v.begin(),v.end()
#define revall(v) v.rbegin(), v.rend()
#define srt(v,l,r) sort(v.begin()+l, v.begin()+r) 
#define pb push_back
#define pii pair<int,int>
const int mod = 1e9+7;
const int N = 2e5+3;
const int MAXN = 1e6+2;
const int INF = 1e17;
void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
// #ifndef ONLINE_JUDGE
//     freopen("inputf.nxt", "r", stdin);
//     freopen("outputf.nxt", "w", stdout);
// #endif
}
 
//APPROACH : DFS
int n, m;
vector<pii> monster;
vector<vector<char>> g;
vector<vector<int>> vis;
 
pair<int,int> A, B; 
vector<pii> dirs = {{-1,0},{1,0},{0,1},{0,-1}}; 
 
void dfs(int x, int y){
    if(x<0 or x>=n or y<0 or y>=m or vis[x][y]) return;
 
    vis[x][y] = 1;
    for(auto d : dirs){
        int nx = x + d.ff, ny = y + d.ss;
        dfs(nx,ny);
    }
}
 
void solve(){
    cin >> n >> m;
    g.assign(n,vector<char>(m));
    vis.assign(n,vector<int>(m,0));
 
    for(int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin>>g[i][j];
            if(g[i][j] == '#') vis[i][j] = 1;
        }
    }
 
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j]){
                dfs(i,j);
                cnt++;
            }
        }
    }    
 
    cout<<cnt<<"\n";
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
