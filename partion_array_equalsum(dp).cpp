
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
#define  vii            vector<int>
#define  vll            vector<ll>
#define  ff             first
#define  ss             second
#define  sz(v)          v.size()
#define  all(v)         v.begin(),v.end()
#define  READ           freopen("abc.txt", "r", stdin);
#define  WRITE          freopen("abc.txt", "w", stdout);

int const MOD=(int) 1e9+7;
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }
inline ll mod(ll a, ll m){ if(a<0) return m-(abs(a)%m); else if(a<m) return a; else return (a%m); }

const int N = 1e3+5;
const int MAX=1000000;
const int INF = 1e9;


int main()
{
    optimize
    int t=1; //cin>>t;
    while(t--){
       int n; cin>>n;
       int a[n+2];
       int sum=0;
       for(int i=0;i<n;i++){
          cin>>a[i];
          sum+=a[i];
       }
       if(sum%2){
        cout<<"0\n";
        continue;
       }
       bool dp[sum/2+1][n+1];
       for(int i=0;i<=n;i++) dp[0][i]=true;
       for(int i=1;i<=sum/2;i++) dp[i][0]=false;
       for(int i=1;i<=sum/2;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=dp[i][j-1];
            if(i>=a[j-1])
                dp[i][j]=dp[i][j] || dp[i-a[j-1]][j-1];
        }
       }
       if(dp[sum/2][n]==0){
          cout<<"0\n";
       }
       else{
           int flag=0,id=0;
           for(int i=0;i<n;i++){
              if(a[i]%2){
                flag=1;
                id=i;
                break;
              }
           }
           if(flag) cout<<1<<"\n"<<id+1<<"\n";
           else{
            flag=0;
              while(flag==0){
                for(int i=0;i<n;i++){
                    a[i]/=2;
                    if(a[i]%2){
                        id=i+1;
                        flag=1;
                        break;
                    }
                }
              }
              cout<<1<<"\n"<<id<<"\n";
           }
       }
    }
}
