
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

const int N = 1000000;
const int MAX=1000000;
const int INF = 1e9;
int dp[N];
struct Job{
   int st,en,prf;
};
bool cmp(Job x,Job y){
    return x.en<y.en;
}
int bn(Job a[],int n){
    int l=0;
    int r=n-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(a[mid].en<=a[n].st){
            if(a[mid+1].en<=a[n].st)
                l=mid+1;
            else return mid;
        }
        else r=mid-1;
    }
    return -1;
}
int solve(Job a[],int n){
    RESET(dp,0);
    dp[0]=a[0].prf;
    for(int i=1;i<n;i++){
        int inc = a[i].prf;
        int id=bn(a,i);
        if(id!=-1) inc+=dp[id];
        dp[i]=max(inc,dp[i-1]);
    }
    return dp[n-1];
}
int main()
{
    optimize
    int n; cin>>n;
    Job a[n+2];
    for(int i=0;i<n;i++) cin>>a[i].st>>a[i].en>>a[i].prf;
    sort(a,a+n,cmp);
    cout<<solve(a,n);
}
// output :
/* 4
   1 2 50
   3 5 20
   6 19 100
   2 100 200
   ans = 250
   */
