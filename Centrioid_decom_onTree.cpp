
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define  prec(n)        fixed<<setprecision(n)
#define  optimize       ios::sync_with_stdio(0); cin.tie(0);
#define  PI             acos(-1.0)
#define  RESET(a, b)    memset(a, b, sizeof(a))
#define  pb             push_back
#define  sz(v)          v.size()
#define  pii            pair<ll,ll>
#define  ff             first
#define  ss             second
#define  vv             vector<int>
#define  all(v)         v.begin(),v.end()

const int MOD = 1e9+7;
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p & 1LL) r = modMul(r, b); b = modMul(b, b); p >>= 1LL; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }


//update & query : https://www.youtube.com/watch?v=33K59_WrWZs
const int MAXN = 200005;
set<int>a[MAXN];
int par[MAXN];
int sub[MAXN];

int dfs1(int node,int p){
     sub[node]=1;
     for(auto x:a[node]){
        if(p==x) continue;
        sub[node]+=dfs1(x,node);
     }
     return  sub[node];
}
int dfs(int node,int p,int n){
    for(auto x :a[node]){
        if(x!=p && sub[x]>n/2)
            return dfs(x,node,n);
    }
    return node;
}
void decompose(int node,int p){
   int subTreeSize=dfs1(node,-1);
   int centroid= dfs(node,p,subTreeSize);

   cout<<"tree root at "<<node<<" with size "<<subTreeSize<<" has centroid "<<centroid<<endl;

   par[centroid]=p;
   for(auto x : a[centroid]){
      a[x].erase(centroid);
      decompose(x,centroid);
   }
}
int main()
{
    int n,x,y;
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        a[x].insert(y);
        a[y].insert(x);
    }
    decompose(1,-1);
    cout<<"parent array is follows "<<endl;
    for(int i=1;i<=n;i++){
        cout<<"\tPar["<<i<<"] = "<<par[i]<<endl;
    }
}
/* input
15 10
2 1
2 3
2 4
2 5
5 6
5 8
6 7
8 9
9 10
9 13
10 11
10 12
13 14
13 15

*/












