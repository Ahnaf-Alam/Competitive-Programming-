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

ll const MOD= 1e9+7;
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }
inline ll mod(ll a, ll m){ if(a<0) return m-(abs(a)%m); else if(a<m) return a; else return (a%m); }
const ll MAX = 1000005;
const ll N = 1000000;
const int INF = 1e9;

unsigned long long binpow(unsigned long long base,unsigned long long e,unsigned long long mod){

    unsigned long long r=1;
    base%=mod;
    while(e){
        if(e & 1){
            r= r * base % mod;
        }
        base = base*base %mod;
        e>>=1;
    }
    return r;
}

bool chk_composite(ll n,ll a,ll d,int s){
   unsigned long long x=binpow(a,d,n);
   if(x==1 || x==n-1) return false;
   for(int r=1;r<s;r++){
    x= x*x %n;
    if(x==n-1) return false;
   }
   return true;
}
bool MillerRabin(unsigned long long n){
    if(n<2) return false;

    int r=0;
    unsigned long long d= n-1;
    while((d & 1)==0){
        d>>=1;
        r++;
    }
    //cout<<r<<" "<<d<<endl;
    for(int a : {2,5,7,11,13,17,19,23,29,31,37}){
        if(n==a) return true;

        if(chk_composite(n,a,d,r))
            return false;
    }
    return true;
}
int main()
{
    optimize;
    int t; cin>>t;
    while(t--){
      unsigned long long n;
      cin>>n;
      n--;
      while(1){
         bool x=MillerRabin(n);
         if(x) break;
         n--;
      }
      cout<<n<<endl;
    }
}
