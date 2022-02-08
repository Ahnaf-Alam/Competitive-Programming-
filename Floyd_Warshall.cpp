#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define  prec(n)        fixed<<setprecision(n)
#define  optimize       ios::sync_with_stdio(0); cin.tie(0);
#define  PI             acos(-1.0)
#define  RESET(a, b)    memset(a, b, sizeof(a))
#define  pb             push_back
#define  pii            pair<int,int>
#define  pll            pair<ll,ll>
#define  vv             vector<int>
#define  ff             first
#define  ss             second
#define  sz(v)          v.size()
#define  all(v)         v.begin(),v.end()

int const MOD=(int) 1e9+7;
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }
inline ll mod(ll a, ll m){ if(a<0) return m-(abs(a)%m); else if(a<m) return a; else return (a%m); }
const int N = 2000007;
const int MAX=1000005;
const int INF = INT_MAX;
vv g[N];
int dis[2001][2001],path[2001][2001];
int dp[2001][2001];
stack<int>stk;
void floyd_warshall(int n,int m){

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j]=dis[i][j];
            if(dp[i][j]!= INF && i!=j) path[i][j]=i;
            else path[i][j]=-1;
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dp[i][k]== INF || dp[k][j]==INF) continue;
                if(dp[i][j]>dp[i][k]+dp[k][j]){
                    dp[i][j]=dp[i][k]+dp[k][j];
                    path[i][j]=path[k][j];
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) cout<<dp[i][j]<<" ";
            cout<<"\n";
        }
        cout<<"\n";
    }
}
void printpath(int s,int e){
      stk.push(path[s][e]);
      if(path[s][e]==s) return;
      printpath(s,path[s][e]);
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) dis[i][j]=0;
            else dis[i][j]=INF;
        }
    }
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        u--; v--;
        g[u].pb(v);
        dis[u][v]=w;
    }
    floyd_warshall(n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    stk.push(2);
    printpath(3,2);
    /*while(stk.size()>0)
    {
        int t=stk.top();
        cout<<t<<" ";
        stk.pop();
    }*/

}
// sample input
/*
   4 6
   1 2 3
   1 3 6
   1 4 15
   2 3 -2
   3 4 2
   4 1 1
   */
