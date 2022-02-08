
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
const int N = 3e5+5;
const int INF = 1e9;
const int LN =  20;


// this code give a most frequent value of an array .
int K,a[N],ans[N],cnt[N],qtd[N],sum,val;
struct Query{
    int index, L, R;
    bool operator < (const Query &other) const {
		int block_own = L/K;
		int block_other = other.L/K;
		if(block_own == block_other)
            return R < other.R;
		return block_own < block_other;
	}
}query[N];

void add(int index){
    qtd[cnt[a[index]]]--;
    cnt[a[index]]++;
    qtd[cnt[a[index]]]++;
    if(qtd[sum+1]) sum++;
}

void remove(int index){
    qtd[cnt[a[index]]]--;
    cnt[a[index]]--;
    qtd[cnt[a[index]]]++;
    if(sum>0 && !qtd[sum]) sum--;
}
int main()
{
    optimize
    //int t,ca=0; cin>>t;
    int n,q;
    cin>>n>>q;
    K=sqrt(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        l--,r--;
        query[i].L=l;
        query[i].R=r;
        query[i].index=i;
    }
    sort(query,query+q);
    int L=0,R=-1;
    sum=0;
    for(int i=0;i<q;i++){

        while(R<query[i].R) add(++R);
        while(L<query[i].L) remove(L++);
        while(R>query[i].R) remove(R--);
        while(L>query[i].L) add(--L);
        int len=query[i].R-query[i].L+1;
        if(sum<=(len+2-1)/2) ans[query[i].index]=1;
        else ans[query[i].index] = sum-(len-sum+1)+1;
    }
    for(int i=0;i<q;i++) cout<<ans[i]<<"\n";
}
