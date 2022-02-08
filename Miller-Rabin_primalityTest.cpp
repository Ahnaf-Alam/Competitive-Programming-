#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define  prec(n)        fixed<<setprecision(n)
#define  optimize       ios::sync_with_stdio(0); cin.tie(0);
#define  PI             2*acos(0.0)
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
const ll MAX = 1e7+1;
const ll N = 1000000;
const int INF = INT_MAX;
bool a[N];
int fx[]={2,-2,2,-2,-1,-1,1,1};
int fy[]={-1,-1,1,1,2,-2,2,-2};
ll binpow(ll base,ll e, ll mod){

    ll r=1;
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
   ll x=binpow(a,d,n);
   if(x==1 || x==n-1) return false;
   for(int r=1;r<s;r++){
    x= x*x %n;
    if(x==n-1) return false;
   }
   return true;
}
bool MillerRabin(ll n){
    if(n<2) return false;

    int r=0;
    ll d= n-1;
    while((d & 1)==0){
        d>>=1;
        r++;
    }
    cout<<r<<" "<<d<<endl;
    for(int a : {2,5,7,11,13,17,19,23,29,31,37}){
        if(n==a) return true;

        if(chk_composite(n,a,d,r))
            return false;
    }
    return true;
}
int main()
{
    ll n;
    cin>>n;
    bool x=MillerRabin(n);
    if(x==true) cout<<"isPrime";
    else cout<<"notPrime";
}
