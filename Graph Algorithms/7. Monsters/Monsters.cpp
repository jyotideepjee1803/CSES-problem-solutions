//https://cses.fi/problemset/task/1194/
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
 
//APPROACH : BFS
int n, m;
vector<pii> monster;
vector<vector<int>> g;
vector<vector<pii>> path;
pair<int,int> A, B; 
vector<pii> dirs = {{-1,0},{1,0},{0,1},{0,-1}}; 
 
bool bfsA()
{
    queue<pair<pii,int>> q;
    q.push(make_pair(A,0));
    path[A.ff][A.ss] = {-1,-1};
 
    while(!q.empty())
    {
        auto curr = q.front(); q.pop();
        int x = curr.ff.ff, y = curr.ff.ss, currTime = curr.ss; 
        int nextTime = currTime+1; 
 
        for(auto d: dirs)
        {
            int nx = x+d.ff, ny = y+d.ss;
 
            //update g[nx][ny] if valid and if A reached earlier than monster :
            if(nx>=0 and nx<n and ny>=0 and ny<m and nextTime < g[nx][ny])
            {
                //reached edge : 
                if(nx == 0 or ny == 0 or nx == n-1 or ny == m-1){
                    path[nx][ny] = {d.ff,d.ss};
                    B = {nx,ny}; return true; 
                }
 
                path[nx][ny] = {d.ff,d.ss};
                g[nx][ny] = nextTime;
                q.push({{nx,ny}, nextTime});
            }
        }
    }
    return false;
}
 
void preMonsters()
{
    queue<pair<pii,int>> q;
 
    for(auto m: monster)
    {
        q.push(make_pair(m,0));
    }
 
    while(!q.empty())
    {
        auto curr = q.front(); q.pop();
        int x = curr.ff.ff, y = curr.ff.ss, currTime = curr.ss; 
        int nextTime = currTime+1; 
 
    
        for(auto d: dirs)
        {
            int nx = x+d.ff, ny = y+d.ss;
 
            //update g[nx][ny] if valid and if any other monster reached earlier :
            if(nx>=0 and nx<n and ny>=0 and ny<m and nextTime < g[nx][ny])
            {
                g[nx][ny] = nextTime;
                q.push({{nx,ny}, nextTime});
            }
        }
    }
}
 
void solve(){
    cin >> n >> m;
    g.assign(n,vector<int>(m, INT_MAX));
    path.assign(n,vector<pii>(m,{-1,-1}));
    
    for(int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            char c; cin >> c;
            if(c == '#') g[i][j] = 0;
            else if(c == 'M') g[i][j] = 0, monster.pb({i,j});
            else if(c == 'A') g[i][j] = 0, A = {i,j};
        }
    }
 
    //already at edge :
    if(A.ff == 0 or A.ss == 0 or A.ff == n-1 or A.ss == m-1) 
    {
        cout<<"YES\n0";
        return;
    }
 
    //precompute monsters using bfs : 
    preMonsters();
    
    if(!bfsA())
    {
        cout << "NO";
        return;
    }
 
    //retrace 
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
