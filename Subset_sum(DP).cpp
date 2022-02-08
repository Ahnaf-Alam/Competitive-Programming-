
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
const int N = 1000;
const int MAX=10000000;
const int INF=1e9;

// Time complexity O(n*sum) & space complexity O(n*sum)
int dp[1001][1001];
void solve1(int a[],int n,int sum){

    RESET(dp,0);
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(j<a[i]) dp[i][j]=dp[i-1][j];
            else{
                int need=j-a[i];
                if(dp[i-1][j]==1 || dp[i-1][need]==1) dp[i][j]=1;
                else dp[i][j]=0;
            }
        }
    }
    if(dp[n][sum]==1) cout<<"Yes\n";
    else cout<<"No\n";
}
int dp1[10001];
void solve2(int a[],int n,int sum){
   dp1[0]=1;
   for(int i=1;i<=n;i++){
      int cur=a[i];
      for(int j=sum;j>=cur;j--){
        if(dp1[j] || (dp1[j-cur]==0)) continue;
        else dp1[j]=1;
      }
   }
   for(int i=1;i<=sum;i++) cout<<dp1[i]<<" ";
   cout<<endl;
}
int main()
{
    optimize
    int n; cin>>n;
    int a[n+2];
    for(int i=1;i<=n;i++) cin>>a[i];
    int S;
    cin>>S;
    solve1(a,n,S); //space O(n*sum)
    solve2(a,n,S); // space O(sum) eta use krle jkno sum ber korte parbo.
}
