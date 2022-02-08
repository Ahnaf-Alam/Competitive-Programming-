

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define  prec(n)        fixed<<setprecision(n)
#define  optimize       ios::sync_with_stdio(0); cin.tie(0);
#define  PI             acos(-1.0)
#define  RESET(a, b)    memset(a, b, sizeof(a))
#define  pb             push_back
#define  pii            pair<int,int>
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
const int N = 200007;
const int MAX=1000005;
vv ANS;
// https://www.youtube.com/watch?v=S9oUiVYEq7E
// longest increasing subsequence with binary search . Time complexity is  O(nlogn)
int lis(vector<int> const& a){
    int n=a.size();
    const int INF=1e9;
    vv d(n+1,INF);
    d[0]= -INF;

    for(int i=0;i<n;i++){
        int j= upper_bound(all(d),a[i])-d.begin();
        if(d[j-1]<a[i] && a[i]<d[j])
            d[j]=a[i];
    }
    int ans=0;
    for(int i=0;i<=n;i++){
        if(d[i]<INF){
            ans=i;
            ANS.pb(d[i]);
        }
    }
     for(int i=0;i<n;i++) cout<<d[i]<<" ";
     cout<<endl;
    return ans;
}
int main()
{
    optimize
    int n;
    cin>>n;
    vv a(n);
    for(int i=0;i<n;i++)  cin>>a[i];
    int ans=lis(a);
    for(auto x : ANS) cout<<x<<" ";
    cout<<endl;
    //cout<<n-ans<<endl;
}
