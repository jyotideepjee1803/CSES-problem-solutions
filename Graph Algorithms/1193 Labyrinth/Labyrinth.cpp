//https://cses.fi/problemset/task/1193/
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
//     freopen("inputf.txt", "r", stdin);
//     freopen("outputf.txt", "w", stdout);
// #endif
}
 
//APPROACH : BFS
int n,m;
pii A, B;
vector<vector<pii>> path;
vector<vector<int>> vis;
 
vector<pii> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
 
void bfs(){
    queue<pii> q;
    q.push(A);
 
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        int x = cur.ff, y = cur.ss;
 
        for(int i=0; i<4; ++i){
            auto d = dirs[i];
            int nx = x + d.ff, ny = y + d.ss;
 
            if(nx>=0 and nx<n and ny>=0 and ny<m and !vis[nx][ny]){
                q.push({nx,ny});
                vis[nx][ny] = 1;
                path[nx][ny] = {d.ff,d.ss};
            }
        }
    }
}
 
void solve(){
    cin>>n>>m;
    path.assign(n, vector<pii>(m,{-1,-1}));
    vis.assign(n,vector<int>(m,0));
 
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            char c; cin>>c;
            if(c=='#') vis[i][j] = 1;
            if(c=='A') A = {i,j};
            if(c=='B') B = {i,j};
        }
    }
    //couldn't reach end : 
    bfs();
    if(!vis[B.ff][B.ss]){
        cout<<"NO\n"; return;
    }
 
    cout<<"YES\n";
    string ans;
    while(B.ff != A.ff or B.ss != A.ss)
    {
       auto c  = path[B.ff][B.ss];
        char ch;
 
        if(c.ff == 1 and c.ss ==0) ch = 'D';
        else if(c.ff == -1 and c.ss ==0) ch = 'U';
        else if(c.ff == 0 and c.ss == 1) ch = 'R';
        else if(c.ff == 0 and c.ss == -1) ch = 'L';
    
        ans.push_back(ch);
        B.ff -= c.ff;  B.ss -= c.ss;	
    }
    reverse(ans.begin(), ans.end());
    cout<< ans.size() << endl<<ans<<"\n";
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
