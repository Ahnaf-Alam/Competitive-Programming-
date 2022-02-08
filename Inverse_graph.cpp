#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using    namespace __gnu_pbds;
using namespace std;
typedef long long ll;

#define  prec(n)        fixed<<setprecision(n)
#define  optimize       ios::sync_with_stdio(0); cin.tie(0);
#define  PI             acos(-1.0)
#define  RESET(a, b)    memset(a, b, sizeof(a))
#define  pb             push_back
#define  sz(v)          v.size()
#define  pii            pair<int,int>
#define  pll            pair<ll,ll>
#define  ff             first
#define  ss             second
#define  vv             vector<int>
#define  all(v)         v.begin(),v.end()

const ll MOD=   1000000007 ;
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }
inline ll mod(ll a, ll m){ if(a<0) return m-(abs(a)%m); else if(a<m) return a; else return (a%m); }

const int MAX = 1e6;
const int N = 5e5;
const int INF = 1e8;
const int LN =  100;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


// time complexity O(NlogN + NlogM)
unordered_set<int>g[N+7];
unordered_set<int>rmv;
queue<int>q;
vector<int>ans[N+7];
void solve(){
    int n,m; cin>>n>>m;
    int cnt=0;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        g[x].insert(y);
        g[y].insert(x);
    }
    for(int i=0;i<n;i++) rmv.insert(i);
    for(int i=0;i<n;i++){
        if(rmv.count(i)){
            q.push(i);
            rmv.erase(i);
            ans[cnt].pb(i);
            while(sz(q)>0){
                int top = q.front();
                q.pop();
                vector<int>tmp;
                for(int j : rmv){
                    if(!g[top].count(j)) tmp.pb(j);
                }
                for(int j : tmp){
                    rmv.erase(j);
                    q.push(j);
                    ans[cnt].pb(j);
                }
            }
            cnt++;
        }
    }
    cout<<cnt<<"\n";
    for(int i=0;i<cnt;i++){
        cout<<sz(ans[i])<<" ";
        for(int j=0;j<sz(ans[i]);j++) cout<<ans[i][j]+1<<" ";
        cout<<"\n";
    }
}
int main()
{
    optimize
    int t=1;  //cin>>t;
    while(t--){
        solve();
    }
}



