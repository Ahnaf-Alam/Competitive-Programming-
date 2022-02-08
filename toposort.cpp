#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define  prec(n)        fixed<<setprecision(n)
#define  optimize       ios::sync_with_stdio(0); cin.tie(0);
#define  PI             acos(-1.0)
#define  RESET(a, b)    memset(a, b, sizeof(a))
#define  pb             push_back
#define  pii            pair<int,int>
#define  ff             first
#define  ss             second
#define  vv             vector<int>
#define  sz(v)          v.size()
#define  all(v)         v.begin(),v.end()

int const MOD=(int)1e9+7;
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }
inline ll mod(ll a, ll m){ if(a<0) return m-(abs(a)%m); else if(a<m) return a; else return (a%m); }

vv toposort(vector<vector<int> > g){
   vv order;
   int n=g.size();
   vv indeg(n,0);
   for(int i=0;i<n;i++){
      for(auto it : g[i]){
        indeg[it]++;
      }
   }
   queue<int>q;
   for(int i=0;i<n;i++){
    if(indeg[i]==0) q.push(i);
   }
   while(q.size()>0){
      int top=q.front();
      q.pop();
      order.pb(top);
      for(auto it:g[top]){
        if(--indeg[it]==0) q.push(it);
      }
   }
   return order;
}
int main()
{
    optimize
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int> > g(n);
        vector<pair<int,int>>lst;
        for(int i=1;i<=m;i++){
            int t,x,y;
            cin>>t>>x>>y;
            x--,y--;
            lst.pb({x,y});
            if(t==1){
                g[x].pb(y);
            }
        }
        vv order=toposort(g);
        if(sz(order)<n){ // detect cycle
             cout<<"NO"<<endl;
             continue;
        }
        cout<<"YES"<<endl;
        vv idx(n,-1);
        for(int i=0;i<n;i++){
            idx[order[i]]=i;
        }
        for(auto it:lst){
            if(idx[it.ff]>idx[it.ss]) {
                    swap(it.ff,it.ss);
            }
            cout<<it.ff+1<<" "<<it.ss+1<<endl;
        }
    }
}
