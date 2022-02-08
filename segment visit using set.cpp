#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using    namespace __gnu_pbds;
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

const ll MAX = 1e10;
const int N = 2e5;
const int INF = 1e9;
const int LN =  100;

typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// segement visited kina check korbe . ex : (0,0)->(0,1) = 1 . ekhne 0,0 theke 0,1  path ekbar visited hoise.
void solve(){
    string s; cin>>s;
    int n=s.length();
    set<pair<pair<int,int>,pair<int,int>>> st;
    int x=0,y=0;
    int ans=0;
    for(int i=0;i<n;i++){
        int x1,y1;
        if(s[i]=='N'){
            x1 = x+1;
            y1 = y ;
        }
        else if(s[i]=='S'){
            x1 = x-1;
            y1 = y;
        }
        else if(s[i]=='W'){
            x1 = x;
            y1 = y+1;
        }
        else if(s[i]=='E'){
            x1 = x;
            y1 = y-1;
        }
        pii s = make_pair(x,y);
        pii e = make_pair(x1,y1);
        pair<pii,pii> p = make_pair(s,e);
        pair<pii,pii> q = make_pair(e,s);
        if(st.find(p)!=st.end() || st.find(q)!=st.end()){
            ans++;
        }
        else{
            ans+=5;
            st.insert(p);
            //st.insert(q);
        }
        x=x1;
        y=y1;
    }
    cout<<ans<<"\n";
}
int main()
{
    optimize
    int t; cin>>t;
    while(t--){
        solve();
    }
}

