
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")


#include<bits/stdc++.h>
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

int const MOD= 1e9+7;
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }
inline ll mod(ll a, ll m){ if(a<0) return m-(abs(a)%m); else if(a<m) return a; else return (a%m); }
const ll MAX = 200005;
const int N = 200005;
const ll INF = 1e15;

int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
ll a[1001][1001];
ll dis[1001][1001];
int n,w,h;
struct node{
   int u,v, cost;
   node(int _u,int _v,int _cost){
      u = _u;
      v = _v;
      cost = _cost;
   }
   bool operator < (const node& p) const { return cost> p.cost; } // operator overloading.
};
void dijkstra(int x,int y){
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++) dis[i][j]=INF;
    }
    priority_queue<node>q;
    q.push(node(x,y,0));
    dis[x][y]=0;
    while(sz(q)>0){
        node top=q.top();
        q.pop();
        for(int i=0;i<4;i++){
           int tx=top.u+fx[i];
           int ty=top.v+fy[i];
           if(tx>=0 && ty>=0 && tx<h && ty<w && dis[top.u][top.v]+a[tx][ty]<dis[tx][ty]){
              dis[tx][ty]=dis[top.u][top.v]+a[tx][ty];
              q.push(node(tx,ty,dis[tx][ty]));
           }
        }
    }
}

int main()
{
    optimize
    int t; cin>>t;
    while(t--){
        //int n,w,h;
        cin>>n>>w>>h;
        map<char,ll>cls;
        cls['E']= INF;
        for(int i=0;i<n;i++){
            char ch; ll val;
            cin>>ch>>val;
            cls[ch]=val;
        }
        int x,y;
        for(int i=0;i<h;i++){
            string s;
            cin>>s;
            for(int j=0;j<w;j++){
                if(s[j]=='E'){
                    x=i;
                    y=j;
                }
                a[i][j]=cls[s[j]];
            }
        }
        dijkstra(x,y);
        ll ans=INF;
        /*for(int i=0;i<h;i++){
            for(int j=0;j<w;j++) cout<<dis[i][j]<<" ";
            cout<<endl;
        }*/
        for(int i=0;i<w;i++){
            ans=min({ans,dis[0][i],dis[h-1][i]});
        }
        for(int i=0;i<h;i++){
            ans=min({ans,dis[i][0],dis[i][w-1]});
        }
        cout<<ans<<endl;
    }
}
