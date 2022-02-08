#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;

#define  prec(n)        fixed<<setprecision(n)
#define  optimize       ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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

const ll MOD= 1e9+7;
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }
inline ll mod(ll a, ll m){ if(a<0) return m-(abs(a)%m); else if(a<m) return a; else return (a%m); }

const int MAX = 2e7+5;
const int N = 100005;
const ll INF = 1e18;
const int LN =  20;

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ll tree[3*N];
ll a[N];
void built(int node,int b,int e){

    if(b==e){
        tree[node]=a[b];
        return;
    }
    int left= 2*node;
    int right=2*node+1;
    int mid = (b+e)/2;
    built(left,b,mid);
    built(right,mid+1,e);
    tree[node] = __gcd(tree[left],tree[right]);
    return;
}
int query(int node,int b,int e,int i,int j){
    if(i>e || j<b) return 0;
    if(i<=b && e<=j) return tree[node];
    int left = 2*node;
    int right =2*node+1;
    int mid = (b+e)/2;
    int p1 = query(left,b,mid,i,j);
    int p2 = query(right,mid+1,e,i,j);
    return __gcd(p1,p2);
}
void solve(){
   int n,q; cin>>n>>q;
   for(int i=1;i<=n;i++) cin>>a[i];
   built(1,1,n);
   while(q--){
       int x,y; cin>>x>>y;
       ll g1 = query(1,1,n,1,x-1);
       ll g2 = query(1,1,n,y+1,n);
       cout<<__gcd(g1,g2)<<"\n";
   }
}
int main()
{
     optimize
     int t; cin>>t;
     while(t--){
        solve();
     }
}

