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
#define  ff             first
#define  ss             second
#define  vv             vector<int>
#define  all(v)         v.begin(),v.end()

const ll M = 1000000007;
const int maxN = 1e5+5;
const int maxA = 1e6+5;
const int LN = 19;
int cur;
int st[maxN],en[maxN],level[maxN],T[maxN],a[maxN];
int cnt[maxA];
int ANS[maxN];
int ID[2*maxN];
int vis[maxA];
int P[maxN][22]; // sparse table
int spf[maxA];
ll inv[20*maxN];
ll ans;
int K;
vector<int> g[maxN];
struct Query{
    int index, L, R,lc;
    bool operator < (const Query &other) const {
		int block_own = L/K;
		int block_other = other.L/K;
		if(block_own == block_other)
            return R < other.R;
		return block_own < block_other;
	}
}Q[maxN];
ll power(ll a, ll b) {
    if(b == 0) return 1;
    ll x = power(a, b / 2);
    x = (x * x)%M;
    if(b%2) x = (x*a)%M;
    return x;
}
void dfs(int u,int p){
   st[u]= ++cur;
   ID[cur]=u;
   T[u]=p;
   level[u]=level[p]+1;
   for(int i=0;i<g[u].size();i++){
     int x=g[u][i];
     if(x==p) continue;
     dfs(x,u);
   }
   en[u]= ++cur;
   ID[cur]=u;
}
void LCA_init(){
   RESET(P,-1);
   for(int i=0;i<maxN;i++) P[i][0]=T[i];

   for(int j=1;(1<<j)<maxN;j++){
    for(int i=0;i<maxN;i++){
        if(P[i][j-1]!=-1)
            P[i][j]=P[P[i][j-1]][j-1];
    }
   }
}
int LCA_query(int n,int p,int q){
    int tmp,log=1;
    if(level[p]<level[q])
        tmp=p,p=q,q=tmp;

    while(1){
        int next=log+1;
        if((1<<next)>level[p]) break;
        log++;
    }
    for(int i=log;i>=0;i--){
        if(level[p]-(1<<i)>=level[q])
            p=P[p][i];
    }
    if(p==q) return p;
    for(int i=log;i>=0;i--){
        if(P[p][i]!=-1 && P[p][i]!=P[q][i])
            p=P[p][i],q=P[q][i];
    }
    return T[p];
}
// precom find smallest prime factor which will be used for logn prime factorization and inv[i] will store modular inverse of i
void precom(){
   spf[1]=1;
   for(int i=2;i<maxA;i++) spf[i]=i;
   for(int i=4;i<maxA;i+=2) spf[i]=2;
   for(int i=3;i*i<maxA;i++){
    if(spf[i]==i){
        for(int j=i*i;j<maxA;j+=i){
            if(spf[j]==j) spf[j]=i;
        }
    }
   }
   for(ll i=i;i<20*maxN;i++){
    inv[i]=power(i,M-2);
   }
}
// this function will prime factorize x in logn and based on whether we are inserting/removing x in the product,
// ans will be updated.
void factorize(int x, int add) {
    x = a[x];
    int p = -1;
    while(x != 1) {
        if(spf[x] != p) {
            ans = (ans * inv[cnt[spf[x]]+1])%M;
            if(p != -1)
                ans = (ans * (cnt[p]+1))%M;
            p = spf[x];
        }
        if(add)
            ++cnt[spf[x]];
        else
            --cnt[spf[x]];
        x /= spf[x];
    }
    ans = (ans * (cnt[p]+1))%M;
}
void update(int x){
    vis[x] !=vis[x];
    factorize(x,vis[x]);
}
void mos(int q){
   int cl=0,cr=-1;
   ans=1;
   for(int i=0;i<q;i++){
    while(cl<Q[i].L) update(ID[cl++]);
    while(cl>Q[i].L) update(ID[--cl]);
    while(cr<Q[i].R) update(ID[++cr]);
    while(cr>Q[i].R) update(ID[cr--]);

    int u= ID[cl],v=ID[cr];
    if(Q[i].lc!=u && Q[i].lc!=v) update(Q[i].lc);
    ANS[Q[i].index]=ans;
    if(Q[i].lc!=u && Q[i].lc!=v) update(Q[i].lc);
   }
}
int main()
{
    optimize
    int t;
    cin>>t;
    LCA_init();
    precom();
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++) g[i].clear();
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            g[u-1].pb(v-1);
            g[v-1].pb(u-1);
        }
        for(int i=0;i<n;i++) cin>>a[i];
        cur=0;
        dfs(0,0);
        int q;
        cin>>q;
        for(int i=0;i<q;i++){
            int u,v;
            cin>>u>>v;
            u--;
            v--;
            Q[i].index=i;
            Q[i].lc=LCA_query(n,u,v);
            //cout<<Q[i].lc<<endl;
            if(st[u]>st[v]) swap(u,v);
            if(Q[i].lc==u){
                Q[i].L=st[u];
                Q[i].R=st[v];
            }
            else{
                Q[i].L=en[u];
                Q[i].R=st[v];
            }
        }
        K= sqrt(cur+1);
        sort(Q,Q+q);
        RESET(cnt,0);
        RESET(vis,0);
        mos(q);
        for(int i=0;i<q;i++) cout<<ANS[i]<<endl;
    }
}
