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

const ll MOD= 1e9+7;
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }
inline ll mod(ll a, ll m){ if(a<0) return m-(abs(a)%m); else if(a<m) return a; else return (a%m); }

const int MAX = 1000000;
const int N = 1e7+100;
const int INF = 1e9;
const int LN =  20;

// problem link : https://codeforces.com/contest/1512/problem/G ; explanation dairy  ;
ll d[N];
ll s[N];
ll ans[N];
void precom()
{
    RESET(d,-1);
    d[1]=1;
    for(ll i=2;i*i<=N;i++){
        if(d[i]==-1){
            d[i]=i;
            for(ll j=i*i;j<N;j+=i){
                if(d[j]==-1){
                    d[j]=i;
                }
            }
        }
    }
    s[1]=1;
    for(ll i=2;i<N;i++){
        if(d[i]==-1){
            d[i]=i;
            s[i]=i+1;
        }
        else{
            ll x=i;
            s[i]=1;
            while(x%d[i]==0){
                x/=d[i];
                s[i]=s[i]*d[i]+1;
            }
            s[i]*=s[x];
        }
    }
    RESET(ans,-1);
    for(ll i=N-1;i>0;i--){
        if(s[i]<N){
            ans[s[i]]=i;
        }
    }
}
int main()
{
    optimize
    precom();
    int t; cin>>t;
    while(t--){
        ll c;
        cin>>c;
        cout<<ans[c]<<"\n";
    }
}
