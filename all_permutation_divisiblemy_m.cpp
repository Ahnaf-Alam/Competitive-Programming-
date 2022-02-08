
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

    const int MAX = 100000;
    const int N = 2e5+7;
    const int INF = 1e9;
    const int LN =  21;

// given a base and a number k...and a number m; find how many number r divisible by k in base that is given.
// https://lightoj.com/problem/painful-bases
    ll dp[N][LN];
    int getdigit(char ch){
         if('0'<=ch && ch<='9') return int(ch-'0');
         else return int(ch-'A')+10;
    }
int main()
{
    optimize
    int t,ca=0; cin>>t;
    while(t--){

        int base,k;
        string s;
        cin>>base>>k;
        cin>>s;
        int n=s.length();
        int M=pow(2,n);
        for(int i=0;i<M;i++) for(int j=0;j<k;j++) dp[i][j]=0;
        dp[0][0]=1;
        for(int mask=0;mask<M;mask++){
            for(int j=0;j<n;j++){
                int d=getdigit(s[j]);
                if((mask&(1<<j))==0){
                    for(int rem=0;rem<k;rem++){
                        dp[mask|(1<<j)][(rem*base+d)%k]+=dp[mask][rem];
                    }
                }
            }
        }
        cout<<"Case "<<++ca<<": "<<dp[M-1][0]<<"\n";
    }
}
