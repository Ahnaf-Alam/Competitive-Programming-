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

int const MOD=(int) 1e9+7;
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }
inline ll mod(ll a, ll m){ if(a<0) return m-(abs(a)%m); else if(a<m) return a; else return (a%m); }
const int N = 200007;
const int MAX=1000005;

int main()
{
    optimize
    int n,m;
    cin>>n>>m;
    int a[n+2];
    for(int i=0;i<n;i++) cin>>a[i];
    deque<pii>dq;
    pii p1,p2;
    for(int i=0;i<n;i++){
        if(!dq.empty()){
           int y=0;
           for(auto it=dq.begin();it!=dq.end();){
              p1= *it;
              if(a[i]<=p1.ff || p1.ss<=i-m){
                dq.erase(it);
                it=dq.begin()+y;
              }
              else{
                y++;
                it=dq.begin()+y;
              }
           }
        }
        dq.push_front({a[i],i});
        if(m-1<=i){
            p1=dq.back();
            cout<<p1.ff<<endl;
        }
    }
}
// sample output
/* 5 3
   10 50 15 12 4

*/
