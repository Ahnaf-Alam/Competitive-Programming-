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
const int MAX=100000;

int n,e;
vii g[MAX];
vii color,par,cycle;
int cycle_start,cycle_end;
bool dfs(int s){
    color[s]=1;
    for(auto x : g[s]){
        if(color[x]==0){
            par[x]=s;
            if(dfs(x)) return true;
        }
        else if(color[x]==1){
            cout<<"yes"<<endl;
            cycle_start=x;
            cycle_end=s;
            return true;
        }
    }
    color[s]=2;
    return false;
}
void find_cycle(){
   color.assign(n,0);
   par.assign(n,-1);
   cycle_start=-1;
   for(int i=1;i<=n;i++){
    if(color[i]==0 && dfs(i)){
        break;
    }
   }
   //cout<<cycle_start<<" "<<cycle_end<<endl;
   if(cycle_start==-1) cout<<"Acyclic\n";
   else{
       cycle.pb(cycle_start);
       for(int i=cycle_end; i!=cycle_start;i=par[i]){
         cycle.pb(i);
       }
       cycle.pb(cycle_start);
       reverse(all(cycle));
       cout<<"cycle found\n";
       for(auto x:cycle){
         cout<<x<<" ";
       }
   }

}
int main(){

    optimize
    cin>>n>>e;
    for(int i=1;i<=e;i++){
        int x,y;
        cin>>x>>y;
        g[x].pb(y); // direct edge
    }
    find_cycle();
}
