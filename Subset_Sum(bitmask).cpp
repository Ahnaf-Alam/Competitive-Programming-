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

ll const MOD= 11092019;
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }
inline ll mod(ll a, ll m){ if(a<0) return m-(abs(a)%m); else if(a<m) return a; else return (a%m); }
const int MAX = 1000000;
const int N = 200005;
const int INF = 1e9;

int main()
{
    optimize
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n+2];
        for(int i=0;i<n;i++) cin>>a[i];
        int S; cin>>S;
        int flag=0;
        int tt=1<<n;
        for(int mask=0;mask<tt;mask++){
            int sum=0;
            for(int i=0;i<n;i++){
                int f=1<<i;
                if((mask & f)!=0) sum+=a[i];
            }
            if(sum==S){
                flag=1;
                break;
            }
        }
        if(flag) cout<<"Yes\n";
        else cout<<"No\n";
    }
}
/*input
1
5
8 5 -3 4 1
9
output : yes*/
