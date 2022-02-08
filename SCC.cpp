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
const int N = 2e5;
const int INF = 1e8;
const int LN =  100;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

vector<int>g[N],gr[N];
vector<bool> used;
vector<int>order,component;


vector<int>roots(N,0);
vector<int>root_node;
vector<int>scc[N];
void dfs1(int v){
    used[v]=true;

    for(auto x : g[v]){
        if(used[x]==false)
            dfs1(x);
    }
    order.pb(v);
}
void dfs2(int v){
    used[v]=true;
    component.pb(v);
    for(auto x : gr[v]){
        if(!used[x]){
            dfs2(x);
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g[x].pb(y);
        gr[y].pb(x);
    }
    used.assign(n,false);
    for(int i=0;i<n;i++){
        if(!used[i]){
            dfs1(i);
        }
    }
    used.assign(n,false);
    reverse(all(order));
    for(auto v : order){
        if(!used[v]){
            dfs2(v);
            for(auto x : component) cout<<x<<" ";
            cout<<"\n";
            int root = component.front();
            for(auto x : component) roots[x]=root;
            root_node.pb(root);
            component.clear();
        }
    }
    for(auto v=0;v<n;v++){
        for(auto u : g[v]){
            int root_v = roots[v];
            int root_u = roots[u];
            if(root_u != root_v){
                scc[root_v].pb(root_u);
            }
        }
    }
    /*for(int i=1;i<=n;i++){
        for(auto x : scc[i]) cout<<x<<" ";
        cout<<"\n";
    }*/
}

/*output
7 8
1 2
2 3
3 1
3 4
4 5
5 6
6 7
7 5
*/
