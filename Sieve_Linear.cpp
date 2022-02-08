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

const ll MOD= 1e9 + 7;
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }
inline ll mod(ll a, ll m){ if(a<0) return m-(abs(a)%m); else if(a<m) return a; else return (a%m); }

const int MAX = 10000000;
const int N = 200005;
const int INF = 1e9;
//NOTE :
/* Normal sieve run time O(nlog log n) but this algorithm run time is O(n). Besides, the algorithm given here
calculates factorizations of all numbers in the segment [2;n] as a side effect, and that can be helpful in many
 practical applications.
The weakness of the given algorithm is in using more memory than the classic sieve of Eratosthenes':
it requires an array of n numbers, while for the classic sieve of Eratosthenes it is enough to have n
bits of memory (which is 32 times less).
Thus, it makes sense to use the described algorithm only until for numbers of order 10e7
and not greater.
*/
vector<int>prime;
int lp[MAX+1];
int main()
{
    optimize
    for(int i=2;i<=MAX;i++){
        if(lp[i]==0){
            lp[i]=i;
            prime.pb(i);
        }
        for(int j=0; j<sz(prime) && prime[j]<=lp[i] && i*prime[j]<=MAX;j++){
            lp[i * prime[j]]= prime[j];
        }
    }
    for(int i=2;i<=20;i++) cout<<i<<" "<<lp[i]<<endl;
}
